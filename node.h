#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>

class Node
{
public:
    Node(int data);
    void createNode(int data);
    void insertNode(int inData);
    void inOrder(Node* root);
    void postOrder(Node* root);
    void getNodeCount();
private:
    int data;
    int nodeCount;
    Node* left;
    Node* right;
};

#endif // TREE_H
