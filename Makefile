all:
	mkdir -p bin
	g++ test/funcional/*.cpp src/*.cpp -I./src -o bin/funcional_tests.exe

run:
	./bin/funcional_tests.exe

clean:
	rm -f bin/funcional_tests.exe
