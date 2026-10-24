## Aim

Use Arrays, Loops and Conditions to analyse data and rotate an array.


START

1. Read N. Repeat until N is between 5 and 12.
2. Read N array elements. Repeat each input until it is between 0 and 1000.
3. Display the original array.
4. Initialize sum, minimum, maximum, and pattern counters.
5. Traverse the array to calculate sum, minimum, and maximum.
6. Calculate average = sum / N.
7. Find the largest value smaller than maximum.
   If none exists, display a message.
8. Count local peaks by comparing each interior element
   with its immediate neighbours.
9. Track the current increasing run and the longest run.
10. Read integer K and normalize it:
    shifts = K % N
    If shifts is negative, add N.
11. Rotate right in place using array reversal:
    a. Reverse the entire array.
    b. Reverse the first shifts elements.
    c. Reverse the remaining elements.
12. Display the rotated array.
13. Read R, the last two digits of the registration number.
14. Calculate D = (R % 9) + 1.
15. Count rotated values divisible by D.
16. Display D and the count.

STOP
