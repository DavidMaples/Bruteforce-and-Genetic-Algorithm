//
// Created by David Maples on 3/18/20.
//

#ifndef PROJECT3_GENETICALG_HPP
#define PROJECT3_GENETICALG_HPP
#include <string>
#include <iostream>
#include <vector>
#include "userParse.hpp"

class geneticAlg {
private:
    int gen;
    int tours;
    int percentage;

public:
    void setGeneration(int gen);
    int getGeneration();

    void setTours(int tours);
    int getTours();

    void setPercentage(int percentage);
    int getPercentage();
};


#endif //PROJECT3_GENETICALG_HPP
