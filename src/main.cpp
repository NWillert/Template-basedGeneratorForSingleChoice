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
#include <iterator>
#include <regex>

using namespace std;
namespace fs = std::filesystem;

string path = ".\\input";
string outputFolder = ".\\output";
const fs::path outputPath{ outputFolder };

string folderMarking = "1644584918__0__";
const string qpl = "qpl_";
const string qti = "qti_";



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
        << "Wrong 3: " << wrongAnswerThree << endl
        << endl;
}

int GetQuestionId() {
    return questionId;
}
string GetName() {
    return name;
}
string GetAuthor() {
    return author;
}
string GetDescription() {
    return description;
}
string GetCode() {
    return code;
}
string GetAdditionalText() {
    return additionalText;
}
string GetTaxonomy() {
    return taxonomy;
}
string GetTask() {
    return task;
}
string GetCorrectAnswer() {
    return correctAnswer;
}
string GetWrongAnswerOne() {
    return wrongAnswerOne;
}
string GetWrongAnswerTwo() {
    return wrongAnswerTwo;
}
string GetWrongAnswerThree() {
    return wrongAnswerThree;
}
bool IsCodeEmpty() {
    return code.empty();
}
bool IsAdditionalTextEmpty() {
    return additionalText.empty();
}
bool IsTaxonomyEmpty() {
    return taxonomy.empty();
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

bool isInPairOne(vector<pair<string, string>> interactions, string name) {
    bool isIn = false;
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<1>(interactions[i]) == name) {
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

void replaceAll(string& s, const string& search, const string& replace) {
    for (size_t pos = 0; ; pos += replace.length()) {
        // Locate the substring to replace
        pos = s.find(search, pos);
        if (pos == string::npos) break;
        // Replace by erasing and inserting
        s.erase(pos, search.length());
        s.insert(pos, replace);
    }
}




int main() {

    string questionPoolId{};
    string qpTitle{};
    string taxId{};
    string taxTitle{};

    int childId{}, parentId{};
    int numberOfExams{};
    int currentQuestionId{ 1 };
    vector <Question> questions;
    vector <string> taxonomyLevels;

    int mode{};

    //Aktivieren wenn gebraucht.
    /*
    cout << "Please input, how many versions should be generated: ";
    cin >> numberOfExams;

    cout << "Please input the question pool id: ";
    cin >> questionPoolId;

    cout << "Please input the question pool title: ";
    cin >> qpTitle;

    cout << "Please input the Taxonomy Id: ";
    cin >> taxId;

    cout << "Please input the Taxonomy Title: ";
    cin >> taxTitle;
    */
    cout << "Please input the question pool id: ";
    cin >> questionPoolId;

    cout << "Which Mode is to start? Enter 1 for Random and 2 for All: ";
    cin >> mode;

    numberOfExams = 20;
    //questionPoolId = "34568";
    qpTitle = "TestTitle";
    taxId = "42069";
    taxTitle = "TaxTest";

    childId = 15001;
    parentId = 15000;


    //Parsing Files in Input Folder
    for (const auto& entry : fs::directory_iterator(path))
    {
        ifstream readFromFile;
        string name{}, author{}, date{}, version{}, description{}, taxonomy{}, task{}, code{}, additionalText{};
        string taskToSet{}, codeToSet{}, additionalTextToSet{};
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
                          code += "<br/>";
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



        if (mode == 1) {
            //Create Number of Questions and Replace potential Parameters
            for (int i = 0; i < numberOfExams; ++i) {
                string correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
                int correct{}, first{}, second{}, third{};

                int randomNumber = createRandomNumber(0, validCombinations.size() - 1);

                correctAnswer = correctAnswers[get<0>(validCombinations[randomNumber])];
                wrongAnswerOne = wrongAnswers[get<1>(validCombinations[randomNumber])];
                wrongAnswerTwo = wrongAnswers[get<2>(validCombinations[randomNumber])];
                wrongAnswerThree = wrongAnswers[get<3>(validCombinations[randomNumber])];

                //Setting these Variables because task, code and additionalText are set through the parser and when using Parameters we write them out
                //So to keep the Originals we use the extra variables *ToSet to dont change the variables that might be the same when creating more then one
                taskToSet = task;
                codeToSet = code;
                additionalTextToSet = additionalText;

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
                                    if (isInInteractionsOne(interactions, nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name)))) {
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
                                        //if the chosen parameter is set but there is no interaction set random
                                        chosenParameters.push_back(make_pair(name, p.GetRandomValue()));
                                    }
                                }
                                else {
                                    unsetParameters.push_back(p);
                                }
                            }
                        }
                        else if (isInInteractionsTwo(interactions, name)) {
                            // check if coressponding Interaction 0 is set?
                            if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                                if (isInInteractionsOne(interactions, nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name)))) {
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
                                    chosenParameters.push_back(make_pair(name, p.GetRandomValue()));
                                }
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
                                if (!isInPairZero(chosenParameters, p.GetName())) {
                                    string name = p.GetName();
                                    //wenn interaction in pos 0
                                    if (isInInteractionsZero(interactions, name)) {
                                        if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                                            if (isInInteractionsOne(interactions, nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name)))) {
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
                                                chosenParameters.push_back(make_pair(name, p.GetRandomValue()));
                                            }
                                        }
                                    }
                                    else if (isInInteractionsTwo(interactions, name)) {
                                        // check if coressponding Interaction 0 is set?
                                        if (isIZeroSetForITwo(interactions, chosenParameters, name)) {
                                            if (isInInteractionsOne(interactions, nameOfZeroForTwo(chosenParameters, nameOfZeroForTwo(interactions, name)))) {
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
                                                chosenParameters.push_back(make_pair(name, p.GetRandomValue()));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }



                    //Replace all parameters where they could stand
                    for (pair n : chosenParameters) {
                        replaceAll(correctAnswer, get<0>(n), get<1>(n));
                        replaceAll(wrongAnswerOne, get<0>(n), get<1>(n));
                        replaceAll(wrongAnswerTwo, get<0>(n), get<1>(n));
                        replaceAll(wrongAnswerThree, get<0>(n), get<1>(n));
                        replaceAll(codeToSet, get<0>(n), get<1>(n));
                        replaceAll(taskToSet, get<0>(n), get<1>(n));
                        replaceAll(additionalTextToSet, get<0>(n), get<1>(n));
                    }
                }





                if (!isInVector(taxonomyLevels, taxonomy)) {
                    taxonomyLevels.push_back(taxonomy);
                }

                Question q(currentQuestionId, name, author, description, additionalTextToSet, codeToSet, taxonomy, taskToSet, correctAnswer, wrongAnswerOne, wrongAnswerTwo, wrongAnswerThree);
                ++currentQuestionId;
                //q.outputQuestion();
                questions.push_back(q);

            }
        }
        else if (mode == 2) {
        //create parameter Combinations
            for (tuple t : validCombinations) {
                            //for all parameter cominations
                             /*
                             string correctAnswer{}, wrongAnswerOne{}, wrongAnswerTwo{}, wrongAnswerThree{};
                        int correct{}, first{}, second{}, third{};

                        int randomNumber = createRandomNumber(0, validCombinations.size() - 1);

                        correctAnswer = correctAnswers[get<0>(validCombinations[randomNumber])];
                        wrongAnswerOne = wrongAnswers[get<1>(validCombinations[randomNumber])];
                        wrongAnswerTwo = wrongAnswers[get<2>(validCombinations[randomNumber])];
                        wrongAnswerThree = wrongAnswers[get<3>(validCombinations[randomNumber])];

                        //if Parameters exist
                        if (!parameters.empty())
                        {

                            //Setting these Variables because task, code and additionalText are set through the parser and when using Parameters we write them out
                                //So to keep the Originals we use the extra variables *ToSet to dont change the variables that might be the same when creating more then one
                            taskToSet = task;
                            codeToSet = code;
                            additionalTextToSet = additionalText;
                            //Replace all parameters where they could stand
                            for (pair n : chosenParameters) {
                                replaceAll(correctAnswer, get<0>(n), get<1>(n));
                                replaceAll(wrongAnswerOne, get<0>(n), get<1>(n));
                                replaceAll(wrongAnswerTwo, get<0>(n), get<1>(n));
                                replaceAll(wrongAnswerThree, get<0>(n), get<1>(n));
                                replaceAll(codeToSet, get<0>(n), get<1>(n));
                                replaceAll(taskToSet, get<0>(n), get<1>(n));
                                replaceAll(additionalTextToSet, get<0>(n), get<1>(n));
                            }
                        }
                        if (!isInVector(taxonomyLevels, taxonomy)) {
                            taxonomyLevels.push_back(taxonomy);
                        }

                        Question q(currentQuestionId, name, author, description, additionalTextToSet, codeToSet, taxonomy, taskToSet, correctAnswer, wrongAnswerOne, wrongAnswerTwo, wrongAnswerThree);
                        ++currentQuestionId;
                        //q.outputQuestion();
                        questions.push_back(q);

                 */
            }
        }
    }


    //Creating Output Structure
    if (!fs::exists(outputPath)) {
        fs::create_directory(outputPath);
    }
    string questionpoolFolder = outputFolder + "\\" + folderMarking + qpl + questionPoolId;
    fs::path questionpoolPath{ questionpoolFolder };
    fs::create_directory(questionpoolPath);

    fs::path modulesPath{ questionpoolFolder + "\\Modules" };
    fs::create_directory(modulesPath);
    fs::path modulesTestQPPath{ questionpoolFolder + "\\Modules\\TestQuestionPool" };
    fs::create_directory(modulesTestQPPath);
    fs::path modulesTestQPSetPath{ questionpoolFolder + "\\Modules\\TestQuestionPool\\set_1" };
    fs::create_directory(modulesTestQPSetPath);

    fs::path servicesPath{ questionpoolFolder + "\\Services" };
    fs::create_directory(servicesPath);
    fs::path servicesTaxPath{ questionpoolFolder + "\\Services\\Taxonomy" };
    fs::create_directory(servicesTaxPath);
    fs::path servicesTaxSetPath{ questionpoolFolder + "\\Services\\Taxonomy\\set_1" };
    fs::create_directory(servicesTaxSetPath);

    //Write/Append to Files
    ofstream writeToFile;
    //Write Manifest xml
    writeToFile.open(questionpoolFolder+"\\manifest.xml", ios_base::out);
    writeToFile <<
        "<?xml version=\"1.0\" encoding =\"UTF-8\"?><!--Generated by ILIAS XmlWriter--><Manifest MainEntity=\"qpl\" Title=\""
        << "Testimport"
        << "\" TargetRelease=\"5.4.0\" InstallationId=\"0\" InstallationUrl=\"https://eassessment.rz.uni-leipzig.de/eklausuren\"><ExportFile Component=\"Modules/TestQuestionPool\" Path=\"Modules/TestQuestionPool/set_1/export.xml\"/><ExportFile Component=\"Services/Taxonomy\" Path=\"Services/Taxonomy/set_1/export.xml\"/></Manifest>";
    writeToFile.close();

    //Write export in TestQuestionPool
    writeToFile.open(questionpoolFolder + "\\Modules\\TestQuestionPool\\set_1\\export.xml", ios_base::out);
    writeToFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        << "<!--Generated by ILIAS XmlWriter-->"
        << "<exp:Export InstallationId=\"0\" InstallationUrl=\"https://eassessment.rz.uni-leipzig.de/eklausuren\" Entity=\"qpl\" SchemaVersion=\"4.1.0\" TargetRelease=\"5.4.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:exp=\"http://www.ilias.de/Services/Export/exp/4_1\" xsi:schemaLocation=\"http://www.ilias.de/Services/Export/exp/4_1 https://eassessment.rz.uni-leipzig.de/eklausuren/xml/ilias_export_4_1.xsd http://www.ilias.de/Modules/TestQuestionPool/htlm/4_1 https://eassessment.rz.uni-leipzig.de/eklausuren/xml/ilias_qpl_4_1.xsd\" xmlns=\"http://www.ilias.de/Modules/TestQuestionPool/htlm/4_1\">"
        << "<exp:ExportItem Id=\""
        << questionPoolId
        << "\"></exp:ExportItem></exp:Export>";
    writeToFile.close();

    //Write the Questions into the qti
    writeToFile.open(questionpoolFolder + "\\" + folderMarking + qti + questionPoolId + ".xml");
    writeToFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        << "<!DOCTYPE questestinterop SYSTEM \"ims_qtiasiv1p2p1.dtd\">"
        << "<!--Generated by ILIAS XmlWriter-->"
        << "<questestinterop>";
    for (Question q : questions) {
        writeToFile << "<item ident=\"il_0_qst_" << q.GetQuestionId() << "\" title=\"" << q.GetName() << "\" maxattempts=\"0\">"
            << "<qticomment/><duration>P0Y0M0DT0H1M0S</duration><itemmetadata><qtimetadata><qtimetadatafield><fieldlabel>ILIAS_VERSION</fieldlabel><fieldentry>5.4.26 2021-12-22</fieldentry></qtimetadatafield><qtimetadatafield><fieldlabel>QUESTIONTYPE</fieldlabel><fieldentry>SINGLE CHOICE QUESTION</fieldentry></qtimetadatafield>"
            << "<qtimetadatafield><fieldlabel>AUTHOR</fieldlabel><fieldentry>" << q.GetAuthor() << "</fieldentry></qtimetadatafield><qtimetadatafield><fieldlabel>additional_cont_edit_mode</fieldlabel><fieldentry>default</fieldentry></qtimetadatafield><qtimetadatafield><fieldlabel>thumb_size</fieldlabel><fieldentry/></qtimetadatafield>"
            << "<qtimetadatafield><fieldlabel>feedback_setting</fieldlabel><fieldentry>2</fieldentry></qtimetadatafield><qtimetadatafield><fieldlabel>singleline</fieldlabel><fieldentry>0</fieldentry></qtimetadatafield></qtimetadata></itemmetadata>"
            << "<presentation label=\""<< q.GetName() << "\"><flow>"
            << "<material><mattext texttype=\"text/xhtml\">" << q.GetTask() <<"</mattext></material>"
            << "<response_lid ident=\"MCSR\" rcardinality=\"Single\"><render_choice shuffle=\"Yes\">"
            << "<response_label ident=\"0\"><material><mattext texttype=\"text/xhtml\">"<< q.GetCorrectAnswer() <<"</mattext></material></response_label>"
            << "<response_label ident=\"1\"><material><mattext texttype=\"text/xhtml\">" << q.GetWrongAnswerOne() << "</mattext></material></response_label>"
            << "<response_label ident=\"2\"><material><mattext texttype=\"text/xhtml\">" << q.GetWrongAnswerTwo() << "</mattext></material></response_label>"
            << "<response_label ident=\"3\"><material><mattext texttype=\"text/xhtml\">" << q.GetWrongAnswerThree() << "</mattext></material></response_label>"
            << "</render_choice></response_lid></flow></presentation><resprocessing><outcomes><decvar></decvar></outcomes><respcondition continue=\"Yes\"><conditionvar><varequal respident=\"MCSR\">0</varequal></conditionvar><setvar action=\"Add\">1</setvar><displayfeedback feedbacktype=\"Response\" linkrefid=\"response_0\"/></respcondition>"
            << "<respcondition continue=\"Yes\"><conditionvar><varequal respident=\"MCSR\">1</varequal></conditionvar><setvar action=\"Add\">0</setvar><displayfeedback feedbacktype=\"Response\" linkrefid=\"response_1\"/></respcondition>"
            << "<respcondition continue=\"Yes\"><conditionvar><varequal respident=\"MCSR\">2</varequal></conditionvar><setvar action=\"Add\">0</setvar><displayfeedback feedbacktype=\"Response\" linkrefid=\"response_2\"/></respcondition>"
            << "<respcondition continue=\"Yes\"><conditionvar><varequal respident=\"MCSR\">3</varequal></conditionvar><setvar action=\"Add\">0</setvar><displayfeedback feedbacktype=\"Response\" linkrefid=\"response_3\"/></respcondition></resprocessing>"
            << "<itemfeedback ident=\"response_0\" view=\"All\"><flow_mat><material><mattext texttype=\"text/plain\">&#10;          </mattext></material></flow_mat></itemfeedback>"
            << "<itemfeedback ident=\"response_1\" view=\"All\"><flow_mat><material><mattext texttype=\"text/plain\">&#10;          </mattext></material></flow_mat></itemfeedback>"
            << "<itemfeedback ident=\"response_2\" view=\"All\"><flow_mat><material><mattext texttype=\"text/plain\">&#10;          </mattext></material></flow_mat></itemfeedback>"
            << "<itemfeedback ident=\"response_3\" view=\"All\"><flow_mat><material><mattext texttype=\"text/plain\">&#10;          </mattext></material></flow_mat></itemfeedback></item>"
            ;
    }
    writeToFile << "</questestinterop>";
    writeToFile.close();

    //Writing Question extras like Code or additional text in qpl
    writeToFile.open(questionpoolFolder + "\\" + folderMarking + qpl + questionPoolId + ".xml");
    writeToFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><!DOCTYPE Test SYSTEM \"http://www.ilias.uni-koeln.de/download/dtd/ilias_co.dtd\"><!--Export of ILIAS Test Questionpool "<< questionPoolId << " of installation .-->"
        << "<ContentObject Type=\"Questionpool_Test\"><MetaData><General Structure=\"Hierarchical\">"
        << "<Identifier Catalog=\"ILIAS\" Entry=\"il_0_qpl_" << questionPoolId << "\"/><Title Language=\"de\">"<<qpTitle<<"</Title><Language Language=\"de\"/><Description Language=\"de\"></Description><Keyword Language=\"de\"/></General></MetaData>"
        << "<Settings><ShowTaxonomies>1</ShowTaxonomies><NavTaxonomy>0</NavTaxonomy><SkillService>0</SkillService></Settings>";
    for (Question q : questions) {
        writeToFile << "<PageObject>";
        if (!q.IsAdditionalTextEmpty()) {
            writeToFile << "<PageContent><Paragraph Language=\"de\" Characteristic=\"Standard\">" << q.GetAdditionalText() << "</Paragraph></PageContent>";
        }
        if (!q.IsCodeEmpty()) {
            writeToFile << "<PageContent><Paragraph Language=\"de\" SubCharacteristic=\"cpp\" ShowLineNumbers=\"y\" Characteristic=\"Code\">" << q.GetCode() << "</Paragraph></PageContent>";
        }
        writeToFile << "<PageContent><Question QRef=\"il_0_qst_" << q.GetQuestionId() << "\"/></PageContent></PageObject>";
    }
    writeToFile << "<QuestionSkillAssignments>";
    for (Question q : questions) {
        writeToFile << "<TriggerQuestion Id=\"" << q.GetQuestionId() << "\"></TriggerQuestion>";
    }
    writeToFile << "</QuestionSkillAssignments></ContentObject>";
    writeToFile.close();

    //Writing the export xml for the Used Taxonomy
    writeToFile.open(questionpoolFolder + "\\Services\\Taxonomy\\set_1\\export.xml", ios_base::out);
    writeToFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><!--Generated by ILIAS XmlWriter--><exp:Export InstallationId=\"0\" InstallationUrl=\"https://eassessment.rz.uni-leipzig.de/eklausuren\" Entity=\"tax\" SchemaVersion=\"4.3.0\" TargetRelease=\"5.4.0\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:exp=\"http://www.ilias.de/Services/Export/exp/4_1\" xsi:schemaLocation=\"http://www.ilias.de/Services/Export/exp/4_1 https://eassessment.rz.uni-leipzig.de/eklausuren/xml/ilias_export_4_1.xsd http://www.ilias.de/Services/Taxonomy/tax/4_3 https://eassessment.rz.uni-leipzig.de/eklausuren/xml/ilias_tax_4_3.xsd http://www.ilias.de/Services/DataSet/ds/4_3 https://eassessment.rz.uni-leipzig.de/eklausuren/xml/ilias_ds_4_3.xsd\" xmlns=\"http://www.ilias.de/Services/Taxonomy/tax/4_3\" xmlns:ds=\"http://www.ilias.de/Services/DataSet/ds/4_3\">"
        << "<exp:ExportItem Id = \"" << taxId << "\"><ds:DataSet InstallationId=\"0\" InstallationUrl=\"https://eassessment.rz.uni-leipzig.de/eklausuren\" TopEntity=\"tax\">";
    //Tax Toplevel
    writeToFile << "<ds:Rec Entity=\"tax\"><Tax><Id>" << taxId << "</Id><Title>" << taxTitle << "</Title><Description></Description><SortingMode>0</SortingMode></Tax></ds:Rec>";
    //TaxTree Toplevel
    writeToFile << "<ds:Rec Entity=\"tax_tree\"><TaxTree><TaxId>" << taxId << "</TaxId><Child>"<< parentId <<"</Child><Parent>0</Parent><Depth>1</Depth><Type></Type><Title>Root node for taxonomy "<< taxId << "</Title><OrderNr>0</OrderNr></TaxTree></ds:Rec>";

    //For each level in taxonomy levels add a node to the tree
    int temp = 10;
    for (string t : taxonomyLevels) {
        writeToFile << "<ds:Rec Entity=\"tax_tree\"><TaxTree><TaxId>" << taxId << "</TaxId><Child>"
            << childId << "</Child><Parent>" << parentId << "</Parent><Depth>2</Depth><Type>taxn</Type><Title>"
            << t << "</Title><OrderNr>" << temp << "</OrderNr></TaxTree></ds:Rec>";
        for (Question q : questions) {
            if (q.GetTaxonomy() == t) {
                writeToFile << "<ds:Rec Entity=\"tax_node_assignment\"><TaxNodeAssignment><NodeId>" << childId
                    << "</NodeId><Component>qpl</Component><ItemType>quest</ItemType><ItemId>" << q.GetQuestionId() << "</ItemId></TaxNodeAssignment></ds:Rec>";
            }
        }
        ++childId;
        temp += 10;
    }
    writeToFile << "<ds:Rec Entity=\"tax_usage\"><TaxUsage><TaxId>" << taxId << "</TaxId><ObjId>" << questionPoolId << "</ObjId></TaxUsage></ds:Rec></ds:DataSet></exp:ExportItem></exp:Export>";
    writeToFile.close();

    return 0;
}
