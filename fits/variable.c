#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[20];
    int size;
    struct node* next;
};

int spaceLeft;

struct node* newNode(){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->size = 0;
    new->next = NULL;
    return new;
}

void joinSpace(struct node** head){
    struct node* temp = *head;
    while(temp->next){
        if(strcmp(temp->name,"FREE") && strcmp(temp->next->name,"FREE")){
            temp->size += temp->next->size;
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
}

void display(struct node* head){
    int used = 0;
    printf("\nName\tSize");
    while(head != NULL){
        printf("\n%s\t%d bytes",head->name,head->size);
        if(strcmp(head->name,"FREE") != 0)
            used += head->size;
        head = head->next;
    }
    printf("\nUsed: %d bytes, Free: %d bytes", used, spaceLeft);
}

void deleteFront(struct node** head){
    if(*head == NULL){
        return;
    }
    if((*head)->next == NULL){
        *head = NULL;
        return;
    }
    *head = (*head)->next;
}

void delete(struct node** head, char* name){
    struct node* temp = *head;
    struct node* slow = temp;
    while(temp != NULL){
        if(strcmp(temp->name,name) == 0){
            if(temp == *head){
                if((*head)->next == NULL){
                    spaceLeft += (*head)->size;
                    *head = NULL;
                    printf("\nMemory is now Empty!");
                    return;
                }
            }
            strcpy(temp->name,"FREE");
            joinSpace(head);
            display(*head);
            return; 
        }
        temp = temp->next;
    }
    printf("\nProcess %s is not present in memory!",name);
}


void insert(struct node** head,int size){
    char name[20];
    int n;
    printf("\nEnter process name: ");
    scanf(" %s",name);

    printf("Enter process size: ");
    scanf("%d",&n);

    struct node* new = newNode();
    strcpy(new->name,name);
    new->size = n;

    if(*head == NULL){
        *head = new;
        spaceLeft -= n;
        display(*head);
        return;
    }
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp){
        if(strcmp(temp->name,"FREE") == 0 && temp->size >= new->size){
            if(temp->size == n){
                strcpy(temp->name,name);
                display(*head);
                return;
            }
            else{
                new->next = temp;
                if(prev == NULL){
                    *head = new;
                }
                else{
                    prev->next = new;
                }
                temp->size -= n;
                display(*head);
                return;
            }
        }
        prev = temp;
        temp = temp->next; 
        
    }

    if(n > spaceLeft){
        printf("\nNot enough space available!");
        return;
    }

    temp = *head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = new;
    spaceLeft -= n;
    display(*head);
}


void main(){
    int size,ch;
    char name[20];
    printf("\nEnter Total memory: ");
    scanf("%d",&size);
    spaceLeft = size;
    struct node* head = NULL;
    do{
        printf("\n\n1.Insert Process\n2.Delete Process\n3.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case(1):{
                insert(&head,size);
                break;
            }
            case(2):{
                printf("\nEnter name of process to delete: ");
                scanf("%s",name);
                delete(&head,name);
            }
            case(3):{
                break;
            }
            default:{
                printf("\nInvalid option!");
            }
        }
    }while(ch != 3);

}