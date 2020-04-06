// Name: Joseph Chang
// VUNetID: changj6
// Email Address: joseph.chang@vanderbilt.edu
// Class: CS 3251
// Date: 4/4/2020
// Honor Statement: I have not given or received unauthorized aid on this assignment
// Assignment Number: Assignment #6

#include "Universe.h"
#include "Object.h"

// initialize the singleton
Universe* Universe::inst = nullptr;

Universe* Universe::instance() {
    if (inst == nullptr) inst = new Universe();
    return inst;
}

Universe::~Universe() {
    release(objects);
    inst = nullptr;
}

Universe::iterator Universe::begin() {
    return objects.begin();
}

Universe::const_iterator Universe::begin() const {
    return objects.begin();
}

Universe::iterator Universe::end() {
    return objects.end();
}

Universe::const_iterator Universe::end() const {
    return objects.end();
}

std::vector<Object*> Universe::getSnapshot() const {
    std::vector<Object*> temp;
    for (uint32_t i = 0; i < objects.size(); ++i) {
        temp.emplace_back(objects[i]);
    }
    return temp;
}

void Universe::stepSimulation(const double& timeSex) {
    std::vector<Object*> temp = getSnapshot();
    for (uint32_t i = 1; i < temp.size(); ++i) {
        vector2 totalForce;
        Object* tempPoint = temp[i];
        for (uint32_t j = 0; i < temp.size(); ++i) {
            totalForce += (tempPoint)->getForce(*temp[j]);
        }
        vector2 accel = totalForce/(tempPoint)->getMass();
        vector2 vel = (tempPoint)->getVelocity();
        vector2 newVel = vel + (accel * timeSex);
        (tempPoint)->setVelocity(newVel);
        vector2 pos = (tempPoint)->getPosition();
        pos += (vel * timeSex);
        (tempPoint)->setPosition(pos);
    }
    objects.swap(temp);
}

void Universe::swap(std::vector<Object*>& snapshot) {
    std::vector<Object*> temp = snapshot;
    std::copy(objects.begin(), objects.end(), temp.begin());
    objects.swap(temp);
}

Object* Universe::addObject(Object* ptr) {
    objects.emplace_back(ptr);
    return ptr;
}

void Universe::release(std::vector<Object*>& objects) {
    for (uint32_t i = 0; i < objects.size(); ++i) {
        delete objects[i];
        objects[i] = nullptr;
    }
    objects.clear();
}




