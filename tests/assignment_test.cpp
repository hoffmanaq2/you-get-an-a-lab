#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/assignment.hpp"

// ZOMBIES: Zero, One, Many, Boundary, Interface, Exceptions, Simple

TEST_CASE("Assignment class follows ZOMBIES testing", "[Assignment]") {

    // Z
    SECTION("Z: Create a default assignment and check values") {
        Assignment a("Quiz1", 100);
        REQUIRE(a.get_name() == "Quiz1");
        REQUIRE(a.get_total_points() == (100.0));
    }

    // O
    SECTION("O: Single assignment stores correct information") {
        Assignment a("Lab1", 50);
        REQUIRE(a.get_name() == "Lab1");
        REQUIRE(a.get_total_points() == (50.0));
    }

    // M
    SECTION("M: Many assignments store independent values") {
        Assignment a1("Quiz1", 100);
        Assignment a2("Lab1", 50);
        REQUIRE(a1.get_name() != a2.get_name());
        REQUIRE(a1.get_total_points() != a2.get_total_points());
    }

    // B
    SECTION("B: Boundary - zero and large total points") {
        Assignment a1("ExtraCredit", 0);
        Assignment a2("FinalProject", 1000);
        REQUIRE(a1.get_total_points() == (0.0));
        REQUIRE(a2.get_total_points() == (1000.0));
    }

    // I
    SECTION("I: Interface - confirm correct data types") {
        Assignment a("Exam", 200);
        REQUIRE(typeid(a.get_name()) == typeid(string));
        REQUIRE(typeid(a.get_total_points()) == typeid(double));
    }

    // E
    SECTION("E: Exceptions - negative point totals are still stored (no validation)") {
        Assignment a("BrokenAssignment", -10);
        REQUIRE(a.get_total_points() == (-10.0));
    }

    // S
    SECTION("S: Simple - ensure multiple fields are correct together") {
        Assignment a("Quiz2", 75);
        REQUIRE(a.get_name() == "Quiz2");
        REQUIRE(a.get_total_points() == (75.0));
    }
}