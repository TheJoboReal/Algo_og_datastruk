#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <string>

struct Node{
    int _data;
    Node* left;
    Node* right;
    Node(int val) : _data(val), left(nullptr), right(nullptr){}
};


//------------------------------------------------------------------------------------------------------------------------------------------

// Opgave 1

int countLettersInWord(std::string word, char letter, int index){
    if(index > word.size()){
        return 0;
    }

    if(word[index] == letter){
        return countLettersInWord(word, letter, index + 1) + 1;
    }

    return countLettersInWord(word, letter, index + 1);
}

//------------------------------------------------------------------------------------------------------------------------------------------

// Opgave 4
std::string findRoute(Node* root, int value){
    if(root == nullptr){
        return "";
    }
    std::string path = "";

    if(root->_data == value){
        path.append(":");
        path.append(std::to_string(root->_data));
        return path;
    }

    
    // go through left sub
    path.append(findRoute(root -> left, value));
    if(path[0] == ':'){
        path.append(" ");
        path.append(std::to_string(root->_data));
        return path;
    }


    //go through right sub
    path.append(findRoute(root -> right, value));
    if(path[0] == ':'){
        path.append(" ");
        path.append(std::to_string(root->_data));
        return path;
    }
    return "Node ikke fundet";
}




//------------------------------------------------------------------------------------------------------------------------------------------

// Opgave 


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

    // std::cout << countLettersInWord("banana", 'a', 0) << std::endl;

    std::cout << findRoute(root, 79) << std::endl;
    // std::string test = "";
    // test.append(std::to_string(root->_data));
    // test.append("");
    // test.append("");
    // std::cout << test.size() << std::endl;

    return 0;
}