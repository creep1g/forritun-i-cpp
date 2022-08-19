#include <iostream>

using namespace std;

#include "binaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(char data ,
                               int frequency ,
                               BinaryTreeNode* left ,
                               BinaryTreeNode* rigth)
{
  this->data = data;
  this->frequency = frequency;
  this->left = left;
  this->right = right;
}

BinaryTreeNode::~BinaryTreeNode(){
  delete this->left;
  delete this->right;
  this->data = '0';
  this->frequency  = 0;
}

void BinaryTreeNode::updateCount(){
  this->frequency++;
}

void BinaryTreeNode::updateData(char c){
  this->data = c;
}

void BinaryTreeNode::insertLeft(BinaryTreeNode* leftOff){
  this->left = leftOff;
}

void BinaryTreeNode::insertRight(BinaryTreeNode* rightOff){
  this->right = rightOff;
}
