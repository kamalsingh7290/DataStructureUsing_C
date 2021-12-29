#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct node
{
    int data;
    struct node *next;
}*cn,*cn2,*head,*newnode,*current,*previous,*temp,*nextnode;
void exit_pro()
{
    exit(1);
}
struct node *start=NULL;
struct node *last=NULL;
struct node *create_node(int flag)
{
    system("color 1");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|BACKGROUND_INTENSITY);

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("creating a nw node\n");
    if(newnode==NULL)
    {
        printf("memory is not allocated\n");
        exit(1);
    }
    printf("enter the data for the node\n");
    scanf("%d",&newnode->data);
    fflush(stdin);
    newnode->next=NULL;
    if(start==NULL)
    { 
        printf("creating new list\n");
            start=newnode;
    }
    if(flag==0)
    {
        last=newnode;
    }
    return newnode;
}
void append_node()
{
    struct node *append=create_node(1);
    system("color 2");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);

    append->next=NULL;
    if(last==NULL)
    {
        printf("creating a list now\n");
        last=append;
    }
    else
    {
        printf("adding into old list\n");
        last->next=append;
        last=append;
    }
}
void print_list()
{
    system("color 0");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
        cn=start;
        int count=0;
        if(cn!=NULL)
        {
            while (cn!=NULL)
            {
                printf("data at %d position is %d\n",++count,cn->data);
                cn=cn->next;
            }
        }
        else
        {
            printf("list is empty right now first you have create a node(choice 1)\n");
        }
}
void  delete_end()
{
   
    
    cn2=start;
     if (cn2->next==NULL)
    {
        printf("cannot perform deletion because this is the only node in the list\n ");
    }
    else if (start->next!=NULL)
    {
    while(cn2->next!=NULL)
    {
        temp=cn2;
        cn2=cn2->next;
    }
    temp->next=NULL;
    free(cn2); 
    last=head;
    }
    }
  
void insert_begin()
{
    system("color 4");
    if(start==NULL)
    {
        printf("List is not in existence, So id you we cant insert something in the begining\nthen First create a list\n");
    }
    else{
    struct node *insertbegin=create_node(1);
    head=start;
    start=insertbegin;
    start->next=head;
    }
}
void insert_end()
{
    struct node *end=create_node(1);
    head=last;
    last=end;
    head->next=last;
}
void insert_btw()
{
    system("color 5");
    int num,count=0,pos=0;
    struct node *insertbtw;
    printf("please enter the number whose after you wanna insert\n");
    scanf("%d",&num);
    fflush(stdin);
    cn=start;
    while(cn!=NULL)
    {
        ++count;
        if(cn->data==num)
        {
            pos=count; 
            previous=cn;
        }
        cn=cn->next;
    }
    // printf("");
    insertbtw=create_node(1);
    current=previous->next;
    // insertbtw->next=current;
    printf("the previos is %d and current is %d\n",previous->data,current->data);
    if(start==NULL)
    {
        printf("there is no list\n");
    }
    else
    {
        insertbtw->next=current;
        previous->next=insertbtw;
    }
}
void clear()
{
    system("cls");
    if(start!=NULL)
        print_list();
    
}

void delete()
{
    struct node *det;
    printf("enter the node you want to delete\n");
    int num,count=0,pos;
    scanf("%d",&num);
    cn=start;
    while (cn!=NULL)
    {
        ++count;
        if(cn->data==num)
        {
            pos=count;
            det=cn;
            // break;
        }
        // previous=cn;
        cn=cn->next;
    }
    current=det->next;
    printf(" detlet data is %d,  and next data is %d\n",det->data,current->data);
    cn2=start; 
        int size=0;
    // printf("its working");
    while (cn2!=NULL)
    {
        if((pos-1)==++size)
        {
            previous=cn2;
        }
        cn2=cn2->next;
    }
    // printf("its working");
    printf("previous data is %d, detlet data is %d,  and next data is %d\n",previous->data,det->data,current->data);
    previous->next=current;
    free(det);
    printf("deleted\n");
    // scanf("\n");

}

void delete_ist()
{
    head=start;
    start=start->next;
    printf("%d is delete from the list\n",head->data);
    free(head); 
}
void reverse()
{
    head=start;
     current=nextnode=head;
     previous=NULL;
     while (nextnode!=NULL)
     {
         nextnode=nextnode->next;
         current->next=previous;
         previous=current;
         current=nextnode;
     }
     head=nextnode;
     while (head!=NULL)
     {
         printf("%d\n",head->data);
        head=head->next;
     }
     
}
int main()
{
    int ch;
    char choice;
    int flag=0;
    struct node *p=NULL;
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
        printf("1.create node\n");
        printf("2.print list\n");
        printf("3.append node\n");
        printf("4.insert in begining\n");
        printf("5.Insert in Between\n");
        printf("6.exit the programe\n");
        printf("7.If you want to clear the screen\n");
        printf("8.delete a node\n");
        printf("9.insert in end\n");
        printf("10.delete from end\n");
        printf("11.delete from first\n");
        printf("12.reverse the list\n");
        printf("please enter your choice according to the given instruction\n");
        scanf("%d",&ch);
        fflush(stdin);
        switch (ch)
        {
        case 1: if(p==NULL)
            {
                p=create_node(flag);
                break;
            }
            else
            {
                printf("This option can be selected only once, \nSo if you want to add more data on new node then please chose option 3\n");
                break;
            }
        case 2:
            print_list();
            break;
        case 3:
            append_node();
            break;
        case 4:
            insert_begin();
            break;
        case 5:
            insert_btw();
            break;
        case 6:
            exit_pro();
            break;
        case 7:
            clear();
            break;
            case 8:
            delete();
            break;
             case 9:
            insert_end();
            break;
             case 10:
            delete_end();
            break;
             case 11:
            delete_ist();
            break;
            case 12:
            reverse();
            break;
        default:printf("your choice is invalid");
            break;
        }
        printf("If you want to continue please enter [Y or y]\n");
        scanf("\n");
        scanf("%c",&choice);
    } while (choice=='y'||choice=='Y');
    return 0;
}