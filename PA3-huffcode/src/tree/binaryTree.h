#ifndef BINARY_TREE
#define BINARY_TREE
#include <cstddef>
#include <vector>
#include <bits/stdc++.h>
#include <queue>

using namespace std;
class BinaryTreeNode;

class compare {
public:
  bool operator()(BinaryTreeNode* a, BinaryTreeNode* b);
};

class BinaryTree
{
  public:
    BinaryTree();
    virtual ~BinaryTree();

    void insert(char c);
    bool contains(char c);
    BinaryTreeNode* getNode(char c);
    void setRoot(BinaryTreeNode* node);
    BinaryTreeNode* getRoot();
    void clear();
    void removeSubTree(BinaryTreeNode* &node);
    int getNodeCount();
    void extractNodes(priority_queue<BinaryTreeNode*,vector<BinaryTreeNode*>, compare> &arr);
    void extractNodes(priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, compare> &arr, BinaryTreeNode* node, int count=0);

  private:
    int nodeCount;
    BinaryTreeNode *root;
    BinaryTreeNode* &find(char c, BinaryTreeNode* &node);

};

#endif
