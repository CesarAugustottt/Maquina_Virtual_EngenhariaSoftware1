CXX = g++
CFLAGS = -Wall -I./src -I./test/funcional
OBJS = ./bin/Flow.o ./bin/LogisticFlow.o ./bin/ExponentialFlow.o ./bin/ComplexFlow.o ./bin/Model.o ./bin/System.o

all: main funcional_tests

main: ./src/main.cpp $(OBJS)
	$(CXX) ./src/main.cpp -o ./bin/main.exe $(CFLAGS) $(OBJS)

funcional_tests: ./test/funcional/main.cpp ./test/funcional/funcional_tests.cpp $(OBJS)
	$(CXX) ./test/funcional/main.cpp ./test/funcional/funcional_tests.cpp -o ./bin/funcional_tests.exe $(CFLAGS) $(OBJS)

./bin/%.o: ./src/%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

clean:
	rm -f ./bin/*.exe ./bin/*.o