#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
	
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

void sort() {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

void main() {
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 

   printf("Original List: "); 
	
   //print list
   printList();

   while(!isEmpty()) {            
      struct node *temp = deleteFirst();
      printf("\nDeleted value:");
      printf("(%d,%d) ",temp->key,temp->data);
   }  
	
   printf("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   printf("\nRestored List: ");
   printList();
   printf("\n");  

   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");  
   } else {
      printf("Element not found.");
   }

   delete(4);
   printf("List after deleting an item: ");
   printList();
   printf("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      printf("Element found: ");
      printf("(%d,%d) ",foundLink->key,foundLink->data);
      printf("\n");
   } else {
      printf("Element not found.");
   }
	
   printf("\n");
   sort();
	
   printf("List after sorting the data: ");
   printList();
	
   reverse(&head);
   printf("\nList after reversing the data: ");
   printList();
}




#include<stdio.h>
#include<conio.h>
#include<process.h>
 
struct node
{
    int data;
    struct node *next;
}*start=NULL,*q,*t;
 
int main()
{
    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();
 
    while(1)
    {
        printf("\n\n---- Singly Linked List(SLL) Menu ----");
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Exit\n\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&ch);
 
        switch(ch)
        {
            case 1:
                    printf("\n---- Insert Menu ----");
                    printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: insert_beg();
                                break;
                        case 2: insert_end();
                                break;
                        case 3: insert_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
 
            case 2: display();
                    break;
 
            case 3: printf("\n---- Delete Menu ----");
                    printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified position\n4.Exit");
                    printf("\n\nEnter your choice(1-4):");
                    scanf("%d",&ch);
 
                    switch(ch)
                    {
                        case 1: delete_beg();
                                break;
                        case 2: delete_end();
                                break;
                        case 3: delete_pos();
                                break;
                        case 4: exit(0);
                        default: printf("Wrong Choice!!");
                    }
                    break;
            case 4: exit(0);
                    default: printf("Wrong Choice!!");
        }
    }
    return 0;
}
 
void insert_beg()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
 
    if(start==NULL)        //If list is empty
    {
        t->next=NULL;
        start=t;
    }
    else
    {
        t->next=start;
        start=t;
    }
}
 
void insert_end()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
 
    if(start==NULL)        //If list is empty
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}
 
int insert_pos()
{
    int pos,i,num;
    if(start==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    t->data=num;
 
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
 
        q=q->next;
    }
 
    t->next=q->next;
    q->next=t;
    return 0;
}
 
void display()
{
    if(start==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}
 
void delete_beg()
{
    if(start==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=start;
        start=start->next;
        printf("Deleted element is %d",q->data);
        free(q);
    }
}
 
void delete_end()
{
    if(start==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=start;
        while(q->next->next!=NULL)
        q=q->next;
 
        t=q->next;
        q->next=NULL;
        printf("Deleted element is %d",t->data);
        free(t);
    }
}
 
int delete_pos()
{
    int pos,i;
 
    if(start==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    printf("Enter position to delete:");
    scanf("%d",&pos);
 
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
        q=q->next;
    }
 
    t=q->next;
    q->next=t->next;
    printf("Deleted element is %d",t->data);
    free(t);
 
    return 0;
}