// generador_datos.cpp
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <cmath>
#include <omp.h>

struct Cuerpo {
    double x, y, z;
    double vx, vy, vz;
    double masa;
};

void generar_uniforme(std::vector<Cuerpo>& cuerpos, int N);
void generar_gaussiana(std::vector<Cuerpo>& cuerpos, int N);
void generar_plummer(std::vector<Cuerpo>& cuerpos, int N);
void guardar_en_archivo(const std::vector<Cuerpo>& cuerpos, const std::string& nombre_archivo, const std::string& formato);

int main() {
    int N;
    std::string tipo, formato;

    std::cout << "Cantidad de cuerpos: ";
    std::cin >> N;

    std::cout << "Tipo de distribución (uniforme/gaussiana/plummer): ";
    std::cin >> tipo;

    std::cout << "Formato de salida (csv/txt): ";
    std::cin >> formato;

    std::vector<Cuerpo> cuerpos(N);

    if (tipo == "uniforme") {
        generar_uniforme(cuerpos, N);
    } else if (tipo == "gaussiana") {
        generar_gaussiana(cuerpos, N);
    } else if (tipo == "plummer") {
        generar_plummer(cuerpos, N);
    } else {
        std::cerr << "Tipo de distribución inválido.\n";
        return 1;
    }

    guardar_en_archivo(cuerpos, "datos_generados." + formato, formato);

    std::cout << "Datos generados correctamente.\n";
    return 0;
}



void generar_uniforme(std::vector<Cuerpo>& cuerpos, int N) {
    #pragma omp parallel
    {
        std::mt19937 gen(omp_get_thread_num() + time(nullptr));
        std::uniform_real_distribution<double> dist(-1.0, 1.0);

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            cuerpos[i] = {dist(gen), dist(gen), dist(gen), 0, 0, 0, 1.0};
        }
    }
}

void generar_gaussiana(std::vector<Cuerpo>& cuerpos, int N) {
    #pragma omp parallel
    {
        std::mt19937 gen(omp_get_thread_num() + time(nullptr));
        std::normal_distribution<double> dist(0.0, 0.5);

        #pragma omp for
        for (int i = 0; i < N; ++i) {
            cuerpos[i] = {dist(gen), dist(gen), dist(gen), 0, 0, 0, 1.0};
        }
    }
}



void generar_plummer(std::vector<Cuerpo>& cuerpos, int N) {
    #pragma omp parallel
    {
        std::mt19937 gen(omp_get_thread_num() + time(nullptr));
        std::uniform_real_distribution<double> dist01(0.0, 1.0);
        #pragma omp for
        for (int i = 0; i < N; ++i) {
            double X1, X2, r;
            do {
                X1 = dist01(gen);
                X2 = dist01(gen);
                r = 1.0 / std::sqrt(std::pow(X1, -2.0/3.0) - 1.0);
            } while (r > 100.0);

            double z = (1.0 - 2.0 * dist01(gen)) * r;
            double theta = 2 * M_PI * dist01(gen);
            double x = std::sqrt(r*r - z*z) * std::cos(theta);
            double y = std::sqrt(r*r - z*z) * std::sin(theta);

            cuerpos[i] = {x, y, z, 0, 0, 0, 1.0};
        }
    }
}


void guardar_en_archivo(const std::vector<Cuerpo>& cuerpos, const std::string& nombre_archivo, const std::string& formato) {
    std::ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo.\n";
        return;
    }

    for (const auto& c : cuerpos) {
        if (formato == "csv") {
            archivo << c.x << "," << c.y << "," << c.z << "," << c.vx << "," << c.vy << "," << c.vz << "," << c.masa << "\n";
        } else {
            archivo << c.x << " " << c.y << " " << c.z << " " << c.vx << " " << c.vy << " " << c.vz << " " << c.masa << "\n";
        }
    }

    archivo.close();
}
