#include "DataGeneration.h"
#include <array>

std::vector<Student> createData(int population) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<Student> data;
    data.reserve(population);

    for (int i = 0; i < population; i++) {
        std::uniform_int_distribution<int> major(0, 15);
        std::uniform_int_distribution<int> bool_type(0, 1);
        std::array<bool,11> avail;
        for (int j = 0; j < 11; j++) {
            avail[j] = bool_type(gen);
        }
        Student new_student(genId(i), genName(i),pickMajor(major(gen)),avail);
        data.push_back(new_student);
    }

    return data;
}

std::vector<Student> createData(int population, int seed) {
    std::mt19937 gen(seed);

    std::vector<Student> data;
    data.reserve(population);

    for (int i = 0; i < population; i++) {
        std::uniform_int_distribution<int> major(0, 15);
        std::uniform_int_distribution<int> bool_type(0, 1);
        std::array<bool,11> avail;
        for (int j = 0; j < 11; j++) {
            avail[j] = bool_type(gen);
        }
        Student new_student(genId(i), genName(i),pickMajor(major(gen)),avail);
        data.push_back(new_student);
    }

    return data;
}

std::string genName(int index) {
    if (index >= SIZE_NAMES * SIZE_NAMES) {
        index = index % (SIZE_NAMES * SIZE_NAMES);
    }
    int f = index % SIZE_NAMES;
    int l = (index / SIZE_NAMES + f) % SIZE_NAMES;
    return (f_names[f] + " " + l_names[l]);
}

std::string genId(int index) {
    std::string base = "00000000";
    std::string Id = std::to_string(index);
    base.replace((8 - Id.length() % 8),7, Id);
    return base;
}

std::string pickMajor(int index) {
    return majors[index];
}