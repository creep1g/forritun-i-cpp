#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "tree/binaryTree.h"
#include "tree/binaryTreeNode.h"
#include "fileMan/fileMan.h"

using namespace std;

/* vector<BinaryTreeNode*> nodeList; */

void printHelper(){
  cout << "Usage: " << endl;
  cout << "Encode:   huffcode -e <file_name> <comressed_file_name>" << endl;
  cout << "Decode:   huffcode -d <compressed_file_name> <file_name>" << endl;
  cout << "Help:     huffcode -h <to see this text>" << endl;
}

int main(int argc, char * argv[]){
  if (argc > 3){
    char* option = argv[1];
    string inFile = argv[2];
    string outFile = argv[3];

    priority_queue<BinaryTreeNode*,vector<BinaryTreeNode*>, compare> minHeap;
    BinaryTree* tree = new BinaryTree(); 

    // Initialize FileManager with in file and out file.
    FileManager fm = FileManager(inFile, outFile);

    if (strcmp(option, "-e") == 0){ 
      cout << "Encoding " << inFile << " to " << outFile << endl;
      // Load contents of file into a binary tree
      // This method was chosen because it is quite simple to
      // count frequncies each char that is read from the file 
      fm.traverseFile(tree);
      // Add nodes to priority queue
      tree->extractNodes(minHeap);     
      // Generate a huffman tree
      BinaryTreeNode *left, *right, *top;
      int count = 0;
      while(minHeap.size() != 1){
        right = minHeap.top();
        minHeap.pop();
        left = minHeap.top();
        minHeap.pop();

        top = new BinaryTreeNode('#', left->frequency + right->frequency);

        top->insertLeft(left);
        top->insertRight(right);
        minHeap.push(top);
      }
      tree->setRoot(top);

      // Write code table to file, end with slash
      // Write each charachter with binary code to the file.
      fm.encodeFile(tree);
    }

    else if (strcmp(option,"-d") == 0){
      fm.decodeFile(tree);

      cout << "Decoding: " << inFile << " To: " << outFile  << endl;

    }

    else if (strcmp(option, "-h") == 0){
      printHelper();
    }

    else {
      cout << option << " is not a known command." << endl;
      printHelper();
    }

  }

  else{
    cout << "to few arguments" << endl;
    printHelper();
  }
  return 0;
}

