#include <stdio.h>

// Structure to store details of each process
struct Process {
    int pid;            // Process ID
    int arrival;        // Arrival Time (AT)
    int burst;          // Burst Time (BT)
    int remaining;      // Remaining Burst Time
    int priority;       // Priority (lower value = higher priority)
    int completion;     // Completion Time (CT)
    int turnaround;     // Turnaround Time (TAT)
    int waiting;        // Waiting Time (WT)
    int completed;      // Completion status
};

int main() {
    int n;
    struct Process p[10];
    int i, time = 0, completed = 0;
    int idx, highestPriority;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess %d Arrival Time: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Process %d Burst Time: ", p[i].pid);
        scanf("%d", &p[i].burst);

        printf("Process %d Priority: ", p[i].pid);
        scanf("%d", &p[i].priority);

        p[i].remaining = p[i].burst;
        p[i].completed = 0;
    }

    // Preemptive Priority Scheduling Logic
    while (completed < n) {
        idx = -1;
        highestPriority = 9999;

        // Select highest priority process available at current time
        for (i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].completed == 0) {
                if (p[i].priority < highestPriority) {
                    highestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        // If no process is ready, CPU is idle
        if (idx == -1) {
            time++;
        } else {
            // Execute selected process for 1 unit time
            p[idx].remaining--;
            time++;

            // If process finishes execution
            if (p[idx].remaining == 0) {
                p[idx].completion = time;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
                p[idx].completed = 1;
                completed++;
            }
        }
    }

    // Display result
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    return 0;
}
