#include<stdio.h>
#include<stdlib.h>
int queue[5];
int font=-1,rear=-1;
void enqueue()
{
    if (font==-1&&rear==-1)
    {
       font=rear=0;
        printf("Enter the first value for the queue\n");
        scanf("%d",&queue[rear]);
    }
    else if(rear==4)
    {
        printf("OVERFLOW OF QUEUE\n");
    }
    else{
        rear++;
        printf("Enter the value for the queue at %d position\n",rear+1);
        scanf("%d",&queue[rear]);
    }
    
}
void dequeue()
{
    if (rear==-1&&font==-1)
    {
        printf("UNDERFLOW OF QUEUE\n");
    }
    else if (rear==font)
    {
        printf("%d is dequeued from the queue\n",queue[rear]);
        font=rear=-1;
    }
    else
    {
        printf("%d is dequeued from the list\n",queue[font]);
        font++;
    }
}
void display()
{
    if (rear==-1&&font==-1)
    {
        printf("QUEUE IS EMPTY\n");
    }
    else if (rear==0&&font==0)
    {
        printf("There is only one value in the QUEUE which is %d\n",queue[rear]);
    }
    else
    {
        for (int i = font; i<=rear; i++)
        {
            printf("Data at %d position is %d\n",(i+1),queue[i]);
        }
        
    }
}
void peek()
{
    if (rear==-1&&font==-1)
    {
        printf("QUEUE is empty\n");
    }
    else{
    printf("Data at peek position is %d\n",queue[rear]);
    }
}
void isempty()
{
    if (rear==-1&&font==-1)
    {
        printf("QUEUE is empty\n");
    }
    // else if ()
    // {
    //     /* code */
    // }
    else{
        printf("NO QUEUE is not empty\n");
    }
}
void isfull()
{
    if (rear==4)
    {
        printf("QUEUE is full\n");
    }
    else{
        printf("No QUEUE is not full\n");
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
        printf("6.ISFULL\n");
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
            case 6:
            isfull();
            break;
        default:printf("SORRY! INVALID CHOICE\n");
            break;
        }
        printf("IF You Want To Continue Please Enter [Y,y]\n");
        fflush(stdin);
        scanf("%c",&choice);
    } while (choice=='y'||choice=='Y');
    return 0;
}