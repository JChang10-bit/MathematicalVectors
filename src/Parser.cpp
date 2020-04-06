// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/4/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #6

#include "Parser.h"
#include <cstring>
#include <fstream>
#include <iostream>


void Parser::loadFile(const char* filename) {
    std::ifstream file(filename, std::ifstream::in);
    if (file.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        std::cout << "UMCTest not able to open file: ../tests/testData.txt." << std::endl;
        exit(-1);
    } else {
        std::cout << "UMCTest opened file." << std::endl;
    }
    file.close();
}

