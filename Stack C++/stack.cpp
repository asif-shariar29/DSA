#include<iostream>
using namespace std;
#define n 100

class stack {
    int* arr;
    int top;

    public:
    stack () {
        arr = new int[n];
        top = -1;
    }

    void push (int x) {
        if (top == n-1) {
            cout<<"OVERFLOW"<<endl;
            return;
        }
        top++;
        arr[top] = x;
        cout<<"pushed "<<x<<" to stack"<<endl;
    }
    void pop () {
        if (top == -1) {
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        cout<<"poped "<<arr[top]<<" from stack"<<endl;
        top--;
    }
    int TOP () {
          if (top == -1) {
            cout<<"NO ELEMENT"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    void print () {
        if (top == -1) {
            cout<<"Stack is empty"<<endl;
            return;
        }
            for (int i = top; i >= 0; i--) {
                cout<<arr[i]<<endl;
            }
            cout<<endl;
    }

};

int main() {

stack obj;
int choice, value;
while (true) {
    cout<<"Choose any option: "<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Top"<<endl;
    cout<<"4.Empty"<<endl;
    cout<<"5.Print"<<endl;
    cout<<"6.Exit"<<endl;
    cin>>choice;
    cout<<endl;

    switch(choice) {
        case 1:
        cout<<"Enter a value to push into stack: ";
        cin>>value;
        obj.push(value);
        break;
        case 2:
        obj.pop();
        break;
        case 3:
        cout<<"Top element: "<<obj.TOP()<<endl;
        break;
        case 4:
        if (obj.empty()) {
            cout<<"Empty stack"<<endl;
        }
        else {
            cout<<"Not Empty"<<endl;
        }
        break;
        case 5:
        obj.print();
        break;
        case 6:
        EXIT_FAILURE;
        break;
        default:
        cout<<"INVALID CHOICE"<<endl;
    }
}

}