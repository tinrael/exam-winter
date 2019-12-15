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
	int timeSolving; // the time needed to solve the task

	// Sets the new value of success probability with upper and lower limits
	void changeSuccessProbability(double newValue);
	// Sets the new value of time-solving with lower limit
	void changeTimeSolving(int newValue);

public:
	Approach(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~Approach() = 0;

	bool virtual solve(const Task &task);

	string getTaskType();
};

// fixed time and success probability
class ApproachTypeA : public Approach {
public:
	ApproachTypeA(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~ApproachTypeA();
};