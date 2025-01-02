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
                std::vector<Student> students;

                Timer timer; // Start the timer for the entire operation
                timer.startTimer();

                // Measure time for reading data
                std::cout << "Reading data from file...\n";
                FileManager::readStudentDataFromFile(filename, students);
                double readTime = timer.stopTimer(); // Stop and get elapsed time
                std::cout << "Reading data took " << readTime << " seconds.\n";

                // Calculate final grade for each student
                char choice;
                std::cout << "Calculate final grade using (A)verage or (M)edian? ";
                std::cin >> choice;
                bool useAverage = (choice == 'A' || choice == 'a');

                for (auto &student : students)
                {
                    student.calculateFinalGrade(useAverage);
                }

                timer.startTimer(); // Restart timer for sorting phase
                std::cout << "Sorting students...\n";
                Sorting::sortStudents(students);
                double sortTime = timer.stopTimer(); // Stop and get elapsed time
                std::cout << "Sorting took " << sortTime << " seconds.\n";

                timer.startTimer(); // Restart timer for splitting phase
                std::cout << "Splitting students into passed and failed...\n";
                FileManager::splitStudentsByGrade(students, "passed.txt", "failed.txt");
                double splitTime = timer.stopTimer(); // Stop and get elapsed time
                std::cout << "Splitting students took " << splitTime << " seconds.\n";

                timer.startTimer(); // Restart timer for writing output
                std::cout << "Writing sorted students to files...\n";
                FileManager::writeStudentDataToFile(students, "sorted_students.txt");
                double writeTime = timer.stopTimer(); // Stop and get elapsed time
                std::cout << "Writing to file took " << writeTime << " seconds.\n";

                // Total time
                double totalTime = readTime + sortTime + splitTime + writeTime;
                std::cout << "\nTotal time for sorting and processing: " << totalTime << " seconds.\n";
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
