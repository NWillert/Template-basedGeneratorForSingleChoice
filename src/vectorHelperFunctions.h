#ifndef VECTORHELPERFUNCTIONS_H
#define VECTORHELPERFUNCTIONS_H

//As we save all Picture Objects in a vector, we check if the same pictures are used by different templates, so that we only have one picture copied and used
bool isPictureInVector(std::vector<Picture> picVector, std::string name);

//overloaded functions for checking if a certain int or string is allready in a given vector with these types. 
bool isInVector(std::vector<int> duplicateVector, int number);
bool isInVector(std::vector<std::string> duplicateVector, std::string number);
bool isInVector(std::vector<Parameter> paraVector, std::string name);

//Return the first string at tuple position 0, where postion 2 is name
std::string nameOfZeroForTwo(std::vector<std::tuple<std::string, std::string, std::string, std::string>> interactions, std::string name);

//Checking if a pair of two strings is present at position 0 and 1 in a vector of tuples
bool isPairInVectorTupleZeroOne(std::pair<std::string, std::string> p_pair, std::vector<std::tuple<std::string, std::string, std::string, std::string>> v_vector);

bool isValueForParameter(std::vector<Parameter> paraVector, std::string parameter, std::string value);

#endif // !1