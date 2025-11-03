#ifndef TREE_H
#define TREE_H
 
#include <memory>
#include <vector>
#include "Problem.h"

struct TreeNode : public std::enable_shared_from_this<TreeNode>
{

    int costToHere;
    int distToGoal;

    std::weak_ptr<TreeNode> parent;
    std::vector<std::shared_ptr<TreeNode>> children;

    Problem state;

    void addChild(std::shared_ptr<TreeNode> child) 
    {
        child->parent = shared_from_this();
        children.push_back(child);
    }

};
class Tree
{
    public:
    Tree(Problem newState)
    {
        root->costToHere = 0;
        root->distToGoal = 0;
        root->state = newState;
    }

    std::shared_ptr<TreeNode> root;
};

#endif // TREE_H



