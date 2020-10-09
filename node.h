#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>

class Node
{
public:
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
    void createNode(int data);
    void insertNode(int inData);
    void inOrder(Node* root);
    void postOrder(Node* root);
    int data;
    Node* left;
    Node* right;
    std::vector<int> treekeys =
    {50, 12, 95, 8, 100, 47, 83, 59, 32, 21, 77, 90, 20, 66, 45, 88};
private:

};

#endif // TREE_H
