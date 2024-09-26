#include <iostream>

using namespace std;

// Class definition for the Stack data structure
class Stack {
    int* storage;
    int currentIndex;
    int maxSize;

public:
    Stack(int size) {
        storage = new int[size];
        maxSize = size;
        currentIndex = -1;
    }

    ~Stack() {
        delete[] storage;
    }

    // Method to insert an element onto the stack
    void insert(int element) {
        if (isAtCapacity()) {
            cout << "Stack Overflow: Unable to insert " << element << endl;
            return;
        }
        storage[++currentIndex] = element;
    }

    // Method to remove the top element from the stack
    int remove() {
        if (isEmpty()) {
            cout << "Stack Underflow: Unable to remove" << endl;
            return -1; // Return a special value to indicate error
        }
        return storage[currentIndex--];
    }

    // Method to output the contents of the stack
    void outputStack() const {
        if (isEmpty()) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= currentIndex; i++) {
                cout << storage[i] << " ";
            }
        }
        cout << endl;
    }

private:
    // Method to check if the stack has reached its maximum capacity
    bool isAtCapacity() const {
        return currentIndex == maxSize - 1;
    }

    // Method to check if the stack has no elements
    bool isEmpty() const {
        return currentIndex == -1;
    }
};

// Stacks representing the three towers
Stack* towerA;
Stack* towerB;
Stack* towerC;

// Method to display the contents of all three towers
void showAllTowers() {
    cout << "Tower A: ";
    towerA->outputStack();
    cout << "Tower B: ";
    towerB->outputStack();
    cout << "Tower C: ";
    towerC->outputStack();
    cout << "\n";
}

// Recursive method to move disks between towers
void moveDisks(int count, Stack& startTower, Stack& endTower, Stack& helperTower, char fromTower, char toTower, char helpTower) {
    if (count == 1) {
        // Move a single disk from the starting tower to the destination tower
        int disk = startTower.remove();
        endTower.insert(disk);
        cout << "Move disk " << disk << " from " << fromTower << " to " << toTower << endl;
        showAllTowers();
        return;
    }

    // Recursively move (count-1) disks from the start tower to the helper tower
    moveDisks(count - 1, startTower, helperTower, endTower, fromTower, helpTower, toTower);
    
    // Move the nth disk from the starting tower to the destination tower
    int disk = startTower.remove();
    endTower.insert(disk);
    cout << "Move disk " << disk << " from " << fromTower << " to " << toTower << endl;
    showAllTowers();

    // Recursively move (count-1) disks from the helper tower to the destination tower
    moveDisks(count - 1, helperTower, endTower, startTower, helpTower, toTower, fromTower);
}

int main() {
    int diskCount;
    //cout << "Enter the number of disks: ";
    cin >> diskCount;

    if (cin.fail() || diskCount <= 0) {
        cout << "Invalid Input" << endl;
        return 1;
    } else {

      towerA = new Stack(diskCount);
      towerB = new Stack(diskCount);
      towerC = new Stack(diskCount);

      for (int i = diskCount; i >= 1; i--) {
        towerA->insert(i);
      }

      showAllTowers();

      moveDisks(diskCount, *towerA, *towerC, *towerB, 'A', 'C', 'B');

      delete towerA;
      delete towerB;
      delete towerC;

     return 0;
    }
}
