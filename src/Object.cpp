// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/4/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #6

#include "Object.h"
#include "Visitor.h"
#include "Universe.h"
#include "Vector.h"

void Object::accept(Visitor& visitor) {
    visitor.visit(*this);
}

Object* Object::clone() const {
    Object* temp = new Object(name, mass, position, velocity);
    return temp;
}

double Object::getMass() const noexcept {
    return mass;
}

std::string Object::getName() const noexcept {
    return name;
}

vector2 Object::getPosition() const noexcept {
    return position;
}

vector2 Object::getVelocity() const noexcept {
    return velocity;
}

vector2 Object::getForce(const Object& rhs) const noexcept {
    vector2 temp = (rhs.position - position);
    double distanceSq = temp.normSq();
    double magnitude = (Universe::G * mass * rhs.getMass())/distanceSq;
    vector2 unitVec = temp.normalize();
    return (unitVec * magnitude);
}

void Object::setPosition(const vector2& pos) {
    position = pos;
}

void Object::setVelocity(const vector2& vel) {
    velocity = vel;
}

bool Object::operator==(const Object& rhs) const {
    return (name == rhs.name && mass == rhs.mass && position == rhs.position && velocity == rhs.velocity);
}

bool Object::operator!=(const Object& rhs) const {
    return !(*this == rhs);
}

Object::Object(const std::string& name, double mass, const vector2& pos, const vector2& vel) {
    this->name = name;
    this->mass = mass;
    position = pos;
    velocity = vel;
}

