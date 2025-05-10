
# Método de Integración Leapfrog

El **método Leapfrog** es un esquema de integración numérica **simplicial** de segundo orden. Es particularmente útil en simulaciones de sistemas dinámicos como el problema de N-cuerpos en gravitación, ya que conserva mejor la energía total del sistema durante largas simulaciones.

---

## Fundamento Matemático

Para un sistema de la forma:

$$
\frac{d^2x}{dt^2} = a(x, t)
$$

se define la velocidad como:

$$
v = \frac{dx}{dt}
$$

La forma básica del método Leapfrog divide el paso de tiempo en dos partes:

1. **Drift** (media posición):

$$
x_{n+1/2} = x_n + \frac{1}{2} \Delta t \cdot v_n
$$

2. **Kick** (actualización de la velocidad):

$$
v_{n+1} = v_n + \Delta t \cdot a(x_{n+1/2})
$$

3. **Drift** (completando la posición):

$$
x_{n+1} = x_{n+1/2} + \frac{1}{2} \Delta t \cdot v_{n+1}
$$

Esto da lugar al llamado **esquema Drift-Kick-Drift (DKD)**.

---

## Justificación Analítica

Para un sistema newtoniano de N cuerpos, se tiene:

$$
\frac{d^2\vec{r}_i}{dt^2} = \sum_{j \neq i} G \frac{m_j(\vec{r}_j - \vec{r}_i)}{|\vec{r}_j - \vec{r}_i|^3}
$$

El método Leapfrog se deriva al aproximar estas derivadas mediante diferencias finitas centradas, aprovechando su simetría para que el error global sea del orden \( \mathcal{O}(\Delta t^2) \).

---

## Ventajas

- **Simplicidad y eficiencia**
- **Estabilidad a largo plazo** (conservación de la energía)
- **Natural para sistemas hamiltonianos**

---

## Visualización: Órbita Simple con Leapfrog

A continuación se muestra la simulación de una partícula orbitando una masa central fija mediante Leapfrog:
![Orbit](orbit.png)

---

## Uso en tu Proyecto

Puedes usar este método en tu simulación con Octree y OpenMP, implementando tu propia gravedad con Barnes-Hut y luego usando Leapfrog como integrador numérico. Aunque REBOUND ya lo tiene implementado, puedes usar su código como guía o comparar resultados.



## ¿qué se conserva?

calcular el centro de masa y que se mueva con velocidad constante