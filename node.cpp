#include "node.h"
#include <iostream>
#include <stack>

Node::Node(int data)
{
    this->data = data;
    left = right = nullptr;
    nodeCount = 1;
}


void Node::insertNode(int inData)
{
    nodeCount++;
    if (inData < data){
        if (left){ //Does left exist?
            left->insertNode(inData); //Yes, call the function again to insert the value
        }else{
            left = new Node(inData); //No, let's make left
        }
    }else{
        if(right){//Same procedure, but for right
            right->insertNode(inData);
        }else{
            right = new Node(inData);
        }
    }
}

void Node::inOrder(Node *root)
{
    //Create a stack
    std::stack<Node *> s;
    Node* current = root;
    while (true)
    {
        //Traverse to left node
        while(current != nullptr)
        {
            //Push root to stack
            s.push(current);
            current = current->left;
        }
        //Breaks loop if stack is empty
        if(s.empty())
        {
            break;
        }
        current = s.top();
        s.pop();
        std::cout << current->data << " ";
        //Left has been visited, now it's time for right
        current = current->right;
    }
}

void Node::reverseInOrder(Node *root)
{
    std::stack<Node *> s;
    Node* current = root;
    while (true)
    {
        while(current != nullptr)
        {
            s.push(current);
            current = current->right;
        }
        if(s.empty())
        {
            break;
        }
        current = s.top();
        s.pop();
        std::cout << current->data << " ";
        current = current->left;
    }
}

int Node::getNodeCount()
{
    std::cout << std::endl << "The Tree Has: " << nodeCount << " Nodes" << std::endl;
    return nodeCount;
}

int Node::GetLevelCount(Node *node){
    Height(node);
    std::cout << std::endl << "The Tree Has: " << levelCount << " Levels" << std::endl;
    return levelCount;
}

int Node::Height(Node *node){
    if (node == NULL)
            return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = Height(node->left);
            int rheight = Height(node->right);

            /* use the larger one */
            if (lheight > rheight)
                return(levelCount = lheight + 1);
            else return(levelCount = rheight + 1);
        }
}

bool Node::isBalanced(Node* root){
    /* If tree is empty then return true */
    if (root == NULL)
        return 1;
    /* Get the height of left and right sub trees */
    int lh = Height(root->left);// for height of left subtree
    int rh = Height(root->right);//for height of right subtree

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) // Checks the difference of heights of each of the branches
        return 1;

    // If we reach here then tree is not height-balanced
    return 0;
}

bool Node::GetTreeBalance(Node *root)
{
    if(isBalanced(root)){
        std::cout << std::endl << "The Tree Is Balanced" << std::endl;
    }else{
        std::cout << std::endl << "The Tree Is Not Balanced" << std::endl;
    }
    return isBalanced(root);
}

void Node::postOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    //Create two stacks
    std::stack <Node*> s1, s2;
    Node* current = root;

    //Push root to first stack
    s1.push(current);
    //Runs while stack 1 is not empty
    while(!s1.empty())
    {
        //Pops from s1 and pushes to s2
        current = s1.top();
        s1.pop();
        s2.push(current);

        //Push children of popped item to s2
        if(current->left)
        {
            s1.push(current->left);
        }
        if(current->right)
        {
            s1.push(current->right);
        }
    }

    while (!s2.empty())
    {
        //Print the second stack
        current = s2.top();
        s2.pop();
        std::cout << current->data << " ";
    }
}

void Node::GetPrintSpecificLevel(Node * root, int Level){
    std::cout << "This level " << Level << " Contains The Following Data ";
    printSpecificLevel(root, Level);
}

void Node::printSpecificLevel(Node* root, int Level)
{
    if (root == NULL)
        return;
    if (Level == 1)
    std::cout << root->data << " ";
    else if (Level > 1)
    {
        printSpecificLevel(root->left, Level-1);
        printSpecificLevel(root->right, Level-1);
    }
}
