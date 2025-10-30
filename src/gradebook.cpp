#include "gradebook.hpp"
#include <sstream>
#include <iostream>

void Gradebook::add_student(string first, string last, string id) {
    students.push_back(Student(first, last, id));
}

void Gradebook::add_assignment(string name, double total_points) {
    assignments.push_back(Assignment(name, total_points));
}

void Gradebook::enter_grade(string full_name, string assignment_name, double grade) {
    string student_id = "";
    for (int i = 0; i < students.size(); i++) {
        string combined = students[i].get_first_name() + " " + students[i].get_last_name();
        if (combined == full_name) {
            student_id = students[i].get_id();
            break;
        }
    }

    if (student_id == "") {
        cout << "Error: Student not found (" << full_name << ")" << endl;
        return;
    }

    bool assignment_found = false;
    double max_points = 0;
    for (int j = 0; j < assignments.size(); j++) {
        if (assignments[j].get_name() == assignment_name) {
            assignment_found = true;
            max_points = assignments[j].get_total_points();
            break;
        }
    }

    if (!assignment_found) {
        cout << "Error: Assignment not found (" << assignment_name << ")" << endl;
        return;
    }

    if (grade < 0 || grade > max_points) {
        cout << "Error: Invalid grade entered." << endl;
        return;
    }

    grades[student_id][assignment_name] = grade;
}

string Gradebook::report() const {
    stringstream output;
    output << "Last_Name,First_Name,Student_Id";

    for (int i = 0; i < assignments.size(); i++) {
        output << "," << assignments[i].get_name();
    }
    output << "\n";

    for (int i = 0; i < students.size(); i++) {
        output << students[i].get_last_name() << ","
               << students[i].get_first_name() << ","
               << students[i].get_id();

        for (int j = 0; j < assignments.size(); j++) {
            string assignment_name = assignments[j].get_name();
            string student_id = students[i].get_id();

            output << ",";
            if (grades.find(student_id) != grades.end()) {
                if (grades.at(student_id).find(assignment_name) != grades.at(student_id).end()) {
                    output << grades.at(student_id).at(assignment_name);
                } else {
                    output << "none";
                }
            } else {
                output << "none";
            }
        }
        output << "\n";
    }

    return output.str();
}