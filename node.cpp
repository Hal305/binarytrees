#include "node.h"
#include <iostream>
#include <stack>

void Node::insertNode(int inData)
{
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
    }
    else
    {
        //Same procedure, but for right
        if(right)
        {
            right->insertNode(inData);
        }
        else
        {
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
