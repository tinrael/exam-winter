#include "Approach.h"
#include <stdexcept>
#include <random>

Approach::Approach(string taskType, double successProbability, bool isReused, unsigned timeSolving) :
	taskType(taskType), isReused(isReused), timeSolving(timeSolving)
{
	if (successProbability >= 0.0 && successProbability <= 1.0) {
		this->successProbability = successProbability;
	}
	else {
		throw std::invalid_argument("The value of success probability is invalid!");
	}
}

Approach::~Approach()
{
}

string Approach::getTaskType()
{
	return taskType;
}

ApproachTypeA::ApproachTypeA(string taskType, double successProbability, bool isReused, unsigned timeSolving) :
	Approach(taskType, successProbability, isReused, timeSolving)
{
}

ApproachTypeA::~ApproachTypeA()
{
}

// Solve the task with a certain probability (successProbability)
bool ApproachTypeA::solve(const Task &task)
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
