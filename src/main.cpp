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
#include <algorithm>
#include <random>

using namespace std;
namespace fs = std::filesystem;

string path = ".\\input";
string outputPath = ".\\output";

int createRandomNumber(int startValue, int randomTo) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(startValue, randomTo);
    return distrib(gen);
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

  vector<string> GetValueRangeVector() {
      return valueRange;
  }

  string GetRandomValue() {
      return valueRange[createRandomNumber(0, valueRange.size() - 1)];
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
  Question(int Id,string q_name,string q_author,string q_description,string q_additionalText, string q_code,string q_taxonomy,string q_task,
    string q_correctAnswer, string q_wrongAnswerOne, string q_wrongAnswerTwo, string q_wrongAnswerThree){
      questionId=Id;
      name=q_name;
      author=q_author;
      description=q_description;
      additionalText = q_additionalText;
      code = q_code;
      taxonomy=q_taxonomy;
      task=q_task;
      correctAnswer=q_correctAnswer;
      wrongAnswerOne=q_wrongAnswerOne;
      wrongAnswerTwo=q_wrongAnswerTwo;
      wrongAnswerThree=q_wrongAnswerThree;
    }

void outputQuestion(){
  cout << "Id: " << questionId << endl
      << "Name: " << name << endl
      << "Author: " << author << endl
      << "Description: " << description << endl
      << "Additional Text: " << additionalText << endl
      << "Code: " << code << endl
      << "Taxonomy: " << taxonomy << endl
      << "Task: " << task << endl
      << "Correct: " << correctAnswer << endl
      << "Wrong 1: " << wrongAnswerOne << endl
      << "Wrong 2: " << wrongAnswerTwo << endl
      << "Wrong 3: " << wrongAnswerThree << endl;
}



private:
  int questionId;
  string name{}, author{}, description{},code{}, additionalText{}, taxonomy{}, task{}, correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
};


bool isInVector(vector<int> duplicateVector, int number) {
    if (std::find(duplicateVector.begin(), duplicateVector.end(), number) != duplicateVector.end())
        return true;
    else
        return false;
}

bool isInVector(vector<string> duplicateVector, string number) {
    if (std::find(duplicateVector.begin(), duplicateVector.end(), number) != duplicateVector.end())
        return true;
    else
        return false;
}

bool isInPairZero(vector<pair<string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<0>(interactions[i]) == name) {
            isIn = true;
        }
    }
    return isIn;
}

bool isInInteractionsZero(vector<tuple<string, string, string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<0>(interactions[i]) == name) {
            isIn = true;
        }
    }
    return isIn;
}


bool isInInteractionsOne(vector<tuple<string, string, string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<1>(interactions[i]) == name) {
            isIn = true;
        }
    }
    return isIn;
}

bool isInInteractionsTwo(vector<tuple<string, string, string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<2>(interactions[i]) == name) {
            isIn = true;
        }
    }
    return isIn;
}

bool isInInteractionsThree(vector<tuple<string, string, string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<3>(interactions[i]) == name) {
            isIn = true;
        }
    }
    return isIn;
}

string nameOfZeroForTwo(vector<tuple<string, string, string, string>> interactions, string name) {
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<2>(interactions[i]) == name) 
        {
            return get<0>(interactions[i]);
        }
    }
    return "";
}

string nameOfZeroForTwo(vector<pair<string, string>> interactions, string name) {
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<0>(interactions[i]) == name)
        {
            return get<1>(interactions[i]);
        }
    }
    return "";
}

bool isIZeroSetForITwo(vector<tuple<string, string, string, string>> interactions, vector<pair<string, string>> chosenOnes, string name) {
    if (isInPairZero(chosenOnes, nameOfZeroForTwo(interactions, name))) {
        return true;
    }
    else {
        return false;
    }
}




