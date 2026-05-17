# define o compilador g++
CC = g++
# define as flags -Wall para avisos de warnings e -Isrc para buscar arquivos .h na pasta src
CFLAGS = -Wall -Isrc
# define a pasta src
SRC_DIR = src
# define a pasta bin
BIN_DIR = bin
# define a pasta test
TEST_DIR = test

# Caminho completo para o executável
TARGET = $(BIN_DIR)/main.exe

# Caminho completo para os arquivos objeto modularizados
OBJS = $(BIN_DIR)/main.o $(BIN_DIR)/Flow.o $(BIN_DIR)/LogisticFlow.o $(BIN_DIR)/ExponentialFlow.o $(BIN_DIR)/Model.o $(BIN_DIR)/System.o

# roda o all para gerar executavel
all: $(TARGET)

# para criar o executavel precisa dos arquivos objeto (Linkagem)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Regra genérica (Pattern Rule) para compilar qualquer .cpp em .o correspondente
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# limpar os binarios ao digitar make clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.exe
