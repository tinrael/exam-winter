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

string Approach::getTaskType()
{
	return taskType;
}

ApproachTypeA::ApproachTypeA(string taskType, double successProbability, bool isReused, int timeSolving) :
	Approach(taskType, successProbability, isReused, timeSolving)
{
}

ApproachTypeA::~ApproachTypeA()
{
}
