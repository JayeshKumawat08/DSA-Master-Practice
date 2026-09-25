#include <stdio.h>

struct Passport
{
    int passportID;
    char name[30];
    int age;
    char city[30];
    char country[30];
};

int main()
{
    int n, i, j;
    struct Passport temp;

    printf("Enter number of passport records: ");
    scanf("%d", &n);

    struct Passport p[n];

    for(i = 0; i < n; i++)
    {
        printf("\nRecord %d\n", i + 1);

        printf("Passport ID: ");
        scanf("%d", &p[i].passportID);

        printf("Name: ");
        scanf("%s", p[i].name);

        printf("Age: ");
        scanf("%d", &p[i].age);

        printf("City: ");
        scanf("%s", p[i].city);

        printf("Country: ");
        scanf("%s", p[i].country);
    }

    // Insertion Sort by Passport ID
    for(i = 1; i < n; i++)
    {
        temp = p[i];
        j = i - 1;

        while(j >= 0 && p[j].passportID > temp.passportID)
        {
            p[j + 1] = p[j];
            j--;
        }

        p[j + 1] = temp;
    }

    printf("\nSorted Passport Records:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %s %d %s %s\n",
               p[i].passportID,
               p[i].name,
               p[i].age,
               p[i].city,
               p[i].country);
    }

    return 0;
}