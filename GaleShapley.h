#pragma once

#ifndef GALESHAPLEY_H
#define GALESHAPLEY_H

#include "Student.h"
#include <vector>
using namespace std;

struct Match {
    int studentAId;
    int studentBId;
};

vector<Match> galeShapleyAlgorithm(vector<Student> groupA, vector<Student> groupB);

#endif //GALESHAPLEY_H
