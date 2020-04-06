// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/4/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #6

#include "Visitor.h"
#include "Object.h"

PrintVisitor::PrintVisitor(std::ostream& os) : os(os) {}

void PrintVisitor::visit(Object& object) {
    os << object.getName();
}

