#include "notepad.h"
#include <iostream>
#include <fstream>
#include <string>

// 1. Function to create a new file and write text to it
void createFile() {
    std::string filename;
    std::string content;

    std::cout << "\nEnter the filename to create (e.g., notes.txt): ";
    std::cin >> filename;
    std::cin.ignore(); // Clear the input buffer newline character

    // Open file in write mode (creates a new file or overwrites existing content)
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cout << "Error: Could not create the file.\n";
        return;
    }

    std::cout << "Enter the text you want to write (Press Enter to finish):\n";
    std::getline(std::cin, content);

    outFile << content;
    outFile.close(); // Close the file to save changes
    std::cout << "File '" << filename << "' created and saved successfully!\n";
}

// 2. Function to read and display the content of an existing file
void readFile() {
    std::string filename;
    std::string line;

    std::cout << "\nEnter the filename to read (e.g., notes.txt): ";
    std::cin >> filename;

    // Open file in read mode
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cout << "Error: Could not open the file. Make sure it exists.\n";
        return;
    }

    std::cout << "\n--- File Content for '" << filename << "' ---\n";
    // Read line by line until the end of the file
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "---------------------------------------\n";

    inFile.close(); // Close the file
}

// 3. Function to append new text to an existing file
void appendToFile() {
    std::string filename;
    std::string content;

    std::cout << "\nEnter the filename to append to (e.g., notes.txt): ";
    std::cin >> filename;
    std::cin.ignore(); // Clear the input buffer

    // Open file in append mode (std::ios::app ensures existing content isn't deleted)
    std::ofstream outFile(filename, std::ios::app);

    if (!outFile) {
        std::cout << "Error: Could not open the file.\n";
        return;
    }

    std::cout << "Enter the text you want to append:\n";
    std::getline(std::cin, content);

    // Write a newline before the appended text for clean structure
    outFile << "\n" << content;
    outFile.close(); // Close the file
    std::cout << "Text appended successfully to '" << filename << "'.\n";
}
