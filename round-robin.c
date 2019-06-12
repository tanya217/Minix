#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>

#define LARGE_DIVISOR 1000000
#define TIME_QUANTUM 1000

typedef struct process_block
{
	int burstTime;
} ProcessBlock;

#include "QueueLinkedList/QueueLinkedList.h"

Queue SchedulingQueue;

void ProcessBlock_Create(int n)
{
	int i = 0;
	while (i++ < n)
	{
		int burstTime = rand() / LARGE_DIVISOR;

		ProcessBlock enqueueingProcessBlock;
		enqueueingProcessBlock.burstTime = burstTime;

		QueueLinkedList_Enqueue(SchedulingQueue, enqueueingProcessBlock);

		printf("Created Process with burst time %d\n", burstTime);
	}
}

void ProcessBlock_Scheduling()
{
	int totalBurstTime = 0;

	while (!QueueLinkedList_IsEmpty(SchedulingQueue))
	{
		ProcessBlock dequeuedProcessBlock = QueueLinkedList_Dequeue(SchedulingQueue);

		printf("Process with burst time %d has arrived\n", dequeuedProcessBlock.burstTime);

		if ((dequeuedProcessBlock.burstTime > TIME_QUANTUM) && (QueueLinkedList_Size(SchedulingQueue) > 1))
		{
			dequeuedProcessBlock.burstTime -= TIME_QUANTUM;
			
			totalBurstTime += TIME_QUANTUM;

			QueueLinkedList_Enqueue(SchedulingQueue, dequeuedProcessBlock);

			printf("Process has been preempted\n");
		}
		else
		{
			totalBurstTime += dequeuedProcessBlock.burstTime;

			printf("Process has been executed\n");
		}
	}

	printf("Total Time = %d\n", totalBurstTime);
}

int main()
{
	srand(getpid());

	SchedulingQueue = QueueLinkedList_Create();

	ProcessBlock_Create(10);

	ProcessBlock_Scheduling();

	return 0;
}