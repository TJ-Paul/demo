#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

int main()
{
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 1;
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return 1; // Exit code
        }

        printf("enter data: ");
        scanf("%d", &newnode->data);
        
        newnode->next = NULL;  
        
        if(head == NULL) head = temp = newnode;
        else{
            temp->next = newnode;
            temp = newnode;
        }
        
        printf("do you want to continue(0/1)?");
        scanf("%d",&choice);
    }

    // printing linked list elemets:

    temp = head;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}