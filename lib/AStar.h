#ifndef ASTAR_H
#define ASTAR_H

#include "Problem.h"
#include "Tree.h"

#include <queue>

class Astar
{
public:
    Astar(Problem& state)
    {
        Tree.root = std::make_shared<TreeNode>();
        Tree.root->costToHere = 0;
        Tree.root->distToGoal = 0;
        Tree.root->state = state;
    }
 
    bool findPath()
    {

    }


private:
    //I so that it will compare and get the best f() from each TreeNode
    std::priority_queue<std::shared_ptr<TreeNode>, std::vector<std::shared_ptr<TreeNode>>, CompareTreeNode> frontier;
    
    std::shared_ptr<TreeNode> whereWeAre;

    Tree Tree;

    int heuristicTile(Problem* brother)
    {
        int count{'1'};
        int blankTile{-1};
        int h{};
        for(int i = 0; i < brother->PUZZLE_SIZE; ++i)
        {
            for(int j = 0; j < brother->PUZZLE_SIZE; ++j)
            {
                if(brother->state[i][j] == count)
                {
                    ++h;
                }
                else if(i == brother->PUZZLE_SIZE - 1 && j == brother->PUZZLE_SIZE - 1 && brother->state[i][j] == blankTile)
                {
                    ++h;
                }
                ++count;
            }
        }

        return h;
    }
    
    int heuristicEuclidean(Problem* problem)
    {
        
    }


};

#endif //ASTAR_H