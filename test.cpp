#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "mokinys.h"

TEST_CASE("Vector Constructor with size, capacity, and default value", "[constructor]")
{
    Vector<int> v(5, 10, 0);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 10);
    for (size_t i = 0; i < v.size(); ++i)
    {
        REQUIRE(v[i] == 0);
    }
}

TEST_CASE("Default Constructor", "[constructor]")
{
    Vector<int> v;
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("Constructor with initial capacity", "[constructor]")
{
    Vector<int> v(10);
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 10);
}

TEST_CASE("Constructor with size and default value", "[constructor]")
{
    Vector<int> v(5, 10);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);
    for (size_t i = 0; i < v.size(); ++i)
    {
        REQUIRE(v[i] == 10);
    }
}

TEST_CASE("Constructor with initializer list", "[constructor]")
{
    Vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);
    for (size_t i = 0; i < v.size(); ++i)
    {
        REQUIRE(v[i] == static_cast<int>(i + 1));
    }
}
TEST_CASE("Copy Constructor", "[constructor]")
{
    Vector<int> original = {1, 2, 3, 4, 5};
    Vector<int> copy(original);
    REQUIRE(copy.size() == original.size());
    REQUIRE(copy.capacity() == original.capacity());
    for (size_t i = 0; i < copy.size(); ++i)
    {
        REQUIRE(copy[i] == original[i]);
    }
}

TEST_CASE("Move Constructor", "[constructor]")
{
    Vector<int> original = {1, 2, 3, 4, 5};
    Vector<int> moved(std::move(original));
    REQUIRE(moved.size() == 5);
    REQUIRE(moved.capacity() == 5);
    for (size_t i = 0; i < moved.size(); ++i)
    {
        REQUIRE(moved[i] == static_cast<int>(i + 1));
    }
    REQUIRE(original.size() == 0);
    REQUIRE(original.capacity() == 0);
}

TEST_CASE("Copy Assignment Operator", "[assignment]")
{
    Vector<int> original = {1, 2, 3};
    Vector<int> copy;
    copy = original;
    REQUIRE(copy.size() == original.size());
    REQUIRE(copy.capacity() == original.capacity());
    for (size_t i = 0; i < copy.size(); ++i)
    {
        REQUIRE(copy[i] == original[i]);
    }
}

TEST_CASE("Move Assignment Operator", "[assignment]")
{
    Vector<int> original = {1, 2, 3};
    Vector<int> moved;
    moved = std::move(original);
    REQUIRE(moved.size() == 3);
    REQUIRE(moved.capacity() == 3);
    for (size_t i = 0; i < moved.size(); ++i)
    {
        REQUIRE(moved[i] == static_cast<int>(i + 1));
    }
    REQUIRE(original.size() == 0);
    REQUIRE(original.capacity() == 0);
}
TEST_CASE("push_back", "[modifiers]")
{
    Vector<int> v;
    v.push_back(1);
    REQUIRE(v.size() == 1);
    REQUIRE(v.capacity() == 1);
    REQUIRE(v[0] == 1);

    v.push_back(2);
    REQUIRE(v.size() == 2);
    REQUIRE(v.capacity() == 2);
    REQUIRE(v[1] == 2);

    v.push_back(3);
    REQUIRE(v.size() == 3);
    REQUIRE(v.capacity() == 4);
    REQUIRE(v[2] == 3);
}

TEST_CASE("pop_back", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.pop_back();
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);

    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 1);

    v.pop_back();
    REQUIRE(v.size() == 0);
}
TEST_CASE("size", "[accessors]")
{
    Vector<int> v = {1, 2, 3};
    REQUIRE(v.size() == 3);

    v.pop_back();
    REQUIRE(v.size() == 2);

    v.clear();
    REQUIRE(v.size() == 0);
}

TEST_CASE("capacity", "[accessors]")
{
    Vector<int> v;
    REQUIRE(v.capacity() == 0);

    v.push_back(1);
    REQUIRE(v.capacity() == 1);

    v.reserve(100);
    REQUIRE(v.capacity() == 100);
}

TEST_CASE("empty", "[accessors]")
{
    Vector<int> v;
    REQUIRE(v.empty());

    v.push_back(1);
    REQUIRE_FALSE(v.empty());

    v.clear();
    REQUIRE(v.empty());
}

TEST_CASE("operator[]", "[accessors]")
{
    Vector<int> v = {1, 2, 3};
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);

    const Vector<int> const_v = {1, 2, 3};
    REQUIRE(const_v[0] == 1);
    REQUIRE(const_v[1] == 2);
    REQUIRE(const_v[2] == 3);
}

