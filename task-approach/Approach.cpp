#include "Approach.h"
#include <stdexcept>
#include <random>

void Approach::changeSuccessProbability(double newValue)
{
	if (newValue <= 0.0) {
		successProbability = 0.0;
	}
	else if (newValue >= 1.0) {
		successProbability = 1.0;
	}
	else {
		successProbability = newValue;
	}
}

void Approach::changeTimeSolving(int newValue)
{
	if (newValue <= 0) {
		timeSolving = 0;
	}
	else {
		timeSolving = newValue;
	}
}

Approach::Approach(string taskType, double successProbability, bool isReused, int timeSolving) :
	taskType(taskType), isReused(isReused)
{
	if (successProbability >= 0.0 && successProbability <= 1.0) {
		this->successProbability = successProbability;
	}
	else {
		throw std::invalid_argument("The value of success probability is invalid!");
	}

	if (timeSolving >= 0) {
		this->timeSolving = timeSolving;
	}
	else {
		throw std::invalid_argument("The value of time-solving is invalid!");
	}
}

Approach::~Approach()
{
}

// Solve the task with a certain probability (successProbability)
bool Approach::solve(const Task& task)
{
	if (task.getType() == this->taskType) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0.0, 1.0);

		// Each call to dis(gen) generates a new random double in [0, 1)
		if (dis(gen) < successProbability) {
			return true;
		}
	}
	return false;
}

bool Approach::isUsable(const Task& task)
{
	if (getSuccessProbability(task) != 0.0 && (task.getType() == taskType)) {
		return true;
	}
	return false;
}

string Approach::getTaskType()
{
	return taskType;
}

double Approach::getSuccessProbability(const Task& task)
{
	return successProbability;
}

int Approach::getTimeSolving(const Task& task)
{
	return timeSolving;
}

ApproachTypeA::ApproachTypeA(string taskType, double successProbability, bool isReused, int timeSolving) :
	Approach(taskType, successProbability, isReused, timeSolving)
{
}

ApproachTypeA::~ApproachTypeA()
{
}

ApproachTypeB::ApproachTypeB(string taskType, double successProbability, bool isReused, int timeSolving) :
	Approach(taskType, successProbability, isReused, timeSolving)
{
}

ApproachTypeB::~ApproachTypeB()
{
}

bool ApproachTypeB::solve(const Task& task)
{
	bool isSolved = Approach::solve(task);
	
	if (task.getType() == taskType) {
		changeSuccessProbability(successProbability + probabilityIncreaseValue);
		changeTimeSolving(timeSolving - timeSolvingDecreaseValue);
	}
	
	return isSolved;
}

ApproachTypeC::ApproachTypeC(string taskType, double successProbability, bool isReused, int timeSolving) :
	Approach(taskType, successProbability, isReused, timeSolving), tasks()
{
}

ApproachTypeC::~ApproachTypeC()
{
}

// TODO: make the code better
double ApproachTypeC::getSuccessProbability(const Task& task)
{
	int id = task.getId();
	auto search = tasks.find(id);

	if (search != tasks.end()) {
		int factor = search->second; // the number of attempts to solve
		return successProbability - factor * probabilityDecreaseValue;
	}
	else {
		return successProbability;
	}
}

// TODO: make the code better
int ApproachTypeC::getTimeSolving(const Task& task)
{
	int id = task.getId();
	auto search = tasks.find(id);

	if (search != tasks.end()) {
		int factor = search->second; // the number of attempts to solve
		return timeSolving - timeSolving + factor * timeSolvingIncreaseValue;
	}
	else {
		return timeSolving;
	}
}

// TODO: make the code better
bool ApproachTypeC::solve(const Task& task)
{
	int id = task.getId();
	auto search = tasks.find(id);

	if (search != tasks.end()) {		
		double defaultProbabilityValue = successProbability;
		int defaultTimeSolvingValue = timeSolving;
		
		int factor = search->second;
		changeSuccessProbability(successProbability - factor * probabilityDecreaseValue);
		changeTimeSolving(timeSolving + factor * timeSolvingIncreaseValue);
		
		bool isSolved = Approach::solve(task);

		changeSuccessProbability(defaultProbabilityValue);
		changeTimeSolving(defaultTimeSolvingValue);

		search->second++;
		return isSolved;
	}
	else {
		tasks.insert({ id, 1 });
		return Approach::solve(task);
	}
}
