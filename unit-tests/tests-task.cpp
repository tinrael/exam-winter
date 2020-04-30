#include "catch.hpp"

#include "Task.h"

TEST_CASE("initialization and assignment", "[task]") {
	Task task1("square", 50);
	REQUIRE(task1.getType() == "square");
	REQUIRE(task1.getSize() == 50);

	Task task2 = task1;
	REQUIRE(task2.getType() == "square");
	REQUIRE(task2.getSize() == 50);

	Task task3("perimeter", 20);
	REQUIRE(task3.getType() == "perimeter");
	REQUIRE(task3.getSize() == 20);

	task2 = Task("matrix addition", 45);
	REQUIRE(task2.getType() == "matrix addition");
	REQUIRE(task2.getSize() == 45);
}