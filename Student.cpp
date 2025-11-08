#include "Student.h"

Student::Student(std::string name, int id, std::string major, std::array<bool, 11> availablity)
{
    this->id = id;
    this->name = name;
    this->major = major;
    this->availability = availablity;
}

int Student::getId() const
{
    return this->id;
}

std::string Student::getName() const
{
    return this->name;
}

std::string Student::getMajor() const
{
    return this->major;
}

bool Student::getAvailability(int period) const
{
    return this->availability[period];
}

int Student::getCompatibilityScore(Student &otherStudent) {
    int score = 0;
    for (int i = 0; i < 11; i++) {
        if (this->availability[i] == 1 && otherStudent.getAvailability(i) == 1) {
            score += 1;
        }
    }
    if (score != 0 && this->major == otherStudent.getMajor()) {
        score += 5;
    }
    return score;
}