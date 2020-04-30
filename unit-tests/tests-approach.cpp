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

	ApproachTypeB approach3("square", 0.2, true, 40);
	REQUIRE(approach3.isUsable(task1));
	REQUIRE_FALSE(approach3.isUsable(task2));
}

TEST_CASE("approaches of type C decrease success probability if this certain task solves again", "[approach]") {
	Task task1("square", 20);
	Task task2("square", 35);
	ApproachTypeC approach("square", 0.5, true, 10);

	REQUIRE(approach.getSuccessProbability(task1) == Approx(0.5));
	approach.solve(task1);
	REQUIRE(approach.getSuccessProbability(task1) < 0.5);

	REQUIRE(approach.getSuccessProbability(task2) == Approx(0.5));
}