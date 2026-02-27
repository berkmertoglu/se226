//
// Created by ML201 on 2/27/2026.
//

#include "myFirstLabScript.h"
#include <iostream>
#include <string>
int main() {
    std::string name;
    std::string student_id;
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout <<"Hello" << name << "."<< std::endl;
    std::cout << "What is your Student ID?"<< std::endl;
    std::cin >> student_id;
    std::cout << "Your ID is : " << student_id <<"."<< std::endl;

    return 0;


}
