#include "Approach.h"
#include <stdexcept>

Approach::Approach(string taskType, unsigned successProbability, bool isReused, unsigned timeSolving) :
	taskType(taskType), isReused(isReused), timeSolving(timeSolving)
{
	if (successProbability >= 0 && successProbability <= 1) {
		this->successProbability = successProbability;
	}
	else {
		throw std::invalid_argument("The value of success probability is invalid!");
	}
}

Approach::~Approach()
{
}
