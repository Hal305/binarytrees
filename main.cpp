#include <iostream>
#include "node.h"



int main()
{
    Node node;
    class Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    node.inOrder(root);
    return 0;
}
