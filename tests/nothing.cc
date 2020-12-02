// 0-parameter registered things
#include "aspartame/registry.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
using Catch::Matchers::Equals;

SCENARIO("123", "[reg]") {
  GIVEN("The registry itself") {
    THEN("true") {
      REQUIRE(2 == 2);
    }
  }
} // End placeholder scenario
