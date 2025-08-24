#include <iostream>

const int maxSize = 5;

using namespace std;

class Stack {
private:
    int arr[maxSize];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "StackOverflow Occured!!\n";
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop() {
        if (isEmpty()) {
           cout << "StackUnderflow Occured!!\n";
           return;
        }

        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout <<  "Stack Is Empty!!\n";
            return -1;
        }

        return arr[top];
    }

    int size() {
        return top + 1;
    }
};

int main()
{
    Stack myStack;

    myStack.push(100);
    myStack.push(200);
    myStack.push(300);

    myStack.pop();

    cout << "Stack (Empty) : " << ((myStack.isEmpty()) ? " True\n" : " False\n");
    cout << "Stack (Full) : " << ((myStack.isFull()) ? " True\n" : " False\n");
    cout << "Stack (Top) : " << myStack.peek() << '\n';
    cout << "Stack (Size) : " << myStack.size() << "\n";

}
