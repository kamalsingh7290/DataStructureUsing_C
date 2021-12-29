#include<stdio.h>
#include<stdlib.h>
struct doublecircularlinklist
{
    int data;
    struct doublecircularlinklist *next,*pre;
}*head=NULL,*tail=NULL,*start,*previous,*current,*list;
struct doublecircularlinklist *create_node(int flag)
{
    struct doublecircularlinklist *newnode;
    newnode=(struct doublecircularlinklist*)malloc(sizeof(struct doublecircularlinklist*));
    if (newnode==NULL)
    {
        printf("Unable to allocate the memory\n");
        exit(1);
    }
    if (flag==0||flag==1)
    {
        printf("Enter the data for the node\n");
    }
    if (flag==2)
    {
        printf("Enter the data for the node to be insert in the beginning\n");
    }
    if (flag==3)
    {
        printf("Enter the data for the node to be insert in the middle\n");
    }
    scanf("%d",&newnode->data);
    if (head==NULL)
    {
        tail=head=newnode;
        newnode->next=newnode;
        newnode->pre=newnode;
    printf("creating a list\n");
    }
    return newnode;
}
struct doublecircularlinklist *append_node(int dlag){
    struct doublecircularlinklist  *append=create_node(1);
    if (head!=NULL&&dlag==0)
    {
        printf("Adding into old list\n");
    }
    if (dlag==1)
    {
        printf("A node is inserted in the end of the list\n");
    }
    
    tail->next=append;
    append->pre=tail;
    append->next=head;
    head->pre=append;
    tail=append;
    return append;
}
void print_list()
{
    int count=0;
    struct doublecircularlinklist *cn=head;
    if (head==NULL)
    {
        printf("SORRY! no list is there\n");
    }
    else if (head!=NULL)
    {
        while(cn->next!=tail->next)
    {
        printf("data at %d position is %d\n",++count,cn->data);
        cn=cn->next;
    }
    printf("Data at %d position is %d\n",++count,cn->data);
    }
}
void reverse()
{
    int count=0;
    struct doublecircularlinklist *cn2=head,*temp;
    if (head==NULL)
    {
        printf("SORRY! no list is there\n");
    }
    else if (head!=NULL)
    {
        temp=tail;
        while(cn2->next!=temp->next)
    {
        printf("data at %d position is %d\n",++count,temp->data);
        temp=temp->pre;
    }
    printf("Data at %d position is %d\n",++count,temp->data);
    }  
    // head=cn2;
}
void insert_begin()
{
    if (head==NULL)
    {
        printf("there is no list in the existence\n");
    }
    else
    {
        struct doublecircularlinklist *ist=create_node(2);
            start=head;
            head=ist;
            head->next=start;
            start->pre=head;
            tail->next=head;
            head->pre=tail;
            printf("%d is added in the beginning of the list\n",ist->data);
    }
}
int find(int flag)
{
    int count=0,num,pos;
    out:
    if (flag==0)
    {
        printf("enter the number whose after you wanna perform insertion\n");
    }
    scanf("%d",&num);
    list=head;
    while (list->next!=tail->next)
    {
        if (list->data==num)
        {
            ++count;
            previous=list;
        }
        else{
            printf("SOORY Cannot find the number at any index\n");
            printf("%d at pos\n",list->data);
            goto out;
        }
        // start=start->next;
        list=list->next; 
    }
    return num;
}
void delete_mid()
{
    struct doublecircularlinklist *mid,*temp;
    int count=1,n;
    temp=tail->next;
    while (temp->next!=tail->next)
    {
        ++count;
        temp=temp->next;
    }
    if (count>=3)
    {
        // n=find(1);
        printf("Enter thee number you want to delete from the list\n");
        int num;
        scanf("%d",&num);
        temp=tail->next;
        while (temp->next!=tail->next)
        {
            if (temp->data==num)
            {
                mid=temp;
                // break;
            }
            temp=temp->next;
        }
        previous=mid->pre;
        current=mid->next;
        printf("%d is at deleting %d is at previous and %d is at current\n",mid->data,previous->data,current->data);
        if (mid->data!=head->data&&mid->data!=tail->data)
        {
            previous->next=current;
            current->pre=previous;
            printf("%d is deleted from the list\n",mid->data);
            free(mid);
        }
        else{
            printf("there should be a previous and next node to the deleting node\n");
        }
    }
    else{
        printf("Three node is necssary to perform this action\n");
    }
}
void insert_mid()
{
    find(0);
    current=previous->next;
    previous->pre=current;
    struct doublecircularlinklist *mid=create_node(3);
    previous->next=mid;
    mid->pre=previous;
    mid->next=current;
    current->pre=mid;
    printf("%d is inserted between %d and %d\n",mid->data,previous->data,current->data);
}
void clear()
{
    system("cls");
     int count=0;
    struct doublecircularlinklist *cn=tail->next;
    while(cn->next!=tail->next)
    {
        printf("data at %d position is %d\n",++count,cn->data);
        cn=cn->next;
    }
    printf("Data at %d position is %d\n",++count,cn->data);
}
void Exitpro()
{
    system("cls");
    exit(1);
}
void delete_ist()
{
    char num;
    struct doublecircularlinklist *del;
    del=head;
    // del->pre=tail;
    if (del->next==del&&del->pre==del)
    {
        printf("There is only one node in the list\n");
        printf("If you wanna delete that node enter [y|Y]\n");
        scanf("\n");
        scanf("%c",&num);
        if (num=='y'||num=='Y')
        {
            printf("%d is deleted from the list\n",del->data);
            free(del);
            head=NULL;
        }
    }
    else{
            del=head;
            head=del->next;
            tail->next=head;
            head->pre=tail;
            printf("%d is deleted from the list\n",del->data);
            free(del);
    }
}

