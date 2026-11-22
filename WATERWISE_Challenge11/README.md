# Challenge 11 – WATERWISE

## Algorithm

1. Start the program.
2. Declare a two-dimensional array for five zones and seven days, and an array for the five daily targets.
3. Read the seven daily consumption values for each zone.
4. Validate each reading. If it is below 0 or above 50,000, ask for it again.
5. Read and validate each zone's daily target. It must be between 100 and 50,000 litres.
6. Display the menu: Display Water Data, Generate Audit Report, Rank Zones by Excess, Conservation Actions, and Exit.
7. If the user selects **Display Water Data**, print all seven readings and the daily target for every zone.
8. If the user selects **Generate Audit Report**, process each zone:
   - Calculate weekly total, average, highest reading, and the earliest day on which the highest reading occurs.
   - Count readings strictly greater than the daily target and add only the amount above the target to total excess.
   - From Day 2 onward, detect a spike when the current reading is strictly greater than 1.40 times the previous day's reading.
   - Count a unique alert day once if it is over the target OR is a spike, even if both happen on that day.
   - Store the zone's excess, over-limit, spike, and alert counts.
9. If the user selects **Rank Zones by Excess** before generating the report, display a message asking them to generate the report first. Otherwise, find the greatest excess and print all zones tied for it, then print ranks from highest to lowest. Equal excess values receive equal ranks.
10. If the user selects **Conservation Actions** before generating the report, display a message asking them to generate the report first. Otherwise, recommend checking for leaks/unexpected use when spikes exist; a water audit when there are at least three over-limit days; monitoring and tap/valve inspection for one or two over-limit days; and maintaining good practices when there are no alert days.
11. If the user enters an invalid menu option, display an error and show the menu again.
12. Repeat the menu until the user selects Exit.
13. Stop.

