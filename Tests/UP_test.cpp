/*#include <catch2/catch_all.hpp>
#include "unique_ptr.h"


TEST_CASE("[UP]") {
    SECTION("564") {
        UniquePtr<int> ptr = new int(564);
        CHECK(*ptr == 564);
    }

    SECTION("Hello world") {
        UniquePtr<std::string> ptr = new std::string("Hello world");
        CHECK(*ptr == "Hello world");
    }

    /*SECTION("Двумерный массив int") {
        UniquePtr<int> ptr = new int(4, int(5));
        CHECK();
    }#1#
}*/