#include "catch.hpp"

#include "Task.h"
#include "Approach.h"

TEST_CASE("approaches can be usable and unusable to the task", "[approach]") {
	Task task1("square", 20);
	Task task2("matrix addition", 10);

	ApproachTypeA approach1("square", 0.3, true, 35);
	REQUIRE(approach1.isUsable(task1));
	REQUIRE_FALSE(approach1.isUsable(task2));

	ApproachTypeA approach2("square", 0, true, 35);
	REQUIRE_FALSE(approach2.isUsable(task1));
	REQUIRE_FALSE(approach2.isUsable(task2));
}