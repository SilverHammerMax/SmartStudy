#include "Greedy.h"

vector<Match> greedyAlgorithm(vector<Student> groupA, vector<Student> groupB) {
    vector<Match> matches;
    bool matched[groupB.size()] = {false}; //array to check who in groupB has already matched
    const int MAX_SCORE = 13;

    //iterating through each student in group A
    for (int a = 0; a < groupA.size(); a++) {
        std::pair<int, int> bestMatch = {0,0};

        //iterating through each student in group B to find the highest compatability score
        for (int b = 0; b < groupB.size(); b++) {
            //small optimization of skipping already matched students, negligible on O(n)
            if (matched[b]) {
                continue;
            }
            int score = groupA[a].getCompatibilityScore(groupB[b]);
            if (score > bestMatch.second) {
                bestMatch = {b,score};
            }
            //small optimization of breaking out when score is max, won't affect worst case O(n)
            if (score == MAX_SCORE) {
                break;
            }
        }
        matches.push_back({a, bestMatch.first});
        matched[bestMatch.first] = true;
    }
    return matches;
}