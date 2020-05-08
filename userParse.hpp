//
// Created by David Maples on 3/18/20.
//

#ifndef PROJECT3_USERPARSE_HPP
#define PROJECT3_USERPARSE_HPP
#include <string>

class userParse {
private:
    int city;
    double adArray[20][20];
    int s[20];
public:
    int getCities();
    void setCities(int city);
    void loadArray();
    void fillStartArray();
    int findFactorial(int num);
    double findCost(std::string temp);
    double findCostTemp(int x, int y);
    std::vector<std::string> permute(int permsThisCall);
    std::string printS();
};


#endif //PROJECT3_USERPARSE_HPP
