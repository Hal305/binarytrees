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

    if (inData < data)
    {
        //Does left exist?
        if (left)
        {
            //Yes, call the function again to insert the value
            left->insertNode(inData);
        }
        else
        {
            //No, let's make left
            left = new Node(inData);
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

void Node::getNodeCount()
{
    std::cout << std::endl << "Your Node Count Is: " << nodeCount << std::endl;
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
