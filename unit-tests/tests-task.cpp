#include "catch.hpp"

#include "../task-approach/Task.h"

TEST_CASE("Tasks' types are equal", "[task]") {
	Task task("square", 15);
	REQUIRE(task.getType() == "square");
}