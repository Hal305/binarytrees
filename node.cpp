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
    }
    else
    {
        //Same procedure, but for right
        if(right)
        {
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
    std::stack<Node *> s;
    Node* current = root;
    while (true)
    {
        while(current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        if(s.empty())
        {
            break;
        }
        current = s.top();
        s.pop();
        std::cout << current->data << " ";
        current = current->right;
    }
    std::cout << "\n";
}

void Node::postOrder(Node *root)
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
}
