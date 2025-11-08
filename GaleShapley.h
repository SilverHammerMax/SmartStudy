#pragma once

#ifndef GALESHAPLEY_H
#define GALESHAPLEY_H

#include "Student.h"
#include <vector>
#include <nlohmann/json.hpp>
using namespace std;

struct Match {
    int studentAId;
    int studentBId;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Match, studentAId, studentBId);

vector<Match> galeShapleyAlgorithm(vector<Student> groupA, vector<Student> groupB);

#endif //GALESHAPLEY_H
