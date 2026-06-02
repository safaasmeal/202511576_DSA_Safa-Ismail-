#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class Student {
private:
    std::string rollNumber;
    std::string name;
    int age;

public:
    // Constructors
    Student() : rollNumber(""), name(""), age(0) {}
    Student(std::string roll, std::string n, int a) : rollNumber(roll), name(n), age(a) {}

    // Getters
    std::string getRollNumber() const { return rollNumber; }
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Setters
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }

    // Helper to convert object data to a CSV line
    std::string toCSV() const {
        return rollNumber + "," + name + "," + <<std::to_string(age);
    }

    // Display student details in a clean format
    void display() const {
        std::cout << "Roll Number: " << rollNumber << "\n"
                  << "Name:        " << name << "\n"
                  << "Age:         " << age << "\n"
                  << "-----------------------\n";
    }
};

// Helper function to read all student records from the CSV file into a vector
std::vector<Student> readAllFromFile() {
    std::vector<Student> students;
    std::ifstream file("student.txt");
    
    if (!file.is_open()) {
        return students; // Returns empty vector if file doesn't exist yet
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string roll, name, ageStr;
        
        // Parse CSV fields
        if (std::getline(ss, roll, ',') && 
            std::getline(ss, name, ',') && 
            std::getline(ss, ageStr, ',')) {
            
            int age = std::stoi(ageStr);
            students.push_back(Student(roll, name, age));
        }
    }
    file.close();
    return students;
}

// Helper function to write the entire vector back to the file permanently
void writeAllToFile(const std::vector<Student>& students) {
    std::ofstream file("student.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file for writing.\n";
        return;
    }
    for (const auto& student : students) {
        file << student.toCSV() << "\n";
    }
    file.close();
}

// 1. Function to add a new student object and save to file
void addStudent() {
    std::string roll, name;
    int age;

    std::cout << "\n--- Add New Student ---\n";
    std::cout << "Enter Roll Number: ";
    std::cin >> roll;
    std::cin.ignore(); // Clear newline character from buffer
    std::cout << "Enter Name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Age: ";
    std::cin >> age;

    // Read current data, append new student, and save
    std::vector<Student> students = readAllFromFile();
    
    // Check if roll number already exists to prevent duplicates
    for (const auto& s : students) {
        if (s.getRollNumber() == roll) {
            std::cout << "Error: A student with this Roll Number already exists!\n";
            return;
        }
    }

    students.push_back(Student(roll, name, age));
    writeAllToFile(students);
    std::cout << "Student record saved successfully!\n";
}

// 2. Requirement: Function to display all students stored in the file
void displayAllStudents() {
    std::vector<Student> students = readAllFromFile();
    
    std::cout << "\n--- All Student Records ---\n";
    if (students.empty()) {
        std::cout << "No records found in student.txt.\n";
        return;
    }

    for (const auto& student : students) {
        student.display();
    }
}

// 3. Requirement: Search for a student by Roll Number
void searchStudent() {
    std::string roll;
    std::cout << "\nEnter Roll Number to search: ";
    std::cin >> roll;

    std::vector<Student> students = readAllFromFile();
    for (const auto& student : students) {
        if (student.getRollNumber() == roll) {
            std::cout << "\nStudent Found:\n";
            student.display();
            return;
        }
    }
    
