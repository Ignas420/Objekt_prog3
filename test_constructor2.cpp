#include "catch_amalgamated.hpp"
#include "mokinys2.h"

TEST_CASE("Test constructor") {
    // Create a Mokinys object with some initial values
    Mokinys mokinys("John", "Doe", {10, 8, 9}, 7, 8.5, 8.2);
    // Check if the constructor sets the values correctly
    REQUIRE(mokinys.getVardas() == "John");
    REQUIRE(mokinys.getPavarde() == "Doe");
    REQUIRE(mokinys.getND() == deque<int>{10, 8, 9});
    REQUIRE(mokinys.getEgzaminas() == 7);
    REQUIRE(mokinys.getVID() == 8.5);
    REQUIRE(mokinys.getMED() == 8.2);
}