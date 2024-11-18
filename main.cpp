#include <iostream>

int sum(int n){
    // Returns all the first n natural numbers
    return n*(n+1)/2;
}

int main(){
    std::cout << sum(10) << std::endl;
}
