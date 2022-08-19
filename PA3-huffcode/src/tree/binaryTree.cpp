#include "binaryTree.h"
#include "binaryTreeNode.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

BinaryTree::BinaryTree(){
  root = NULL;
}

BinaryTree::~BinaryTree(){
  this->clear();
}

BinaryTreeNode* BinaryTree::getRoot(){
  return this->root;
}

void BinaryTree::insert(char c){
  BinaryTreeNode* &node = find(c, this->root);

  if(node != NULL){
    node->updateCount();
  }
  else{
    node = new BinaryTreeNode(c, 1);
  }
}

BinaryTreeNode* BinaryTree::getNode(char c){
  return find(c, this->root);
}

bool BinaryTree::contains(char c){
  return (this->find(c, this->root)) != NULL;
}

void BinaryTree::setRoot(BinaryTreeNode* node){
  this->root = node;
}

bool compare::operator()(BinaryTreeNode* a, BinaryTreeNode* b){
  return a->frequency > b->frequency;
}

int BinaryTree::getNodeCount(){
  return this->nodeCount;
}

void BinaryTree::extractNodes(priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, compare> &arr){
  this->extractNodes(arr, this->root);

}

void BinaryTree::extractNodes(priority_queue<BinaryTreeNode*, vector<BinaryTreeNode*>, compare> &arr, BinaryTreeNode* node, int count){
  // Recursively add nodes to our array.
  if (node != NULL){
    extractNodes(arr, node->left);
    node->left = nullptr;
    arr.push(node);
    extractNodes(arr, node->right);
    node->right=nullptr;
  }
}

BinaryTreeNode* &BinaryTree::find(char c, BinaryTreeNode* &node){
  if(node == NULL){
    return node;
  }
  
  if(c < node->data ){
    return this->find(c, node->left);

  }
  else if (node->data < c){
    return this->find(c, node->right);
  }

  return node;
}

void BinaryTree::clear(){
  this->removeSubTree(this->root);
  this->root = NULL;
}

void BinaryTree::removeSubTree(BinaryTreeNode* &node){
  if(node != NULL){
    removeSubTree(node->left);
    removeSubTree(node->right);
    delete node;
    node = NULL;
  }
}

