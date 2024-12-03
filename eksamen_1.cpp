#include <iostream>
#include <vector>
#include <array>

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

bool sumAfToLigParameter(int arraylength, int l, int X){
    std::array<int, 100> arr = {0};

}


int main(){
    std::cout << sumDeleligMedTreOgOtte(26) << std::endl;
}