#include <stdio.h>
#include <string.h>

struct Employee
{
    char employee_name[30];
    int emp_no;
    float emp_salary;
};

int main()
{
    int n, i, j;
    int comparisons = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n], temp;

    for(i = 0; i < n; i++)
    {
        printf("\nEmployee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", emp[i].employee_name);

        printf("Employee No: ");
        scanf("%d", &emp[i].emp_no);

        printf("Salary: ");
        scanf("%f", &emp[i].emp_salary);
    }

    // Bubble Sort by Name
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(strcmp(emp[j].employee_name,
                      emp[j + 1].employee_name) > 0)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Employee Records:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %d %.2f\n",
               emp[i].employee_name,
               emp[i].emp_no,
               emp[i].emp_salary);
    }

    printf("\nTotal Comparisons = %d\n", comparisons);

    return 0;
}