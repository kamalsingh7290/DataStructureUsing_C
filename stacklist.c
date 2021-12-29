#include<stdio.h>
#include<stdlib.h>
struct stacklist
{
    int data;
    struct stacklist *next;
}*top=NULL,*head;
int count=0;
void push()
{
    printf("Working\n");
    struct stacklist *newnode=(struct stacklist*)malloc(sizeof(struct stacklist*));
    if (newnode==NULL)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }
    printf("Enter the data for node\n");
    scanf("%d",&newnode->data);
   if (top==NULL)
   {
       newnode->next=NULL;
       top=newnode;
   }
   else{
       newnode->next=top;
       head=top=newnode;
   }
    count++;
}
void pop()
{
    struct stacklist *del;
    if (top==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else{
    del=top;
    top=top->next;
    printf("%d is deleted from the stack\n",del->data);  
    free(del);
    count--;
    } 
}
void display()
{
    if (top==NULL)
    {
        printf("No value in the stack SORRY!\n");
    }
    else{
        int c=count;
    while (top!=NULL)
    {
        printf("%d is at %d position\n",top->data,c--);
        top=top->next;
    }
    top=head;
    }
}
void peek()
{
    printf("%d is at peek in the stack\n",head->data);
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