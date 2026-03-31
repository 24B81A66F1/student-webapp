#include <stdio.h>
int main() {
    int n, tq;  
    int at[10],bt[10],rbt[10],tat[10],wt[10],ct[10];              
    int i, time = 0, done;
    int completed = 0;
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    printf("Enter Time Quantum: \n");
    scanf("%d", &tq);
    printf("ENter arrival times\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&at[i]);
    }
    printf("ENter burst times\n");
    for(i=0;i<n;i++)
    {
       scanf("%d",&bt[i]);
       rbt[i]=bt[i];
    }

    while (completed < n) {
        done = 1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rbt[i] > 0) {
                done = 0;

                if (rbt[i] > tq) {
                    time += tq;
                    rbt[i]-= tq;
                } else {
                    time += rbt[i];
                   rbt[i] = 0;
                    ct[i] = time;
                    completed++;
                }
            }
        }

        if (done)
            time++;
    }
    for (i = 0; i < n; i++) {
        tat[i] = ct[i]- at[i];
        wt[i] = tat[i]- bt[i];
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    return 0;
}
