
#include <stdio.h>

int main()
{
    int a[12], n, i, j, t, k, r, d;
    int sum = 0, min, max, second, found = 0;
    int peaks = 0, run = 1, longest = 1, count = 0;

    do {
        printf("Enter N (5-12): ");
        scanf("%d", &n);
    } while (n < 5 || n > 12);

    for (i = 0; i < n; i++) {
        do {
            printf("Enter reading: ");
            scanf("%d", &a[i]);
        } while (a[i] < 0 || a[i] > 1000);
    }

    min = max = a[0];

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
        sum += a[i];
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
        if (i > 0 && a[i] > a[i-1]) {
            run++;
            if (run > longest) longest = run;
        } else if (i > 0) run = 1;
        if (i > 0 && i < n-1 &&
            a[i] > a[i-1] && a[i] > a[i+1]) peaks++;
    }

    printf("\nSum=%d Average=%.2f Min=%d Max=%d",
           sum, (double)sum/n, min, max);

    for (i = 0; i < n; i++)
        if (a[i] < max && (!found || a[i] > second)) {
            second = a[i];
            found = 1;
        }

    if (found) printf("\nSecond largest=%d", second);
    else printf("\nNo second-largest distinct value");

    printf("\nPeaks=%d Longest increasing run=%d", peaks, longest);

    printf("\nEnter K: ");
    scanf("%d", &k);
    k = ((k % n) + n) % n;

    for (i = 0, j = n-1; i < j; i++, j--) {
        t=a[i]; a[i]=a[j]; a[j]=t;
    }
    for (i = 0, j = k-1; i < j; i++, j--) {
        t=a[i]; a[i]=a[j]; a[j]=t;
    }
    for (i = k, j = n-1; i < j; i++, j--) {
        t=a[i]; a[i]=a[j]; a[j]=t;
    }

    printf("\nRotated: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);

    printf("\nEnter R (last two digits): ");
    scanf("%d", &r);
    d = r % 9 + 1;

    for (i = 0; i < n; i++)
        if (a[i] % d == 0) count++;

    printf("\nD=%d Divisible count=%d\n", d, count);

    return 0;
}
