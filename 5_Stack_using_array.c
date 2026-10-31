//Stack using array
#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;
int main()
{
    int choice, item, i;
    while (1)
    {
        printf("\n1.PUSH  2.POP  3.DISPLAY  4.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (top == SIZE - 1)
                    printf("Stack Full\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &item);
                    stack[++top] = item;
                }
                break;
            case 2:
                if (top == -1)
                    printf("Stack Empty\n");
                else
                    printf("Popped = %d\n", stack[top--]);
                break;
            case 3:
                if (top == -1)
                    printf("Stack Empty\n");
                else
                {
                    printf("Stack: ");
                    for (i = top; i >= 0; i--)
                        printf("%d ", stack[i]);
                    printf("\nTOP = %d\n", top);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

