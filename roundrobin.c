#include <stdio.h>

// Structure to store process details
struct Process {
    int pid;            // Process ID
    int arrival;        // Arrival Time (AT)
    int burst;          // Burst Time (BT)
    int remaining;      // Remaining Burst Time
    int completion;     // Completion Time (CT)
    int turnaround;     // Turnaround Time (TAT)
    int waiting;        // Waiting Time (WT)
};

int main() {
    int n, tq;                  // Number of processes and Time Quantum
    struct Process p[10];
    int i, time = 0, done;
    int completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Input process details
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess %d Arrival Time: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Process %d Burst Time: ", p[i].pid);
        scanf("%d", &p[i].burst);

        p[i].remaining = p[i].burst;  // Initialize remaining time
    }

    // Round Robin Scheduling Logic
    while (completed < n) {
        done = 1;

        for (i = 0; i < n; i++) {

            // Check if process has arrived and still has burst time left
            if (p[i].arrival <= time && p[i].remaining > 0) {
                done = 0;

                if (p[i].remaining > tq) {
                    time += tq;
                    p[i].remaining -= tq;
                } else {
                    time += p[i].remaining;
                    p[i].remaining = 0;
                    p[i].completion = time;
                    completed++;
                }
            }
        }

        // If no process is ready, increment time
        if (done)
            time++;
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++) {
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }

    // Display result
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    return 0;
}
