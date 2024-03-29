gen:
	g++ -std=c++2a -o obj/picture.o -c src/picture.cpp 
	g++ -std=c++2a -o obj/parameter.o -c src/parameter.cpp 
	g++ -std=c++2a -o obj/randomNumberFunction.o -c src/randomNumberFunction.cpp 
	g++ -std=c++2a -o obj/question.o -c src/question.cpp
	g++ -std=c++2a -o obj/questionTextVariants.o -c src/questionTextVariants.cpp
	g++ -std=c++2a -o obj/vectorHelperFunctions.o -c src/vectorHelperFunctions.cpp 
	g++ -std=c++2a -o obj/main.o -c src/main.cpp 
	g++ -std=c++2a -o gen obj/main.o obj/picture.o obj/parameter.o obj/randomNumberFunction.o obj/question.o obj/vectorHelperFunctions.o obj/questionTextVariants.o
	./gen.exe

clean: 
	rm -f obj/*
	rm -rf output/*