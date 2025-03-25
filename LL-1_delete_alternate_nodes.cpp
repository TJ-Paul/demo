/*
delete alternate nodes of a Linked List

input   : 1,2,3,4,5,6,7,8,9,10;
output  : 1,3,5,7,9;

time complexity: O(n)
*/

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

void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data << " -> ";
        temp = temp->next;
    }cout<< "NULL" << endl;
}

void atEnd(Node* &head, int val){
    Node* temp = head;
    Node* new_node = new Node(val);
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

// method 1:
void deleteAlternate1(Node* &head, int pos){
    Node* temp = head;
    Node* prev = nullptr;
    Node* curr = nullptr;

    while(temp != nullptr){
        display(head);

        prev = temp;
        curr = prev->next;
        prev->next = curr->next;
        free(curr);

        temp = temp->next;
    }
}

// method 2:
void deleteAlternate2(Node* &head, int pos){
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(deleteNode);
    }
}

int main()
{
    Node* head = new Node(1);
    atEnd(head, 2);
    atEnd(head, 3);
    atEnd(head, 4);
    atEnd(head, 5);
    atEnd(head, 6);
    atEnd(head, 7);
    atEnd(head, 8);
    atEnd(head, 9);
    atEnd(head, 10);

    cout<< "raw" << endl;
    display(head);

    cout<<"after deletion" << endl;

    // deleteAlternate1(head, 2);
    deleteAlternate2(head, 2);
    
    display(head);
}