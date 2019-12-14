#include "Approach.h"
#include <stdexcept>

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
