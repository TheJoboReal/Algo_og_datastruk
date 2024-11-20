#include <iostream>
#include <queue>
#include <cmath>
#include <string>

struct Node{
    int _data;
    Node* left;
    Node* right;
    Node(int val) : _data(val), left(nullptr), right(nullptr){}
};

// Minimum Spanning Tree Function
void spanningTree(Node* root){
    // Check if node is a leaf node
    if(root == nullptr){
        return;
    }

    // Create a queue to hold the nodes
    std::queue<Node*> q;
    q.push(root);

    // Run through the nodes in the queue
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        // Print the node
        std::cout << curr->_data << " ";

        // Push the left child into the queue
        if (curr->left) q.push(curr->left);

        // Push the right child into the queue
        if (curr->right) q.push(curr->right);
    }
}


int main(){
    Node* root = new Node(25);
    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(22);
    root->right = new Node(36);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    spanningTree(root);
    return 0;

}