// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/4/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #6

#include "../include/ObjectFactory.h"
#include "../include/Object.h"
#include "../include/Universe.h"

Object* ObjectFactory::makeObject(
    std::string name, double mass, const vector2& pos, const vector2& vel)
{
    Object* temp = new Object(name, mass, pos, vel);
    Universe::instance()->addObject(temp);
    return temp;
}
