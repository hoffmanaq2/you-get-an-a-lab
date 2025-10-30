#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"

// ZOMBIES: Zero, One, Many, Boundary, Interface, Exceptions, Simple

TEST_CASE("Gradebook class follows ZOMBIES testing", "[Gradebook]") {

    Gradebook gb;

    // Z
    SECTION("Z: Empty Gradebook should print only headers") {
        string report = gb.report();
        REQUIRE(report.find("Last_Name,First_Name,Student_Id") != string::npos);
    }

    // O
    SECTION("O: Add one student and one assignment") {
        gb.add_student("Bob", "Bobberson", "ABC123");
        gb.add_assignment("Quiz1", 100);
        gb.enter_grade("Bob Bobberson", "Quiz1", 95);

        string report = gb.report();
        REQUIRE(report.find("Bobberson") != string::npos);
        REQUIRE(report.find("95") != string::npos);
    }

    // M
    SECTION("M: Add multiple students and assignments") {
        gb.add_student("Sam", "Sammerson", "A1");
        gb.add_student("Jess", "Jesserson", "A2");
        gb.add_assignment("Quiz1", 100);
        gb.add_assignment("Lab1", 50);

        gb.enter_grade("Sam Sammerson", "Quiz1", 88);
        gb.enter_grade("Jess Jesserson", "Lab1", 45);

        string report = gb.report();
        REQUIRE(report.find("Sammerson") != string::npos);
        REQUIRE(report.find("Jesserson") != string::npos);
        REQUIRE(report.find("88") != string::npos);
        REQUIRE(report.find("45") != string::npos);
    }

    // B
    SECTION("B: Boundary - invalid grades should not crash") {
        gb.add_student("Alex", "Anderson", "B1");
        gb.add_assignment("Quiz2", 100);
        gb.enter_grade("Alex Anderson", "Quiz2", 150); // invalid
        string report = gb.report();
        REQUIRE(report.find("Anderson") != string::npos);
    }

    // I
    SECTION("I: Interface - ensure add and report work together") {
        gb.add_student("Sam", "Sammerson", "C1");
        gb.add_assignment("Quiz3", 100);
        gb.enter_grade("Sam Sammerson", "Quiz3", 90);
        string report = gb.report();
        REQUIRE(report.find("Quiz3") != string::npos);
        REQUIRE(report.find("90") != string::npos);
    }

    // E
    SECTION("E: Exceptions - handle missing data gracefully") {
        gb.add_student("Bob", "Bobberson", "ABC123");
        gb.add_assignment("Quiz1", 100);

        gb.enter_grade("Fake Name", "Quiz1", 80);
        gb.enter_grade("Bob Bobberson", "FakeAssignment", 80);

        string report = gb.report();
        REQUIRE(report.find("Bobberson") != string::npos);
    }

    // S
    SECTION("S: Simple - missing grades show 'none' in report") {
        gb.add_student("Jess", "Jesserson", "XYZ789");
        gb.add_assignment("Quiz4", 50);
        string report = gb.report();
        REQUIRE(report.find("none") != string::npos);
    }
}