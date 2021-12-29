#include<stdio.h>
#include<stdlib.h>
struct doublylinklist
{
    int data;
    struct doublylinklist *next;
    struct doublylinklist *pre;
}*start,*last,*cn,*head,*temp,*previous,*current;
struct doublylinklist *create_node(int flag)
{
    struct doublylinklist *newnode=(struct doublylinklist*)malloc(sizeof(struct doublylinklist*));
    printf("creating a anew node\n");
    if(newnode==NULL)
    {
        printf("unbale to allocate the memory SORRY!\n");
        exit(1);
    }   
    printf("please enter the data for node\n");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
        printf("creating a new list\n");
        newnode->next=NULL;
        newnode->pre=NULL;
        start=newnode;
        // printf("hlo %d\n",start->data);
    }
    if(flag==0)
    {
        newnode->next=NULL;
        newnode->pre=NULL;
        last=newnode;
    }
    return newnode;
}
void append_node()
{
    struct doublylinklist *append=create_node(1);
    append->next=NULL;
    if(last==NULL)
    {
        last=append;
    }
    else
    {
        append->pre=last;
        last->next=append;
        last=append;
    }
}
void print_list()
{
    // printf("your list is\n");
    // printf("adres of next is %d and address of previous is %d and address of newnode\n %d",&start->next,&start->pre,start);
    int count;
    cn=start;
    while(cn!=NULL) 
    {
        printf("data at %d position is %d\n",++count,cn->data);
        cn=cn->next;
    }
    // printf("%d",last->data);
}
void insert_begin()
{
    struct doublylinklist *begin=create_node(1);
    head=start;
    start=begin;
    start->next=head;
    head->pre=start;
}
void insert_end()
{
    append_node();
}
void insert_btw()
{
    int pos,num,count=0;
   struct  doublylinklist *previous,*current;
   printf("enter the number whose after you want to insert\n");
    scanf("%d",&num);
    cn=start;
    while (cn!=NULL)
    {
        ++count;
        if(cn->data==num)
            {
                pos=count;
                previous=cn;
            }
            cn=cn->next;
    }
     struct doublylinklist *bet=create_node(1);
    current=previous->next;
    printf("the previos is %d and current is %d\n",previous->data,current->data);
    if (start==NULL)    
    {
        printf("no list exits\n");
    }
    else
    {
        bet->next=current;
        current->pre=bet;
        previous->next=bet;
        bet->pre=previous;
    }
}
void delete_mid()
{
    struct doublylinklist *det;
    printf("enter the number you want tpo delete from the list\n");
    int num,count=0,pos=0;
    scanf("%d",&num);
    cn=start;
    while (cn!=NULL)
    {
        ++count;
        if(cn->data==num)
        {
            pos=count;
            det=cn;
        }
        cn=cn->next;
    }
    printf("the data at deleting node is %d at %d postion\n",det->data,pos);
    current=det->next;
    printf("the data at next node is %d at %d position\n",current->data,(pos+1));
    int size=0;
    cn=start;
    while (cn!=NULL)
    {
        if((pos-1)==++size)
        {
            previous=cn;
        }
        cn=cn->next;
    }
    previous->next=current;
    current->pre=previous;
    printf("the data at previous node is %d at %d position\n",previous->data,(pos-1));
    printf("%d deleted from list\n",det->data);
    free(det);
    
}
void delete_beg()
{
    head=start;
    start=start->next;
    start->pre=NULL;
    printf("%d is deleted from the list\n",head->data); 
    free(head);
}
void delete_end()
{
    cn=start;
    while(cn->next!=NULL)
    {
        head=cn;
        cn=cn->next;
    }
    head->next=NULL;
    free(cn);
    last=head;
}
void reverse()
{
    // printf("%d\n",last->data);
    cn=last;
    while(last!=NULL)
    {
        printf("%d\n",last->data);
        last=last->pre;
    }
    last=cn;
}
int main()
{
    int flag=0;
    int choice;
    char ch;
    struct doublylinklist *p=NULL;
    do
    {
        printf("1.create a node for doubly linked list\n");
        printf("2.append a node\n");
        printf("3.print the doubly linked list\n");
        printf("4.insert in beginning\n");
        printf("5.insert in end\n");
        printf("6.insert in between\n");
        printf("7.reverse the list\n");
        printf("8.delete a node from middle of the list\n");
        printf("9.delete a node froom beginning\n");
        printf("10.delete a node froom from end\n");
        printf("enter your choice please\n");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:create_node(flag);  
            break;
        case 2:append_node();
            break;
        case 3:print_list();
            break;
        case 4:insert_begin();
            break;
        case 5:insert_end();
            break;
        case 6:insert_btw();
            break;
        case 7:reverse();
            break;
        case 8:delete_mid();
            break;
        case 9:delete_beg();
            break;
        case 10:delete_end();
            break;
        default:printf("invalid choice SORRY!\n");
            break;
        }
        printf("if you want to continue please press[y|Y]\n");
        scanf("\n");
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
    return 0;
}