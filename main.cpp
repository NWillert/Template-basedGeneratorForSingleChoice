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

int createRandomNumber(int randomFrom, int randomTo){
  srand(time(0));
  int randomNumber = rand();
  int anotherRandomNumber = randomFrom + rand() % randomTo;
  return anotherRandomNumber;
}

class Parameter
{
public:
  Parameter(string thisName){
    name = thisName;
  }

  string GetName(){
    return name;
  }

  void push_backValueRange(string value){
    valueRange.push_back(value);
  }

  void output(){
    cout << "Values:" << endl;
    for (string n : valueRange) {
        cout << "\t"<< n << endl;
    }
    cout << "Size of valueRangeVector: " << valueRange.size() << endl;
  }

private:
  string name{};
  vector<string> valueRange;
};

class Question
{
public:
  Question(string q_name,string q_author,string q_description,string q_taxonomy,string q_task,
    string q_correctAnswer, string q_wrongAnswerOne, string q_wrongAnswerTwo, string q_wrongAnswerThree){
      name=q_name;
      author=q_author;
      description=q_description;
      taxonomy=q_taxonomy;
      task=q_task;
      correctAnswer=q_correctAnswer;
      wrongAnswerOne=q_wrongAnswerOne;
      wrongAnswerTwo=q_wrongAnswerTwo;
      wrongAnswerThree=q_wrongAnswerThree;
    }

void outputQuestion(){
  cout << "Name: " << name << endl
      << "Author: " << author << endl
      << "Description: " << description << endl
      << "Taxonomy: " << taxonomy << endl
      << "Task: " << task << endl
      << "Correct: " << correctAnswer << endl
      << "Wrong 1: " << wrongAnswerOne << endl
      << "Wrong 2: " << wrongAnswerTwo << endl
      << "Wrong 3: " << wrongAnswerThree << endl;
}



private:
  string name{}, author{}, description{}, taxonomy{}, task{}, correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
};






int main() {

    int examId{};
    int numberOfExams{};
    int currentQuestionId{ 1 };
    vector <Question> questions;


    //Aktivieren wenn gebraucht.
    /*
    cout << "Please input, how many versions should be generated: ";
    cin >> numberOfExams;

    cout << "Please input the question pool id: ";
    cin >> examId;
    */


    //Parsing Files in Input Folder
    for (const auto& entry : fs::directory_iterator(path))
    {
        ifstream readFromFile;
        string name{}, author{}, date{}, version{}, description{}, taxonomy{}, task{};
        vector<Parameter> parameters{};
        vector<string> correctAnswers{};
        vector<string> wrongAnswers{};
        vector<pair<string, string>> interactions{};
        vector<pair<string, string>> exclusions{};

        string txtFromFile = "";


        string filename= entry.path().string() ;
        readFromFile.open(filename, ios_base::in);

        if (readFromFile.is_open()) {
          //  cout << filename << endl;
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
                            Parameter p(parameterString);
                            parameters.push_back(p);
                        }
                    }
                    else if (txtFromFile == "@VALUERANGE") {
                        int position=0;
                        string tempLine{};
                        string temp{};
                        while (readFromFile.peek() != '@'){
                          istringstream is;
                          getline(readFromFile,tempLine);
                          is.str(tempLine);
                          while(is){
                            string whitespace = " ";
                            while (is.peek() > 32) {
                                temp += is.get();
                            }
                            is.get();
                            if (is.peek() == '#')
                            {
                                parameters[position].push_backValueRange(temp);
                                is.get();
                                temp = "";
                            }
                            else if(!temp.empty())
                            {
                                temp += whitespace;
                            }
                            if (is.peek() == '@') {
                              if(temp != ""){
                                parameters[position].push_backValueRange(temp);
                              }
                            }
                          }
                          ++position;
                        }
                    }
                    else if (txtFromFile == "@INTERACTION") {
                      int line = 0;
                      int position=0;
                      string tempLine{};
                      string temp{};
                      string parameterName{}, parameterValue{}, parameterTwoName{}, parameterTwoValue{};
                      while (readFromFile.peek() != '@'){
                        istringstream is;
                        getline(readFromFile,tempLine);
                        is.str(tempLine);
                          string whitespace = " ";
                          while (is.peek() > 32) {
                              temp += is.get();
                          }
                          is.get();
                          parameterName= temp;
                          temp= "";
                          while (is.peek() > 32) {
                              temp += is.get();
                          }
                          is.get();
                          parameterValue= temp;
                          temp= "";
                          while (is.peek() > 32) {
                              temp += is.get();
                          }
                          is.get();
                          parameterTwoName= temp;
                          temp= "";
                          while(is){
                            while (is.peek() > 32) {
                                temp += is.get();
                            }
                            is.get();
                            if(is.peek() == '#'){
                              //make pair pushback into vector
                              is.get();
                              parameterTwoValue=temp;
                              interactions.push_back(make_pair(parameterValue,parameterTwoValue));
                              ++position;
                              temp="";
                            }else if(!temp.empty())
                            {
                                temp += whitespace;
                            }
                          }
                          if(temp != ""){
                            //make pair pushback vector
                            parameterTwoValue = temp;
                            interactions.push_back(make_pair(parameterValue,parameterTwoValue));
                            temp="";
                          }
                          ++line;
                        }
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
                        while(readFromFile.good()){
                          string tempLine{},temp{};
                          string tempOne{},tempTwo{};
                          istringstream is;
                          getline(readFromFile,tempLine);
                          is.str(tempLine);
                          if (!tempLine.empty()){
                            while(is){
                                while (is.peek() > 32) {
                                    temp += is.get();
                                }
                                is.get();
                                tempOne=temp;
                                temp="";
                                while (is.peek() > 32) {
                                    temp += is.get();
                                }
                                is.get();
                                temp="";
                                while (is) {
                                    temp += is.get();
                                }
                                tempTwo=temp;
                                exclusions.push_back(make_pair(tempOne,tempTwo));
                              }
                          }
                        }
                    }
                    else {
                        cout << "There is something wrong with the Config" << endl;
                    }
                }
                else {
                    getline(readFromFile, txtFromFile);
                }

            }
            readFromFile.close();
        }
        //TODO Create Questions
        for(int i=0;i<numberOfExams; ++i){


          //questions.push_back(Question );
        }

        //TODO Fill in Parameters
    }


    //#TODO CREATE FILE HEADS

    //TODO Write/Append to the exisisting Files


    //#TODO CREATE file ends

    return 0;
}
