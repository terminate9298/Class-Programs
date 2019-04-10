#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node *next;
}*start = NULL , *q , *t; 
 
void insert_first()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
 
    if(start==NULL)
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

int insert()
{
    int pos,i,num;
    if(start==NULL)
    {
        insert_beg();
        return 0;
    }
 
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter position to insert:");
    scanf("%d",&pos);
    if(pos==0){
    	insert_beg();
    	return 0;
    }
    printf("Enter data:");
    scanf("%d",&num);
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

int delete()
{
    int pos,i;
 
    if(start==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    printf("Enter position to delete:");
    scanf("%d",&pos);
 	if(pos==0){
 		delete_beg();
 		return 0;
 		}
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("Deleting Last Element\n");
            delete_end();
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
 
void transverse()
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
int reaggrangeoddeven(){
    if(start ==NULL){
        printf("List is empty!!");
        return 0;
    }
    struct node* odd = start;
    struct node* even = start->next;
    struct node* evenf = even; 
    while(1){
        if(!odd || !even || !(even->next))
            break;
        odd->next = even->next;
        odd = even->next;
        if (odd->next == NULL) { 
            even->next = NULL; 
            break; 
        } 
        even->next = odd->next; 
        even = odd->next; 
    }
    struct node* current = evenf; 
    struct node* prev = NULL; 
    struct node* front = NULL; 
    while (current != NULL) { 
        front = current->next; 
        current->next = prev; 
        prev = current; 
        current = front; 
    } 

    evenf = prev; 
    odd->next = evenf; 
}
int main(){
	int n1 = 1;
	for (int i=0;i<20;i++)
		printf("******");
	printf("\n\n \t\tProgram For Implementation of Linked List \n\n");
	for (int i=0;i<20;i++)
		printf("******");
	int choise;
	while(n1){
		printf("\n\tEnter Your Choice\t\n\t 1 -> Insertion \t\n\t 2-> Deletion \t\n\t 3->Transverse \t\n\t 4->Rearrrange Odd and Even \t\n\t 5->Quit \t\n\t Enter your Choice \n\t\t");
		scanf("%d",&choise);
		if(choise==1)
			insert();
		if(choise ==2)
			delete();
		if(choise ==3)
			transverse();
        if(choise==4)
            reaggrangeoddeven();
		if(choise ==5)
			n1=0;
	}
}
