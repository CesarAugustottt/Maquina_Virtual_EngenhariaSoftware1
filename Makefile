# define o compilador g++
CC = g++
# define as flags -Wall para avisos de warnings e -Isrc para buscar arquivos .h na pasta src
# Itest busca o funcional_teste.h
CFLAGS = -Wall -Isrc -Itest/funcional
# define a pasta src
SRC_DIR = src
# define a pasta bin
BIN_DIR = bin
# define a pasta test
TEST_DIR = test

# Caminho completo para o executável
TARGET_MAIN = $(BIN_DIR)/main.exe
TARGET_TEST = $(BIN_DIR)/funcional_tests.exe

# Caminho completo para os arquivos objeto modularizados na pasta src
OBJS = $(BIN_DIR)/main.o $(BIN_DIR)/Flow.o $(BIN_DIR)/LogisticFlow.o $(BIN_DIR)/ExponentialFlow.o $(BIN_DIR)/ComplexFlow.o $(BIN_DIR)/Model.o $(BIN_DIR)/System.o

#Caminho completo para os arquivos objeto na pasta Test funcionais
OBJS_TEST = $(BIN_DIR)/funcional_tests.o $(BIN_DIR)/main_test.o

# Os testes também precisam do core do sistema (menos o main.o da src) para linkar
CORE_OBJS_FOR_TEST = $(BIN_DIR)/Flow.o $(BIN_DIR)/LogisticFlow.o $(BIN_DIR)/ExponentialFlow.o $(BIN_DIR)/ComplexFlow.o $(BIN_DIR)/Model.o $(BIN_DIR)/System.o

# roda o all para gerar executavel (Compila projeto principal e testes)
all: $(TARGET_MAIN) $(TARGET_TEST)

# para criar o executavel precisa dos arquivos objeto (Linkagem) -PROJETO PRINCIPAL
$(TARGET_MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET_MAIN)

# para criar o executavel precisa dos arquivos objeto (Linkagem) - TESTES FUNCIONAIS
$(TARGET_TEST): $(OBJS_TEST) $(CORE_OBJS_FOR_TEST)
	$(CC) $(CFLAGS) $(OBJS_TEST) $(CORE_OBJS_FOR_TEST) -o $(TARGET_TEST)

# Regra genérica (Pattern Rule) para compilar qualquer .cpp em .o correspondente
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regras específicas para compilar os arquivos de teste em .o correspondente
$(BIN_DIR)/funcional_tests.o: $(TEST_DIR)/funcional/funcional_tests.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/main_test.o: $(TEST_DIR)/funcional/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# limpar os binarios ao digitar make clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.exe

#Para rodar testes funcionais : ./bin/funcional_teste.exe