
#include <stdio.h>

int main()
{
    float expense, smallTotal = 0, mediumTotal = 0;
    float largeTotal = 0, total = 0, average;
    int smallCount = 0, mediumCount = 0, largeCount = 0;
    int validCount = 0;

    while (1)
    {
        printf("Enter expense amount (0 to stop): ");
        scanf("%f", &expense);

        if (expense == 0)
            break;

        if (expense < 0)
        {
            printf("Invalid expense! Enter a positive amount.\n");
            continue;
        }

        validCount++;
        total = total + expense;

        if (expense < 100)
        {
            smallCount++;
            smallTotal = smallTotal + expense;
        }
        else if (expense < 500)
        {
            mediumCount++;
            mediumTotal = mediumTotal + expense;
        }
        else
        {
            largeCount++;
            largeTotal = largeTotal + expense;
        }
    }
    printf("Valid Expenses Count = %d\n", validCount);
    printf("Total Expenses = Rs. %.2f\n", total);

    printf("\nSmall Count = %d\n", smallCount);
    printf("Small Total = Rs. %.2f\n", smallTotal);

    printf("\nMedium Count = %d\n", mediumCount);
    printf("Medium Total = Rs. %.2f\n", mediumTotal);

    printf("\nLarge Count = %d\n", largeCount);
    printf("Large Total = Rs. %.2f\n", largeTotal);

    if (validCount > 0)
    {
        average = total / validCount;
        printf("\nAverage Expense = Rs. %.2f\n", average);
    }
    else
    {
        printf("\nNo valid expenses were entered.\n");
    }

    return 0;
}