int main() {

    int examId{};
    int numberOfExams{};
    int currentQuestionId{ 1 };
    vector <Question> questions;

    //Aktivieren wenn gebraucht.
    cout << "Please input, how many versions should be generated: ";
    cin >> numberOfExams;
/*
    cout << "Please input the question pool id: ";
    cin >> examId;
    */


    //Parsing Files in Input Folder
    for (const auto& entry : fs::directory_iterator(path))
    {
        ifstream readFromFile;
        string name{}, author{}, date{}, version{}, description{}, taxonomy{}, task{};
        string code{}, additionalText{};
        vector<Parameter> parameters{};
        vector<string> correctAnswers{};
        vector<string> wrongAnswers{};
        vector<tuple<string, string, string, string>> interactions{};
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
                    else if (txtFromFile == "@ADDITIONALTEXT") {
                        getline(readFromFile, additionalText);
                    }
                    else if (txtFromFile == "@CODE") {
                      string tempLine{};
                        while(readFromFile.peek() != '@'){
                          getline(readFromFile, tempLine);
                          code +=tempLine;
                        }
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
                            if(is.peek() == '#' || is.peek() < 32){
                              //make pair pushback into vector
                              is.get();
                              parameterTwoValue=temp;
                              interactions.push_back(make_tuple(parameterName, parameterValue, parameterTwoName, parameterTwoValue));
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
                            interactions.push_back(make_tuple(parameterName, parameterValue, parameterTwoName, parameterTwoValue));
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
                                tempOne[1]=tempOne[1]-1;
                                tempTwo[1]=tempTwo[1]-1;
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

        //Combinatorics
        vector<tuple<int,int,int,int>> possibleCombinations;
        for(int i =0;i<correctAnswers.size();++i){
          for(int j=0;j<wrongAnswers.size();++j){
            for(int k=0;k<wrongAnswers.size();++k){
              for(int l=0;l<wrongAnswers.size();++l){
                possibleCombinations.push_back(make_tuple(i, j, k, l));                        
              }
            }
          }
        }

        //Delete Where same answers
        possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[](const tuple<int,int,int,int>& n) -> bool{
          return get<1>(n) == get<2>(n);
        }),possibleCombinations.end());

        possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[](const tuple<int,int,int,int>& n) -> bool{
          return get<1>(n) == get<3>(n);
        }),possibleCombinations.end());
       
        possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(), [](const tuple<int, int, int, int>& n) -> bool {
            return get<2>(n) == get<3>(n);
        }), possibleCombinations.end());


        

        //Delete based on Exclusions
        if(exclusions.size() != 0){
          for (pair n : exclusions) {
            string firstInPair (1,n.first[1]);
            string secondInPair(1,n.second[1]);
              if(n.first[0] == 'c'){
                possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[firstInPair, secondInPair](const tuple<int,int,int,int>& n) -> bool{
                  return (get<0>(n) == stoi(firstInPair) && stoi(secondInPair)==get<1>(n) || stoi(secondInPair)==get<2>(n) || stoi(secondInPair)==get<3>(n));
                }),possibleCombinations.end());
              }else{
                possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[firstInPair, secondInPair](const tuple<int,int,int,int>& n) -> bool{
                  return (get<1>(n) == stoi(firstInPair) && stoi(secondInPair)==get<1>(n) || stoi(secondInPair)==get<2>(n) || stoi(secondInPair)==get<3>(n));
                }),possibleCombinations.end());
                possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[firstInPair, secondInPair](const tuple<int,int,int,int>& n) -> bool{
                  return (get<2>(n) == stoi(firstInPair) && stoi(secondInPair)==get<1>(n) || stoi(secondInPair)==get<2>(n) || stoi(secondInPair)==get<3>(n));
                }),possibleCombinations.end());
                possibleCombinations.erase(std::remove_if(possibleCombinations.begin(), possibleCombinations.end(),[firstInPair, secondInPair](const tuple<int,int,int,int>& n) -> bool{
                  return (get<3>(n) == stoi(firstInPair) && stoi(secondInPair)==get<1>(n) || stoi(secondInPair)==get<2>(n) || stoi(secondInPair)==get<3>(n));
                }),possibleCombinations.end());
              }
            }
          }

        vector<int> duplicates;

        //Welche sind Duplikate?
        for (auto pos = 0; pos < possibleCombinations.size(); ++pos) {
            for (auto pos2 = 0; pos2 < possibleCombinations.size(); ++pos2) {
                if ((pos != pos2) &&
                    (pos < pos2) &&
                    (get<0>(possibleCombinations[pos]) == get<0>(possibleCombinations[pos2])) &&
                    (get<1>(possibleCombinations[pos]) == get<1>(possibleCombinations[pos2]) || get<1>(possibleCombinations[pos]) == get<2>(possibleCombinations[pos2]) || get<1>(possibleCombinations[pos]) == get<3>(possibleCombinations[pos2])) &&
                    (get<2>(possibleCombinations[pos]) == get<1>(possibleCombinations[pos2]) || get<2>(possibleCombinations[pos]) == get<2>(possibleCombinations[pos2]) || get<2>(possibleCombinations[pos]) == get<3>(possibleCombinations[pos2])) &&
                    (get<3>(possibleCombinations[pos]) == get<1>(possibleCombinations[pos2]) || get<3>(possibleCombinations[pos]) == get<2>(possibleCombinations[pos2]) || get<3>(possibleCombinations[pos]) == get<3>(possibleCombinations[pos2]))
                    )
                {
                    if (!isInVector(duplicates, pos2)) {
                        duplicates.push_back(pos2);
                    }
                }
            }
        }
        
        vector<tuple<int, int, int, int>> validCombinations;
        for (int i = 0; i < possibleCombinations.size(); ++i) {
            if (!isInVector(duplicates, i)) {
                validCombinations.push_back(possibleCombinations[i]);
            }
        }

        //Shuffle the validCombinations
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(validCombinations.begin(), validCombinations.end(), gen);     

        //Create Number of Questions and Replace potential Parameters
        for(int i=0;i<numberOfExams; ++i){          
          string correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
          int correct{},first{}, second{}, third{};

          int randomNumber = createRandomNumber(0,validCombinations.size() - 1);

          correctAnswer=correctAnswers[get<0>(validCombinations[randomNumber])];
          wrongAnswerOne = wrongAnswers[get<1>(validCombinations[randomNumber])];
          wrongAnswerTwo = wrongAnswers[get<2>(validCombinations[randomNumber])];
          wrongAnswerThree = wrongAnswers[get<3>(validCombinations[randomNumber])];

          //if Parameters exist
          if (!parameters.empty()) 
          {
              vector<pair<string, string>> chosenParameters{};
              vector<Parameter> unsetParameters{};
              //setzen der Parameter
              for (Parameter p : parameters) 
              {
                  string name = p.GetName();
                  //wenn interaction in pos 0
                  if (isInInteractionsZero(interactions, name)) {
                      //aber nicht an pos 2
                      if (!isInInteractionsTwo(interactions, name)) {                        
                          chosenParameters.push_back(make_pair(name, p.GetRandomValue()));
                      }
                      else {
                          if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                              // if yes then take value from one that is interacting with the other                             
                              // get the name of Zero with function allready written. 
                              //    nameOfZeroForTwo(interactions, name);
                              // get the name of ONE set in chosen Parameters
                              string chosenInteraction = nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name));
                              // put all THREES into a new vector 
                              vector<string> values;
                              for (tuple t : interactions) {
                                  if (chosenInteraction == get<1>(t))
                                  {
                                      values.push_back(get<3>(t));
                                  }
                              }
                              // randomised taking of one in the vectors                             
                              // assignment
                              chosenParameters.push_back(make_pair(name, values[createRandomNumber(0, values.size() - 1)]));
                          }
                          else {
                              unsetParameters.push_back(p);
                          }
                      }
                  }
                  else if (isInInteractionsTwo(interactions, name)) {
                      // check if coressponding Interaction 0 is set?
                      if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                          string chosenInteraction = nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name));
                          vector<string> values;
                          for (tuple t : interactions) {
                              if (chosenInteraction == get<1>(t))
                              {
                                  values.push_back(get<3>(t));
                              }
                          }
                          chosenParameters.push_back(make_pair(name, values[createRandomNumber(0, values.size() - 1)]));
                      }
                      else {
                          unsetParameters.push_back(p);
                      }                      
                  }
                  else {
                      chosenParameters.push_back(make_pair(name, p.GetRandomValue()));

                  }
              }

              if (!unsetParameters.empty()) {
                  while (parameters.size() > chosenParameters.size()) {
                      for (Parameter p : unsetParameters)
                      {
                          if (!isInPairZero(chosenParameters , p.GetName())) {
                              string name = p.GetName();
                              //wenn interaction in pos 0
                              if (isInInteractionsZero(interactions, name)) {  
                                if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                                    string chosenInteraction = nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name));
                                    vector<string> values;
                                    for (tuple t : interactions) {
                                        if (chosenInteraction == get<1>(t))
                                        {
                                            values.push_back(get<3>(t));
                                        }
                                    }
                                    chosenParameters.push_back(make_pair(name, values[createRandomNumber(0, values.size() - 1)]));
                                }
                              }
                              else if (isInInteractionsTwo(interactions, name)) {
                                  // check if coressponding Interaction 0 is set?
                                  if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                                      string chosenInteraction = nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name));
                                      vector<string> values;
                                      for (tuple t : interactions) {
                                          string temp = get<1>(t);
                                          if(chosenInteraction == temp)
                                          {
                                              values.push_back(get<3>(t));
                                          }
                                      }
                                      chosenParameters.push_back(make_pair(name, values[createRandomNumber(0, values.size() - 1)]));
                                  }
                              }
                          }                       
                      }
                  }               
              }
              
              // TODO -> wenn get 1 nicht in Interaction aber gew�hlt dann random. 
              // weil aktuell ist es so wenn ein wert genauer spezifiziert ist, dann m�ssen alle genauer spezifiziert werden. 


              




            // TODO STring ersetzung 
            //wenn in strings existiert (Answers, task, code?)
            //dann ersetzen 
          }




          Question q(currentQuestionId, name, author, description,additionalText, code, taxonomy,task,correctAnswer,wrongAnswerOne, wrongAnswerTwo, wrongAnswerThree);
          ++currentQuestionId;
          //q.outputQuestion();
          questions.push_back(q);

        }
    }


    //#TODO CREATE FILE HEADS

    //TODO Write/Append to the exisisting Files


    //#TODO CREATE file ends

    return 0;
}


/*
cout << "Tuples:" << endl;
for (tuple n : validCombinations) {
    cout << "\t"<< get<0>(n) << "\t"<< get<1>(n) << "\t"<< get<2>(n) << "\t"<< get<3>(n) << endl;
}
cout << "Size of validCombinations: " << validCombinations.size() << endl;


for (auto n : interactions) {
    cout << get<0>(n) << "\t" << get<1>(n) << "\t" << get<2>(n) << "\t" << get<3>(n) << "\t" << endl;
}


for (pair p : chosenParameters) {
                  cout << "Parameter: " << get<0>(p) << " is set to: " << get<1>(p) << endl;
              }
cout << currentQuestionId << endl;
*/