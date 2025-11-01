# CSC122 Gradebook
A simple **C++ Gradebook** for managing students, assignments, and grades — designed for CSC 122.  
The Gradebook allows instructors to add students, add assignments, record grades, and generate a full report.
---
## Features

- Add a new student to the class (first name, last name, student ID). 
- Add a new assignment to the class (name of assignment, total points possible). 
- Give a student a grade for an assignment (the grade can be between zero and the total points possible). 
- Print out a formatted report that shows all of the students and all of the grade information.
- The design uses separate C++ classes for Gradebook, Student, and Assignment, each in its own header (.hpp) and implementation (.cpp) file.
---
## Setup/How to Use
1. Open the project folder in your preferred C++ IDE (for example, Visual Studio, Code::Blocks, or CLion).
2. Add all .cpp and .hpp files to your project.
3. Build and run main.cpp, this is the driver file that interacts with the user.
4. When prompted, you’ll be able to:
   - Add students to the gradebook 
   - Add assignments to the gradebook 
   - Enter grades for students 
   - Print a formatted report
---
## Testing
This project includes automated unit tests using Catch2.
Each class (**Gradebook**, **Student**, and **Assignment**) has its own test file following the ZOMBIES testing method (Zero, One, Many, Boundary, Interface, Exceptions, Simple).

You can find the test files in the tests/ folder:
- Open and run them individually inside your IDE to verify that each class works correctly.


