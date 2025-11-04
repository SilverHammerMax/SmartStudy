#pragma once

#include <string>
#include <array>

#ifndef SMARTSTUDY_STUDENT_H
#define SMARTSTUDY_STUDENT_H


class Student
{
private:
    int id;
    std::string name;
    std::string major;
    std::array<bool, 11> availability;
public:
    Student(int id, std::string name, std::string major, std::array<bool, 11> availablility);
    int getId();
    std::string getName();
    std::string getMajor();
    bool getAvailability(int period);
    int getCompatibilityScore(Student& otherStudent);
};


#endif //SMARTSTUDY_STUDENT_H