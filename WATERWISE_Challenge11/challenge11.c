#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ZONES 5
#define DAYS 7

const char *zoneNames[ZONES] = {
    "Academic Block", "Hostel", "Library", "Cafeteria", "Sports Complex"
};

int readInteger(const char *prompt) {
    char line[100];
    char *end;
    long value;

    while (1) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input ended. Exiting.\n");
            exit(0);
        }
        value = strtol(line, &end, 10);
        if (end == line) {
            printf("Invalid input. Please enter a whole number.\n");
            continue;
        }
        while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')
            end++;
        if (*end != '\0' || value < -2147483647L - 1 || value > 2147483647L) {
            printf("Invalid input. Please enter a valid whole number.\n");
            continue;
        }
        return (int)value;
    }
}

void inputWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]) {
    int zone, day;
    char prompt[120];

    printf("\n========== ENTER WATER DATA ==========\n");
    printf("Enter authorised readings, or clearly labelled simulated readings for testing.\n");

    for (zone = 0; zone < ZONES; zone++) {
        printf("\n--- %s ---\n", zoneNames[zone]);
        for (day = 0; day < DAYS; day++) {
            do {
                sprintf(prompt, "Day %d consumption (0-50000 litres): ", day + 1);
                usage[zone][day] = readInteger(prompt);
                if (usage[zone][day] < 0 || usage[zone][day] > 50000)
                    printf("Out of range. Reading must be between 0 and 50000. Try again.\n");
            } while (usage[zone][day] < 0 || usage[zone][day] > 50000);
        }
        do {
            sprintf(prompt, "Daily target for %s (100-50000 litres): ", zoneNames[zone]);
            dailyTarget[zone] = readInteger(prompt);
            if (dailyTarget[zone] < 100 || dailyTarget[zone] > 50000)
                printf("Out of range. Target must be between 100 and 50000. Try again.\n");
        } while (dailyTarget[zone] < 100 || dailyTarget[zone] > 50000);
    }
    printf("\nAll water readings and targets have been recorded.\n");
}

void displayWaterData(int usage[ZONES][DAYS], int dailyTarget[ZONES]) {
    int zone, day;
    printf("\n================ WATER CONSUMPTION MATRIX (litres) ================\n");
    printf("%-19s", "Campus Zone");
    for (day = 0; day < DAYS; day++) printf("Day%-6d", day + 1);
    printf("Target\n");
    for (zone = 0; zone < ZONES; zone++) {
        printf("%-19s", zoneNames[zone]);
        for (day = 0; day < DAYS; day++) printf("%-9d", usage[zone][day]);
        printf("%d\n", dailyTarget[zone]);
    }
}

void calculateZoneStats(int *zoneUsage, int *total, float *average, int *peakUsage, int *peakDay) {
    int day;
    *total = 0;
    *peakUsage = *zoneUsage;
    *peakDay = 1;

    for (day = 0; day < DAYS; day++) {
        int reading = *(zoneUsage + day);
        *total += reading;
        if (reading > *peakUsage) {
            *peakUsage = reading;
            *peakDay = day + 1;
        }
    }
    *average = (float)(*total) / DAYS;
}

void detectWaterAlerts(int *zoneUsage, int dailyTarget, int *overLimitDays,
                       int *totalExcess, int *spikeDays, int *alertDays) {
    int day;
    *overLimitDays = 0;
    *totalExcess = 0;
    *spikeDays = 0;
    *alertDays = 0;

    for (day = 0; day < DAYS; day++) {
        int reading = *(zoneUsage + day);
        int overLimit = (reading > dailyTarget);
        int spike = 0;

        if (overLimit) {
            (*overLimitDays)++;
            *totalExcess += reading - dailyTarget;
        }
        if (day > 0 && (double)reading > (double)(*(zoneUsage + day - 1)) * 1.40)
            spike = 1;
        if (spike)
            (*spikeDays)++;
        if (overLimit || spike)
            (*alertDays)++;
    }
}

