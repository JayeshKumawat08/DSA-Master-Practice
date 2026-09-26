#include <stdio.h>

struct Student
{
    char student_name[30];
    int student_roll_no;
    int total_marks;
};

void merge(struct Student s[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;

    struct Student temp[100];

    while(i <= mid && j <= high)
    {
        if(s[i].student_roll_no < s[j].student_roll_no)
            temp[k++] = s[i++];
        else
            temp[k++] = s[j++];
    }

    while(i <= mid)
        temp[k++] = s[i++];

    while(j <= high)
        temp[k++] = s[j++];

    for(i = low, k = 0; i <= high; i++, k++)
        s[i] = temp[k];
}

void mergeSort(struct Student s[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(s, low, mid);
        mergeSort(s, mid + 1, high);

        merge(s, low, mid, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%s", s[i].student_name);

        printf("Roll No: ");
        scanf("%d", &s[i].student_roll_no);

        printf("Total Marks: ");
        scanf("%d", &s[i].total_marks);
    }

    mergeSort(s, 0, n - 1);

    printf("\nSorted Student Records:\n");

    for(i = 0; i < n; i++)
    {
        printf("%s %d %d\n",
               s[i].student_name,
               s[i].student_roll_no,
               s[i].total_marks);
    }

    return 0;
}