Generator to create single choice questions and question pools based on templates. 

The path structure is currently only tested on Windows, and would probaby need some customization and further developement. 

Questions have to be created as stated in the TemplateSpecification.txt
Each question has to be in its own file, in the input folder. 
Pictures can be present for the question and need to be in the inputPicture Folder. 

Building the Program either using make (compiles and executes the program), 
or just compiling the main.cpp with an adequate compiler currently everything was tested with g++ -std=c++2a.

There are two modi when using the generator. 
Randomised generation, so that you can specify how many instantiations you want for each question. 
	The valid Answer possibilities and parameter combinations get randomised and then matched in cycles.
All - generates all possible instantiation for each question. 
	Permutations of Answers are matched with each permutation of parameters. 


The Generator supports the export format for ILIAS-Questionpool Imports when the created folder for ILIAS is zipped. 
In Addition to this a simple Moodle-XML is supported, were ONLY the questions and answers can be imported!