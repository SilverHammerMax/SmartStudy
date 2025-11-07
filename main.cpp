#include <iostream>
#include <vector>
#include <fstream>

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
                    std::string id;
                    std::getline(std::cin, id);

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
                // TODO
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
                // TODO
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