all:
	mkdir -p bin
	g++ test/funcional/*.cpp src/*.cpp -I./src -o bin/funcional_tests.exe
	g++ test/unit/*.cpp src/*.cpp -I./src -o bin/unit_tests.exe

run_funcional:
	./bin/funcional_tests.exe

run_unit:
	./bin/unit_tests.exe

clean:
	rm -rf bin/