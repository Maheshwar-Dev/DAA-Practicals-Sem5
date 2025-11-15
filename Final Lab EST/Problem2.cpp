// Problem 2 : Implement Stack Using Linked List

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
public:
    Node* head;

    Stack() {
        head = NULL;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl; 
    st.pop();
    cout << st.top() << endl;

    return 0;
}
