#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};


int main()
{
    Node* head = NULL;
    Node* temp = NULL;

    int x = 0;
    int choice = 1;

    while(choice){
        cout << "enter data: ";
        cin >> x;
        Node* newNode = new Node(x);

        if(head == NULL){
            head = temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }    
        cout << "enter more? (0/1) : ";
        cin >> choice;
    }
    

    // printing linked list elements:

    temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}