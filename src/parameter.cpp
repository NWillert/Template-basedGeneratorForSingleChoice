#include <string>
#include <vector>
#include "parameter.h"
#include "randomNumberFunction.h"
using namespace std;
//Class for creating a Parameter that has one name and a vector with all its Values

    Parameter::Parameter(string thisName) {
        name = thisName;
    }

    string Parameter::GetName() {
        return name;
    }

    vector<string> Parameter::GetValueRangeVector() {
        return valueRange;
    }
    
    string Parameter::GetRandomValue() {
        return valueRange[createRandomNumber(0, valueRange.size() - 1)];
    }

    void Parameter::push_backValueRange(string value) {
        valueRange.push_back(value);
    }
