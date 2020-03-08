#include "catch.hpp"

#include "Task.h"

TEST_CASE("Tasks' types are equal", "[task]") {
	Task task("square", 15);
	REQUIRE(task.getType() == "square");
}