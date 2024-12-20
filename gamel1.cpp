#include <iostream>
#include <vector>
#include <array>

struct Node{
    int _data;
    Node* left;
    Node* right;
    Node(int val) : _data(val), left(nullptr), right(nullptr){}
};

// Opg 2
int sumDeleMedTreOgOtte(int N){

    if(N <= 0){
        return 0;
    }

    if(N % 3 == 0 || N % 8 == 0){
        return sumDeleMedTreOgOtte(N - 1) + N;
    }

    return sumDeleMedTreOgOtte(N - 1);
}



int main(){
    std::cout << sumDeleMedTreOgOtte(26) << std::endl;
}