#include "Task.h"

Task::Task(const string& type, unsigned size) : type(type), size(size)
{
}

Task::~Task()
{
}

string Task::getType() const
{
	return type;
}

unsigned Task::getSize() const
{
	return size;
}
