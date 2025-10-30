#pragma once
#include <string>
#include <vector>
#include <map>
#include "Student.hpp"
#include "Assignment.hpp"

using namespace std;

class Gradebook {
private:
    vector<Student> students;
    vector<Assignment> assignments;
    map<string, map<string, double>> grades; // student_id -> (assignment -> grade)

public:
    void add_student(string first, string last, string id);
    void add_assignment(string name, double total_points);
    void enter_grade(string full_name, string assignment_name, double grade);
    string report() const;
};