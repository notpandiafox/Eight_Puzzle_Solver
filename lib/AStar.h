#ifndef ASTAR_H
#define ASTAR_H

#include "Problem.h"
#include "Tree.h"
#include <queue>
#include <cmath>
#include <unordered_set>

static int HEURISTIC_CHOICE = 0;


class Astar
{
public:
	Astar(Problem& state)
	{
		Tree.root = std::make_shared<TreeNode>();
		Tree.root->costToHere = 0;
		Tree.root->distToGoal = 0;
		Tree.root->problem = state;

		whereWeAre = Tree.root;
	}

	bool findPath()
	{
		frontier.push(whereWeAre);
		std::vector<PuzzleOperation> validPuzzleOperations;
		PuzzleOperation valid;
		int i{};

		while(!frontier.empty())
		{
			whereWeAre = frontier.top();
			std::shared_ptr<TreeNode> initializeChildPtr;
			frontier.pop();
			validPuzzleOperations = whereWeAre->problem.getValidOperations();
			if(whereWeAre->problem.isGoalState())
				return true;

			//visited.insert(whereWeAre);
			for(PuzzleOperation valid : validPuzzleOperations)
			{
				initializeChildPtr = std::make_shared<TreeNode>();
				initializeChildPtr->costToHere = whereWeAre->f();
				initializeChildPtr->problem = whereWeAre->problem;
				initializeChildPtr->problem.runOperation(validPuzzleOperations, valid);
				if(HEURISTIC_CHOICE == 0)
					initializeChildPtr->distToGoal = heuristicUniform(initializeChildPtr->problem);// TODO: MAKE SURE IT IS UNIFORM SEARCH
				else if(HEURISTIC_CHOICE == 1)
					initializeChildPtr->distToGoal = heuristicTile(initializeChildPtr->problem);
				else if(HEURISTIC_CHOICE == 2)
					initializeChildPtr->distToGoal = heuristicEuclidean(initializeChildPtr->problem);
				
				frontier.push(initializeChildPtr);



				whereWeAre->addChild(std::make_shared<TreeNode>());
				initializeChildPtr = whereWeAre->children;
			}

			++i;

		}
	}


private:
	//I so that it will compare and get the best f() from each TreeNode
	std::priority_queue<std::shared_ptr<TreeNode>, std::vector<std::shared_ptr<TreeNode>>, CompareTreeNode> frontier;
	
	std::unordered_set<TreeNode> visited;

	std::shared_ptr<TreeNode> whereWeAre;

	Tree Tree;

	int heuristicUniform(Problem problem) {
		return 0;
	}

	int heuristicTile(Problem brother) {
		int count{'1'};
		int blankTile{-1};
		int h{};
		for(int i = 0; i < brother.PUZZLE_SIZE; ++i)
			for(int j = 0; j < brother.PUZZLE_SIZE; ++j)
			{
				if(brother.state[i][j] == count)
				{
					++h;
				}
				else if(i == brother.PUZZLE_SIZE - 1 && j == brother.PUZZLE_SIZE - 1 && brother.state[i][j] == blankTile)
				{
					++h;
				}
				++count;
			}
			return h;
		}
	
	int heuristicEuclidean(Problem problem) {
		int count{'1'};
		int blankTile{-1};
		int h{};
		int currentValue, goalJ, goalI = -1;
		for(int i = 0; i < problem.PUZZLE_SIZE; ++i) {
			for(int j = 0; j < problem.PUZZLE_SIZE; ++j) {
				if (problem.goal_state[i][j] == problem.state[i][j]) {
					h = 0;
					exit;
				} else {
					int currentValue = problem.state[i][j];
					int goalJ = floor(currentValue / problem.PUZZLE_SIZE);
					int goalI = currentValue - (goalJ * problem.PUZZLE_SIZE) - 1;
					
					h = sqrt(pow((goalI - i), 2) + pow((goalJ - j), 2));
				}
			}
		}
		return h;
	}


};

#endif //ASTAR_H