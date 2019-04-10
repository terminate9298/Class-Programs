#include <stdio.h>
#define MAX 6
typedef struct
{
    int front   ;
    int rear    ;
    int count   ;
    int ele[MAX]    ;
}CirQueue;

//for stack
int stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
      printf("Stack Overflow\n");
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
      printf("Stack Underflow\n");
   else {
      printf(" %d\t",stack[top]);
      top--;
   }
}
void initCirQueue(CirQueue * q)
{
    q->front =  0;
    q->rear  = -1;
    q->count =  0;
}
int isFull(CirQueue * q)
{
    int full=0;
     
    if(q->count == MAX)
        full = 1;   
 
    return full;
}
 
/*Check Queue is empty or not*/
int isEmpty(CirQueue * q)
{
    int empty=0;
     
    if(q->count == 0)
        empty = 1;  
 
    return empty;
}
 
/*To insert item into circular queue.*/
void insertCirQueue(CirQueue * q, int item)
{
    if( isFull(q) )
    {
        printf("\nQueue Overflow");
        return;
    }
     
    q->rear = (q->rear+1)%MAX;
    q->ele[q->rear] = item;
     
    q->count++;
  
    //printf("\nInserted item : %d",item);
}
 
/*To delete item from queue.*/
int deleteCirQueue(CirQueue * q, int *item)
{
    if( isEmpty(q) )
    {
        printf("\nQueue Underflow");
        return -1;
    }
 
    *item    = q->ele[q->front];
 
    q->front = (q->front+1)%MAX;
     
    q->count--;
 
    return 0;
}
 
 
int main()
{
    int item=0;
    CirQueue q;
 
    initCirQueue(&q);

int n =MAX ,t2;
while(n--){
    scanf("%d",&t2);
    insertCirQueue(&q , t2);
}
n=MAX;
int t1 =0;
 while(n--){
    if ( deleteCirQueue( &q, &item ) == 0 )
{
        if(item%2==1){
            printf("%d\t",item);
            
    }
        else{
            push(item);
            t1++;
}
}
}
 
while(t1--){
pop();
}
 
    printf("\n");
    return 0;   
}
