# Define the compiler and flags
CXX = g++
CXXFLAGS = -std=c++2a

# Define the source and object files
SRCS = src/picture.cpp src/parameter.cpp src/randomNumberFunction.cpp src/question.cpp src/questionTextVariants.cpp src/vectorHelperFunctions.cpp src/main.cpp
OBJS = $(SRCS:src/%.cpp=obj/%.o)

# Determine the executable extension based on the OS
ifeq ($(OS), Windows_NT)
	EXE = gen.exe
	RM = del /Q
	RMDIR = rmdir /S /Q
	RUN = $(EXE)
else
	EXE = gen
	RM = rm -f
	RMDIR = rm -rf
	RUN = ./$(EXE)
endif

# Default target
gen: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS)
	$(RUN)

# Compile object files
obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

# Clean target
clean:
	$(RM) obj/*
	$(RMDIR) output/*

# Create the obj directory if it doesn't exist
$(shell mkdir -p obj)

