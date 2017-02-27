#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int key;
    struct node *next;
};
void push(int , struct node **);
void display(struct node *);
int pop(struct node **);
bool empty(struct node*);
int search(int , struct node*);

int main()
{
    int choice , data;
    struct node *top;
    top = NULL;
    while(1)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Peek\n5.Empty\n6.Search\n7.Clear\n8.Exit");
        printf("\n\tEnter Your Choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the data\n");
            scanf("%d", &data);
            push(data, &top);
            break;
        case 2:
            if(pop(&top) == -1)
                printf("The stack is empty.");
            break;
         case 3:
            display(top);
            break;
         case 4:
            printf("%d" , top->key);
            break;
         case 5:
            if(!empty(top))
                printf("\nThe stack is empty.");
            else
                printf("\nThe stack isn't empty.");
            break;
         case 6:
            printf("Enter the value that you want to find in the stack: ");
            scanf("%d" , &data);
            if(search(data , top)== -1)
                printf("The value is not in the stack.");
            else
                printf("The index of the value is %d" , search(data ,top) );
            break;
         case 7:
             system("cls");
             break;
         case 8:
            return 0;
         default:
            printf("Default");

        }
    }

    return 0;
}

bool empty(struct node *top)
{
    if(top != NULL)
        return 1;
    return 0;
}
void push(int a , struct node **top)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->key = a;
    temp->next = *top;
    *top = temp;
}
void display(struct node *top)
{
   if(top == NULL)
    {
        printf("The stack is empty");
        return;
    }
    while(top!=NULL)
    {
        printf("\t| %d |\n" , top->key);
        if(top->next == NULL)
                    printf("\t ---\n");
        top = top->next;
    }
    /*if( top == NULL)
    {
        return;
    }
    printf("\t| %d |\n " , top->key);
    if(top->next == NULL)
        printf("\t ---\n");
    display(top->next);*/
}
int pop(struct node **top)
{
    if(*top == NULL) return -1;
    struct node *temp;
    int k;
    temp = *top;
    *top = (*top)->next;
    k = temp->key;
    free(temp);
    return k;
}

int search(int a, struct node* top)
{
    int i , sem = 0 , j;
    for(i = 0 ; top != NULL ; i++)
        {
        if(top->key==a)
        {
            sem = 1;
            j = i;
        }
        top = top->next;

        }
    if(sem)return i-j-1;

    return -1;
}
