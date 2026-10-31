//Queue using array
#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int main()
{
    int choice, item, i;
    while (1)
    {
        printf("\n--- QUEUE ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                if (rear == SIZE - 1)
                    printf("Queue is full\n");
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &item);
                    if (front == -1)
                        front = 0;
                    queue[++rear] = item;
                    printf("Element inserted\n");
                }
                break;
            case 2:
                if (front == -1 || front > rear)
                    printf("Queue is empty\n");
                else
                {
                    printf("Deleted element = %d\n", queue[front]);
                    front++;

                    if (front > rear)
                        front = rear = -1;
                }
                break;

            case 3:
                if (front == -1)
                    printf("Queue is empty\n");
                else
                {
                    printf("Queue elements: ");

                    for (i = front; i <= rear; i++)
                        printf("%d ", queue[i]);

                    printf("\nFRONT = %d\n", front);
                    printf("REAR = %d\n", rear);
                }
                break;
            case 4:
                printf("Program ended\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}


