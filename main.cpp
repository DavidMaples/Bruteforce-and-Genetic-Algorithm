//
// Created by David Maples on 3/18/20.
//
#include "userParse.hpp"
#include "geneticAlg.hpp"
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    //objects used for the genetic algorithm class and userParse
    geneticAlg object1;
    userParse object2;

    //asks the user to set the number of cities
    std::cout<<"Please enter the number of cities: "<< std::endl;
    int cityTemp;
    std::cin>>cityTemp;
    object2.setCities(cityTemp);

    //loads array from distances.txt
    object2.loadArray();
    object2.fillStartArray();

    //asks the user to set the number of generations
    std::cout<<"Please enter the number of generations: "<< std::endl;
    int genTemp;
    std::cin>>genTemp;
    object1.setGeneration(genTemp);

    //asks the user to set the number of tours
    std::cout<<"Please enter the number of tours: "<< std::endl;
    int toursTemp;
    std::cin>>toursTemp;
    object1.setTours(toursTemp);

    //asks the user to set the number of mutations
    std::cout<<"Please enter the percentage of mutations: "<< std::endl;
    int perTemp;
    std::cin>>perTemp;
    object1.setPercentage(perTemp);
    std::cout<<"-------------------------------------------"<< std::endl;
    std::cout<<"Number of cities run: " << object2.getCities()<< std::endl;


    //timer structure which is used below
    struct timeval * t;
    t = (struct timeval *)malloc(sizeof(struct timeval));
    gettimeofday(t,NULL);
    time_t startSec = t->tv_sec;



    //computing the number of mutated tours needed
    int numMut = object1.getTours() * object1.getPercentage() / 100;
    double finalCost = 100000;
    double finalLowest = 10000;

    for (int k = 0; k < object1.getGeneration(); ++k) {
        std::vector<std::string> temp1 = object2.permute(object1.getTours());
        std::vector<std::string> elites;
        std::vector<std::string> total;
        std::string elite;

        //selecting two elites from each generation
        for (int j = 0; j < 2; ++j) {
            double lowest1 = 100000;
            double cost1 = 100000;
            int index;

            for (int i = 0; i < temp1.size(); ++i) {
                std::string tempS = temp1.at(i);
                cost1 = object2.findCost(tempS);
                if(cost1 < lowest1){
                    lowest1 = cost1;
                    elite = temp1.at(i);
                    elites.push_back(elite);
                    index = i;
                }
            }
            elites.at(j) = temp1.at(index);
            temp1.erase(temp1.begin() + index);
        }
        //creating mutations by switching out 3 cities
        for (int l = 0; l < numMut; ++l) {
            char tempC, tempC2, tempC3;
            std::string tempString;
            if(l % 2 == 0){
                tempString = elites.at(1);
                tempC = tempString[1];
                tempC2 = tempString[2];
                tempC3 = tempString[3];
                tempString[1] = tempC2;
                tempString[2] = tempC3;
                tempString[3] = tempC;
                total.push_back(tempString);
            }else{
                tempString = elites.at(0);
                tempC = tempString[1];
                tempC2 = tempString[2];
                tempC3 = tempString[3];
                tempString[1] = tempC3;
                tempString[2] = tempC;
                tempString[3] = tempC2;
                total.push_back(tempString);
            }
        }

        // filling the rest of the tour up with fresh permutations
        std::vector<std::string> perms = object2.permute(object1.getTours() - total.size());
        for (int n = 0; n < perms.size(); ++n) {
            total.push_back(perms.at(n));
        }

        //computing the lowest cost tour
        for (int i = 0; i < object1.getTours(); ++i) {
            std::string stringTemp = total.at(i);
            finalCost = object2.findCost(stringTemp);
            if(finalCost < finalLowest){
                finalLowest = finalCost;
            }
        }
    }


    //time  and cost to run the GA algorithm
    std::cout<<"-------------------------------------------"<< std::endl;
    gettimeofday(t,NULL);
    printf("It took the GA algorithm: %ld seconds and %d microseconds.\n",t->tv_sec - startSec,t->tv_usec);
    std::cout<<"Genetic algorithm cost: "<< finalLowest << std::endl;


    //brute force algorithm to find the optimal tour distance
    std::vector<std::string> bruteVec = object2.permute(object2.findFactorial(object2.getCities()));
    double cost = 10000;
    double lowest = 10000;
    for (int i = 0; i < bruteVec.size(); ++i) {
        std::string temp1 = bruteVec.at(i);
        cost = object2.findCost(temp1);
        if(cost < lowest){
            lowest = cost;
        }
    }

    //brute force algorithm time and cost
    gettimeofday(t,NULL);
    printf("It took the Brute force algorithm: %ld seconds and %d microseconds.\n",t->tv_sec - startSec, t->tv_usec);
    std::cout<<"Optimal Brute force cost: " << lowest << std::endl;

    int totalPer;
    totalPer = (finalLowest/lowest) * 100;
    std::cout<<"The GA produced a solution that is " << totalPer << "% of the optimal solution." <<std::endl;

    return 0;
}
