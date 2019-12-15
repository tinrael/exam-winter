#include "Task.h"
#include "Approach.h"
#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::vector;

// TODO: make the code clearer and better; add tests units; add comments
int solve(const Task &task, vector<std::shared_ptr<Approach>> approaches, int timeFrame) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, approaches.size() - 1);
	int random;

	string taskType = task.getType();
	int spentTime = 0;
	bool isSolved = false;

	while (!isSolved && !approaches.empty() && spentTime <= timeFrame) {
		random = dis(gen);	
		
		cout << "--- \t---" << endl;
		cout << "Random number: " << random << endl;
		cout << "Try to solve the \"" << taskType << "\" task using the \"" << approaches[random]->getTaskType() << "\" approach." << endl;


		if (approaches[random]->isUsable(task)) {					
			
			cout << "Success Probability: " << approaches[random]->getSuccessProbability(task) << endl;
			cout << "Time solving: " << approaches[random]->getTimeSolving(task) << endl;
			cout << "All spent time: " << spentTime << endl;

			spentTime += approaches[random]->getTimeSolving(task);
			isSolved = approaches[random]->solve(task);

			cout << "Success result: " << isSolved << endl;
		}
		else {		
			cout << "This approach is not usable for this task." << endl;
			approaches.erase(approaches.begin() + random);
		}

		dis = std::uniform_int_distribution<>(0, approaches.size() - 1);
		cout << "--- \t---" << endl;
	}

	return spentTime;
}

int main()
{
	Task myTask("calculate square", 35);
	vector<std::shared_ptr<Approach>> approaches;
	
	approaches.emplace_back(std::make_shared<ApproachTypeA>("calculate square", 0.2, true, 15));
	approaches.emplace_back(std::make_shared<ApproachTypeA>("calculate integral", 0.9, false, 25));
	approaches.emplace_back(std::make_shared<ApproachTypeB>("calculate square", 0.01, false, 5));
	approaches.emplace_back(std::make_shared<ApproachTypeC>("calculate square", 0.02, false, 10));
	approaches.emplace_back(std::make_shared<ApproachTypeC>("calculate perimeter", 0.4, true, 8));
	approaches.emplace_back(std::make_shared<ApproachTypeB>("calculate square", 0.4, false, 7));

	solve(myTask, approaches, 150);
	
	return 0;
}