#include <stdio.h>

int main()
{
    int allocation[100][100], max[100][100], need[100][100], available[100], work[100], finish[100];
    int m, n;

    printf("Enter number of resources and number of processes: ");
    scanf("%d%d", &m, &n);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Calculate need matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Enter available matrix:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int safeSequence[n];
    int count = 0;

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("The system is not in a safe state.\n");
            return 1;
        }
    }

    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 0;
}
