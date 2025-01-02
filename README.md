# Student Grade Calculation System:
## Project Overview
This project is a simple console-based C++ application designed to calculate student final grades based on homework and exam scores. The program offers flexibility in calculating final grades by allowing the user to choose between using the average or median of homework scores, combined with the exam score.

The project is version-controlled with Git, hosted on GitHub, and organized into versions for iterative improvement and feature additions.

## Repository Structure:

**main:** This is the primary branch, containing the core project setup and documentation.

**v0.1:** The first version branch where code implementation begins, including basic student data handling, file reading, and final grade calculations based on user-defined methods (average or median).



# Application Features
## Functionalities
1. User Input and Data Collection:

- Users can input a student’s first name, surname, homework scores (with no set limit on the number), and exam score.
- Input collection is facilitated through an overloaded cin operator.

2. Final Grade Calculation:

- The final grade is calculated based on a combination of homework and exam scores.
- Formula:

```plaintext
Final points = 0.4 * (average of HW | median of HW) + 0.6 * exam
```

- Users can choose between using the average or median of homework scores to calculate the final grade.

3. Data Display:

- The program displays each student’s final grade based on both calculation methods (average and median).
- Output is formatted for clarity with two decimal places.