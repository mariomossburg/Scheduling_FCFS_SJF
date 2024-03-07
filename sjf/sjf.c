#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arrival[], int burstTime[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (burstTime[j] > burstTime[j + 1])
            {
                swap(&burstTime[j], &burstTime[j + 1]);
                swap(&arrival[j], &arrival[j + 1]);
            }
        }
    }
}

void waitTimeSJF(int arrivals[], int n, int burstTime[], int waitTime[], int turnaroundTime[])
{
    int totalWaitTime = 0;
    waitTime[0] = 0;
    int currentTime = 0;
    int process_id[n];

    for (int i = 0; i < n; i++)
        process_id[i] = i + 1;

    for (int i = 0; i < n; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arrivals[j] <= currentTime && burstTime[j] < burstTime[min_index])
                min_index = j;
        }

        swap(&arrivals[i], &arrivals[min_index]);
        swap(&burstTime[i], &burstTime[min_index]);
        swap(&process_id[i], &process_id[min_index]);

        waitTime[i + 1] = currentTime - arrivals[i];
        totalWaitTime += waitTime[i + 1];
        currentTime += burstTime[i];
    }

    printf("\n");

    double averageWT = (double)totalWaitTime / n;
    // printf("total waititme: %d\n", totalWaitTime);
    printf("Average Waiting Time: %.2f\n", averageWT);
}

void turnaroundTimeSJF(int arrivals[], int n, int burstTime[], int waitTime[], int turnaroundTime[]){
    int totalTurnaroundTime = 0;
    int currentTime = 0;
    int process_id[n];

    for (int i = 0; i < n; i++)
        process_id[i] = i + 1;

    for (int i = 0; i < n; i++){
        int min_index = i;

        for (int j = i + 1; j < n; j++){
            if (arrivals[j] <= currentTime && burstTime[j] < burstTime[min_index])
                min_index = j;
        }

        swap(&arrivals[i], &arrivals[min_index]);
        swap(&burstTime[i], &burstTime[min_index]);
        swap(&process_id[i], &process_id[min_index]);

        currentTime += burstTime[i];
        turnaroundTime[i] = currentTime - arrivals[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    double averageTurnaroundTime = (double)totalTurnaroundTime / n;
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
}

void executionOrderSJF(int arrival[], int numProcesses, int burstTime[]){
    int processes[numProcesses]; // Tracks process IDs

    for (int i = 0; i < numProcesses; i++)
        processes[i] = i + 1;

    // Execute SJF algorithm
    printf("Order of Execution: ");
    int currentTime = 0;
    for (int i = 0; i < numProcesses; i++){
        int minIndex = i;

        for (int j = i + 1; j < numProcesses; j++){

            if (arrival[j] <= currentTime && burstTime[j] < burstTime[minIndex])
                minIndex = j;
        }

        swap(&arrival[i], &arrival[minIndex]);
        swap(&burstTime[i], &burstTime[minIndex]);
        swap(&processes[i], &processes[minIndex]);

        printf("P%d", processes[i]);
        currentTime += burstTime[i];
        if (i < numProcesses - 1){
            printf(" -> ");
        }
    }
}
