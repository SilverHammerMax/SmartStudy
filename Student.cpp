#include "Student.h"

Student::Student(int id, std::string name, std::string major, std::array<bool, 11> availablity)
{
    this->id = id;
    this->name = name;
    this->major = major;
    this->availability = availablity;
}

int Student::getId()
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

int Student::getCompatibilityScore(Student &otherStudent) {
    int score = 0;
    if (this->major == otherStudent.getMajor()) {
        score += 3;
    }
    for (int i = 0; i < 11; i++) {
        if (this->availability[i] == otherStudent.getAvailability(i)) {
            score += 1;
        }
    }
    return score;
}
