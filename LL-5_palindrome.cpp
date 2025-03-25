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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

int palindrome(Node* head){
    
    Node* temp = head;
    Node* middle = findMiddle(head);

    reverse(middle);

    while(middle->next != nullptr){
        if(temp->data != middle->data) return 0;
        temp = temp->next;
        middle = middle->next;
    }

    return 1;
}


int main()
{
    Node* head = new Node(1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    
    display(head);
    cout << palindrome(head) << endl;
}
