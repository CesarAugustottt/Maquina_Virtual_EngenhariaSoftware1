# Define o compilador
CC = g++

# FLAGS:
# -Wall: ativa avisos de erro importantes
# -Isrc: Busca os arquivos .h dentro da pasta src/ (onde estão Model.h, Flow.h, etc.)
# -Itest/funcional: Busca o funcional_tests.h para os testes se acharem
CFLAGS = -Wall -Isrc -Itest/funcional

# Pastas do projeto
SRC_DIR = src
BIN_DIR = bin
TEST_DIR = test/funcional

# Executáveis gerados
TARGET_MAIN = $(BIN_DIR)/main.exe
TARGET_TEST = $(BIN_DIR)/funcional_tests.exe

# Arquivos objeto do CORE do sistema (tudo que está em src/)
CORE_OBJS = $(BIN_DIR)/Flow.o $(BIN_DIR)/LogisticFlow.o $(BIN_DIR)/Model.o $(BIN_DIR)/System.o $(BIN_DIR)/ExponentialFlow.o

# Arquivos objeto exclusivos dos testes funcionais
TEST_OBJS = $(BIN_DIR)/funcional_tests.o $(BIN_DIR)/main_test.o

# Regra padrão: compila o sistema principal E os testes ao mesmo tempo
all: $(TARGET_MAIN) $(TARGET_TEST)

# Linkagem do executável principal (da pasta src)
$(TARGET_MAIN): $(BIN_DIR)/main.o $(CORE_OBJS)
	$(CC) $(CFLAGS) $(BIN_DIR)/main.o $(CORE_OBJS) -o $(TARGET_MAIN)

# Linkagem do executável de TESTES (Junta os testes com o Core do sistema)
$(TARGET_TEST): $(TEST_OBJS) $(CORE_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(CORE_OBJS) -o $(TARGET_TEST)

# Regra para compilar os arquivos .cpp da pasta src/ em .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regras para compilar os arquivos de teste da pasta test/funcional/
$(BIN_DIR)/funcional_tests.o: $(TEST_DIR)/funcional_tests.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/main_test.o: $(TEST_DIR)/main.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os binários antigos ao digitar make clean
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.exe