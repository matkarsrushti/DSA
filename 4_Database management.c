
#include <stdio.h>
typedef struct employee
{
    int emp_no;
    char name[20];
    float salary;
} employee;

int main()
{
    employee e[50];
    int n, i, ch, no, j;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Store employee information
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("Employee No: ");
        scanf("%d", &e[i].emp_no);

        printf("Name: ");
        scanf("%s", e[i].name);

        printf("Salary: ");
        scanf("%f", &e[i].salary);
    }

    ch = 1;

    while(ch != 6)
    {
        printf("\n\n--- Employee Database ---");
        printf("\n1. Display");
        printf("\n2. Search");
        printf("\n3. Update");
        printf("\n4. Insert");
        printf("\n5. Delete");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

       //Display
        if(ch == 1)
        {
            printf("\nEmployee Information:\n");

            for(i = 0; i < n; i++)
            {
                printf("\nEmployee No: %d", e[i].emp_no);
                printf("\nName: %s", e[i].name);
                printf("\nSalary: %.2f\n", e[i].salary);
            }
        }

    //Search
        else if(ch == 2)
        {
            printf("Enter Employee No to search: ");
            scanf("%d", &no);

            for(i = 0; i < n; i++)
            {
                if(e[i].emp_no == no)
                {
                    printf("\nEmployee found!");
                    printf("\nName: %s", e[i].name);
                    printf("\nSalary: %.2f", e[i].salary);
                    break;
                }
            }

            if(i == n)
                printf("\nEmployee not found!");
        }

//Update
        else if(ch == 3)
        {
            printf("Enter Employee No to update: ");
            scanf("%d", &no);

            for(i = 0; i < n; i++)
            {
                if(e[i].emp_no == no)
                {
                    printf("Enter new name: ");
                    scanf("%s", e[i].name);

                    printf("Enter new salary: ");
                    scanf("%f", &e[i].salary);

                    printf("Employee updated successfully!");
                    break;
                }
            }
        }

//Insert
        else if(ch == 4)
        {
            printf("Enter Employee No: ");
            scanf("%d", &e[n].emp_no);

            printf("Enter Name: ");
            scanf("%s", e[n].name);

            printf("Enter Salary: ");
            scanf("%f", &e[n].salary);
            n++;

            printf("Employee inserted successfully!");
        }

          //Delete
        else if(ch == 5)
        {
            printf("Enter Employee No to delete: ");
            scanf("%d", &no);

            for(i = 0; i < n; i++)
            {
                if(e[i].emp_no == no)
                {
                    for(j = i; j < n - 1; j++)
                    {
                        e[j] = e[j + 1];
                    }
                    n-- ;
                    printf("Employee deleted successfully!");
                    break;
                }
            }
        }
        else if(ch == 6)
        {
            printf("\nProgram ended.");
        }
        else
        {
            printf("\nInvalid choice!");
        }
    }
    return 0;
}

 
