#include <string>
#include <vector>
#include <tuple>
#include "picture.h"
#include "parameter.h"
#include "vectorHelperFunctions.h"



using namespace std;


//As we save all Picture Objects in a vector, we check if the same pictures are used by different templates, so that we only have one picture copied and used
bool isPictureInVector(vector<Picture> picVector, string name) {
    bool isIn = false;
    for (int i = 0; i < picVector.size(); ++i) {
        if (picVector[i].GetName() == name) {
            isIn = true;
        }
    }
    return isIn;
}

//overloaded functions for checking if a certain int or string is allready in a given vector with these types. 
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
//As we save all Parameter Objects in a vector, we might want to check for errors in Interactions
bool isInVector(vector<Parameter> paraVector, string name) {
    bool isIn = false;
    for (int i = 0; i < paraVector.size(); ++i) {
        if (paraVector[i].GetName() == name) {
            isIn = true;
        }
    }
    return isIn;
}

//Return the first string at tuple position 0, where postion 2 is name
string nameOfZeroForTwo(vector<tuple<string, string, string, string>> interactions, string name){
    for (int i = 0; i < interactions.size(); ++i) {
        if (get<2>(interactions[i]) == name)
        {
            return get<0>(interactions[i]);
        }
    }
    return "";
}

//Checking if a pair of two strings is present at position 0 and 1 in a vector of tuples
bool isPairInVectorTupleZeroOne(pair<string, string> p_pair, vector<tuple<string, string, string, string>> v_vector)
{
    for (tuple t : v_vector) {
        if (get<0>(p_pair) == get<0>(t) && get<1>(p_pair) == get<1>(t)) {
            return true;
        }
    }
    return false;
}

//Check if the given string is a value for a given Parameter
bool isValueForParameter(vector<Parameter> paraVector, string parameter, string value) {
    bool isIn = false;
    for (int i = 0; i < paraVector.size(); ++i) {
        if (paraVector[i].GetName() == parameter) {
            if (isInVector(paraVector[i].GetValueRangeVector(), value)) {
                isIn = true;
            }            
        }
    }
    return isIn;
}