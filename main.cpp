#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "FileManager.h"
#include "Sorting.h"
#include "Timer.h"

int main()
{
    int choice;
    bool exitProgram = false;

    while (!exitProgram)
    {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Generate a random student list\n";
        std::cout << "2. Sort students\n";
        std::cout << "3. Calculate final grade (Average/Median)\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                int numStudents;
                std::string filename;
                std::cout << "How many students to generate? ";
                std::cin >> numStudents;
                std::cout << "Enter the filename to save: ";
                std::cin >> filename;
                FileManager::generateRandomStudentList(numStudents, filename);
                break;
            }
            case 2:
            {
                std::string filename;
                std::cout << "Enter the filename to read from: ";
                std::cin >> filename;

                int containerChoice;
                std::cout << "Select container:\n1. List\n2. Deque\n3. Vector\nEnter your choice: ";
                std::cin >> containerChoice;

                Timer timer;
                double readTime = 0.0, sortTime = 0.0, splitTime = 0.0, writeTime = 0.0;

                if (containerChoice == 1) // List
                {
                    std::list<Student> students;

                    // Reading data
                    timer.startTimer();
                    FileManager::readStudentDataFromFile(filename, students);
                    readTime = timer.stopTimer();
                    std::cout << "Data reading took " << readTime << " seconds.\n";

                    // Calculating final grade
                    char gradeChoice;
                    std::cout << "Calculate final grade using (A)verage or (M)edian? ";
                    std::cin >> gradeChoice;
                    bool useAverage = (gradeChoice == 'A' || gradeChoice == 'a');
                    for (auto &student : students)
                    {
                        student.calculateFinalGrade(useAverage);
                    }

                    // Sorting data
                    timer.startTimer();
                    Sorting::sortStudents(students);
                    sortTime = timer.stopTimer();
                    std::cout << "Data sorting took " << sortTime << " seconds.\n";

                    // Splitting data
                    timer.startTimer();
                    FileManager::splitStudentsByGrade(students, "passed_list.txt", "failed_list.txt");
                    splitTime = timer.stopTimer();
                    std::cout << "Data splitting took " << splitTime << " seconds.\n";

                    // Writing data
                    timer.startTimer();
                    FileManager::writeStudentDataToFile(students, "sorted_students_list.txt");
                    writeTime = timer.stopTimer();
                    std::cout << "Writing data took " << writeTime << " seconds.\n";
                }
                else if (containerChoice == 2) // Deque
                {
                    std::deque<Student> students;

                    // Reading data
                    timer.startTimer();
                    FileManager::readStudentDataFromFile(filename, students);
                    readTime = timer.stopTimer();
                    std::cout << "Data reading took " << readTime << " seconds.\n";

                    // Calculating final grade
                    char gradeChoice;
                    std::cout << "Calculate final grade using (A)verage or (M)edian? ";
                    std::cin >> gradeChoice;
                    bool useAverage = (gradeChoice == 'A' || gradeChoice == 'a');
                    for (auto &student : students)
                    {
                        student.calculateFinalGrade(useAverage);
                    }

                    // Sorting data
                    timer.startTimer();
                    Sorting::sortStudents(students);
                    sortTime = timer.stopTimer();
                    std::cout << "Data sorting took " << sortTime << " seconds.\n";

                    // Splitting data
                    timer.startTimer();
                    FileManager::splitStudentsByGrade(students, "passed_deque.txt", "failed_deque.txt");
                    splitTime = timer.stopTimer();
                    std::cout << "Data splitting took " << splitTime << " seconds.\n";

                    // Writing data
                    timer.startTimer();
                    FileManager::writeStudentDataToFile(students, "sorted_students_deque.txt");
                    writeTime = timer.stopTimer();
                    std::cout << "Writing data took " << writeTime << " seconds.\n";
                }
                else // Vector
                {
                    std::vector<Student> students;

                    // Reading data
                    timer.startTimer();
                    FileManager::readStudentDataFromFile(filename, students);
                    readTime = timer.stopTimer();
                    std::cout << "Data reading took " << readTime << " seconds.\n";

                    // Calculating final grade
                    char gradeChoice;
                    std::cout << "Calculate final grade using (A)verage or (M)edian? ";
                    std::cin >> gradeChoice;
                    bool useAverage = (gradeChoice == 'A' || gradeChoice == 'a');
                    for (auto &student : students)
                    {
                        student.calculateFinalGrade(useAverage);
                    }

                    // Sorting data
                    timer.startTimer();
                    Sorting::sortStudents(students);
                    sortTime = timer.stopTimer();
                    std::cout << "Data sorting took " << sortTime << " seconds.\n";

                    // Splitting data
                    timer.startTimer();
                    FileManager::splitStudentsByGrade(students, "passed_vector.txt", "failed_vector.txt");
                    splitTime = timer.stopTimer();
                    std::cout << "Data splitting took " << splitTime << " seconds.\n";

                    // Writing data
                    timer.startTimer();
                    FileManager::writeStudentDataToFile(students, "sorted_students_vector.txt");
                    writeTime = timer.stopTimer();
                    std::cout << "Writing data took " << writeTime << " seconds.\n";
                }

                double totalTime = readTime + sortTime + splitTime + writeTime;
                std::cout << "\nTotal time for all operations: " << totalTime << " seconds.\n";
                break;
            }

            case 3:
            {
                std::string filename;
                std::cout << "Enter the filename to read from: ";
                std::cin >> filename;
                std::vector<Student> students;
                FileManager::readStudentDataFromFile(filename, students);

                char choice;
                std::cout << "Calculate final grade using (A)verage or (M)edian? ";
                std::cin >> choice;
                bool useAverage = (choice == 'A' || choice == 'a');

                // Remove the debugging message for entering final grade calculation
                // std::cout << "Entering final grade calculation...\n";

                // Loop through students and calculate final grade
                for (auto &student : students)
                {
                    student.calculateFinalGrade(useAverage); // No debug output inside the calculation loop
                }

                // Ask for the file name to save results
                std::string outputFilename;
                std::cout << "Enter the filename to save the final grades: ";
                std::cin >> outputFilename;

                // Save the results to the specified file
                FileManager::writeStudentDataToFile(students, outputFilename);
                std::cout << "Final grades saved to " << outputFilename << std::endl;
                break;
            }

            case 4:
                exitProgram = true;
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please select a valid option.\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
