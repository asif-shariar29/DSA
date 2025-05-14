#include<iostream>
using namespace std;
#define n 20

class queue {
    int* arr;
    int front = -1;
    int back = -1;

    public:
    queue () {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void enqueue (int x) {
        if (back == n-1) {
            cout<<"Overflow";
            return;
        }
        back++;
        arr[back] = x;
        cout<<"Enqueue "<<x<<" to queue"<<endl;
        if (front == -1) {
            front++;
        }
    }
   void  dequeue () {
        if (front == -1 || front > back) {
            cout<<"Underflow";
            return;
        }
        cout<<"Dequeue "<<arr[front]<<" from queue"<<endl;
        front++;

    }
    int peek () {
         if (front == -1 || front > back) {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() {
          if (front == -1 || front > back) {
           return true;
        }
        return false;
    }

    void print () {
        if (empty()) {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue Element: ";
        for (int i = front; i <= back; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

 
};

int main () {
        queue obj;
        int choice,value;
         while (true) {
            cout<<"Choose any option: "<<endl;
            cout<<"1.Enqueue"<<endl;
            cout<<"2.Dequeue"<<endl;
            cout<<"3.Peek"<<endl;
            cout<<"4.Print"<<endl;
            cout<<"5.Empty"<<endl;
            cout<<"6.Exit"<<endl;
            cin>>choice;

            switch (choice) {
                case 1:
                cout<<"Enter a value to enqueue: "<<endl;
                cin>>value;
                obj.enqueue(value);
                break;
                case 2:
                obj.dequeue();
                break;
                case 3:
                cout<<"Peek value: "<<obj.peek()<<endl;
                break;
                case 4:
                obj.print();
                break;
                case 5:
                if (obj.empty()) {
                    cout<<"Empty Queue"<<endl;
                }
                else {
                    cout<<"Not Empty"<<endl;
                }
                break;
                case 6:
                EXIT_FAILURE;
                default:
                cout<<"INVALID CHOICE"<<endl;
            }
         }

}