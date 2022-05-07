#ifndef PARAMETER_H
#define PARAMETER_H

//Class for creating a Parameter that has one name and a vector with all its Values
class Parameter
{
public:
    Parameter(std::string thisName);

    std::string GetName();

    std::vector<std::string> GetValueRangeVector();

    std::string GetRandomValue();

    void push_backValueRange(std::string value);

private:
    std::string name{};
    std::vector<std::string> valueRange;
};

#endif // !1