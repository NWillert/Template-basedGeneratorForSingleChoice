#include <random>
#include "randomNumberFunction.h"


int createRandomNumber(int startValue, int randomTo) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(startValue, randomTo);
    return distrib(gen);
}