#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    int pr[10], pid[10];
    int done[10] = {0};
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        pid[i] = i + 1;

    printf("Enter arrival time:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter burst time:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter priority :\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    time = at[0];
    for (i = 1; i < n; i++)
        if (at[i] < time)
            time = at[i];

    while (completed < n)
    {
        int idx = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && done[i] == 0)
            {
                if (idx == -1 || pr[i] < pr[idx])
                    idx = i;
            }
        }

        if (idx == -1)
        {
            time++;   // CPU idle
        }
        else
        {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turn Around Time = %.2f\n", avgTAT / n);

    return 0;
}

