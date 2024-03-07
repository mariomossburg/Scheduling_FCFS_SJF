//#include "fcfs.h"
#include <stdio.h>
#include <stdlib.h>

void waitTimeFCFS(int arrivals[], int n, int burstTime[], int waitTime[], int turnaroundTime[]){

    int totalWaitTime = 0;

    for (int i = 0; i < n; i++){
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
        turnaroundTime[i] = (burstTime[i] + waitTime[i]) - arrivals[i];
        totalWaitTime += (turnaroundTime[i] - burstTime[i]);
    }
    double averageWT = (double)totalWaitTime / n;
    printf("Average Waiting Time: %.2f\n", averageWT);
}

void turnaroundTimeFCFS(int processes[], int n, int burstTime[], int waitTime[], int turnaroundTime[]){
    int totalTime = 0;

    for (int i = 0; i < n; i++){
        turnaroundTime[i] = (burstTime[i] + waitTime[i]) - processes[i];
        totalTime += turnaroundTime[i];
    }
    double averageTime = (double)totalTime / n;
    printf("Average Turnaround Time: %.2f\n", averageTime);
}

void executionOrderFCFS(int *arrival, int numProcesses){
 
    int *processes = (int *)malloc(numProcesses * sizeof(int));
    for (int i = 0; i < numProcesses; i++){
        processes[i] = i + 1;
    }

    printf("Order of Execution: ");
    for (int i = 0; i < numProcesses; i++){
        if (i > 0){
            printf(" -> ");
        }
        printf("P%d", processes[i]);
    }
    printf("\n");

    free(processes);
}
