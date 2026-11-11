Challenge 10 – ECOGUARD

Problem Statement

A menu driven C program which monitors and analyses environmental data collected from 5 different zones in the campus over a period of 7 days.


##Algorithm:


##Start

Declare 3 two dimensional arrays for temperature, humidity and AQI.
Declare averages, risk days and Green Index arrays.
Set dataReady to 0.
Display menu.
Get users choice.
If choice is 1:
Get 7 days of data for all 5 zones.
Validate all data. If any invalid data entered ask to re-enter.
Set dataReady to 1.
If choice is 2:
Display all 3 matrices.
If choice is 3:
Calculate and display averages.
If choice is 4:
Detect and display risk days.
If choice is 5:
Calculate averages, calculate Green Index and display rankings.
If choice is 6:
Calculate averages, detect risk days and make recommendations.
If data has not been entered display a warning.
Repeat menu.
Stop.
Testing:
Normal data
AQI risk
Temperature and Humidity risk
Multiple risks for one day
No risk days
Negative Green Index value
Tied Green Index score
Invalid data input.
Compiling:
