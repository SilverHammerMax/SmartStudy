#include "Student.h"

Student::Student(std::string name, std::string id, std::string major, std::array<bool, 11> availablity)
{
    this->id = id;
    this->name = name;
    this->major = major;
    this->availability = availablity;
}

std::string Student::getId()
{
    return this->id;
}

std::string Student::getName()
{
    return this->name;
}

std::string Student::getMajor()
{
    return this->major;
}

bool Student::getAvailability(int period)
{
    return this->availability[period];
}