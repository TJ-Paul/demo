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
    while(temp!=nullptr){
        cout<< temp->data << "-> ";
        temp = temp->next;
    }cout << "NULL" << endl;
}

void insert(Node* head, int x){
    Node* temp = head;
    Node* new_node = new Node(x);
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

int findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        cout << "omg";
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node* head = new Node(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "middle = " << findMiddle(head) << endl;


    display(head);
}