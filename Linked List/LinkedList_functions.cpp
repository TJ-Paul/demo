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
        cout<< temp->data << "-> ";
        temp=temp->next;
    } cout << "NULL";
}

void addAtStart(Node* &head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void addAtEnd(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
}

void addAtMiddle(Node* &head, int val, int pos){
    Node* new_node = new Node(val);
    Node* temp = head;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void DeleteAtStart(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void DeleteMiddle(Node* &head, int pos){
    if(pos == 1){
        DeleteAtStart(head);
        return;
    }

    Node* prev = head;
    Node* curr = nullptr;

    int i = 1;
    while(i < pos-1){
        i++;
        prev = prev->next;
    }
    // prev = (pos - 1)th element
    curr = prev->next;
    prev->next = curr->next;
    free(curr);
}

int main()
{
    Node* head = nullptr;
    Node* new_node = nullptr;
    Node* temp = nullptr;

    int x;
    int choice = 1;
    
    while(choice){
        cout << "enter data: ";
        cin>>x;
        Node* new_node = new Node(x);

        if(head == nullptr){
            head = temp = new_node;
        }
        else{
            temp->next = new_node;
            temp = new_node;
        }

        cout << "more? (0/1) : ";
        cin >> choice; 
    } cout<< endl;

    cout<< "raw" << endl;
    display(head);
    cout << endl << endl;
    
    cout<< "at start" << endl;
    addAtStart(head, 5);
    display(head);
    cout << endl << endl;
    
    cout<< "at end" << endl;
    addAtEnd(head, 11);
    display(head);
    cout << endl << endl;

    cout<< "in middle"<< endl;
    addAtMiddle(head, 555, 3);
    display(head);
    cout << endl << endl;

    cout<< "delete at start" << endl;
    DeleteAtStart(head);
    display(head);
    cout << endl << endl;

    cout<< "delete middle" << endl;
    DeleteMiddle(head,2);
    display(head);
    cout << endl << endl;
}