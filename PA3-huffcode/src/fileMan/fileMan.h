#ifndef FILEMANAGER
#define FILEMANAGER

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../tree/binaryTree.h"
#include "../tree/binaryTreeNode.h"

using namespace std;
class BinaryTree;
class BinaryTreeNode;
class FileManager{

  public:
    FileManager();
    FileManager(string readFile, string outFile);
    void openReadFile();
    void encodeFile(BinaryTree* &tree);
    void decodeFile(BinaryTree* &tree);
    void openWriteFile();
    void traverseFile(BinaryTree* &tree);


  private:
    string inFileName;
    string outFileName;
    vector<pair<char, string>> codes;
    ifstream inFile;
    ofstream outFile;
    void readCodes();
    void writeBinary(BinaryTreeNode* node, vector<pair<char, string>> &codeSet);
    string getCharCode(char letter, vector<pair<char, string>> &codeSet);
    void writeCodes(BinaryTreeNode* node, string str, vector<pair<char, string>> &codeSet);
    string traverseCode(BinaryTree* &tree, string &code);
    void addNode(BinaryTreeNode* node, char letter, string code);
    void print(BinaryTreeNode* node, string str);
};
#endif
