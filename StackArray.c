#include<stdio.h>
#include<stdlib.h>
int stack[5];
int top=-1;
void push()
{
    int x;
    if (top==4)
    {
        printf("\t\t\t\t\t\t\tOVERFLOW!\n");
    }
    else{
        top++;
        printf("Enter the data for %d position\n",top);
        scanf("%d",&x);
        stack[top]=x;
    }
}
void pop()
{
    int items;
    if (top==-1)
    {
        printf("\t\t\t\t\t\t\tUNDERFLOW!\n");
    }
    else
    {
        items=stack[top];
        top--;
        printf("%d is deleted from the stack\n",items);
    }
}
void peek()
{
    if (top==-1)
    {
        printf("\t\t\t\t\t\tUNDERFLOW\n");
    }
    else
    {
        printf("%d is the top most element of stack\n",stack[top]);
    }
}
void display()
{
    for (int i = top; i>=0; i--)
    {
        printf("%d is at %d position in the stack\n",stack[i],(i+1));
    }
    
}
int main()
{
    int ch;
    char choice;
        printf("\t\t\t\t\t\t\tIMPLEMENTATION OF STACK USING ARRAY\n");
    do
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("Enter the choice as per given information\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
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