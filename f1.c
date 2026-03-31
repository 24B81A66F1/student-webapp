#include <stdio.h>

#define P 5   
#define R 3  
int Available[R];
int Max[P][R];
int Allocation[P][R];
int Need[P][R];
int Finish[P];
void calculateNeed() {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
}
int isSafe() {
    int Work[R];
    int safeSequence[P];
    int count = 0;
    for (int i = 0; i < R; i++)
        Work[i] = Available[i];
    for (int i = 0; i < P; i++)
        Finish[i] = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (Finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++) {
                    if (Need[i][j] > Work[j])
                        break;
                }
                if (j == R) {
                    for (int k = 0; k < R; k++)
                        Work[k] += Allocation[i][k];
                    safeSequence[count++] = i;
                    Finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in UNSAFE state\n");
            return 0;
        }
 }
    printf("System is in SAFE state\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");
    return 1;
}
void requestResources(int p, int request[]) {
    for (int i = 0; i < R; i++) {
        if (request[i] > Need[p][i]) {
            printf("Error: Process has exceeded its maximum claim\n");
            return;
        }
    }
    for (int i = 0; i < R; i++) {
        if (request[i] > Available[i]) {
            printf("Resources not available. Process must wait\n");
            return;
        }
    }
    for (int i = 0; i < R; i++) {
        Available[i] -= request[i];
        Allocation[p][i] += request[i];
        Need[p][i] -= request[i];
    }

    // 9. Run Safety Algori
    if (isSafe()) {
        printf("Request granted\n");
    } else {
        // Rollback
        for (int i = 0; i < R; i++) {
            Available[i] += request[i];
            Allocation[p][i] -= request[i];
            Need[p][i] += request[i];
        }
        printf("Request rolled back (UNSAFE)\n");
    }
}

int main() {
    // Example data
    int i, j;

    int avail[R] = {3, 3, 2};

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int alloc[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    for (i = 0; i < R; i++)
        Available[i] = avail[i];

    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++) {
            Max[i][j] = max[i][j];
            Allocation[i][j] = alloc[i][j];
        }

    calculateNeed();
    isSafe();

    int request[R] = {1, 0, 2};
    requestResources(1, request);

    return 0;
}

