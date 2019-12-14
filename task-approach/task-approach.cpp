#include "Approach.h"
#include <iostream>

using std::cout;

int main()
{
	ApproachTypeA newOne("square", 0.5, true, 15);
	cout << newOne.getTaskType();
	return 0;
}