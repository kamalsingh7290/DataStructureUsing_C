#include<stdio.h>
#include<stdlib.h>
int font=-1,rear=-1;
int deque[5];
void enqueuefont()
{
    if (rear==-1&&font==-1)
    {
        rear=font=0;
        printf("Enter the value for the deque\n");
        scanf("%d",&deque[font]);
    }
    else if ((font==0&&rear==4)||(font==rear+1))
    {
        printf("deque is full\n");
    }
    else if (font==0)
    {
        font=4;
        printf("enter the value for the deque\n");
        scanf("%d",&deque[font]);
    }
    else
    {
        font--;
        printf("enter the value for the deque\n");
        scanf("%d",&deque[font]);
    }
}
void enqueuerear()
{
    if (rear==-1&&font==-1)
    {
        font=rear=0;
        printf("enter the value for the deque\n");
        scanf("%d",&deque[rear]);
    }
    else if ((font==0&&rear==4)||(font==rear+1))
    {
        printf("deque is full\n");
    }
    else if (rear==4)
    {
        rear=0;
        printf("enter the value of for the deque\n");
        scanf("%d",&deque[rear]);
    }
    else
    {
        rear++;
        printf("enter the value for deque\n");
        scanf("%d",&deque[rear]);
    }
}
void dequeuefont()
{
    if (font==-1&&rear==-1)
    {
        printf("Deque is empty\n");
    }
    else if (font==4)
    {
        printf("%d is deleted from the deque\n",deque[font]);
        font=0;
    }
    else if (font==rear)
    {
        font=rear=-1;
    }
    else{
        printf("%d is deleted from the list\n",deque[font]);
        font++;
    }
}
void dequeuerear()
{
    if (rear==-1&&rear==-1)
    {
        printf("Deque is empty\n");
    }
    else if (font==rear)
    {
        font=rear=-1;
    }
    else if (rear==0)
    {
        printf("%d is deleted fromt the list\n",deque[rear]);
        rear=4;
    }
    else{
        printf("%d is deleted from the list\n",deque[rear]);
        rear--;
    }
}
void display()
{
    if (rear==-1&&font==-1)
    {
        printf("Deque is empty\n");
    }
    else{
        int i=font;
        while (i!=rear)
        {
            printf("%d\n",deque[i]);
            i=(i+1)%5;
        }
        printf("%d\n",deque[rear]);
    }
}
void fontrear()
{
    if (rear==-1&&font==-1)
    {
        printf("Deque is empty\n");
    }
    else{
        printf("The font value of deque is %d and the rear value of deque is %d\n",deque[font],deque[rear]);
    }
}
void isempty()
{

}
void isfull()
{

}
int main()
{
    int ch;
    char choice;
        printf("\t\t\t\t\t\t\tIMPLEMENTATION OF DEQUE USING ARRAY\n");
    do
    {
        printf("1.ENQUEUE FONT\n");
        printf("2.ENQUEUE REAR\n");
        printf("3.DEQUEUE fonT\n");
        printf("4.DEQUEUEU REAR\n");
        printf("5.DISPLAY\n");
        printf("6.GET FONT AND GET REAR VALUES\n");
        printf("7.IS FULL\n");
        printf("8.IS EMPTY\n");
        printf("Enter the choice as per given information\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueuefont();
            break;
        case 2:
            enqueuerear();
            break;
        case 3:
            dequeuefont();
            break;
        case 4:
            dequeuerear();
            break;
            case 5:
            display();
            break;
            case 6:
            fontrear();
            break;
            case 7:
            isfull();
            break;
            case 8:
            isempty();
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