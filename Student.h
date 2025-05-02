#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    std::vector<float> grades;
    float average;

public:
    // Constructor
    Student(std::string name, int id);
    
    // Getters
    std::string getName() const;
    int getId() const;
    float getAverage() const;
    std::vector<float> getGrades() const;
    
    // Methods
    void addGrade(float grade);
    void calculateAverage();
    void displayInfo() const;
};

#endif 