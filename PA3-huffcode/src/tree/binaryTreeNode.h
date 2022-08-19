#ifndef BINARY_TREE_NODE
#define BINARY_TREE_NODE

#include <cstddef>

class BinaryTreeNode
{
  public:
    BinaryTreeNode(char data = '0', 
        int frequency = 0, 
        BinaryTreeNode* left = NULL,
        BinaryTreeNode* right = NULL);
    virtual ~BinaryTreeNode();

    void updateCount();
    void updateData(char c);
    void insertLeft(BinaryTreeNode* leftOff);
    void insertRight(BinaryTreeNode* rightOff);
    char data;
    int frequency;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

  private:

};
#endif
