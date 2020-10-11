#include <iostream>
#include "node.h"



int main()
{
    class Node* root = new Node(8);
    root->insertNode(3);
    root->insertNode(10);
    root->insertNode(1);
    root->insertNode(6);
    root->insertNode(9);
    root->insertNode(14);
    root->inOrder(root);
    std::cout << "\n";
    root->reverseInOrder(root);
    std::cout << "\n";
    root->postOrder(root);
    root->getNodeCount();
    root->GetLevelCount(root);
    root->GetTreeBalance(root);
    root->GetPrintSpecificLevel(root, 3);
    std::cout << "\n";
    return 0;
}

