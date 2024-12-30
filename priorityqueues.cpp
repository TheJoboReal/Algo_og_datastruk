#include <iostream>
#include <array>
#include <cmath>
#include <vector>


struct Node{
    int _data;
    Node* left;
    Node* right;
    Node(int val) : _data(val), left(nullptr), right(nullptr){}
};

//------------------------------------------------------------------------------------------------------------

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

//------------------------------------------------------------------------------------------------------------

// Helper function to calculate the height of the tree
int treeHeight(Node* root) {
    if (!root) return 0;
    return std::max(treeHeight(root->left), treeHeight(root->right)) + 1;
}


// Function to print the binary tree sideways
void printTreeSideways(Node* root, int space = 0, int height = 10) {
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += height;

    // Process right child first
    printTreeSideways(root->right, space);

    // Print current node after space
    std::cout << std::endl;
    for (int i = height; i < space; i++)
        std::cout << ' ';
    std::cout << root->_data << "\n";

    // Process left child
    printTreeSideways(root->left, space);
}



//------------------------------------------------------------------------------------------------------------


void insert(Node* root, int input){
    if(input < root->_data){
        if(root->left == nullptr){
            root->left = new Node(input);
        } else {
            insert(root->left, input);
        }
    } else {
        if(root->right == nullptr){
            root->right = new Node(input);
        } else {
            insert(root->right, input);
        }
    }
}


//------------------------------------------------------------------------------------------------------------


int main()
{

    Node* root = new Node(13);


    insert(root, 16);
    insert(root, 14);
    insert(root, 21);
    insert(root, 24);
    insert(root, 65);
    insert(root, 26);
    insert(root, 32);
    insert(root, 31);
    insert(root, 19);
    insert(root, 68);

    printTreeSideways(root);
    // TraverselInOrder(root);
    
}