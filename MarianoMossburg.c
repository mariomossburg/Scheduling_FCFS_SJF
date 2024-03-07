//Here is command-line text to run program:
//gcc -I./fcfs -I./sjf MarianoMossburg.c fcfs/fcfs.c sjf/sjf.c -o MarianoMossburg
//./MarianoMossburg schedule.txt



#include "fcfs.h"
#include "sjf.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
   FILE *file;
   int numProcess;
   int *arrival;
   int *burst;
   int *waiting;
   int *turnaround;
   //int *processes;

   // Open the file
   file = fopen(argv[1], "r");
   // Read the first line - number of processes, note the '&' operator before num_process
   fscanf(file, "%d", &numProcess);
  
   // Allocate the arrays to store the arrival time and burst time, one element for each process
   arrival = (int *)malloc(numProcess * sizeof(int));
   burst = (int *)malloc(numProcess * sizeof(int));
   waiting = (int *)malloc(numProcess * sizeof(int));
   turnaround = (int *)malloc(numProcess * sizeof(int));
   //processes = (int *)malloc(numProcess * sizeof(int));



   // Read each line of the file for arrival time and burst time, note that no '&' operator used here
   for (int i = 0; i < numProcess; i++)
   {
       fscanf(file, "%d", arrival + i);
       fscanf(file, "%d", burst + i);
   }
   // You should close the file after reading, even though it's usually ok to forget
   fclose(file);
  
   // In this example I only print the values, in your assignment you have to compute the execution sequence
   // as well as the average waiting time and average turnaround time
   printf("There are %d processes\n", numProcess);
   for (int i = 0; i < numProcess; i++)
   {
       printf("Process %d arrives at %d with burst time %d\n", i + 1, arrival[i], burst[i]);
   }


    printf("\n");
    printf("FCFS Algorithm:\n");

    //calling fcfs functions
    executionOrderFCFS(arrival, numProcess);
    waitTimeFCFS(arrival, numProcess, burst, waiting, turnaround);
    turnaroundTimeFCFS(arrival, numProcess, burst, waiting, turnaround);

    printf("\n");
    printf("SJF -> Non-Preemptive:\n");
    executionOrderSJF(arrival, numProcess, burst);
    waitTimeSJF(arrival, numProcess, burst, waiting, turnaround);
    turnaroundTimeSJF(arrival, numProcess, burst, waiting, turnaround);


    //free allocated memory
   free(arrival);
   free(burst);
   free(waiting);
   free(turnaround);
   //free(processes);

   return 0;
}


