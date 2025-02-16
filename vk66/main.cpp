#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

class Student {
private:
    std::string name;
    int age;

public:
    Student(std::string name, int age);

    std::string getName() const;
    int getAge() const;

    void setName(std::string name);
    void setAge(int age);

    void printStudentInfo() const;
};

Student::Student(std::string name, int age) : name(name), age(age) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

void Student::setName(std::string name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::printStudentInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}

int main() {
    int selection = 0;
    std::vector<Student> studentList;

    do {
        std::cout << "Select:" << std::endl;
        std::cout << "Add student = 0" << std::endl;
        std::cout << "Print all students = 1" << std::endl;
        std::cout << "Sort and print students according to Name = 2" << std::endl;
        std::cout << "Sort and print students according to Age = 3" << std::endl;
        std::cout << "Find and print student = 4" << std::endl;
        std::cin >> selection;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selection = -1;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (selection) {
        case 0: {
            std::string name;
            int age;

            std::cout << "Enter student name: ";
            std::getline(std::cin, name);

            std::cout << "Enter student age: ";
            std::cin >> age;

            while (std::cin.fail()) {
                std::cout << "Invalid age. Please enter a number: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> age;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            studentList.emplace_back(name, age);
            std::cout << "Student added." << std::endl;
            break;
        }
        case 1: {
            if (studentList.empty()) {
                std::cout << "No students in the list." << std::endl;
            } else {
                for (const auto &student : studentList) {
                    student.printStudentInfo();
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 2: {
            std::sort(studentList.begin(), studentList.end(),
                      [](const Student &a, const Student &b) {
                          return a.getName() < b.getName();
                      });

            std::cout << "Sorted by name:" << std::endl;
            for (const auto &student : studentList) {
                student.printStudentInfo();
                std::cout << std::endl;
            }
            break;
        }
        case 3: {
            std::sort(studentList.begin(), studentList.end(),
                      [](const Student &a, const Student &b) {
                          return a.getAge() < b.getAge();
                      });

            std::cout << "Sorted by age:" << std::endl;
            for (const auto &student : studentList) {
                student.printStudentInfo();
                std::cout << std::endl;
            }
            break;
        }
        case 4: {
            std::string searchName;
            std::cout << "Enter name to search for: ";
            std::getline(std::cin, searchName);

            bool found = false;
            for (const auto &student : studentList) {
                if (student.getName() == searchName) {
                    student.printStudentInfo();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Student not found." << std::endl;
            }
            break;
        }
        default:
            std::cout << "Wrong selection, stopping..." << std::endl;
            break;
        }
    } while (selection < 5);

    return 0;
}
