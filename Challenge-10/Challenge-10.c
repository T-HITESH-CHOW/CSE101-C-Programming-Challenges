#include <stdio.h>

#define ZONES 5
#define DAYS 7

char *zone[ZONES] = {
    "Academic Block", "Hostel", "Library", "Cafeteria", "Sports Area"
};

float temp[ZONES][DAYS], humidity[ZONES][DAYS], aqi[ZONES][DAYS];
float avgT[ZONES], avgH[ZONES], avgA[ZONES], green[ZONES];
int risk[ZONES], dataReady = 0;

void inputData();
void displayData();
void calculateAverages();
void detectRiskZones();
void computeGreenIndex();
void displayRanking();
void displayRecommendations();

int main() {
    int choice;

    do {
        printf("\n===== ECOGUARD =====\n");
        printf("1. Input Data\n");
        printf("2. Display Data\n");
        printf("3. Calculate Averages\n");
        printf("4. Detect Risk Days\n");
        printf("5. Green Index\n");
        printf("6. Recommendations\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputData();
                break;

            case 2:
                if (dataReady) displayData();
                else printf("Enter data first.\n");
                break;

            case 3:
                if (dataReady) calculateAverages();
                else printf("Enter data first.\n");
                break;

            case 4:
                if (dataReady) detectRiskZones();
                else printf("Enter data first.\n");
                break;

            case 5:
                if (dataReady) {
                    calculateAverages();
                    computeGreenIndex();
                    displayRanking();
                } else printf("Enter data first.\n");
                break;

            case 6:
                if (dataReady) displayRecommendations();
                else printf("Enter data first.\n");
                break;

            case 7:
                printf("Exiting ECOGUARD.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}

void inputData() {
    for (int i = 0; i < ZONES; i++) {
        printf("\nEnter readings for %s:\n", zone[i]);

        for (int j = 0; j < DAYS; j++) {
            do {
                printf("Day %d Temperature (10-50): ", j + 1);
                scanf("%f", &temp[i][j]);
            } while (temp[i][j] < 10 || temp[i][j] > 50);

            do {
                printf("Day %d Humidity (0-100): ", j + 1);
                scanf("%f", &humidity[i][j]);
            } while (humidity[i][j] < 0 || humidity[i][j] > 100);

            do {
                printf("Day %d AQI (0-500): ", j + 1);
                scanf("%f", &aqi[i][j]);
            } while (aqi[i][j] < 0 || aqi[i][j] > 500);
        }
    }

    dataReady = 1;
    printf("\nData saved successfully.\n");
}

void displayData() {
    for (int i = 0; i < ZONES; i++) {
        printf("\n%s\n", zone[i]);
        printf("Day\tTemp\tHumidity\tAQI\n");

        for (int j = 0; j < DAYS; j++) {
            printf("%d\t%.1f\t%.1f\t\t%.1f\n",
                   j + 1, temp[i][j], humidity[i][j], aqi[i][j]);
        }
    }
}

void calculateAverages() {
    for (int i = 0; i < ZONES; i++) {
        avgT[i] = avgH[i] = avgA[i] = 0;

        for (int j = 0; j < DAYS; j++) {
            avgT[i] += temp[i][j];
            avgH[i] += humidity[i][j];
            avgA[i] += aqi[i][j];
        }

        avgT[i] /= DAYS;
        avgH[i] /= DAYS;
        avgA[i] /= DAYS;

        printf("\n%s\n", zone[i]);
        printf("Average Temperature: %.2f\n", avgT[i]);
        printf("Average Humidity: %.2f\n", avgH[i]);
        printf("Average AQI: %.2f\n", avgA[i]);
    }
}

void detectRiskZones() {
    for (int i = 0; i < ZONES; i++) {
        risk[i] = 0;

        for (int j = 0; j < DAYS; j++) {
            if (aqi[i][j] > 150 ||
                temp[i][j] > 35 ||
                humidity[i][j] > 80) {
                risk[i]++;
            }
        }

        printf("%s: %d risk days\n", zone[i], risk[i]);
    }
}

void computeGreenIndex() {
    for (int i = 0; i < ZONES; i++) {
        float a = 100 - avgA[i] / 5;
        float t = 100 - 4 * (avgT[i] > 25 ? avgT[i] - 25 : 25 - avgT[i]);
        float h = 100 - 2 * (avgH[i] > 50 ? avgH[i] - 50 : 50 - avgH[i]);

        if (a < 0) a = 0;
        if (t < 0) t = 0;
        if (h < 0) h = 0;

        green[i] = 0.4 * a + 0.3 * t + 0.3 * h;

        printf("%s: Green Index = %.2f\n", zone[i], green[i]);
    }
}

void displayRanking() {
    printf("\n===== GREEN RANKING =====\n");

    for (int i = 0; i < ZONES; i++) {
        int rank = 1;

        for (int j = 0; j < ZONES; j++) {
            if (green[j] > green[i])
                rank++;
        }

        printf("Rank %d: %s (%.2f)\n", rank, zone[i], green[i]);
    }
}

void displayRecommendations() {
    for (int i = 0; i < ZONES; i++) {
        printf("\n%s: ", zone[i]);

        if (risk[i] >= 4)
            printf("High risk. Improve air quality and ventilation.\n");
        else if (risk[i] >= 1)
            printf("Moderate risk. Monitor environmental conditions.\n");
        else
            printf("Low risk. Maintain current conditions.\n");
    }
}
