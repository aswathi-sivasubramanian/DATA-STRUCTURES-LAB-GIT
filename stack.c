#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}*top,*temp;
void push();
void pop();
void display();
int main()
{
    int choice;
    printf("here is the push, pop and display operations");
    while(1)
    {
        printf("\nEnter\n1.push\n2.pop\n3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                exit (0);
            }
           
        }
    }    
    
}
void push()
{
    int n,i;
    printf("enter how many datas youwant to push ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data to push");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(top==NULL)
        {
            top=temp;
        }
        else
        {
            temp->next=top;
            top=temp;
        }
        display();
    }
}
void pop()
{
    int n,i;
    printf("enter how many datas you want to pop");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(top==NULL)
        {
            printf("the Stack is empty");
            return;
        }
        else
        {
            temp=top;
            printf("%d\n",top->data);
            top=top->next;
            temp->next=NULL;
            free(temp);
        }
    }
    printf("the elements are....");
    display();
}
void display()
{
    temp=top;
    while(temp!=NULL)
    {
    
    printf("%d",temp->data);
    temp=temp->next;
    }
}
// here is the push, pop and display operations
// Enter
// 1.push
// 2.pop
// 3.exit
// 1
// enter how many datas youwant to push 4
// enter the data to push1
// 1enter the data to push2
// 21enter the data to push3
// 321enter the data to push4
// 4321
// Enter
// 1.push
// 2.pop
// 3.exit
// 2
// enter how many datas you want to pop3
// 4
// 3
// 2
// the elements are....1
// Enter
// 1.push
// 2.pop
// 3.exit
// 3