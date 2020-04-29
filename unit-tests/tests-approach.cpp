#include "catch.hpp"

#include "Approach.h"

TEST_CASE("task type", "[approach]") {
	ApproachTypeA approach("square", 0.3, true, 35);
	REQUIRE(approach.getTaskType() == "square");
}