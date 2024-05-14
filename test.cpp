#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "mokinys.h"

TEST_CASE("Default Constructor test", "[Default]") {
    Mokinys mokinys;
	WARN("REQUIRE stops at [Default] failure:");
    REQUIRE(mokinys.getVardas() == "");
    REQUIRE(mokinys.getPavarde() == "");
    REQUIRE(mokinys.getND().empty());
    REQUIRE(mokinys.getEgzaminas() == 0);
    REQUIRE(mokinys.getVID() == 0.0);
    REQUIRE(mokinys.getMED() == 0.0);
}

TEST_CASE("Constructor with parameters test", "[ConstructorParameters]") {
    Mokinys mokinys2("Vardenis", "Pavardenis", {10, 8, 9}, 7, 8.5, 9.0);
	WARN("REQUIRE stops at [ConstructorParameters] failure:");
    REQUIRE(mokinys2.getVardas() == "Vardenis");
    REQUIRE(mokinys2.getPavarde() == "Pavardenis");
    REQUIRE(mokinys2.getND() == vector<int>{10, 8, 9});
    REQUIRE(mokinys2.getEgzaminas() == 7);
    REQUIRE(mokinys2.getVID() == 8.5);
    REQUIRE(mokinys2.getMED() == 9.0);
}

TEST_CASE("Copy Constructor Test", "[CopyConstructor]") {
    Mokinys mokinys("Vardenis", "Pavardenis", {10, 8, 9}, 7, 8.5, 9.0);
	WARN("REQUIRE stops at [CopyConstructor] failure:");
    Mokinys copy_mokinys(mokinys);
    REQUIRE(copy_mokinys.getVardas() == "Vardenis");
    REQUIRE(copy_mokinys.getPavarde() == "Pavardenis");
    REQUIRE(copy_mokinys.getND() == vector<int>{10, 8, 9});
    REQUIRE(copy_mokinys.getEgzaminas() == 7);
    REQUIRE(copy_mokinys.getVID() == 8.5);
    REQUIRE(copy_mokinys.getMED() == 9.0);
}

TEST_CASE("Move Constructor Test","[MoveConstructor]") {
    Mokinys mokinys("Vardenis", "Pavardenis", {10, 8, 9}, 7, 8.5, 9.0);
    Mokinys moved_mokinys(move(mokinys));
	WARN("REQUIRE stops at [MoveConstructor] failure:");
    REQUIRE(moved_mokinys.getVardas() == "Vardenis");
    REQUIRE(moved_mokinys.getPavarde() == "Pavardenis");
    REQUIRE(moved_mokinys.getND() == vector<int>{10, 8, 9});
    REQUIRE(moved_mokinys.getEgzaminas() == 7);
    REQUIRE(moved_mokinys.getVID() == 8.5);
    REQUIRE(moved_mokinys.getMED() == 9.0);

    REQUIRE(mokinys.getVardas().empty());
    REQUIRE(mokinys.getPavarde().empty());
    REQUIRE(mokinys.getND().empty());
    REQUIRE(mokinys.getEgzaminas() == 0);
    REQUIRE(mokinys.getVID() == 0.0);
    REQUIRE(mokinys.getMED() == 0.0);
}
