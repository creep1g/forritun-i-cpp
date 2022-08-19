#include "fileMan.h"
#include <vector>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

FileManager::FileManager(){
  this->inFileName = "";
  this->outFileName = "";

}

FileManager::FileManager(string readFile, string outFile){
  this->inFileName = readFile;
  this->outFileName = outFile;
}

void FileManager::openReadFile(){
  this->inFile.open(this->inFileName);
}

void FileManager::openWriteFile(){
  this->outFile.open(this->outFileName);
}

void FileManager::traverseFile(BinaryTree* &tree){
  string line;
  this->openReadFile();
  char temp = '0';
  int count = 0;

  while(this->inFile.peek() != EOF){

    this->inFile >> line;

    temp = '0';
    count = 0;

    while(temp != '\0'){
      if (line[count] != '\0'){
        tree->insert(line[count]);
      }
      temp = line[count];
      count++;
    }
  }
  this->inFile.close();
}

void FileManager::encodeFile(BinaryTree* &tree){
  this->openReadFile();
  this->openWriteFile();
  string codeLine;
  this->writeCodes(tree->getRoot(), codeLine, this->codes);
  // Write a delimiter to tell decoders where the code table ends
  this->outFile << "/" << "\n\n";

  this->writeBinary(tree->getRoot(), codes);
  this->inFile.close();
  this->outFile.close();
}

string FileManager::getCharCode(char letter, vector<pair<char, string>> &codeSet){
  string temp = "";
  char tempChar = '0';
  int count = 0;
  while(1){
    if(codeSet[count].first == letter){
      return codeSet[count].second;
    }
    count++;
  }
}

void FileManager::writeBinary(BinaryTreeNode* node, vector<pair<char, string>> &codeSet){
  string line;
  string code;
  char temp;
  int count;
  // for each line in our file iterate over each char and get the code associated with it.
  while (this->inFile >> line){
    temp = '0';
    count = 0;
    code = "";
    cout << line << endl;
  
    while(temp != '\0'){
      temp = line[count];
      code = code + getCharCode(temp ,codeSet);
      count++;
    }
    this->outFile << code << "\n";
  }  
}

void FileManager::writeCodes(BinaryTreeNode* node, string str, vector<pair<char, string>> &codeSet){
  if (!node){
    return;
  }
  if (node->data != '#'){
    codeSet.push_back(make_pair(node->data, str));
    this->outFile << node->data << ": " << str << "\n";

  }

  writeCodes(node->left, str + "0", codeSet);
  writeCodes(node->right, str + "1", codeSet);
}


void FileManager::decodeFile(BinaryTree* &tree){
  BinaryTreeNode* root = new BinaryTreeNode('#');
  tree->setRoot(root);
  this->openReadFile();
  this->openWriteFile();
  this->readCodes();

  for(auto i : this->codes){
    this->addNode(tree->getRoot(), i.first, i.second);
  }
  /* this->print(tree->getRoot(), ""); */
  string line;
  string decodedLine;
  while(this->inFile >> line){
    decodedLine = this->traverseCode(tree, line);
    this->outFile << decodedLine << "\n";
  }
}


string FileManager::traverseCode(BinaryTree* &tree, string &code){
  string output = "";
  int len = code.length();
  BinaryTreeNode* node = tree->getRoot();
  for (int i = 0; i < len+1; i++){
  //Use c_str() to acces each char of the code
  //walk through code until we find a leaf node 
    if(!node->left){
      //add it to our decoded string
      output += node->data;
      //reset to root
      node = tree->getRoot();
    }
    if(code.c_str()[i] == '0'){
        node = node->left;
    }
    else{
      node = node->right;
    }
  }
  //return decoded string.
  return output;
  
}

void FileManager::addNode(BinaryTreeNode* node, char letter, string code){
  int len = code.length();
  BinaryTreeNode* temp = node; 
  for (int i = 0; i < len; i++){
    if(code.c_str()[i] == '0'){
      if (!node->left && i < len-1){
          node->left = new BinaryTreeNode('#');
          node = node->left;
          node->left = nullptr;
          node->right = nullptr;
        }
      else if (i == len-1){
        node->left = new BinaryTreeNode(letter);
      }
      else {
        node = node->left;
      }
    }

    else{
      if (!node->right && i < len-1){
        node->right = new BinaryTreeNode('#');
        node = node->right;
        node->left = nullptr;
        node->right = nullptr;
      }
      else if (i == len-1){
        node->right = new BinaryTreeNode(letter);
      }
      else {
        node = node->right; 
      }
    }
  }
}


void FileManager::readCodes(){
  string line;
  string code;
  char temp = '0';
  while (this->inFile >> line && line != "/"){
    temp = line.c_str()[0]; // Get the charachter of the code
    this->inFile >> line;
    this->codes.push_back(make_pair(temp, line));
  }
}

