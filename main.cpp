#include <iostream>
#include "node.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



int main()
{
    class Node* root = new Node(1);
    root->insertNode(6);
    root->insertNode(8);
    root->insertNode(2);
    root->insertNode(3);
    root->inOrder(root);
    std::cout << "\n";
    root->reverseInOrder(root);
    std::cout << "\n";
    root->postOrder(root);
    root->getNodeCount();
    std::cout << "\n";
    return 0;
}
