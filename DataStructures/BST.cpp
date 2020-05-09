#include <iostream>
#include <omp.h>
#include "boost/container/vector.hpp"
using namespace std;

struct Node{
    //struct contains data as well as pointers to neighbouring nodes
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    //Reserve mem for new node
    Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

void printChildren(Node* node){
    //print current node
    cout<<"   "<<node->data<<"  "<<endl;
    //print left and right child of BST
    cout<<node->left->data<<"    "<<node->right->data<<endl;
}

Node* insertNode(Node* node, int data){
    //If the tree is empty
    if (node == nullptr){
        return newNode(data);
    }
    //Keep adding to left if value is less than current node, else add to right
    data <= node->data ? (node->left = insertNode(node->left, data)) : (node->right = insertNode(node->right, data));

    //return node
    return node;
}

Node* minimumValue(Node* node){
    if(node->left != nullptr){
        minimumValue(node->left);
    }
    else {
        cout << node->data << endl;
    }
}

Node* maximumValue(Node* node){
    if(node->right != nullptr){
        maximumValue(node->right);
    }
    else {
        cout << node->data << endl;
    }
}

int main(int argc, char* argv[]) {
    Node* root = nullptr;
    root = insertNode(root,4);
    insertNode(root,2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    //printChildren(root);
    minimumValue(root);
    maximumValue(root);
}


