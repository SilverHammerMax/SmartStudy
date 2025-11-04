#include "GaleShapley.h"

#include <algorithm>
#include <queue>
#include <map>
using namespace std;

vector<Match> galeShapleyAlgorithm(vector<Student> groupA, vector<Student> groupB) {
    map<int, int> currentMatches;
    vector<int> nextBIndex(groupA.size(), 0);
    queue<int> freeA;

    vector<vector<int>> preferences(groupA.size());
    for (int i = 0; i < groupA.size(); i++) {
        vector<pair<int, int>> compatibilityScores;
        for (int j = 0; j < groupB.size(); j++) {
            compatibilityScores.push_back({groupA[i].getCompatibilityScore(groupB[j]), j});
        }
        sort(compatibilityScores.rbegin(), compatibilityScores.rend());
        for (auto& pair : compatibilityScores) {
            preferences[i].push_back(pair.second);
        }
        freeA.push(i);
    }

    while (!freeA.empty()) {
        int currentAIndex = freeA.front();
        freeA.pop();
        if (nextBIndex[currentAIndex] >= groupB.size()) {
            continue;
        }
        Student& studentA = groupA[currentAIndex];
        int bestBIndex = preferences[currentAIndex][nextBIndex[currentAIndex]];
        nextBIndex[currentAIndex]++;
        Student& studentB = groupB[bestBIndex];
        int studentBId = studentB.getId();

        if (currentMatches.find(studentBId) == currentMatches.end()) {
            currentMatches[studentBId] = studentA.getId();
        }
        else {
            int currentAMatch = currentMatches[studentBId];
            Student* currentAStudent = nullptr;
            for (auto& matchCandidate : groupA) {
                if (matchCandidate.getId() == currentAMatch) {
                    currentAStudent = &matchCandidate;
                    break;
                }
            }
            int currentCompatibilityScore = studentB.getCompatibilityScore(*currentAStudent);
            int newCompatibilityScore = studentB.getCompatibilityScore(studentA);

            if (newCompatibilityScore > currentCompatibilityScore) {
                int oldMatch = currentMatches[studentBId];
                currentMatches[studentBId] = studentA.getId();
                freeA.push(oldMatch);
            }
            else {
                if (newCompatibilityScore < currentCompatibilityScore) {
                    freeA.push(currentAIndex);
                }
            }
        }
    }

    vector<Match> finalPairMatches;
    for (auto pair : currentMatches) {
        finalPairMatches.push_back({pair.second, pair.first});
    }
    return finalPairMatches;
}



