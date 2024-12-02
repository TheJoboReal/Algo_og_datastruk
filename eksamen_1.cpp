#include <iostream>
#include <vector>

// Opgave 2

int sumDeleligMedTreOgOtte(int N){
    int sum = 0;

    if(N == 0){
        return 0;
    }

    if(N % 3 == 0 | N % 8  == 0){
        sum += N;
    }

    return sum + sumDeleligMedTreOgOtte(N - 1);
}

// 


int main(){
    std::cout << sumDeleligMedTreOgOtte(26) << std::endl;
}