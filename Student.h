#pragma once

#include <string>
#include <array>
#include <nlohmann/json.hpp>

#ifndef SMARTSTUDY_STUDENT_H
#define SMARTSTUDY_STUDENT_H


class Student
{
private:
    std::string id;
    std::string name;
    std::string major;
    std::array<bool, 11> availability;
public:
    Student(std::string id, std::string name, std::string major, std::array<bool, 11> availablility);
    std::string getId() const;
    std::string getName() const;
    std::string getMajor() const;
    bool getAvailability(int period) const;
    int getCompatibilityScore(Student& otherStudent);
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Student, name, id, major, availability);
};


#endif //SMARTSTUDY_STUDENT_H