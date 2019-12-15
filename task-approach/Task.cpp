#include "Task.h"

int Task::nextId = 0;

Task::Task(const string& type, unsigned size) : type(type), size(size)
{
	id = nextId;
	nextId++;
}

Task::~Task()
{
}

int Task::getId() const
{
	return id;
}

string Task::getType() const
{
	return type;
}

unsigned Task::getSize() const
{
	return size;
}
