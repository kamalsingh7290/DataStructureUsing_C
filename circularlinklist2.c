#include<stdio.h>
#include<stdlib.h>

struct circularlinklist
{
    int data;
    struct circularlinklist *next;
}*cn,*newnode,*temp,*tail=NULL,*start=NULL,*p,*q,*previous,*current,*val;
struct circularlinklist *create_node(int flag)
{
    newnode=(struct circularlinklist*)malloc(sizeof(struct circularlinklist));
    if (newnode==NULL)
    {
        printf("unable to allocate memory\n");
        exit(1);
    }
    printf("enter the data for node\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
        printf("creating a new list\n");
    }
    if (flag==0)
    {
        start=NULL;
    }
    if (flag==1)
    {
        start=newnode;
    }
    
    if (flag==2)
    {
        printf("inserting a node in the beginning of the list\n");
    }
    if (flag==3)
    {
        printf("inserting a node in the middle of the list\n");
    }
    return newnode;
}
struct circularlinklist *append_node(int dlag){
    struct circularlinklist *append=create_node(1);
    
    if (start!=NULL)    
    {
        printf("adding into old list\n");
    }
    else if (start==NULL)
    {
        printf("");
    }
    
        append->next=tail->next;
        tail->next=append;
        tail=append;
        if (dlag==1)
    {
        printf("inserting a node in the end of the list\n");
    }
    return append;
}
void print_list(){
    if (tail==NULL)
    {
        printf("SORRY! there is no data in the list\n");
    }
   
    else if (tail!=NULL)
    {
        temp=tail->next;
        int count=0;
        while (temp->next!=tail->next)
        {
            printf("data at %d psoition is %d\n",++count,temp->data);
            temp=temp->next;
        }
        printf("Data at %d position is %d\n",++count,temp->data);
    }
}
void insert_ist()
{
    if (tail==NULL)
    {
        printf("you cannot insert a node because no list is in existence\n");
    }
    else{
    struct circularlinklist *ist=create_node(2);
    ist->next=tail->next;
    tail->next=ist;
    }
}
void delete_ist()
{
    struct circularlinklist *del;
    if (tail==NULL)
    {
        printf("There is no data at the list SORRY!\n");
    }
   else if (tail!=NULL)
    {
        del=tail->next;
        if (del->next==del)   
        {
            char ch;
            printf("There is only one node in the list\nIf you want to delete that enter [y|Y]\n");
            scanf("\n");
            scanf("%c",&ch);
            if (ch=='y'||ch=='Y')
            {
                  tail=NULL;
                free(del);
                printf("First and only node is deleted\n");
            }
        }
    
        else   
        {
            del=tail->next;
            tail->next=del->next;
            free(del);
            printf("First node is deleted from the list\n");
        }
    }
    
}
void delete_end()
{
    struct circularlinklist *current,*previous,*del;
  if (tail==NULL)
  {
    printf("SORRY there is no data at the list\n");
  }
  else if(tail!=NULL)   
  {
      del=tail->next;
      current=tail->next;
    if (del->next==del)
      {
        char che;
        printf("There is only one node in the list\n If you want to delete that plz enter [y|Y]\n");
        scanf("\n");
        scanf("%c",&che);
        if (che=='y'||che=='Y')
        {
            tail=NULL;
            free(del);
            printf("first node is deleted from the list\n");
        }
      }
    else{
            while (del->next!=tail->next)
            {
                previous=del;
                del=del->next;
            }
            tail=previous;
            tail->next=current;
            free(del);
            printf("last node is deleted from the list\n");
      }
  }
}
int find(int flag)
{
    temp=tail->next;
    if (flag==0)
    {
         printf("enter the number whose after you want to perform insertion\n");
    }
    if (flag==1)
    {
        printf("enter the number whom you wanna delete from the list\n");
    }
    int num,count=0,pos;
    scanf("%d",&num);
    while (temp->next!=tail->next)
    {
            count++;
        if(temp->data==num)
        {
            val=temp;
            break;
        }
        temp=temp->next;
    }
    return count;
}
void delete_mid()
{
    struct circularlinklist *pe;
    int count=1,n;
    temp=tail->next;
    while (temp->next!=tail->next)
    {
        ++count;
        temp=temp->next;
    }
    if (count>=3)
    {
              n=find(1); 
        current=val->next;
                         int size=0;

            pe=temp=tail->next;
            while ((temp->next!=tail->next))
            {
                if ((n-1)==++size)
                {
                    previous=temp;
                }
                temp=temp->next;
            }
        if (val->data!=pe->data&&val->data!=tail->data)
        {
            previous->next=current; 
            printf("%d is deleted from the list\n",val->data);   
            free(val);        
        }
        else
        {
            printf("There should be a previous and next node to the deleting node\n");
        }
    }
    else
    {
        printf("Three node is necssary to perform this action\n");
    }  
}
void reverse()
{
    struct circularlinklist *rev,*nextnode;
    if(tail==NULL)
    {
        printf("SORRY no node in the list\n");
    }
    else
    {
        current=tail->next;
        nextnode=current->next;
        while (current!=tail)
        {
            previous=current;
            current=nextnode;
            nextnode=current->next;
            current->next=previous;
        }
        nextnode->next=tail;
        tail=nextnode;
        rev=tail->next;
        printf("data at ist is %d and at second is %d\n",rev->data,rev->next->data);
        int count=0;
        while (rev->next!=tail->next)
        {
            printf("data at %d psoition is %d\n",++count,rev->data);
            rev=rev->next;
        }
        printf("Data at %d position is %d\n",++count,rev->data);
    }
    
}
void insert_mid()
{
    find(0);
    struct circularlinklist *mid=create_node(3);
    current=val->next;
        mid->next=current;
        val->next=mid;
}
void Clear()
{
    system("cls");
    print_list();
}
void ExitPro(){
    exit(1);
}
int main()
{
    int ch;
    char choice;
    printf("\t\t\t\tWELCOME to Circular Link List!\n");
    do
    {
        printf("1.create node\n");
        printf("2.append node\n");
        printf("3.Print the circular link list\n");
        printf("4.Insert at beginning\n");
        printf("5.Insert at end\n");
        printf("6.Insert at middle\n");
        printf("7.Delete the first node\n");
        printf("8.Delete the last node\n");
        printf("9.Delete a node in the middle of the list\n");
        printf("10.reverse the list\n");
        printf("11.Clear the Screen\n");
        printf("12.Exit the programme\n");
        printf("Enter your choice please\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        if (p==NULL)
        {
             p=create_node(0); 
             break;  
        }
        else
        {
            printf("SORRY this option is selected only once\nIf you want to add more then choice option 2\n");
              break;
        }
          
        case 2:
        if (p==NULL)
        {
            printf("You cannot append something in the list\nFirst you have to create a list with option 1\n");
            break;
        }
        else
        {
           q=append_node(0);
                break;
        }
        case 3:
                print_list();
                break;
        case 4:
                insert_ist();
                break;
        case 5:
        if (p==NULL)
        {
            printf("you cannot insert a node in the end like this\nFirst create a list\n");
            break;
        }
        else{
                append_node(1);
                break;
        }
        case 6:
        if (q==NULL)
        {
            printf("Two node is  necessary to perform this action\n");
            break;
        }
        else{
                insert_mid();
                break;
        }
        case 7:
                delete_ist();
                break;
        case 8:
                delete_end();
                break;
        case 9:
                delete_mid();
                break;
        case 10:
                reverse();
                break;
        case 11:
                 Clear();
                break;
        case 12:
                ExitPro();
                 break;
        default:printf("SORRY! Invalid Choice\n");
            break;
        }
        printf("If you wnat to continue please enter [y|Y]\n");
        scanf("\n");
        scanf("%c",&choice);
    } while (choice=='y'||choice=='Y');
    return 0;
}