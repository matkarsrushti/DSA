
//UART communication (Circular Buffer) 

#include <stdio.h>
#define SIZE 5
struct CircularBuffer
{
    char data[SIZE];
    int head;
    int tail;
    int count;
};
struct CircularBuffer txBuffer = {{0}, 0, 0, 0};
struct CircularBuffer rxBuffer = {{0}, 0, 0, 0};
int is_buffer_full(struct CircularBuffer *buffer)
{
    return buffer->count == SIZE;
}
int is_buffer_empty(struct CircularBuffer *buffer)
{
    return buffer->count == 0;
}
void enqueue(struct CircularBuffer *buffer, char data)
{
    if (is_buffer_full(buffer))
    {
        printf("Buffer is full.\n");
        return;
    }
    buffer->data[buffer->tail] = data;
    buffer->tail = (buffer->tail + 1) % SIZE;
    buffer->count++;
}
char dequeue(struct CircularBuffer *buffer)
{
    char data;

    if (is_buffer_empty(buffer))
    {
        printf("Buffer is empty.\n");
        return '\0';
    }
    data = buffer->data[buffer->head];
    buffer->head = (buffer->head + 1) % SIZE;
    buffer->count--;
    return data;
}

void uart_send(char data)
{
    enqueue(&txBuffer, data);
}
void uart_transmit()
{
    char data;

    if (!is_buffer_empty(&txBuffer))
    {
        data = dequeue(&txBuffer);
        printf("Transmitted: %c\n", data);
    }
}
void uart_receive(char data)
{
    enqueue(&rxBuffer, data);
}
void uart_read()
{
    char data;
    if (!is_buffer_empty(&rxBuffer))
    {
        data = dequeue(&rxBuffer);
        printf("Received: %c\n", data);
    }
}
int main(){
    int choice;
    char data;
    while (1)
    {
        printf("\n--- UART COMMUNICATION ---\n");
        printf("1. Send Data\n");
        printf("2. Transmit Data\n");
        printf("3. Receive Data\n");
        printf("4. Read Received Data\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter character to send: ");
                scanf(" %c", &data);
                uart_send(data);
                printf("Data added to TX buffer.\n");
                break;
            case 2:
                uart_transmit();
                break;
            case 3:
                printf("Enter received character: ");
                scanf(" %c", &data);
                uart_receive(data);
                printf("Data added to RX buffer.\n");
                break;
            case 4:
                uart_read();
                break;
            case 5:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
 }
    return 0;
}


