Challenge 09 - SEATSMART
Problem
Write a C programme which uses a 2D array to implement a seat booking system. It will allow the user to view seats, book individual seats, cancel seats and block seats for groups.
Algorithm
1. Beginning
2. Setup 5 Rows and 8 Columns
3. All seats = 0 (Available)
4. Show menu
5. Take input from user
6. If choice == 1 then show all seats
7. If choice == 2 then take row and seat number input and book if available
8. If choice == 3 then cancel if booked
9. If choice == 4 then take group size input and find a suitable block of consecutive available seats in the same row
10. If a suitable block has been found then book those seats, else output failure message
11. If choice == 5 then calculate how many seats have been booked, available, what percentage of seats are occupied and which rows are most busy.
12. If choice == 6 then exit
13. Loop back to menu
14. End
