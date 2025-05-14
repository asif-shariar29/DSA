//Singly Linked List -> insertion,deletion,traverse,search.

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int val) {
        this -> data = val;
        this -> next = NULL;
    }
    ~Node () {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }

};

void insertAtHead (Node* &head, int d) {

Node* temp = new Node(d);
temp->next = head;
head = temp;
}
void insertAtTail (Node* &tail, int data) {
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertNode(Node* &tail,Node* &head, int position, int data) {
    if (position == 1) {
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position-1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) {
        insertAtTail(tail,data);
        return;
    }
    Node* insert = new Node(data);
    insert->next = temp->next;
    temp->next = insert;
}

void deleteNode (int position, Node* &head) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else { 
        Node* current = head;
        Node* prev = NULL;
        int count = 1;
        while (count < position) {
            prev = current;
            current = current->next;
            count++;
    }
    prev->next = current->next;
    current->next = NULL;
    delete current;

    }
}

void searchNode (Node* &head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            cout<<"Data Found"<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<"Not Found"<<endl;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main() {

int initialValue;
cout<<"Enter initial value for the first node: ";
cin>>initialValue;
Node* node1 = new Node(initialValue);
Node* head = node1;
Node* tail = node1;
int choice;

do {
    cout<<"Choose an option->"<<endl;
    cout<<"1.Insert at head."<<endl;
    cout<<"2.Insert at tail."<<endl;
    cout<<"3.Insert at any position."<<endl;
    cout<<"4.Delete any node at any position."<<endl;
    cout<<"5.Print."<<endl;
    cout<<"6.Search."<<endl;
    cout<<"7.Exit."<<endl;
    cin>>choice;

    int value, position, key;
    switch(choice) {
        case 1: 
        cout<<"Enter value to insert at head: ";
        cin>>value;
        insertAtHead(head,value);
        break;
        case 2:
        cout<<"Enter value to insert at tail: ";
        cin>>value;
        insertAtTail(tail,value);
        break;
        case 3:
        cout<<"Enter the position to insert: ";
        cin>>position;
        cout<<"Enter the value to insert: ";
        cin>>value;
        insertNode(tail,head,position,value);
        break;
        case 4:
        cout<<"Enter the position to delete: ";
        cin>>position;
        deleteNode(position,head);
        break;
        case 5: 
        print(head);
        cout<<endl;
        break;
        case 6:
        cout<<"Enter a value to search: ";
        cin>>key;
        searchNode(head,key);
        break;
        case 7:
        EXIT_FAILURE;
        default:
        cout<<"INVALID CHOICE."<<endl;
    }
} while (choice != 0);

}