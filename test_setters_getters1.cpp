#include "catch_amalgamated.hpp"
#include "mokinys1.h"

TEST_CASE("Test getters and setters") {
    // Create a Mokinys object
    Mokinys mokinys;
    // Set values using setter functions
    mokinys.setVardas("Alice");
    mokinys.setPavarde("Smith");
    mokinys.addND(9);
    mokinys.addND(8);
    mokinys.setEgzaminas(6);
    mokinys.setVID(7.5);
    mokinys.setMED(7.8);
    // Check if getter functions return the correct values
    REQUIRE(mokinys.getVardas() == "Alice");
    REQUIRE(mokinys.getPavarde() == "Smith");
    REQUIRE(mokinys.getND() == list<int>{9, 8});
    REQUIRE(mokinys.getEgzaminas() == 6);
    REQUIRE(mokinys.getVID() == 7.5);
    REQUIRE(mokinys.getMED() == 7.8);
}
