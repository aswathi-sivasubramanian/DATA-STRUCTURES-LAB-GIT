#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[20];
    struct node *next; 
}*head,*tail,*temp,*t;
void create();
void delete_end();
void display();
int main()
{
    
    create();
    display();
    delete_end();
    display();
    return 0;
}
void create()
{
    int n;
    printf("enter the number of nodes ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data at node %d\n",i);
        char a[20];
        scanf("%s",a);
        strcpy(temp->data,a);
        
        temp->next=NULL;
        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    }
void display()
{
    int i=1;
    temp=head;
    while(temp!=NULL)
    {
        
        printf("the data at node %d\t is%s\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}
void delete_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        printf("no element found");
printf("after deletion........the elements are....\t");
    }
    else if(head->next==NULL)
    {
        free(head);
        printf("after deletion........the elements are....\t");
    }
    else
    {
        t=head;
        temp=head;
       while(temp->next!=NULL)
       {
         t=temp;
         temp=temp->next;
       }
       t->next=NULL;
       free(temp);
       
       printf("after deletion........the elements are....\t");
    }
}

// enter the number of nodes 5
// enter the data at node 1
// a
// enter the data at node 2
// s
// enter the data at node 3
// w
// enter the data at node 4
// a
// enter the data at node 5
// t
// the data at node 1       isa
// the data at node 2       iss
// the data at node 3       isw
// the data at node 4       isa
// the data at node 5       ist
// after deletion........the elements are....      the data at node 1         isa
// the data at node 2       iss
// the data at node 3       isw
// the data at node 4       isa









