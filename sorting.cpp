#include <iostream>
#include <array>
#include <vector>

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Print array
void printArray(int* arr, int l){
    for(int i = 0; i < l; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//-------------------------------------------------------------------------------------------------------------------------------------------//

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

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Bubblesort
void bubblesort(int* arr, int l){
    for(int i = 0; i < l; i++){
        bool swapped = false;
        for(int j = 0; j < l - i - 1; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);    // Swap the elements
                swapped = true;
            }
        }
        if(!swapped){
            return;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Merge function to merge two halves
void merge(int* arr, int* left, int* right, int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// Merge sort
void mergeSort(int* arr, int l){
    if(l < 2){      // If the length of the array is less than 2 return
        return;
    }

    int mid = l / 2;        // Find the middle of the array
    int* left = new int[mid];       // Create a new array for the left side
    int* right = new int[l - mid];    // Create a new array for the right

    for(int i = 0; i < mid; i++){       // Fill the left array with the left side of the array
        left[i] = arr[i];
    }

    for(int i = mid; i < l; i++){       // Fill the right array with the right side of the array
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);       // Recursively call mergeSort on the left side
    mergeSort(right, l - mid);    // Recursively call mergeSort on the right side

    merge(arr, left, right, mid, l - mid);  // Merge the left and right side

    delete[] left;      // Delete the left and right array
    delete[] right;
}

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Heapify
void heapify(int* arr, int n, int i){

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heapsort
void heapSort(int* arr, int n){

    // Build heap (rearrange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        std::swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------//

// Insertionsort
void insertionSort(int* arr, int left, int right){
    for(int i = left + 1; i <= right; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}



//-------------------------------------------------------------------------------------------------------------------------------------------//

// void quickSort(int* arr, int left, int right){
//     if(left + CUTOFF < right){
//         int pivot = std::median3(arr, left, right);
//         int i = left, j = right - 1;
//         for(;;){
//             while(arr[i] < pivot){i++};
//             while(arr[i] > pivot){j--};
//             if(i < j){
//                 std::swap(arr, i, j);
//             }
//             else{break};
//         }
//         std::swap(arr, i, right - 1);

//         quickSort(arr, left, i - 1);
//         quickSort(arr, i + 1, right);
//     }
//     else{
//         insertionSort(arr, left, right);
//     }
// }

//-------------------------------------------------------------------------------------------------------------------------------------------//




int main(){
    int arr[] = {78, 63, 61, 45, 25, 11};

    printArray(arr, 6);

    // std::cout << inversion(arr, 6) << std::endl;

    // bubblesort(arr, 6);
    // mergeSort(arr, 6);
    // heapSort(arr, 6);
    insertionSort(arr, 0, 5);



    printArray(arr, 6);

}