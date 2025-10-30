#include "student.hpp"

Student::Student(string first, string last, string id)
    : first_name(first), last_name(last), student_id(id) {}

string Student::get_first_name() const {
    return first_name;
}

string Student::get_last_name() const {
    return last_name;
}

string Student::get_id() const {
    return student_id;
}