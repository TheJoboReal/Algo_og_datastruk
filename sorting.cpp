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

// Minsortering, som også fungere som bucketsort
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
    while (i < leftSize && j < rightSize) {     // Loop through the left and right array and merge them
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {          // If there are any elements left in the left array add them to the array
        arr[k++] = left[i++];
    }
    while (j < rightSize) {         // If there are any elements left in the right array add them to the array
       
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
    for(int i = left + 1; i <= right; i++){         // Loop through the array starting from the second element
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp){          // Loop through the array and swap the elements if they are greater than the temp variable
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------//

// Quick sorting

int partition(int* arr, int l, int r){
    int pivot = arr[r];     // Set the pivot to the last element
    int i = l - 1;

    for(int j = l; j < r; j++){     // Loop through the array and swap the elements if they are less than the pivot
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[r]);      // Swap the pivot with the element at the index i + 1 (the element that is greater than the pivot)
    return i + 1;
}


void quickSort(int* arr, int l, int r){
    if(l < r){
        int pi = partition(arr, l, r);      // Partition the array into two halves
        quickSort(arr, l, pi - 1);      // Recursively call quickSort on the left side
        quickSort(arr, pi + 1, r);      // Recursively call quickSort on the right side
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------//




int main(){
    int arr[] = {78, 63, 61, 45, 25, 11};

    printArray(arr, 6);

    // std::cout << inversion(arr, 6) << std::endl;

    // bubblesort(arr, 6);
    // mergeSort(arr, 6);
    heapSort(arr, 6);
    // insertionSort(arr, 0, 5);
    // quickSort(arr, 0, 5);



    printArray(arr, 6);

}