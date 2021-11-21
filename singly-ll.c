#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;  
}*head,*temp,*tail,*t,*prev;
void create(int);
void display();
void insert_beg();
void insert_middle(int);
void insert_end();
void delete_beg();
void delete_middle();
void delete_end();
int main()
{
 
    int n,choice,num;
    printf("press 1 or 0");
   scanf("%d",&num);
  
    
printf("enter how many nodes you want to create");
 scanf("%d",&n);
create(n);
do
{
    
    printf("press 1 for  insertion at beginning press 2 for  insertion at middle press 3 for  insertion at end 4 for deletion at beggining 5 for deletion at middle 6 for deletion at end");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            insert_beg();
            display();
        }
        case 2:
        {
            printf("enter the element after which you wanna insert");
            int m;
            scanf("%d",&m);
            insert_middle(m);
            display();
            break;
            
        }
        case 3:
        {
            insert_end();
            display();
            break;
        }
        case 4:
        {
            delete_beg();
            display();
            break;
        }
        case 5:
        {
            delete_middle();
            display();
            break;
        }
        case 6:
        {
            delete_end();
            display();
            break;
        }
        case 7:
        {
            exit(0);
            break;
        }
        
   }
   printf("press 1 or 0");
   scanf("%d",&num);
}while(num);

}
void create(int n)
{
	int i;
    
    for(i=1;i<=n;i++)
    {
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data %d\n",i);
     scanf("%d",&temp->data);
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
    int i=0;
    temp=head;
    while(temp!=NULL)
    {
         printf("the data of %d node is\n",i+1);
        printf("%d\n",temp->data);
        temp=temp->next;
        i++;
    }
    temp->next=NULL;
}
void insert_beg()
{
 temp=(struct node*)malloc(sizeof(struct node));
 printf("enter the data to insert at beginning");
 scanf("%d",&temp->data);
 temp->next=NULL;
  if(head==NULL) 
  {
   head=temp;   
  }
  else
  {
     temp->next=head;
      head=temp;
  }
  display();
}
void insert_middle(int m)
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data which you want to insert");
    scanf("%d",&temp->data);
    temp->next=NULL;
   
        prev=head;
        while(prev->data!=m)
        {
         prev=prev->next;            
        }
        temp->next=prev->next;
        prev->next=temp;
        
    
}
void insert_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data added at end");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        tail->next=temp;
        temp=tail;
    }
}
void delete_beg()
{
    if(head->next==NULL)
    {
        printf("empty list");
    }
    else if(head->next==NULL)
    {
        free(head);
        printf("deleted");
    }
    else
    {
        t=head;
        head=head->next;
        free(t);
        display();
        
    }
    
}
void delete_middle()
{
    printf("enter the data you want to delete");
    int thisdata;
    scanf("%d",&thisdata);
    temp=head;
    t=head;

    while(temp->data!=thisdata)
    {
         
        t=temp;
        temp=temp->next;
        
    }
    t->next=temp->next;
    free(temp);
    display();
}
void delete_end()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else if(head->next==NULL)
    {
       free(head); 
    }
    else
    {
        temp=head;
        t=head;
        while(temp->next!=NULL)
        {
            t=temp;
            temp=temp->next;
        }
        free(temp);
        t->next=NULL;
        temp=NULL;
        
    }
}
// press 1 or 01
// enter how many nodes you want to create5
// enter the data 1
// 1
// enter the data 2
// 2
// enter the data 3
// 3
// enter the data 4
// 4
// enter the data 5
// 5
// press 1 for  insertion at beginning press 2 for  insertion at middle press 3 for  insertion at end 4 for deletion at beggining 5 for deletion at middle 6 for deletion at end1
// enter the data to insert at beginning7
// the data of 1 node is
// 7
// the data of 2 node is
// 1
// the data of 3 node is
// 2
// the data of 4 node is
// 3
// the data of 5 node is
// 4
// the data of 6 node is
// 5