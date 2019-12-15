#pragma once

#include <string>

using std::string;

class Task
{
private:
	static int nextId;
	int id;
	string type;
	unsigned size;

public:
	Task(const string &type, unsigned size);
	virtual ~Task();
	
	int getId() const;
	string getType() const;
	unsigned getSize() const;
};

