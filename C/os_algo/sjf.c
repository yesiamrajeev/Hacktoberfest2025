#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], pid[n], completed[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        pid[i] = i + 1;       // process ID
        completed[i] = 0;     // mark not completed
    }

    int time = 0, done = 0;
    while (done < n) {
        int idx = -1;
        int min_bt = 1e9;

        // pick process with min BT among arrived and not completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++; // no process arrived yet, move time
        } else {
            ct[idx] = time + bt[idx];
            time += bt[idx];
            completed[idx] = 1;
            done++;
        }
    }

    // calculate TAT and WT
    int sum_tat = 0, sum_wt = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        sum_tat += tat[i];
        sum_wt += wt[i];
    }

    float avg_tat = (float)sum_tat / n;
    float avg_wt = (float)sum_wt / n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    printf("Average Waiting Time    = %.2f\n", avg_wt);

    return 0;
}
