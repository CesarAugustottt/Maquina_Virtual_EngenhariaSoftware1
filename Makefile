#defini o compilador g++
CC = g++
#define as flags -Wall para avisos de warnings e Iinclude para buscar arquivos .h na pasta include
CFLAGS = -Wall -Iinclude
#define a pasta src
SRC_DIR = src
#define a pasta bin
BIN_DIR = bin
#define a pasta test
TEST_DIR = test

#Camkinho completo para o executável
TARGET = $(BIN_DIR)/main.exe
#Caminho completo para o arquivo do objeto
OBJ = $(BIN_DIR)/main.o

#roda o all para gerar executavel
all: $(TARGET)

#para criar o executavel precisa do arquivo objeto
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

#para criar o bin .o precisa do .cpp
$(OBJ): $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(OBJ)

#limpar os binarios ao digitar make clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.exe
	
#regra para compilar teste funcional (teste regressivo)
testeRegressivo: $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp -o $(BIN_DIR)/testeRegressivo.exe
