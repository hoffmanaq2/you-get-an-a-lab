#include "assignment.hpp"

Assignment::Assignment(string name, double points)
    : name(name), total_points(points) {}

string Assignment::get_name() const {
    return name;
}

double Assignment::get_total_points() const {
    return total_points;
}