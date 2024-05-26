# CSE2002 Programming II - 2023/2024 Spring Project

This repository contains the code and documentation for the CSE2002 Programming II project for the Spring 2023/2024 semester. The project is focused on developing an **Office Hour Appointment System**.

## Project Overview

The Office Hour Appointment System allows teachers and students to manage and track office hour appointments efficiently. The system supports two user roles: Teacher and Student.

## Features

- **Teacher Role:**
  - Add new office hours.
  - Update existing office hours.
  - Print a table of all office hours.
- **Student Role:**
  - View available office hours of teachers.
  - Schedule an appointment with a teacher.

## Project Structure

The project is organized into the following files:

- `teacher.c` - Functions related to teacher operations.
- `student.c` - Functions related to student operations.
- `readLine.c` - Functions to handle line reading.
- `appointment.c` - Main function of the program.
- Header files for each source file to manage function prototypes.

## Usage Instructions

1. **Compilation:**
   - Ensure all source files and header files are in the same directory.
   - Use a C compiler to compile the source files:
     ```sh
     gcc -o appointment_system teacher.c student.c readLine.c appointment.c
     ```

2. **Running the Program:**
   - Execute the compiled program:
     ```sh
     ./appointment_system
     ```

3. **Operation:**
   - The program will prompt the user to enter a role (1 for Teacher, 2 for Student).
   - Depending on the role, follow the on-screen instructions to perform the desired operations.

## Project Submission Requirements

- **Comments:** Each line of the source code must include comments explaining its functionality.
- **Error Handling:** The source code must compile without errors; otherwise, the evaluation will be affected.
- **Documentation:** A detailed explanation of all functions is provided in the `functions.docx` file.
- **Screenshots:** Screenshots of the program's output as both teacher and student are included (`teacher.jpeg` and `student.jpeg`).

## Evaluation

- Projects will be evaluated during the lab sessions from May 20-24, 2024.
- Students must present their projects in person during the lab hours.

## Important Notes

- Plagiarism is strictly forbidden. The submitted code must be original and the result of individual work.
- Late submissions and email submissions are not accepted.
- Attendance during the lab sessions is mandatory for project evaluation.
