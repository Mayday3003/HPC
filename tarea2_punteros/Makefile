# Variables generales
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
BIN_DIR = bin

# Lista de fuentes sin extensión .c
SOURCES := $(wildcard $(SRC_DIR)/*.c)
EXECUTABLES := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SOURCES))

# Regla por defecto: compila todos
all: $(EXECUTABLES)

# Regla para compilar cada archivo individual
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	@echo "Compilando $< -> $@"
	@$(CC) $(CFLAGS) $< -o $@ -lm


# Regla para limpiar ejecutables
clean:
	@echo "Limpiando ejecutables en $(BIN_DIR)..."
	@rm -f $(BIN_DIR)/*

# Regla para compilar solo un ejercicio: make ejercicio3
.PHONY: $(notdir $(basename $(SOURCES)))
$(notdir $(basename $(SOURCES))):
	$(MAKE) $(BIN_DIR)/$@
