#pragma once
#include <string>
using namespace std;

class Assignment {
private:
    string name;
    double total_points;

public:
    Assignment(string name, double points);

    string get_name() const;
    double get_total_points() const;
};