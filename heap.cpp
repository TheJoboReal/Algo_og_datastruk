#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

class Heap{
    private:
        std::vector<int> heap;

        void heapifyUp(int index) {
            while (index > 0 && heap[parent(index)] < heap[index]) {
                std::swap(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }

        void heapifyDown(int index) {
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if (left < heap.size() && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < heap.size() && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                heapifyDown(largest);
            }
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

    public:
        void insert(int key) {
            heap.push_back(key);
            heapifyUp(heap.size() - 1);
        }

        void deleteKey(int key) {
            auto it = std::find(heap.begin(), heap.end(), key);
            if (it != heap.end()) {
                int index = std::distance(heap.begin(), it);
                heap[index] = heap.back();
                heap.pop_back();
                heapifyDown(index);
            }
        }

        void printHeap() {
            for (int i : heap) {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
    };
};