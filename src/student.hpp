#pragma once
#include <string>
using namespace std;

class Student {
private:
    string first_name;
    string last_name;
    string student_id;

public:
    Student(string first, string last, string id);

    string get_first_name() const;
    string get_last_name() const;
    string get_id() const;
};