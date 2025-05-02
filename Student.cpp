#include "Student.h"
#include <iostream>
#include <numeric>

Student::Student(std::string name, int id) : name(name), id(id), average(0.0f) {}

std::string Student::getName() const {
    return name;
}

int Student::getId() const {
    return id;
}

float Student::getAverage() const {
    return average;
}

std::vector<float> Student::getGrades() const {
    return grades;
}

void Student::addGrade(float grade) {
    if (grade >= 0 && grade <= 100) {
        grades.push_back(grade);
        calculateAverage();
    } else {
        std::cout << "Invalid grade! Grade must be between 0 and 100." << std::endl;
    }
}

void Student::calculateAverage() {
    if (grades.empty()) {
        average = 0.0f;
        return;
    }
    float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
    average = sum / grades.size();
}

void Student::displayInfo() const {
    std::cout << "\nStudent Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Grades: ";
    for (float grade : grades) {
        std::cout << grade << " ";
    }
    std::cout << "\nAverage: " << average << std::endl;
} 