#pragma once

#include "Task.h"
#include <string>
#include <map>
#include <memory>

using std::string;
using std::map;

class Approach
{
protected:
	string taskType;
	double successProbability;
	
	int timeSolving; // the time needed to solve the task

	// Sets the new value of success probability with upper and lower limits
	void changeSuccessProbability(double newValue);
	// Sets the new value of time-solving with lower limit
	void changeTimeSolving(int newValue);

public:
	bool isReused;
	
	Approach(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~Approach() = 0;

	virtual bool solve(const Task &task);
	
	/* Checks whether the task is usable to the approach.
	The task is usable if the types are equal and
	the success probability != 0.
	*/
	virtual bool isUsable(const Task& task);

    virtual string getTypeInfo() = 0;
	string getTaskType();
	virtual double getSuccessProbability(const Task& task);
	virtual int getTimeSolving(const Task& task);
};

// fixed time and success probability
class ApproachTypeA : public Approach {
public:
	ApproachTypeA(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~ApproachTypeA();

    string getTypeInfo() override;
};

/* The time needed to solve the task decreases and success probability increases
*  if there is an attempt to solve the task.
*/
class ApproachTypeB : public Approach {
private:
	const double probabilityIncreaseValue = 0.1;
	const int timeSolvingDecreaseValue = 1;

public:
	ApproachTypeB(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~ApproachTypeB();

    bool virtual solve(const Task& task) override;
    string getTypeInfo() override;
};

/* The time needed to solve the task increases and success probability decreases
*  if this task solves again
*/
class ApproachTypeC : public Approach {
private:
	const double probabilityDecreaseValue = 0.2;
	const int timeSolvingIncreaseValue = 2;
	map<int, unsigned> tasks; // the task ID and the number of attempts to solve
	
public:
	ApproachTypeC(string taskType, double successProbability, bool isReused, int timeSolving);
	virtual ~ApproachTypeC();

    string getTypeInfo() override;
	double getSuccessProbability(const Task& task) override;
	int getTimeSolving(const Task& task) override;
    bool virtual solve(const Task& task) override;
};
