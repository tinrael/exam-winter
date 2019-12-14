#pragma once

#include "Task.h"
#include <string>

using std::string;

class Approach
{
protected:
	string taskType;
	double successProbability;
	bool isReused;
	unsigned timeSolving; // the time needed to solve the task

public:
	Approach(string taskType, double successProbability, bool isReused, unsigned timeSolving);
	virtual ~Approach() = 0;

	bool virtual solve(const Task &task);

	string getTaskType();
};

// fixed time and success probability
class ApproachTypeA : public Approach {
public:
	ApproachTypeA(string taskType, double successProbability, bool isReused, unsigned timeSolving);
	virtual ~ApproachTypeA();
};