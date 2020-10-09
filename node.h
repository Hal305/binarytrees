#ifndef TREE_H
#define TREE_H


class Node
{
public:
    Node();

    void createNode(int data);
    void insertNode(int inData);
    void inOrder(Node* root);
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
    int data;
    Node* left;
    Node* right;
private:

};

#endif // TREE_H
