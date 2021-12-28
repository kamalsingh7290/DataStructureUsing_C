#include<stdio.h>
#include<stdlib.h>
struct queuelist
{
    int data;
    struct queuelist *next;
}*rear=NULL,*font=NULL,*head;
int count=0;
void enqueue()
{
    struct queuelist *newnode=(struct queuelist*)malloc(sizeof(struct queuelist*));
    if (newnode==NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    printf("Enter the data for node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
   if (rear==NULL)
   {
       head=font=rear=newnode;
   }
   else{
       rear->next=newnode;
       rear=newnode;
       rear->next=NULL;
   }
    count++;
}
void dequeue()
{
    struct queuelist *del;
    if (rear==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else if (rear==font)
    {
        printf("%d is dequeued from the list\n",rear->data);
        free(rear);
        font=NULL;
    }
    else
    {
        struct  queuelist *del=font;
        printf("%d is dequeued from the list\n",font->data);
        font=font->next;
        free(del);
    }
}
void display()
{
        int c=1;
    if (font==NULL)
    {
        printf("No value in the QUEUE SORRY!\n");
    }
    else if(font!=NULL)
    {
        while (font!=NULL)
        {
            printf("%d is at %d position\n",font->data,c++);
            font=font->next;
        }
    }
}
void peek()
{
    printf("%d is at peek in the stack\n",rear->data);
}
void isempty()
{
    if (font==NULL)
    {
        printf("Yes! QUEUE is empty\n");
    }
    else{
        printf("NO! QUEUE is not empty\n");
    }
}
int main()
{
    int ch;
    char choice;
        printf("\t\t\t\t\t\t\tIMPLEMENTATION OF QUEUE USING ARRAY\n");
    do
    {
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.ISEMPTY\n");
        printf("Enter the choice as per given information\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isempty();
            break;
        default:printf("SORRY! INVALID CHOICE\n");
            break;
        }
        printf("IF You Want To Continue Please Enter [Y,y]\n");
        scanf("\n");
        scanf("%c",&choice);
    } while (choice=='y'||choice=='Y');
    return 0;
}