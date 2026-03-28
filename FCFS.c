#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], WT[n], TAT[n], CT[n], P[n];

    // 🔹 Input
    for (int i = 0; i < n; i++) {
        P[i] = i + 1;

        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);

        printf("Burst Time: ");
        scanf("%d", &BT[i]);
    }

    // 🔹 Sort by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (AT[j] > AT[j + 1]) {
                int temp;

                temp = AT[j];
                AT[j] = AT[j + 1];
                AT[j + 1] = temp;

                temp = BT[j];
                BT[j] = BT[j + 1];
                BT[j + 1] = temp;

                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    int time = 0;

    // 🔹 FCFS Calculation
    for (int i = 0; i < n; i++) {

        if (time < AT[i])  time = AT[i];   // CPU idle
        time += BT[i];
        CT[i] = time;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }

    // 🔹 Gantt Chart
    printf("\nGantt Chart:\n|");

    for (int i = 0; i < n; i++) {
        printf(" P%d |", P[i]);
    }

    printf("\n0");
    time = 0;

    for (int i = 0; i < n; i++) {

        if (time < AT[i])  time = AT[i];
        time += BT[i];
        printf("   %d", time);
    }

    // 🔹 Output Table
    float totalWT = 0, totalTAT = 0;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               P[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);

        totalWT += WT[i];
        totalTAT += TAT[i];
    }

    printf("\nAverage WT = %.2f", totalWT / n);
    printf("\nAverage TAT = %.2f\n", totalTAT / n);

    return 0;
}
