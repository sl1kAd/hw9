
#include <stdio.h>
#include "QueuePriority.h"
/*exercise 1*/
int errorQueuePriority;

void initQueuePriority(QueuePriority* F) 
{
	F->uk = 0;
	errorQueuePriority = okQueuePriority;
}

void putQueuePriority(QueuePriority* F, queuePriorityBaseType E) 
{
	
	if (isFullQueuePriority(F)) 
	{
		return;
	}
	
	F->buf[F->uk] = E;
	F->uk++;
}

void getQueuePriority(QueuePriority* F, queuePriorityBaseType* E) 
{
	
	if (isEmptyQueuePriority(F)) 
	{
		return;
	}
	
	queuePriorityBaseType max = F->buf[0];		

	int maxPos = 0;	

	for (unsigned i = 1; i < F->uk; i++) 
	{			
		if (F->buf[i].priority > max.priority) 
		{		
			max = F->buf[i];
			maxPos = i;
		}
	}
	
	*E = max;											
	F->buf[maxPos] = F->buf[--F->uk];					
	
}

int isFullQueuePriority(QueuePriority* F) 
{
	if (F->uk == SIZE_QUEUE_PRIORITY) 
	{
		errorQueuePriority = fullQueuePriority;

		return 1;
	}

	return 0;
}

int isEmptyQueuePriority(QueuePriority* F) 
{
	if (F->uk == 0) 
	{
		errorQueuePriority = emptyQueuePriority;

		return 1;
	}
	return 0;
}
