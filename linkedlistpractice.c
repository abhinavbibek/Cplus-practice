/*
#include<stdio.h>
struct node
{
    int item;
    struct node *next;
};
int main()
{
    struct node node1,node2;
    node1.item=11;
    node2.item=12;
    node1.next=&node2;
    node2.next=NULL;
    printf("%d%d",node1.next->item,node2.item);
    return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void count_nodes();
struct linked_list
{
    int data;
    struct linked_list *next;
};
typedef struct linked_list node;    //renaming struct linked_list to node and now node is a userdefined datatype
node *head=NULL,*temp=NULL;
int main()
{
    int choice;
      while(1)
    {
    printf("\n________________________________\n");
    printf(".............Menu............\n");
    printf("1. Create\n");
    printf("2. Display\n");
    printf("3. Count number of nodes\n");
    printf("\n________________________________\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create();
            break;
             case 2:
            display();
            break;
             case 3:
            count_nodes();
            break;
            default:
            printf("\nInvalid choice\n");
        }
    }
}
void create()
{
    node *ptr;
    int item;
    ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
    {
    printf("Over flow: Unable to allocate memory\n");
    exit(0);
    }
    printf("\nEnter value to be inserted:");
    scanf("%d",&item);
    ptr->data=item;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        temp=head;
    }
    else
    {
        temp->next=ptr;
        temp=temp->next;
    }
    printf("\nNode Inserted :)\n");

}

void display()
{
    node *ptr;
    if(head==NULL)
    printf("\nthe list is empty\n");
    else 
    {
ptr=head;
while(ptr!=NULL)
{
    printf("%d----->",ptr->data);
    ptr=ptr->next;
}
    }
}

void count_nodes()
{
    node *ptr;
    int count=0;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("\nThe number of nodes are %d\n",count);
}