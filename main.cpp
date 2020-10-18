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
    std::cout << "\n";
    root->getNodeCount();
    std::cout << "\n";
    root->GetLevelCount(root);
    std::cout << "\n";
    root->GetTreeBalance(root);
    std::cout << "\n";
    root->GetPrintSpecificLevel(root, 2);
    std::cout << "\n";
    return 0;
}

