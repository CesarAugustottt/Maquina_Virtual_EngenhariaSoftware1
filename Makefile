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
OBJS = $(BIN_DIR)/main.o $(BIN_DIR)/mySim.o

#roda o all para gerar executavel
all: $(TARGET)

#para criar o executavel precisa do arquivo objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

#Regra para comoilar main.o
$(BIN_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -o $(BIN_DIR)/main.o

#REGRA COMPILAR mySim.o
$(BIN_DIR)/mySim.o: $(SRC_DIR)/mySim.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mySim.cpp -o $(BIN_DIR)/mySim.o

#limpar os binarios ao digitar make clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.exe
	
#regra para compilar teste funcional (teste regressivo)
testeRegressivo: $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/bib.cpp $(TEST_DIR)/main.cpp -o $(BIN_DIR)/testeRegressivo.exe
