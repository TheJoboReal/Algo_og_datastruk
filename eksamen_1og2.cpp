#include <iostream>
#include <vector>
#include <array>

//-------------------------------------------------------------------------------------------------------------------------------------------//

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

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Opgave 1 i reeksamen
bool sumAfToLigParameter(int* arr, int l, int X){
    arr = new int[l];

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

//-------------------------------------------------------------------------------------------------------------------------------------------//


bool isVokal(char k){
    if(k == 'a'| k == 'e'| k == 'i'| k == 'o'| k == 'u'| k == 'y'){
        return true;
    }
    return false;
}

// Opgave 3 i reeksamen
int antalVokaler(std::string str, int l){
    int vokaler = 0;
    if(l < 0){
        return 0;
    }

    if(isVokal(str[l - 1]) == 1){
        vokaler++;
    }

    return vokaler + antalVokaler(str, l - 1);
}

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Opgave 4 i reeksamen
void minSortering(int* arr){
    // Using bucket sort
    int bucket[100] = {0};  
    for(int i = 0; i < 100; i++){
        bucket[arr[i]]++;       // Increment the value in the bucket array
    }
    
    // Print the sorted array
    for(int i = 0; i < 100; i++){
        if(bucket[i] > 0){
            std::cout << i << std::endl;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------//


int main(){
    // std::array<int, 5> arr = {1, 2, 3, 4, 5};
    // std::cout << sumAfToLigParameter(arr.data(), 5, 4) << std::endl;
    // std::string str = "stationsbygninger";
    // std::cout << antalVokaler(str, str.size()) << std::endl;

    // array of 100 random unsorted integers in range 1 to 200
    int arr[100] = {99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73,
        72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42,
        41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    
    
    minSortering(arr);
}