void generateAuditReport(int usage[ZONES][DAYS], int dailyTarget[ZONES],
                         int excessByZone[ZONES], int overLimitByZone[ZONES],
                         int spikeByZone[ZONES], int alertByZone[ZONES]) {
    int zone, total, peakUsage, peakDay;
    float average;
    int totalExcess, overLimitDays, spikeDays, alertDays;

    printf("\n==================== WATER AUDIT REPORT ====================\n");
    printf("%-19s %10s %10s %10s %8s %8s %8s %8s\n",
           "Zone", "Weekly", "Average", "Peak", "PeakDay", "OverLim", "Spikes", "Alerts");
    for (zone = 0; zone < ZONES; zone++) {
        calculateZoneStats(&usage[zone][0], &total, &average, &peakUsage, &peakDay);
        detectWaterAlerts(&usage[zone][0], dailyTarget[zone], &overLimitDays,
                          &totalExcess, &spikeDays, &alertDays);

        excessByZone[zone] = totalExcess;
        overLimitByZone[zone] = overLimitDays;
        spikeByZone[zone] = spikeDays;
        alertByZone[zone] = alertDays;

        printf("%-19s %10d %10.2f %10d %8d %8d %8d %8d\n",
               zoneNames[zone], total, average, peakUsage, peakDay,
               overLimitDays, spikeDays, alertDays);
        printf("  Total excess: %d litres\n", totalExcess);
    }
}

void rankZones(int excessByZone[ZONES]) {
    int zone, other, rank, greatest = excessByZone[0];
    printf("\n================ ZONE RANKING BY TOTAL EXCESS ================\n");
    for (zone = 1; zone < ZONES; zone++)
        if (excessByZone[zone] > greatest) greatest = excessByZone[zone];

    printf("Zone(s) with greatest excess (%d litres): ", greatest);
    for (zone = 0; zone < ZONES; zone++)
        if (excessByZone[zone] == greatest) printf("%s; ", zoneNames[zone]);
    printf("\n\nRanked zones (ties share the same rank):\n");

    for (zone = 0; zone < ZONES; zone++) {
        rank = 1;
        for (other = 0; other < ZONES; other++)
            if (excessByZone[other] > excessByZone[zone]) rank++;
        printf("Rank %d - %-19s : %d litres excess\n", rank,
               zoneNames[zone], excessByZone[zone]);
    }
}

void displayConservationActions(int overLimitByZone[ZONES], int spikeByZone[ZONES],
                                int excessByZone[ZONES]) {
    int zone;
    printf("\n================ CONSERVATION ACTIONS ================\n");
    for (zone = 0; zone < ZONES; zone++) {
        printf("\n%s (excess: %d litres)\n", zoneNames[zone], excessByZone[zone]);
        if (spikeByZone[zone] > 0)
            printf("- Check for a leak or unexpected water use around the flagged days.\n");
        if (overLimitByZone[zone] >= 3)
            printf("- Prioritise a water audit and prepare a reduction plan.\n");
        else if (overLimitByZone[zone] == 1 || overLimitByZone[zone] == 2)
            printf("- Monitor the over-limit days and inspect taps or valves.\n");
        if (overLimitByZone[zone] == 0 && spikeByZone[zone] == 0)
            printf("- Maintain current good water-saving practices.\n");
    }
}

int main(void) {
    int usage[ZONES][DAYS];
    int dailyTarget[ZONES];
    int excessByZone[ZONES] = {0};
    int overLimitByZone[ZONES] = {0};
    int spikeByZone[ZONES] = {0};
    int alertByZone[ZONES] = {0};
    int choice, reportGenerated = 0;

    printf("==========================================================\n");
    printf("             WATERWISE - CAMPUS WATER AUDIT               \n");
    printf("                 Track. Detect. Conserve.                 \n");
    printf("==========================================================\n");
    inputWaterData(usage, dailyTarget);

    do {
        printf("\n==================== MAIN MENU ====================\n");
        printf("1. Display Water Data\n");
        printf("2. Generate Audit Report\n");
        printf("3. Rank Zones by Excess\n");
        printf("4. Conservation Actions\n");
        printf("5. Exit\n");
        choice = readInteger("Enter your choice: ");

        switch (choice) {
            case 1:
                displayWaterData(usage, dailyTarget);
                break;
            case 2:
                generateAuditReport(usage, dailyTarget, excessByZone,
                                    overLimitByZone, spikeByZone, alertByZone);
                reportGenerated = 1;
                break;
            case 3:
                if (reportGenerated)
                    rankZones(excessByZone);
                else
                    printf("Please generate the audit report (Option 2) first.\n");
                break;
            case 4:
                if (reportGenerated)
                    displayConservationActions(overLimitByZone, spikeByZone, excessByZone);
                else
                    printf("Please generate the audit report (Option 2) first.\n");
                break;
            case 5:
                printf("Thank you for using WATERWISE. Conserve water!\n");
                break;
            default:
                printf("Invalid menu choice. Please select 1 to 5.\n");
        }
    } while (choice != 5);

    return 0;
}
