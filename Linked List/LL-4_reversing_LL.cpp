#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};


// DISPLAY:
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<< temp->data << "-> ";
        temp = temp->next;
    }cout << "NULL" << endl;
}


// INSERT ELEMENTS:
void insert(Node* head, int x){
    Node* temp = head;
    Node* new_node = new Node(x);
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void reverse(Node* &head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


int main()
{
    // linked List: {1,2,3,4,5}
    Node* head = new Node(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    
    cout << "original: ";
    display(head);
    cout<< "Reversed: ";
    reverse(head);
    display(head);
}


/*
MY TRY :)

// REVERSE
void reverse(Node* &head){
    Node* prev = head;
    Node* curr = prev->next;
    Node* next = curr->next;

    while(curr){
        curr->next = prev;
        if(prev == head) prev->next = nullptr;
        prev = curr;
        curr = next;
        if(next != nullptr) next = next->next;
    }
    display(prev);
    cout << curr->next->data;
}

*/