#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <utility>


struct Problem
{
    std::vector<std::vector<char>> initial_state;
    std::vector<std::vector<char>> goal_state;
    std::vector<std::vector<char>> state;

    const std::vector<std::pair<int,int>> operators{
        {-1, 0},//up
        {1,0},//down
        {0,1},//right
        {-1,0}//left
    };

    Problem(std::vector<std::vector<char>> initial_state, std::vector<std::vector<char>> goal_state)
    :initial_state{initial_state}, goal_state{goal_state} { }


    void operator=(Problem& otherProblem)
    {
        state = otherProblem.state;
    }

};

#endif //PROBLEM_H