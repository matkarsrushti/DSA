#include <stdio.h>
#include <string.h>

void StudentData(int choice)
{
    char name[3][20];
    char place[3][20];
    int length1, length2, compare;

    for (int i = 0; i < 3; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Enter Name: ");
        scanf("%s", name[i]);
        printf("Enter Place: ");
        scanf("%s", place[i]);
    }

    if (choice >=1 && choice <=3)
    {
        int index = choice - 1;
        length1 = strlen(name[index]);
        length2 = strlen(place[index]);
        compare = strcmp(name[index], place[index]);
        switch (choice)
        {
            case 1:
                printf("\nFirst Student's Data\n");
                break;
            case 2:
                printf("\nSecond Student's Data\n");
                break;
            case 3:
                printf("\nThird Student's Data\n");
                break;
        }
        printf("\n");
        printf("Name : %s\n", name[index]);
        printf("Place: %s\n", place[index]);
        printf("Length of Name : %d\n", length1);
        printf("Length of Place: %d\n", length2);
        printf("String Comparison: %d\n", compare);

        if (length1 > length2)
            printf("Name is longer than Place.\n");
        else if (length1 < length2)
            printf("Place is longer than Name.\n");
        else
            printf("Both strings have the same length.\n");
    }
    else
    {
        printf("Invalid student number!\n");
    }
}

int main()
{
    int choice;
    printf("Hello World!\n");
    printf("Enter Student Number (1-3): ");
    scanf("%d", &choice);
    StudentData(choice);

    return 0;
}


