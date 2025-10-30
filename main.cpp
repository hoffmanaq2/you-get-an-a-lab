#include <iostream>
#include <string>
#include "src/gradebook.hpp"

using namespace std;

int main() {
    Gradebook gradebook;
    int choice = 0;

    while (true) {
        cout << "\n===== CSC 122 Gradebook Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Add Assignment\n";
        cout << "3. Enter Grade\n";
        cout << "4. Show Report\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            continue;
        }

        if (choice == 1) {
            string first, last, id;
            cout << "Enter first name: ";
            cin >> first;
            cout << "Enter last name: ";
            cin >> last;
            cout << "Enter student ID: ";
            cin >> id;
            gradebook.add_student(first, last, id);
        }
        else if (choice == 2) {
            string name;
            double points;

            cout << "Enter assignment name (no spaces): ";
            cin >> name;

            cout << "Enter total points possible: ";
            if (!(cin >> points)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }

            if (points <= 0) {
                cout << "Points must be greater than 0.\n";
                continue;
            }

            gradebook.add_assignment(name, points);
        }
        else if (choice == 3) {
            string first, last, assignment;
            double grade;

            cout << "Enter student's first name: ";
            cin >> first;
            cout << "Enter student's last name: ";
            cin >> last;
            cout << "Enter assignment name: ";
            cin >> assignment;
            cout << "Enter grade: ";

            if (!(cin >> grade)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a numeric value for the grade.\n";
                continue;
            }

            if (grade < 0) {
                cout << "Grade cannot be negative.\n";
                continue;
            }

            string full_name = first + " " + last;
            gradebook.enter_grade(full_name, assignment, grade);
        }
        else if (choice == 4) {
            cout << "\n" << gradebook.report();
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Please select between 1 and 5.\n";
        }
    }

    return 0;
}