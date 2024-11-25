#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to print the heap as a tree-like structure
void printHeap(const vector<int>& heap) {
    int n = heap.size();
    int level = 0, count = 1;
    cout << "\nCurrent Party:\n";
    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
        if (i == count - 1) {
            cout << endl;
            level++;
            count += (1 << level); // 2^level
        }
    }
    cout << endl;
}

// Function to insert into a Max-Heap
void insertHeap(vector<int>& heap, int value) {
    cout << "Summoning Hero with power level: " << value << " into the Current Party.\n";
    heap.push_back(value);
    int i = heap.size() - 1;
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the root of the Max-Heap
void deleteRoot(vector<int>& heap) {
    if (heap.empty()) {
        cout << "Party is empty! Noone to remove from party.\n";
        return;
    }
    cout << "Hero " << heap[0] << " was sent to battle.\n";
    heap[0] = heap.back();
    heap.pop_back();
    int n = heap.size(), i = 0;
    while (true) {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && heap[left] > heap[largest]) largest = left;
        if (right < n && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        swap(heap[i], heap[largest]);
        i = largest;
    }
    printHeap(heap);
}
// Function to heapify a subtree
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to convert an array into a Max-Heap
void buildHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    cout << "Heapified array: ";
    for (int i : arr) cout << i << " ";
    cout << endl;
    printHeap(arr);
}


// Main function
int main() {
    vector<int> heap;
    int choice, value;

    cout << "Welcome to Isekai Ten'i: Heroes From Another World!\n";
    cout << "In this world your a king who needs heroes from another worlds to this current the world from being overtaken by demons\n";
    while (true) {
        cout << "\nChoose your action:\n";
        cout << "1. Summon a new Hero from another world (Insert)\n";
        cout << "2. Send the Hero with the highest power level to fight (Remove)\n";
        cout << "3. View the current party\n";
        cout << "4. Arrange the Heroes from Strongest to Weakest (Heapify)\n";
        cout << "5. Exit Game\n";
        cout << "Enter your decision: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the Power Level of the Hero to summon: ";
                cin >> value;
                insertHeap(heap, value);
                break;
            case 2:
                deleteRoot(heap);
                break;
            case 3:
                if (heap.empty()) {
                    cout << "Current Party is empty.\n";
                } else {
                    printHeap(heap);
                }
                break;
            case 4:
                if (heap.empty()) {
                    cout << "Party is currently empty.\n";
                } else {
                    printHeap(heap);
                }
                break;
            case 5:
                cout << "Closing the Game. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
