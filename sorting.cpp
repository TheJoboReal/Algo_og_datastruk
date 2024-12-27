#include <iostream>
#include <array>
#include <vector>


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


// Inversion of integers
int inversion(int* arr, int l){
    int inversion = 0;  // Initialize inversion counter
    for(int i = 0; i < l; i++){     // Loop through the array
        for(int k = i + 1; k < l; k++){     // Loop through the array again
            if(arr[i] > arr[k]){        // If the first element is greater than the second element increment the inversion counter
                inversion++;
            }
        }
    }
    return inversion;
}

int main(){
    int arr[] = {34, 8, 64, 51, 32, 21};

    std::cout << inversion(arr, 6) << std::endl;
}