#ifndef QUEUE_LINKED_LIST_STRUCTURES
	
	#define QUEUE_LINKED_LIST_STRUCTURES 2

	#define FALSE 0
	#define TRUE 1

	typedef ProcessBlock QueueElement;

	typedef struct node_queue
	{
		QueueElement element;
		struct node_queue *nextNode;
	} QueueNode;

	typedef struct 
	{
		QueueNode *front;
		QueueNode *rear;
	} QueueStructure;
	
	typedef QueueStructure* Queue;

#endif
	
