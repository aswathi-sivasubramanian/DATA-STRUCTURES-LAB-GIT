#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head,*tail,*temp;
void create();
void insert_beg(int);
void display();
int main()
{
    
    int n,remain;
    printf("enter the number");
    scanf("%d",&n);
    while(n!=0)
    {
        remain=n%10;
        printf("%d\n",remain);
        insert_beg(remain);
        n=n/10;
        
    }

    display();
    return 0;
}

void display()
{
    int i=1;
    temp=head;
    while(temp!=NULL)
    {
        printf("the data at node %d\t is%d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
void insert_beg(int remain)
{
    temp=(struct node*)malloc(sizeof(struct node));
    
    temp->data=remain;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }                                   
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
// enter the number532
// 2
// 3
// 5
// the data at node 1       is5
// the data at node 2       is3
// the data at node 3       is2







