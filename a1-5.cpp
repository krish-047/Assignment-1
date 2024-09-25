#include <iostream>

using namespace std;

// Stack class definition
class Stack {
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow: Unable to push " << x << endl;
            return;
        }
        arr[++top] = x;
    }

    // Function to pop the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Unable to pop" << endl;
            return -1; // Return a sentinel value for error
        }
        return arr[top--];
    }

    // Function to display the elements of the stack
    void display() const {
        if (isEmpty()) {
            cout << "Empty";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

private:
    // Function to check if the stack is full
    bool isFull() const {
        return top == capacity - 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }
};

// Stacks for the towers
Stack* A;
Stack* B;
Stack* C;

// Function to display the contents of the towers
void displayTowers() {
    cout << "Tower A: ";
    A->display();
    cout << "Tower B: ";
    B->display();
    cout << "Tower C: ";
    C->display();
    cout << "\n";
}

// Recursive function to rearrange disks
void rearrangeDisks(int n, Stack& source, Stack& target, Stack& auxiliary, char from, char to, char aux) {
    if (n == 1) {
        // Move the disk from source to target
        int disk = source.pop();
        target.push(disk);
        cout << "Move disk " << disk << " from " << from << " to " << to << endl;
        displayTowers();
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    rearrangeDisks(n - 1, source, auxiliary, target, from, aux, to);
    
    // Move the nth disk from source to target
    int disk = source.pop();
    target.push(disk);
    cout << "Move disk " << disk << " from " << from << " to " << to << endl;
    displayTowers();

    // Move the n-1 disks from auxiliary to target
    rearrangeDisks(n - 1, auxiliary, target, source, aux, to, from);
}

int main() {
    int n;
    //cout << "Enter the number of disks: ";
    cin >> n;

    if (cin.fail() || n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    else
    {

      A = new Stack(n);
      B = new Stack(n);
      C = new Stack(n);

      for (int i = n; i >= 1; i--) {
        A->push(i);
      }

      displayTowers();

      rearrangeDisks(n, *A, *C, *B, 'A', 'C', 'B');

      delete A;
      delete B;
      delete C;

     return 0;
    }
}
