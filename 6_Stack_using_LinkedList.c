#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void insert()
{
    int item;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = top;
    top = newnode;
    printf("%d inserted.\n", item);
}
void delete()
{
    struct node *temp;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    temp = top;
    printf("%d deleted.\n", top->data);
    top = top->next;
    free(temp);
}
void display()
{
    struct node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n--- STACK ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Operation ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


