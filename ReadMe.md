Grade Distribution Analyzer
This project aims to analyze the grade distribution of various courses and instructors at a given university. The program reads input from a CSV file containing course data and computes the average GPA of each instructor for each course. The output is then saved to a text file, displaying the average GPA of instructors per course, organized by department.

Getting Started
These instructions will help you get a copy of the project and run it on your local machine.

Prerequisites
A C compiler (such as GCC)
A Unix-like environment or compatible terminal (such as Git Bash on Windows)
Compilation
Clone this repository:
bash
Copy code
git clone https://github.com/username/GradeDistributionAnalyzer.git
Navigate to the project folder:
bash
Copy code
cd GradeDistributionAnalyzer
Compile the project using the provided Makefile:
bash
Copy code
make
Usage
Run the program by providing an input CSV file and specifying an output file:

bash
Copy code
./dist input.txt output.txt
Example Input
The input file should be a CSV file with the following columns:

Year
Term
Department
Course Number
Course Title
Instructor
GPA
Example:

css
Copy code
2018,Fall,CS,101,Introduction to Computer Science,John Doe,3.5
2019,Fall,CS,101,Introduction to Computer Science,Jane Smith,3.7
Example Output
The output file will display the average GPA of each instructor for each course, organized by department:

yaml
Copy code
Grade Distribution: 2018 Fall - 2023 Fall

Department: CS
    Course: CS 101 - Introduction to Computer Science
            Instructor: John Doe, Average GPA: 3.500000, Number of Classes: 1
            Instructor: Jane Smith, Average GPA: 3.700000, Number of Classes: 1
Contributing
If you'd like to contribute to this project, please submit a pull request with your proposed changes.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements
Eric Uehling for the initial implementation of the project