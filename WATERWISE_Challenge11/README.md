# Challenge 11 – WATERWISE

**Course:** CSE101 – Fundamentals of Computing and C Programming  
**Challenge:** CODE2THINK Challenge 11 – WATERWISE  
**Theme:** Track. Detect. Conserve.

## Problem Statement / Question

A university wants to reduce water wastage across its campus. Develop a menu-driven C program that analyses seven days of water-consumption readings from five campus zones, detects unusual usage, identifies zones that exceed their daily targets, and recommends where conservation efforts should begin.

The five zones are:
1. Academic Block
2. Hostel
3. Library
4. Cafeteria
5. Sports Complex

For every zone, the program stores seven daily readings and one daily target. It displays the consumption matrix, calculates weekly statistics, detects over-limit days and sudden spikes, counts unique alert days, ranks zones by excess consumption (including ties), and displays conservation recommendations.

## Data Rules

- `#define ZONES 5` and `#define DAYS 7`.
- Consumption is stored in `int usage[ZONES][DAYS]`.
- Targets are stored in `int dailyTarget[ZONES]`.
- Valid reading: 0–50,000 litres.
- Valid daily target: 100–50,000 litres.
- Invalid values are rejected and requested again.
- Use authorised campus readings. If unavailable, use clearly labelled simulated readings for testing. Never describe simulated values as actual campus measurements.

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

## Pointer Use

- `&usage[zone][0]` passes the address of the first reading in a zone to the analysis functions.
- `*(zoneUsage + day)` accesses each day's reading using pointer arithmetic.
- Output values are returned through pointer parameters, for example `*total = sum` and `*average = (float)(*total) / DAYS`.

## Required Functions

| Function | Purpose |
|---|---|
| `inputWaterData()` | Reads and validates all readings and targets. |
| `displayWaterData()` | Displays the complete consumption matrix and targets. |
| `calculateZoneStats()` | Calculates total, average, peak reading and peak day using pointers. |
| `detectWaterAlerts()` | Calculates over-limit days, excess litres, spikes and unique alert days using pointers. |
| `generateAuditReport()` | Calls the analysis functions for each zone and prints the audit report. |
| `rankZones()` | Ranks zones by total excess and handles ties. |
| `displayConservationActions()` | Displays practical recommendations for each zone. |

## How to Compile and Run

Using GCC:

```bash
gcc -std=c11 -Wall -Wextra -pedantic challenge11.c -o waterwise
./waterwise
```

On Windows with MinGW:

```bash
gcc -std=c11 -Wall -Wextra -pedantic challenge11.c -o waterwise.exe
waterwise.exe
```

## Testing

The `output/` folder contains a sample run and a test checklist. The sample readings are **simulated data for testing only**, not actual SRM University-AP campus measurements. The assignment asks for at least seven test cases; this submission records eight cases, including boundary checks for spike detection and invalid input.

## Files

- `challenge11.c` – complete source code.
- `output/sample_output.txt` – sample execution using simulated readings.
- `output/testing_evidence.md` – test cases and expected behaviours.
- `action-note/water_conservation_action_note_template.md` – fill this using an observation you are permitted to make. Do not claim an observation you did not personally make.

## What I Learned

I used pointer arithmetic to access the seven readings of each zone. Passing the address of the first array element lets the analysis functions process a zone's readings without needing a separate array. Pointer parameters also allow the functions to return multiple calculated results to the calling function.
