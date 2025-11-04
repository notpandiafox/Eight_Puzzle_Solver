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

    Problem problem;

    int f() const
    {
        return costToHere + distToGoal;
    }

    void addChild(std::shared_ptr<TreeNode> child) 
    {
        child->parent = shared_from_this();
        children.push_back(child);
    }

    bool operator>(const TreeNode& other)
    {
        return f() > other.f();
    }

};

struct CompareTreeNode
{
    bool operator()(const std::shared_ptr<TreeNode>& first, const std::shared_ptr<TreeNode>& second)
    {
        return *first > *second;
    }
};




class Tree
{
    public:
    Tree() {}

    Tree(Problem newState)
    {
        root->costToHere = 0;
        root->distToGoal = 0;
        root->problem = newState;
    }

    std::shared_ptr<TreeNode> root;
};

#endif // TREE_H



