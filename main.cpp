#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

string path = ".\\input";
string outputPath = ".\\output";

int main() {

    int examId{};
    int numberOfExams{};
    int currentQuestionId{ 1 };


    //Aktivieren wenn gebraucht.
    /*
    cout << "Please input, how many versions should be generated: ";
    cin >> numberOfExams;

    cout << "Please input the question pool id: ";
    cin >> examId;
    */

    

    //#TODO CREATE FILE HEADS

    //Parsing Files in Input Folder
    for (const auto& entry : fs::directory_iterator(path)) 
    {
        ifstream readFromFile;
        string name{}, author{}, date{}, version{}, description{}, taxonomy{}, task{};
        vector<string> parameter{};
        vector<string> correctAnswers{};
        vector<string> wrongAnswers{};
        vector<string> values{};
        


        string txtFromFile = "";


        string filename= entry.path().string() ;
        readFromFile.open(filename, ios_base::in);

        if (readFromFile.is_open()) {
            while (readFromFile.good()) {
                char c = readFromFile.peek();
                if (c == '@') 
                {
                    getline(readFromFile, txtFromFile);
                    if (txtFromFile == "@NAME") {
                        getline(readFromFile, name);
                    }
                    else if (txtFromFile == "@AUTHOR") {
                        getline(readFromFile, author);
                    }
                    else if (txtFromFile == "@DATE") {
                        getline(readFromFile, date);
                    }
                    else if (txtFromFile == "@VERSION") {
                        getline(readFromFile, version);
                    }
                    else if (txtFromFile == "@DESCRIPTION") {
                        getline(readFromFile, description);
                    }
                    else if (txtFromFile == "@TAXONOMY") {
                        getline(readFromFile, taxonomy);
                    }
                    else if (txtFromFile == "@PARAMETER") {
                        while (readFromFile.peek() == '$') {
                            string parameterString;
                            getline(readFromFile, parameterString);
                            parameter.push_back(parameterString);
                        }
                    }
                    else if (txtFromFile == "@VALUERANGE") {
                        // vector string values , char based comparison, trennzeichen @
                        // whitespace zwischenspeichern für den fall das es sich um satz oder so handelt, 
                        // falls nach einem whitespace @ kommt, verwerfen. 
                        // is.peek()
                        // token += is.get();
                        string temp{};
                        while (readFromFile.peek() != '@') {
                            
                            string whitespace = " ";
                            while (readFromFile.peek() > 32) {
                                temp += readFromFile.get();
                            }
                            readFromFile.get();
                            if (readFromFile.peek() == '#') 
                            {
                                values.push_back(temp);
                                readFromFile.get();
                                temp = "";
                            }
                            else if(!temp.empty())
                            {
                                temp += whitespace;
                            }
                            if (readFromFile.peek() == '@') {
                                values.push_back(temp);
                            }
                        }                     
                    }
                    else if (txtFromFile == "@INTERACTION") {

                    }
                    else if (txtFromFile == "@TASK") {
                        getline(readFromFile, task);
                    }
                    else if (txtFromFile == "@TRUE") {
                        while (readFromFile.peek() != '@') {
                            string correctAnswerString;
                            getline(readFromFile, correctAnswerString);
                            correctAnswers.push_back(correctAnswerString);
                        }
                    }
                    else if (txtFromFile == "@FALSE") {
                        while (readFromFile.peek() != '@') {
                            string wrongAnswerString;
                            getline(readFromFile, wrongAnswerString);
                            wrongAnswers.push_back(wrongAnswerString);
                        }
                    }
                    else if (txtFromFile == "@EXCLUSIONS") {
                        //c1-cn-1 for correct & w1-wn-1 for wrong 

                    }
                    else {
                        cout << "There is something wrong with the Config" << endl;
                    }
                }
                else {
                    getline(readFromFile, txtFromFile);
                }

                /*
@VALUERANGE
@INTERACTION
@EXCLUSIONS
                */

                
                
            }
            readFromFile.close();
        }

        cout << filename << endl;

        cout << "Values:" << endl;
        for (string n : values) {
            cout << n << endl;
        }
        cout << values.size() << endl;

        /*
        cout << "correct Answers:" << endl;
        for (string n : correctAnswers) {
            cout << n << endl;
        }
        cout << correctAnswers.size() << endl;
        
        cout << "wrong Answers:" << endl;
        for (string n : wrongAnswers) {
            cout << n << endl;
        }
        cout << wrongAnswers.size() << endl;
        */



        /*cout << "Name: " << name << endl << "Author: " << author << endl << "Date: " << date << endl
            << "Version: " << version << endl 
            << "Description: " << description << endl 
            << "Taxonomy: " << taxonomy << endl;
        */
        
    }
   
    //Create Questions

    //Fill in Parameters 

    //Write/Append to the exisisting Files 


    //#TODO CREATE file ends

    return 0;
}