void delete_end()
{
    struct doublecircularlinklist *del1;
    del1=tail;
    if (del1->next==del1&&del1->pre==del1)
    {
        char num;
        printf("There is only one node in the list\n");
        printf("If you wanna delete that node enter [y|Y]\n");
        scanf("\n");
        scanf("%c",&num);
        if (num=='y'||num=='Y')
        {
            printf("%d is deleted from the list\n",del1->data);
            free(del1);
            head=NULL;
        }
    }
    else{
    tail=del1->pre;
    tail->next=head;
    head->pre=tail;
    printf("%d is deleted from the list\n",del1->data);
    free(del1);
    }
}
int main()
{
    int ch;
    char choice;
    struct doublecircularlinklist *p=NULL,*q=NULL;
        printf("\t\t\t\t\t\t\tDOUBLY CIRCULAR LINK LIST\n");
    do
    {
        printf("1.Create a Node\n");
        printf("2.Append a Node\n");
        printf("3.Print the list\n");
        printf("4.Insert At beginning\n");
        printf("5.Insert at middle\n");
        printf("6.Insert at the end\n");
        printf("7.Delete the first node\n");
        printf("8.Delete a node in middle of the list\n");
        printf("9.delete a node in the end of the list\n");
        printf("10.Clear the screen\n");
        printf("11.reverse the list\n");
        printf("12.Exit from programe\n");
        printf("Enter your choice according to your given above instruction\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        if (p==NULL)
        {
            p=create_node(0);
            break;
        }
        else{
            printf("This option is selected only once\n");
            break;
        }
        case 2:
        if (p==NULL)
        {
            printf("You cannot append a node because list is have not created yet\nFirst you have to create a node with 1 choice\n");
            break;
        }
        else{
            q=append_node(0);
            break;
        }
        case 3:
            print_list();
            break;
        case 4:
            insert_begin();
            break;
        case 5:
        if (q==NULL)
        {
            printf("Two node is compulsory to perform this action\n");
            break;
        }
        else{
            insert_mid();
            break;
        }
        case 6:
            append_node(1);
            break;
        case 7:
        if (p==NULL)
        {
            printf("No list is in exitence! You cannot perform this action\n");
            break;
        }
        else{
            delete_ist();
            break;
        }
        case 8:
            delete_mid();
            break;
        case 9:
            delete_end();
            break;
        case 10:
            clear();
            break;
        case 11:
            reverse();
            break;
        case 12:
            Exitpro();
            break;
        default:printf("SORRY! Invalid choice\n");
            break;
        }
        printf("If you want to continue please enter [y,Y]]\n");
        scanf("\n");
        scanf("%c",&choice);
        // scanf("\n");
    } while (choice=='y'||choice=='Y');
    
    return 0;
}