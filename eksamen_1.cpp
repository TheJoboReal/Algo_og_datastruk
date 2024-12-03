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


// Opgave 1 i reeksamen
bool sumAfToLigParameter(int* arr, int l, int X){
    arr = new int[l];
    // Create variable length array

    for(int i = 0; i < l; i++){
        for(int k = 0; k < l; k++){
            if(k != i){
                if(k + i == X){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    std::cout << sumAfToLigParameter(arr.data(), 5, 4) << std::endl;
}