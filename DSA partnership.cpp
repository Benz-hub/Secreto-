#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to display the heap
void displayHeap(const vector<int>& heap, const string& heapType) {
    if (heap.empty()) { // If the heap is empty, display a message
        cout << "\nThe " << heapType << " is empty!\n";
        return;
    }
    cout << "\n" << heapType << ": "; // Print the type of heap
    for (int value : heap) { // Loop through and print each element
        cout << value << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    vector<int> heap; // Vector to store the heap elements
    int choice, power, count; // Variables for menu choice, creature power level, and count of creatures

    cout << "Welcome to the Enchanted Menagerie Challenge!\n";
    cout << "Organize magical creatures based on their power levels using heaps.\n";

    while (true) { // Keep showing the menu until the user exits
        cout << "\nMenu:\n";
        cout << "1. Add multiple magical creatures\n";
        cout << "2. Display current heap\n";
        cout << "3. Convert to Min-Heap\n";
        cout << "4. Convert to Max-Heap\n";
        cout << "5. Exit\n" << "\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get the user's menu choice

        switch (choice) {
            case 1: { // Add multiple creatures to the heap
                cout << "How many creatures would you like to add? ";
                cin >> count; // Get the number of creatures to add

                for (int i = 1; i <= count; ++i) { // Loop to add each creature
                    cout << "Enter the power level of creature " << i << ": ";
                    cin >> power; // Get the power level of the creature
                    heap.push_back(power); // Add the power level to the heap
                    push_heap(heap.begin(), heap.end()); // Maintain the heap property
                }
                cout << "All creatures added successfully!\n";
                break;
            }

            case 2: // Display the current state of the heap
                displayHeap(heap, "Current Heap");
                break;

            case 3: { // Convert the heap into a Min-Heap
                sort(heap.begin(), heap.end()); // Sort the heap into ascending order
                displayHeap(heap, "Min-Heap"); // Display the Min-Heap
                break;
            }

            case 4: { // Convert the heap into a Max-Heap
                make_heap(heap.begin(), heap.end()); // Rearrange to satisfy Max-Heap property
                displayHeap(heap, "Max-Heap"); // Display the Max-Heap
                break;
            }

            case 5: // Exit the program
                cout << "Thank you for managing the Enchanted Menagerie!\n";
                return 0; // Exit the program

            default: // Handle invalid menu choices
                cout << "Invalid choice! Please try again.\n";
        }
    }
}