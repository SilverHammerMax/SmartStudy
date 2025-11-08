#include <iostream>
#include <vector>
#include <fstream>

#include "DataGeneration.h"
#include "GaleShapley.h"
#include "Greedy.h"
#include "Student.h"

int main() {
    std::vector<Student> students;
    std::cout << "Welcome to the Smart Study Program!" << std::endl;
    bool goodbye = false;
    while (!goodbye) {
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Generate Students" << std::endl;
        std::cout << "3. Import Data" << std::endl;
        std::cout << "4. Export Data" << std::endl;
        std::cout << "5. Create Pairs" << std::endl;
        std::cout << "6. Quit" << std::endl;
        int choice = 0;
        std::string choiceStr;
        std::getline(std::cin, choiceStr);
        try {
            choice = std::stoi(choiceStr);
        } catch (std::invalid_argument &_) {
            std::cout << "Please enter a number!" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                {
                    std::cout << "Student's Name: ";
                    std::string name;
                    std::getline(std::cin, name);

                    std::cout << "Student's ID: ";
                    std::string idString;
                    std::getline(std::cin, idString);
                    int id = stoi(idString);

                    std::cout << "Student's Major: ";
                    std::string major;
                    std::getline(std::cin, major);

                    std::cout << "Student's Availability (Give a space-separated list of all available periods): ";
                    std::array<bool, 11> availability;
                    availability.fill(false);
                    std::string input;
                    std::getline(std::cin, input);
                    std::string current = "";
                    for (char c : input)
                    {
                        if (c == ' ')
                        {
                            availability[stoi(current)] = true;
                            current = "";
                        } else
                            current += c;
                    }
                    availability[stoi(current)] = true;
                    Student newStudent(name, id, major, availability);
                    students.push_back(newStudent);
                }
                break;
            case 2:
                {
                    std::cout << "How many student's would you like to generate? ";
                    std::string input;
                    std::getline(std::cin, input);
                    int numberOfStudents = stoi(input);
                    students = createData(numberOfStudents);
                }
                break;
            case 3:
                {
                    std::ifstream inputFile("students.json");
                    nlohmann::json inputJson;
                    inputFile >> inputJson;
                    students = inputJson.get<std::vector<Student>>();
                }
                break;
            case 4:
                {
                    std::ofstream outputFile("students.json");
                    nlohmann::json outputJson = students;
                    outputFile << std::setw(4) << outputJson << std::endl;
                    std::cout << "Student Data Exported!" << std::endl;
                }
                break;
            case 5:
                {
                    auto midpoint = students.begin() + students.size() / 2;
                    std::vector<Student> groupOne(students.size()/2);
                    std::vector<Student> groupTwo(students.size()/2);
                    copy(students.begin(), midpoint, groupOne.begin());
                    copy(midpoint, students.end(), groupTwo.begin());
                    std::vector<Match> greedyPairs = greedyAlgorithm(groupOne, groupTwo);
                    std::vector<Match> galeShapelyPairs = galeShapleyAlgorithm(groupOne, groupTwo);
                    std::ofstream greedyOutput("greedyPairs.json");
                    std::ofstream galeShapelyOutput("galeShapelyPairs.json");
                    nlohmann::json greedyJson = greedyPairs;
                    nlohmann::json galeShapelyJson = galeShapelyPairs;
                    greedyOutput << std::setw(4) << greedyJson << std::endl;
                    galeShapelyOutput << std::setw(4) << galeShapelyJson << std::endl;
                    std::cout << "Student Pairs Exported!" << std::endl;
                }
                break;
            case 6:
                goodbye = true;
                std::cout << "Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Please make a valid selection!" << std::endl;
        }
    }
    return 0;
}