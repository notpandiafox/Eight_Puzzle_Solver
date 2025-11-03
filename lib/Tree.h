#ifndef TREE_H
#define TREE_H
 
#include <memory>
#include <vector>

struct TreeNode : public std::enable_shared_from_this<TreeNode>
{
    std::weak_ptr<TreeNode> parent;
    std::vector<std::shared_ptr<TreeNode>> children;

    std::vector<std::vector<char>> state;
    int totalCost;

    void addChild(std::shared_ptr<TreeNode> child) 
    {
        child->parent = shared_from_this();
        children.push_back(child);
    }

};
class Tree
{
    public:


    private:



};

#endif // TREE_H



