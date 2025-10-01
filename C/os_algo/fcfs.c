#include <stdio.h>

int main()
{
    int n;
    printf("enter the number of processes ");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the arival time, burst time of process %d ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                // swap arrival time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // swap corresponding burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    int j = 0;
    int completed = 0;
    int i = 0;
    while (completed != n)
    {
        if (j >= at[i])
        {
            ct[i] = j + bt[i];
            j = j + bt[i];
            i++;
            completed++;
        }
        else
        {
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
    }
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    float avg_tat, avg_wt;
    int sum_tat = 0,sum_wt=0;
    for (int i = 0; i < n; i++)
    {
        sum_tat += tat[i];
        sum_wt += wt[i];

    }
    avg_tat = (float)sum_tat / (float)n;
    avg_wt = (float)sum_wt / (float)n;
    printf("average turn araound time is %.2f: \n", avg_tat);
    printf("average turn araound time is %.2f: \n", avg_wt);
    return 0;
}