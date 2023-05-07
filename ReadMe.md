# Grade Distribution Analyzer

A project that analyzes the average GPA for each instructor in each course at Virginia Tech. This project was made as a guide to students who have the option to take a class with different proffesors. The output file shows each instructor for every course, along with their corresponding gpa.

## Getting Started

Follow the instructions below to run the project on your local machine.

### Prerequisites

- C compiler (e.g., GCC)

### Compiling and Running

1. Open the terminal and navigate to the project folder.
2. Compile the project using the provided Makefile:

```bash
make all
```

3. Run the project with the input and output file names:

```bash
./dist input.txt output.txt
```

This will generate an `output.txt` file containing the average GPA of each instructor for each course.

## Usage

The project reads an input file containing course information and calculates the average GPA for each instructor in each course. It outputs the results in a hierarchical format, with departments, courses, and instructors.

## Project Structure

- `dist.c` and `dist.h` contain the implementation of the data structures and related functions.
- `main.c` contains the main function, which reads input files, performs the calculations, and writes the output.
- The `CSVSorter` folder contains a C program for preprocessing the GradeDistribution.csv file.

## Author

- Eric Uehling

## Acknowledgements

- Eric Uehling for the initial implementation of the project
