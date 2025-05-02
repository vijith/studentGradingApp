#include "Student.h"
#include <iostream>
#include <vector>
#include <limits>

void displayMenu() {
    std::cout << "\n=== Student Grade Management System ===" << std::endl;
    std::cout << "1. Add new student" << std::endl;
    std::cout << "2. Add grade to student" << std::endl;
    std::cout << "3. Display student information" << std::endl;
    std::cout << "4. Display all students" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<Student> students;
    int choice;
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        
        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: {
                std::string name;
                int id;
                
                std::cout << "Enter student name: ";
                std::getline(std::cin, name);
                
                std::cout << "Enter student ID: ";
                std::cin >> id;
                
                students.emplace_back(name, id);
                std::cout << "Student added successfully!" << std::endl;
                break;
            }
            case 2: {
                if (students.empty()) {
                    std::cout << "No students in the system!" << std::endl;
                    break;
                }
                
                int id;
                float grade;
                
                std::cout << "Enter student ID: ";
                std::cin >> id;
                
                bool found = false;
                for (auto& student : students) {
                    if (student.getId() == id) {
                        std::cout << "Enter grade (0-100): ";
                        std::cin >> grade;
                        student.addGrade(grade);
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    std::cout << "Student not found!" << std::endl;
                }
                break;
            }
            case 3: {
                if (students.empty()) {
                    std::cout << "No students in the system!" << std::endl;
                    break;
                }
                
                int id;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                
                bool found = false;
                for (const auto& student : students) {
                    if (student.getId() == id) {
                        student.displayInfo();
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    std::cout << "Student not found!" << std::endl;
                }
                break;
            }
            case 4: {
                if (students.empty()) {
                    std::cout << "No students in the system!" << std::endl;
                    break;
                }
                
                std::cout << "\nAll Students:" << std::endl;
                for (const auto& student : students) {
                    student.displayInfo();
                }
                break;
            }
            case 5:
                std::cout << "Thank you for using the Student Grade Management System!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
} 