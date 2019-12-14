#pragma once

#include <string>

using std::string;

class Task
{
private:
	string type;
	unsigned size;

public:
	Task(const string &type, unsigned size);
	virtual ~Task();
	
	string getType() const;
	unsigned getSize() const;
};