TEST_CASE("at", "[accessors]")
{
    Vector<int> v = {1, 2, 3};
    REQUIRE(v.at(0) == 1);
    REQUIRE(v.at(1) == 2);
    REQUIRE(v.at(2) == 3);

    REQUIRE_THROWS_AS(v.at(3), std::out_of_range);
}

TEST_CASE("front", "[accessors]")
{
    Vector<int> v = {1, 2, 3};
    REQUIRE(v.front() == 1);

    v.clear();
    REQUIRE_THROWS_AS(v.front(), std::out_of_range);
}

TEST_CASE("back", "[accessors]")
{
    Vector<int> v = {1, 2, 3};
    REQUIRE(v.back() == 3);

    v.clear();
    REQUIRE_THROWS_AS(v.back(), std::out_of_range);
}
TEST_CASE("clear", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.clear();
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 3);

    Vector<int> empty_v;
    empty_v.clear();
    REQUIRE(empty_v.size() == 0);
    REQUIRE(empty_v.capacity() == 0);
}

TEST_CASE("reserve", "[modifiers]")
{
    Vector<int> v;
    v.reserve(10);
    REQUIRE(v.capacity() == 10);

    v.reserve(5);
    REQUIRE(v.capacity() == 10);

    Vector<int> v2 = {1, 2, 3};
    v2.reserve(1);
    REQUIRE(v2.capacity() == 3);
}

TEST_CASE("resize", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.resize(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    v.resize(2);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
}

TEST_CASE("swap", "[modifiers]")
{
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {4, 5, 6};
    v1.swap(v2);
    REQUIRE(v1.size() == 3);
    REQUIRE(v2.size() == 3);
    REQUIRE(v1[0] == 4);
    REQUIRE(v1[1] == 5);
    REQUIRE(v1[2] == 6);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("insert", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.insert(1, 4);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 4);
    REQUIRE(v[2] == 2);
    REQUIRE(v[3] == 3);

    v.insert(0, 0);
    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 1);
}

TEST_CASE("erase", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.erase(1);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 3);

    v.erase(0);
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == 3);

    v.erase(0); // Erasing the only element
    REQUIRE(v.size() == 0);
}
TEST_CASE("begin_end", "[iterators]")
{
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        sum += *it;
    }
    REQUIRE(sum == 6);

    const Vector<int> const_v = {1, 2, 3};
    int sum_const = 0;
    for (auto it = const_v.begin(); it != const_v.end(); ++it)
    {
        sum_const += *it;
    }
    REQUIRE(sum_const == 6);
}

TEST_CASE("rbegin_rend", "[iterators]")
{
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        sum += *it;
    }
    REQUIRE(sum == 6);

    const Vector<int> const_v = {1, 2, 3};
    int sum_const = 0;
    for (auto it = const_v.rbegin(); it != const_v.rend(); ++it)
    {
        sum_const += *it;
    }
    REQUIRE(sum_const == 6);
}
TEST_CASE("Assign from initializer list", "[modifiers]")
{
    Vector<int> v;
    v.assign({1, 2, 3});
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
}

TEST_CASE("Assign from another container", "[modifiers]")
{
    std::vector<int> source = {4, 5, 6};
    Vector<int> v;
    v.assign(source.begin(), source.end());
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 4);
    REQUIRE(v[1] == 5);
    REQUIRE(v[2] == 6);
}

TEST_CASE("Assign from range specified by iterators", "[modifiers]")
{
    std::vector<int> source = {7, 8, 9};
    Vector<int> v;
    v.assign(source.begin() + 1, source.end());
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 8);
    REQUIRE(v[1] == 9);
}
TEST_CASE("Insert at the beginning", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.insert(0, 0);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 1);
    REQUIRE(v[2] == 2);
    REQUIRE(v[3] == 3);
}

TEST_CASE("Insert in the middle", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.insert(1, 4);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 4);
    REQUIRE(v[2] == 2);
    REQUIRE(v[3] == 3);
}

TEST_CASE("Insert at the end", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.insert(3, 4);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
}

TEST_CASE("Insert range", "[modifiers]")
{
    Vector<int> v = {1, 5, 6};
    std::vector<int> values = {2, 3, 4};
    v.insert_range(1, values.begin(), values.end());
    REQUIRE(v.size() == 6);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
    REQUIRE(v[4] == 5);
    REQUIRE(v[5] == 6);
}

TEST_CASE("Erase from the beginning", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.erase(0);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 2);
    REQUIRE(v[1] == 3);
}

TEST_CASE("Erase from the middle", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.erase(1);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 3);
}

TEST_CASE("Erase from the end", "[modifiers]")
{
    Vector<int> v = {1, 2, 3};
    v.erase(2);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
}

TEST_CASE("Erase the only element", "[modifiers]")
{
    Vector<int> v = {1};
    v.erase(0);
    REQUIRE(v.size() == 0);
}
