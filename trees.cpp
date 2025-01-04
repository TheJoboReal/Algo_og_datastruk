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

void TraverselInOrder(Node* root){
    // Check if node is a leaf node
    if(root == nullptr){
        return;
    }

    // Go through left sub
    TraverselInOrder(root -> left);

    //Print _data in node
    std::cout << root->_data << " ";


    //Go through right sub
    TraverselInOrder(root -> right);
}


void TraverselPreOrder(Node* root){
    // Check if node is a leaf node
    if(root == nullptr){
        return;
    }

    //Print _data in node
    std::cout << root -> _data << " ";

    // Go through left sub
    TraverselPreOrder(root -> left);

    // Go through right sub
    TraverselPreOrder(root -> right);
}

void TraverselPostOrder(Node* root){
    // Check if node is a leaf node
    if(root == nullptr){
        return;
    }

    // Go through left sub
    TraverselPostOrder(root -> left);

    // Go through right sub
    TraverselPostOrder(root -> right);

    //Print _data in node
    std::cout << root->_data << " ";
}

void TraverselLevelOrder(Node* root) {
    if (!root) return;      // Check if root is empty
    std::queue<Node*> q;    // Initialize a queue to store the nodes
    q.push(root);           // Push the root node into the queue
    while (!q.empty()) {    // While the queue is not empty
        Node* curr = q.front(); // Get the front node in the queue
        q.pop();            // Pop the front node
        std::cout << curr->_data << " ";    // Print the node value
        if (curr->left) q.push(curr->left);     // Push the left child into the queue
        if (curr->right) q.push(curr->right);   // Push the right child into the queue
    }
}

Node getOnlyChild(Node node){
    if(node.left != nullptr){   // Check if left child exists and return it if it does
        return *node.left;
    }
    return *node.right;     // Return right child if left child does not exist. And if right child does not exist the node will be a leaf node
}

 int getBranches(Node* root){
    int branches = 0;
    // Check if node is a leaf node
    if(root == nullptr){
        return 0;
    }

    if(root->left != nullptr && root->right != nullptr){        // Check if node has two children
        branches++;
    }

    // Go through left sub
    branches += getBranches(root -> left);

    // Go through right sub
    branches += getBranches(root -> right);

    return branches;

 }

// Helper function to calculate the height of the tree
int treeHeight(Node* root) {
    if (!root) return 0;
    return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

// Function to fill the tree's structure into a vector of strings
void fillTree(Node* root, int level, int left, int right, std::vector<std::string>& output, int width) {
    if (!root || left > right) return;

    int mid = (left + right) / 2;
    // Place the node value in the middle of the current range
    output[level][mid] = std::to_string(root->_data)[0];

    // If the node has a left child, draw the connection and move to the left
    if (root->left) {
        output[level + 1][mid - 1] = '/';
        fillTree(root->left, level + 2, left, mid - 2, output, width);
    }

    // If the node has a right child, draw the connection and move to the right
    if (root->right) {
        output[level + 1][mid + 1] = '\\';
        fillTree(root->right, level + 2, mid + 2, right, output, width);
    }
}

// Function to print the binary tree in a formatted style
void printFormattedTree(Node* root) {
    if (!root) return;

    int height = treeHeight(root);
    int width = std::pow(2, height + 1) - 1;  // Maximum width of the tree layout

    // Initialize a 2D vector to hold the tree structure
    std::vector<std::string> output(height * 2, std::string(width, ' '));

    // Fill the tree's structure into the vector
    fillTree(root, 0, 0, width - 1, output, width);

    // Print the formatted tree
    std::cout << std::endl;
    for (const auto& line : output) {
        std::cout << line << std::endl;
    }
}


int internalPathLength(Node* root, int depth = 0){
    if(root == nullptr){
        return 0;
    }

    // Check if node has any children
    int pathLength = 0;
    if(root -> left != nullptr || root -> right != nullptr){
        pathLength = depth;
    }

    // Recursively run through the nodes
    int left = internalPathLength(root -> left, depth + 1);
    int right = internalPathLength(root -> right, depth + 1);

    // Return total internal path length
    return left + right + pathLength;
}


void perfectTree(int height, Node* root, int index = 1) {
    if (height == 0) {
        return;
    }

    root->left = new Node(index + 1);
    root->right = new Node(index + 2);

    perfectTree(height - 1, root->left, index + 2);
    perfectTree(height - 1, root->right, index + 2 + std::pow(2, height - 1));
}


int main(){
    Node* root = new Node(45);
    root->left = new Node(15);
    root->left->left = new Node(10);
    root->left->left->right = new Node(12);
    root->left->right = new Node(20);
    root->right = new Node(79);
    root->right->left = new Node(55);
    root->right->left->left = new Node(50);
    root->right->right = new Node(90);


    printFormattedTree(root);
    TraverselLevelOrder(root);
}