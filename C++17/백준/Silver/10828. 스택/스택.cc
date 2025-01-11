#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node* prevNode;
    T value;

public:
    Node(T v) : value(v), prevNode(nullptr) {};
};

template <typename T>
class MyStack
{
    Node<T>* topNode;
    int stackSize = 0;
public:
    MyStack() {
        topNode = nullptr;
    }

    void push(T x) {
        // push X: 정수 X를 스택에 넣는 연산이다.
        Node<T>* newNode = new Node<T>(x);
        newNode->prevNode = topNode;
        topNode = newNode;
        stackSize += 1;
    }

    void pop() {
        // pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
        // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        if (stackSize == 0) {
            cout << "-1\n";
            return;
        }
        cout << topNode->value << "\n";
        Node<T>* nextTopNode = topNode->prevNode;
        delete topNode;
        topNode = nextTopNode;
        stackSize -= 1;
    }

    void size() {
        // size: 스택에 들어있는 정수의 개수를 출력한다.
        cout << stackSize << "\n";
    }

    void empty() {
        // empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
        cout << (stackSize == 0) << "\n";
    }

    void top() {
        // 스택의 가장 위에 있는 정수를 출력한다. 
        // 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
        if (stackSize == 0) {
            cout << "-1\n";
        }
        else {
            cout << topNode->value << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nCommand;
    cin >> nCommand;
    MyStack<int> myStack;
    for (int i = 0; i < nCommand; ++i) {
        string command;
        cin >> command;
        if (command == "push") {
            int n = 0;
            cin >> n;
            myStack.push(n);
        }
        else if (command == "pop") {
            myStack.pop();
        }
        else if (command == "size") {
            myStack.size();
        }
        else if (command == "empty") {
            myStack.empty();
        }
        else if (command == "top") {
            myStack.top();
        }
        else
            cout << "Invalid command entered.\n";
    }
}
