#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <utility>
#include <ostream>

enum PuzzleOperation {MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};

struct Problem {
	// function header
    std::vector<std::vector<int>> initial_state;
    std::vector<std::vector<int>> goal_state;
    std::vector<std::vector<int>> state;
	int BLANK_TILE_X = -1;
	int BLANK_TILE_Y = -1;
	const int PUZZLE_SIZE = 3; // nxn puzzle

	friend std::ostream& operator<<(std::ostream& os, const Problem& obj);

	// void runOperation(std::vector<PuzzleOperation> validOperations, PuzzleOperation operation);
	// bool isGoalState();
	// void updateBlankTile();
	// std::vector<PuzzleOperation> getValidOperations();

	// initializers
	Problem() {
		initial_state = { {1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
		goal_state = { {1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
		state = { {1, 2, 3}, {4, 5, 6}, {7, 8, -1}};
		updateBlankTile();
	}
    Problem(std::vector<std::vector<int>> initial_state, std::vector<std::vector<int>> goal_state)
    :initial_state{initial_state}, goal_state{goal_state}, state(initial_state) { 
		updateBlankTile();
	}


	// methods
    void operator=(const Problem& otherProblem)
    {
        state = otherProblem.state;
        initial_state = otherProblem.initial_state;
        goal_state = otherProblem.goal_state;
    }
	bool isGoalState() {
		return (state == goal_state);
	}

	void updateBlankTile() {
		for(int i = 0; i < PUZZLE_SIZE; ++i) {
        	for (int j = 0; j < PUZZLE_SIZE; ++j) {
				if(state[i][j] == -1) {
					BLANK_TILE_X = i;
					BLANK_TILE_Y = j;
				}
			}
    	}
	}
	void runOperation(std::vector<PuzzleOperation> validOperations, PuzzleOperation operation) {
		for (int i = 0; i < validOperations.size(); i++) {
			if (validOperations.at(i) == operation) {
				switch (operation) {
					case MOVE_UP:
						std::swap(state[BLANK_TILE_X][BLANK_TILE_Y - 1], state[BLANK_TILE_X][BLANK_TILE_Y]);
						BLANK_TILE_Y--;
						break;
					case MOVE_DOWN:
						std::swap(state[BLANK_TILE_X][BLANK_TILE_Y + 1], state[BLANK_TILE_X][BLANK_TILE_Y]);
						BLANK_TILE_Y++;
						break;
					case MOVE_LEFT:
						std::swap(state[BLANK_TILE_X - 1][BLANK_TILE_Y], state[BLANK_TILE_X][BLANK_TILE_Y]);
						BLANK_TILE_X--;
						break;
					case MOVE_RIGHT:
						std::swap(state[BLANK_TILE_X + 1][BLANK_TILE_Y], state[BLANK_TILE_X][BLANK_TILE_Y]);
						BLANK_TILE_X++;
						break;
					default:
						break;
				} 
			}
		}
	}
	std::vector<PuzzleOperation> getValidOperations() {
		std::vector<PuzzleOperation> validOperations = {};
		if (BLANK_TILE_Y > 0) {
			validOperations.push_back(MOVE_UP);
		}
		if (BLANK_TILE_Y < PUZZLE_SIZE - 1) {
			validOperations.push_back(MOVE_DOWN);
		}
		if (BLANK_TILE_X > 0) {
			validOperations.push_back(MOVE_LEFT);
		}
		if (BLANK_TILE_X < PUZZLE_SIZE - 1) {
			validOperations.push_back(MOVE_RIGHT);
		}


		return {};
	}
    std::string stringify() {
        std::string key;
        for (int i = 0; i < PUZZLE_SIZE; i++) {
            for (int j = 0; j < PUZZLE_SIZE; j++) {
                key += state[i][j];
            }
        }
        return key;
}

};
std::ostream& operator<<(std::ostream& os, const Problem& obj) {
	for(int i = 0; i < obj.PUZZLE_SIZE; ++i) {
        for (int j = 0; j < obj.PUZZLE_SIZE; ++j) {
			os << obj.state[i][j] << " ";
		}
		os << "\n";
    }
	return os; // Return the ostream reference for chaining
}
#endif //PROBLEM_H