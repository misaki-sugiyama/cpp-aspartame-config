// The registry is working fine
#include "aspartame/registry.h"
#include "aspartame/option.h"
#include "aspartame/exception-registry.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
using Catch::Matchers::Equals;

SCENARIO("Option registry", "[reg]") {
  GIVEN("The registry itself and some options") {
    aspartame::OptionRegistry REG;
    aspartame::Opt<double> optDouble {REG, "double", 32.5};
    aspartame::Opt<int64_t> optInt {REG, "int64_t", 15, "descint"};

    THEN("We can check these registered options inside the registry") {
      REQUIRE(REG.size() == 2);
      REQUIRE(REG.has("int64_t"));
      REQUIRE(REG.has("double"));
      REQUIRE(!REG.has("not-an-option"));
    }

    THEN("We can get option description by name") {
      REQUIRE_THAT(REG.getDesc("int64_t"), Equals("descint"));
    }
  }
} // end typical usage


SCENARIO("Option registry: not found", "[reg]") {
  GIVEN("The registry itself and one option") {
    aspartame::OptionRegistry REG;
    aspartame::Opt<int64_t> optInt {REG, "int64_t", 15};
    WHEN("Asked the description of an unknown option") {
      THEN("It should throw") {
        REQUIRE_THROWS_AS(
            REG.getDesc("not-an-option"),
            ::aspartame::ExceptionRegistryOutOfRange
            );
      }
    }
  }
} // end not found


SCENARIO("Option registry: wrong usage", "[reg]") {
  GIVEN("The registry itself and one option") {
    aspartame::OptionRegistry REG;
    aspartame::Opt<int64_t> optInt {REG, "int64_t", 15};
    WHEN("Asked to register duplicated name") {
      THEN("It should throw and not adding anything") {
        REQUIRE_THROWS_AS(
            REG.add("int64_t", "", optInt),
            ::aspartame::ExceptionRegistryAddDup
            );
        REQUIRE(REG.size() == 1);
      }
    }
  }
} // end wrong usage
