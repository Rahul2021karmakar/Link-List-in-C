#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
void display(node *head);
int create();
int insert(node*head);
int last_insert(node*head);
int first_insert(node*head);
int mid_insert(node*head);
void search(node*head);
int delete(node*head);
int first_delete(node*head);
int mid_delete(node*head);
int last_delete(node*head);
int sort(node*head);
int reverse(node*head);
int count(node*head);
//void recursion_reverse_display(node*head);
main()
{
    node *head=NULL;
    int n,i,a;
     while(1)
     {
         printf("\t\nPress 1 for create the list...\t\nPress 2 for insert node...\t\nPress 3 for search...\t\nPress 4 for delete node...\t\nPress 5 for reverse list...\t\nPress 6 for sort...\t\nPress 7 for display...\t\nPress 8 for count...\t\nPress 9 for exit...\t\n");
         scanf("%d",&a);
         switch(a)
         {
             case 1:
                {
                head=last_insert(head);
                break;
                }
             case 2:
                {
                head=insert(head);
                break;
                }
                case 3:
                {
                search(head);
                break;
                }
                case 4:
                {
                head=delete(head);
                break;
                }
                case 5:
                {
                head=reverse(head);
                break;
                }
                case 6:
                {
                    head=sort(head);
                    break;
                }
                case 7:
                {
                display(head);
                break;
                }
                case 8:
                {
                    n=count(head);
                    printf("\nNumber of nodes: %d",n);
                    break;
                }
                case 9:
                {
                 exit(1);
                }
                default:
                    printf("\n\tWRONG CHOICE!!!\n\tTry Again...\n");
         }
     }
}
int create()
{
    node *p;
    p=(node*)malloc(sizeof(node));
   // printf("0000000:   %d\n",p);
    int n;
    printf("Enter the data...\n");
    scanf("%d",&n);
    (*p).data=n;
    p->link=NULL;
   // printf("111111111:  %d\n",head);
    return p;
}
int insert(node*head)
{
    int a;
    while(1)
    {
    printf("\t\nPress 1 for insert node at Beginning...\t\nPress 2 for insert node at Inter-Mediate insert...\t\nPress 3 for insert node at Last position...\t\nPress 4 display...\t\nPress 5 for goto previous menu...\n");
    scanf("%d",&a);
        switch(a)
        {
        case 1:
            {
                head=first_insert(head);
                break;
            }
        case 2:
            {
                head=mid_insert(head);
                break;
            }
         case 3:
            {
               head=last_insert(head);
                break;
            }
        case 4:
            {
               display(head);
                break;
            }
         case 5:
            {
                return(head);
            }
         default:
            printf("\n\tWRONG CHOICE!!!\n\tTry Again...\n");
        }
    }
}
int first_insert(node *head)
{
    node *p;
    int a,i;
    printf("How many nodes do you want to insert?\n");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        p=create();
        p->link=head;
        head=p;
    }
    return head;
}
int mid_insert(node*head)
{
    node *q,*p;
    int a,i;
    printf("Enter the position...\n");
    scanf("%d",&a);
    a=a-1;
    q=head;
    for(i=0;i<a-1;i++)
        q=q->link;
    p=create();
    p->link=q->link;
    q->link=p;
    return head;
}
int last_insert(node *head)
{
    node *p,*w;
    int n,i,a=1;
    printf("How many node do you want to insert?\n");
    scanf("%d",&n);
    if(head==NULL)
    {
        p=create();
        head=p;
    }
    else
        a=0;
    w=head;
    for(i=a;i<n;i++)
    {
        p=create();
        while(w->link!=NULL)
            w=w->link;
        w->link=p;
    }
    return head;
}
void search(node*head)
{
    node*p;
    int i=0,j=0,n;
    printf("Enter the data to be search...\n");
    scanf("%d",&n);
    p=head;
    while(p!=NULL)
    {
        j++;
        if(p->data ==n)
        {
            i++;
            printf("Your data %d is foound in '%d' position! \n",n,j);
        }
        p=p->link;
    }
    if(i==0)
        printf("Your data is not found...\n");
}
int delete(node*head)
{
     int a;
    while(1)
    {
    printf("\t\nPress 1 for delete node at Beginning...\t\nPress 2 for delete node at Inter-Mediate position...\t\nPress 3 for delete node at Last position...\t\nPress 4 display...\t\nPress 5 for goto previous menu...\n");
    scanf("%d",&a);
        switch(a)
        {
        case 1:
            {
               head=first_delete(head);
                break;
            }
        case 2:
            {
               head=mid_delete(head);
                break;
            }
         case 3:
            {
               head=last_delete(head);
                break;
            }
         case 4:
            {
                display(head);
                break;
            }
         case 5:
            {
                return(head);
            }
         default:
            printf("\n\tWRONG CHOICE!!!\n\tTry Again...\n");
        }
    }
}
int first_delete(node*head)
{
    printf("YOU ARE DELETING FIRST NODE!\n");
    node*p;
    p=head;
    head=p->link;
    p->link=NULL;
    free(p);
    return head;
}
int mid_delete(node*head)
{
    int n,i;
    node*p,*q;
    p=head;
    printf("YOU ARE DELETING INTER-MIDEATE NODE!\n");
    printf("Enter the position to be delete...\n");
    scanf("%d",&n);
    n=n-1;
    for(i=0;i<n-1;i++)
        p=p->link;
    q=p->link;
    p->link=q->link;
    q->link=NULL;
    free(q);
    return head;
}
int last_delete(node*head)
{
    printf("YOU ARE DELETING LAST NODE...\n");
    node*p,*q;
    p=head;
    while(p->link->link!=NULL)
        p=p->link;
    q=p->link;
    p->link=NULL;
    free(q);
    return head;
}
int reverse(node*head)
{
    node*p,*x=NULL,*y;
    p=head;
    while(p!=NULL)
    {
        y=p;
        p=p->link;
        y->link=x;
        x=y;
    }
    head=x;
    return head;
}
void display(node *head)
{
    node *q;
    if(head==NULL)
        printf("The link list is empty...\n");
    q=head;
    while(q!=NULL)
    {
        //printf("222222:   %d",q);
        printf("%d-->",q->data);
        q=q->link;
    }
    printf("\n");
}

      //                                  void recursion_reverse_display(node*head)
        //                                {
          //                                  node*p;
            //                                p=head;
              //                              if(p==NULL)
                //                                return;
                  //                          printf("recursion_display-->%d",p->data);
                    //                        recursion_reverse_display(p->link);
                      //                      printf("recursion_reversed_display-->%d",p->data);
                        //                }




int sort(node*head)
{
    node *end,*p,*q;
    int tmp;
    for(end=NULL;end!=head->link;end=q)
    {
        for(p=head;p->link!=end;p=p->link)
        {
            q=p->link;
            if(p->data>q->data)
            {
                tmp=p->data;
                p->data=q->data;
                q->data=tmp;

            }
        }
    }
    return head;
}
int count(node*head)
{
    int cow=0;
    node *j;
    j=head;
    while(j!=NULL)
    {
        cow++;
        j=j->link;
    }
    return cow;
}

