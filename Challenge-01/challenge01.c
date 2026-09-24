#include <stdio.h>

int main()
{
    float mark1, mark2, mark3, mark4, mark5;
    float total, average, percentage;

    printf("Enter marks of subject 1: ");
    scanf("%f", &mark1);

    printf("Enter marks of subject 2: ");
    scanf("%f", &mark2);

    printf("Enter marks of subject 3: ");
    scanf("%f", &mark3);

    printf("Enter marks of subject 4: ");
    scanf("%f", &mark4);

    printf("Enter marks of subject 5: ");
    scanf("%f", &mark5);

    total = mark1 + mark2 + mark3 + mark4 + mark5;
    average = total / 5;
    percentage = (total / 500) * 100;

    printf("Total = %.2f\n", total);
    printf("Average = %.2f\n", average);
    printf("Percentage = %.2f%%\n", percentage);

    return 0;
}
