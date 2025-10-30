#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/student.hpp"

// ZOMBIES method: Zero, One, Many, Boundary, Interface, Exceptions, Simple scenarios

TEST_CASE("Student class follows ZOMBIES testing", "[Student]") {

    // Z — Zero / default state
    SECTION("Z: Create a basic student and check values") {
        Student s("Bob", "Bobberson", "ABC123");
        REQUIRE(s.get_first_name() == "Bob");
        REQUIRE(s.get_last_name() == "Bobberson");
        REQUIRE(s.get_id() == "ABC123");
    }

    // O — One
    SECTION("O: Single student should hold correct data") {
        Student s("Jess", "Jesserson", "XYZ789");
        REQUIRE(s.get_first_name() == "Jess");
        REQUIRE(s.get_last_name() == "Jesserson");
        REQUIRE(s.get_id() == "XYZ789");
    }

    // M — Many
    SECTION("M: Multiple students should store independently") {
        Student s1("Sam", "Sammerson", "A1");
        Student s2("Bob", "Bobberson", "B2");

        REQUIRE(s1.get_first_name() != s2.get_first_name());
        REQUIRE(s1.get_id() != s2.get_id());
    }

    // B — Boundary
    SECTION("B: Boundary - unusual but valid student IDs") {
        Student s("Tiny", "Tim", "0000000000001");
        REQUIRE(s.get_id().length() > 0);
    }

    // I — Interface
    SECTION("I: Interface - getters return expected types") {
        Student s("Alex", "Anderson", "123");
        REQUIRE(typeid(s.get_first_name()) == typeid(string));
        REQUIRE(typeid(s.get_last_name()) == typeid(string));
        REQUIRE(typeid(s.get_id()) == typeid(string));
    }

    // E — Exceptions
    SECTION("E: Exceptions - simulated invalid data handling") {
        Student s("", "", "");
        REQUIRE(s.get_first_name() == "");
        REQUIRE(s.get_last_name() == "");
        REQUIRE(s.get_id() == "");
    }

    // S — Simple scenario
    SECTION("S: Simple - check full data consistency") {
        Student s("Bob", "Bobberson", "ID123");
        REQUIRE(s.get_first_name() + " " + s.get_last_name() == "Bob Bobberson");
    }
}
