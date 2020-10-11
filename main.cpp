#include <iostream>
#include "node.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



int main()
{
    srand (time(NULL));

    class Node* root = new Node(5);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->insertNode(rand()%10+1);
    root->inOrder(root);
    root->postOrder(root);
    root->getNodeCount();


    return 0;
}
