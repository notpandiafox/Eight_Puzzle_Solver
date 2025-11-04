#include "lib/AStar.h"
#include "lib/interface.h"

#include <iostream>
#include <vector>

std::vector<std::vector<int>> readPuzzle() {
    std::vector<std::vector<int>> puzzle(3, std::vector<int>(3));
    std::cout << "Enter the first row, use space or tabs between numbers: ";
    for (int j = 0; j < 3; ++j) std::cin >> puzzle[0][j];

    std::cout << "Enter the second row, use space or tabs between numbers: ";
    for (int j = 0; j < 3; ++j) std::cin >> puzzle[1][j];

    std::cout << "Enter the third row, use space or tabs between numbers: ";
    for (int j = 0; j < 3; ++j) std::cin >> puzzle[2][j];

    return puzzle;
}

int main() {
    std::cout << "Welcome to XXX (replace with your ID) 8 puzzle solver." << std::endl;
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << std::endl;

    int choice;
    std::cin >> choice;

    std::vector<std::vector<int>> startState;
    std::vector<std::vector<int>> goalState = {{1,2,3},{4,5,6},{7,8,-1}};

    if (choice == 1) {
        startState = {{1,2,3},{4,8,-1},{7,6,5}};
    } else {
        startState = readPuzzle();
    }

    std::cout << "\nEnter your choice of algorithm:" << std::endl;
    std::cout << "1. Uniform Cost Search\n";
    std::cout << "2. A* with the Misplaced Tile heuristic." << std::endl;
    std::cout << "3. A* with the Euclidean distance heuristic." << std::endl;

    int algoChoice;
    std::cin >> algoChoice;

    Problem problem(startState, goalState);

    std::cout << "\nExpanding state:" << std::endl;
    std::cout << problem;  

    
    if (algoChoice == 1) {
        HEURISTIC_CHOICE = 0;
        std::cout << "\nRunning Uniform Cost Search..." << std::endl;
    } else if (algoChoice == 2) {
        HEURISTIC_CHOICE = 1;
        std::cout << "\nRunning A* with Misplaced Tile heuristic..." << std::endl;
    } else if (algoChoice == 3) {
        HEURISTIC_CHOICE = 2;
        std::cout << "\nRunning A* with Euclidean distance heuristic..." << std::endl;
    } else {
        std::cout << "Invalid choice. Exiting." << std::endl;
        return 0;
    }

    Astar puzzleSolver(problem);

    bool found = puzzleSolver.findPath();

    if (found) {
        std::cout << "\n Goal state reached!" << std::endl;
    } else {
        std::cout << "\n No solution found." << std::endl;
    }

    return 0;
}