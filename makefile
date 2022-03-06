
# Rule 1: Link executable
obj/gen:
	g++ -std=c++2a -o gen src/main.cpp
	./gen.exe

# Rule 4: Delete all binaries and executable
clean:
	rm -r -fo output/*