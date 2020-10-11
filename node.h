#ifndef TREE_H
#define TREE_H

class Node
{
public:
    Node(int data);
    void createNode(int data);
    void insertNode(int inData);
    void inOrder(Node* root);
    void reverseInOrder(Node *root);
    void postOrder(Node* root);
    void printSpecificLevel(Node* root, int Level);
    void GetPrintSpecificLevel(Node * root, int Level);
    int getNodeCount();
    int GetLevelCount(Node *node);
    int Height(Node* node);
    bool isBalanced(Node* root);
    bool GetTreeBalance(Node * root);

private:
    int data;
    int nodeCount;
    int levelCount;
    Node* left;
    Node* right;

};

#endif // TREE_H
