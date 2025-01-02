#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <random>
#include <iostream>
#include <stdexcept>

void FileManager::generateRandomStudentList(int numStudents, const std::string &filename)
{
    std::ofstream outFile(filename);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1.0, 10.0);

    outFile << "Name Surname HW1 HW2 HW3 HW4 HW5 HW6 HW7 Exam\n";

    for (int i = 0; i < numStudents; ++i)
    {
        outFile << "Name" << i + 1 << " Surname" << (i % 2 + 1); // Name pattern
        for (int j = 0; j < 7; ++j)
        {
            outFile << " " << dis(gen); // Random homework scores
        }
        outFile << " " << dis(gen) << "\n"; // Random exam score
    }
}

void FileManager::readStudentDataFromFile(const std::string &filename, std::vector<Student> &students)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    std::getline(inFile, line); // Skip header

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string firstName, surname;
        double score;
        std::vector<double> homeworkScores;

        iss >> firstName >> surname;
        for (int i = 0; i < 7; ++i)
        {
            iss >> score;
            homeworkScores.push_back(score);
        }
        iss >> score; // Exam score

        // Remove debugging print statements
        // std::cout << "First Name: " << firstName << ", Surname: " << surname << "\n";
        // std::cout << "Scores: ";
        // for (const auto &hwScore : homeworkScores)
        // {
        //     std::cout << hwScore << " ";
        // }
        // std::cout << "Exam: " << score << std::endl;

        Student student(firstName, surname);
        student.setScores(homeworkScores, score);
        students.push_back(student);
    }
}

void FileManager::readStudentDataFromFile(const std::string &filename, std::list<Student> &students)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    std::getline(inFile, line); // Skip header

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string firstName, surname;
        double score;
        std::vector<double> homeworkScores;

        iss >> firstName >> surname;
        for (int i = 0; i < 7; ++i)
        {
            iss >> score;
            homeworkScores.push_back(score);
        }
        iss >> score; // Exam score

        Student student(firstName, surname);
        student.setScores(homeworkScores, score);
        students.push_back(student);
    }
}

void FileManager::readStudentDataFromFile(const std::string &filename, std::deque<Student> &students)
{
    std::ifstream inFile(filename);
    if (!inFile)
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    std::getline(inFile, line); // Skip header

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string firstName, surname;
        double score;
        std::vector<double> homeworkScores;

        iss >> firstName >> surname;
        for (int i = 0; i < 7; ++i)
        {
            iss >> score;
            homeworkScores.push_back(score);
        }
        iss >> score; // Exam score

        Student student(firstName, surname);
        student.setScores(homeworkScores, score);
        students.push_back(student);
    }
}

void FileManager::writeStudentDataToFile(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream outFile(filename);
    outFile << "Name Surname FinalGrade\n";
    for (const auto &student : students)
    {
        outFile << student << "\n"; // Ensure the output stream is correctly formatted
    }
}

void FileManager::writeStudentDataToFile(const std::list<Student> &students, const std::string &filename)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    outFile << "FirstName    LastName       FinalGrade\n";
    for (const auto &student : students)
    {
        outFile << student << "\n";
    }
}

void FileManager::writeStudentDataToFile(const std::deque<Student> &students, const std::string &filename)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    outFile << "FirstName    LastName       FinalGrade\n";
    for (const auto &student : students)
    {
        outFile << student << "\n";
    }
}

void FileManager::splitStudentsByGrade(const std::vector<Student> &students, const std::string &passedFile, const std::string &failedFile)
{
    std::vector<Student> passed, failed;
    for (const auto &student : students)
    {
        if (student.getFinalGrade() >= 5.0)
        {
            passed.push_back(student);
        }
        else
        {
            failed.push_back(student);
        }
    }
    writeStudentDataToFile(passed, passedFile);
    writeStudentDataToFile(failed, failedFile);
}

void FileManager::splitStudentsByGrade(const std::list<Student> &students, const std::string &passedFile, const std::string &failedFile)
{
    std::list<Student> passedStudents, failedStudents;

    for (const auto &student : students)
    {
        if (student.getFinalGrade() >= 5.0)
        {
            passedStudents.push_back(student);
        }
        else
        {
            failedStudents.push_back(student);
        }
    }

    writeStudentDataToFile(passedStudents, passedFile);
    writeStudentDataToFile(failedStudents, failedFile);
}

void FileManager::splitStudentsByGrade(const std::deque<Student> &students, const std::string &passedFile, const std::string &failedFile)
{
    std::deque<Student> passedStudents, failedStudents;

    for (const auto &student : students)
    {
        if (student.getFinalGrade() >= 5.0)
        {
            passedStudents.push_back(student);
        }
        else
        {
            failedStudents.push_back(student);
        }
    }

    writeStudentDataToFile(passedStudents, passedFile);
    writeStudentDataToFile(failedStudents, failedFile);
}
