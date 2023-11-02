#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void treeCreation(vector<Node*> &tree) {

    for (int i = 0, j = 0; j * 2 + 2 < tree.size(); i++, j++)
    {      
        if (tree.at(i) == nullptr)
        {
             j--;
             continue;
        }

        Node* current = tree.at(i);

        Node* leftChild = tree.at(j * 2 + 1);
        Node* rightChild = tree.at(2 * j + 2);
        
        current->left = leftChild;
        current->right = rightChild;        
    }
}

bool PreOrder_BinaryTree(Node* first, Node* second) {

    if (first == nullptr && second == nullptr)
    {
        return true;
    }

    if (first == nullptr || second == nullptr)
    {
        return false;
    }   

    if (first->value != second->value )
    {
        return false;
    }

    return PreOrder_BinaryTree(first->left, second->left)
     && PreOrder_BinaryTree(first->right, second->right);
}

int main()
{
    string str;

    vector<Node*> tree1;
    getline(cin, str); 
    stringstream ss(str); 
    while (getline(ss, str, ' ')) 
    {
        if (str != "null")
        {
            tree1.push_back(new Node(stoi(str))); 
        }
        else
        {
            tree1.push_back(nullptr);
        }
    }

    vector<Node*> tree2;
    getline(cin, str); 
    stringstream sss(str); 
    while (getline(sss, str, ' ')) 
    {
        if (str != "null")
        {
            tree2.push_back(new Node(stoi(str)));
        }
        else
        {
            tree2.push_back(nullptr);
        }
    }

    treeCreation(tree1);
    treeCreation(tree2);

    if (PreOrder_BinaryTree(tree1[0], tree2[0]))
    {
        cout << "YES";
    }
    else 
    {
        cout << "NO"; 
    }

    return 0;
}