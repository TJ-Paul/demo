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


// COMPARE LINKED LISTS
int compare(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 && temp2){
        if(temp1->data != temp2->data){
            return 0;   // different elements
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return !(temp1 || temp2); // same elements
    
    // another way:
    // return (temp1 == nullptr && temp2 == nullptr);
}   



int main()
{
    // linked List 1: {1,2,3,4,5}
    Node* head1 = new Node(1);
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 4);
    insert(head1, 5);
    
    // Linked List 2: {1,2,3,4,5,6}
    Node* head2 = new Node(1);
    insert(head2, 2);
    insert(head2, 3);
    insert(head2, 4);
    insert(head2, 5);
    insert(head2, 6);


    display(head1);
    display(head2);

    cout << compare(head1, head2);
}