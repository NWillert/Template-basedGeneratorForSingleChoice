gen:
	g++ -std=c++2a -o gen src/main.cpp
	./gen.exe

clean: 
	rm -rf output/*