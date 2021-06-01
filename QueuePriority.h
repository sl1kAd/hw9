#pragma once

#ifndef _QUEUE_PRIORITY_H_
#define _QUEUE_PRIORITY_H_
/*Размер очереди*/
#define SIZE_QUEUE_PRIORITY 5
/*Описание исключительных ситуаций*/
const int okQueuePriority = 0;			
const int fullQueuePriority = 1;		
const int emptyQueuePriority = 2;		

extern int errorQueuePriority;

typedef struct 
{
	int data;
	int priority;
} queuePriorityBaseType;
/*Дескриптор очереди*/
typedef struct {
	queuePriorityBaseType buf[SIZE_QUEUE_PRIORITY];	
	unsigned uk;									
} QueuePriority;

/*Функции для работы с очередью*/
void initQueuePriority(QueuePriority* F);							
void putQueuePriority(QueuePriority* F, queuePriorityBaseType E);	
void getQueuePriority(QueuePriority* F, queuePriorityBaseType* E);	
int isFullQueuePriority(QueuePriority* F);	
int isEmptyQueuePriority(QueuePriority* F);	

#endif