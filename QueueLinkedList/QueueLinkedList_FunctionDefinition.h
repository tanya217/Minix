#ifndef QUEUE_LINKED_LIST_FUNCTION_DEFINITION

	#define QUEUE_LINKED_LIST_FUNCTION_DEFINITION 4

	Queue QueueLinkedList_Create()
	{
		Queue queue = (Queue) malloc (sizeof(QueueStructure));

		queue->front = NULL;
		queue->rear = NULL;
	
		return queue;
	}

	int QueueLinkedList_IsEmpty(Queue queue)
	{
		return (!(queue->front));
	}

	int QueueLinkedList_IsFull(Queue queue)
	{
		return (!((QueueNode*) malloc (sizeof(QueueNode))));
	}

	int QueueLinkedList_Enqueue(Queue queue, QueueElement element)
	{
		if (QueueLinkedList_IsFull(queue))
		{
			return FALSE;
		}

		if (QueueLinkedList_IsEmpty(queue))
		{
			queue->rear = queue->front = (QueueNode*) malloc (sizeof(QueueNode));
			QueueNode *currentNode = queue->front;
			currentNode->element = element;
			currentNode->nextNode = NULL;
			return TRUE;
		}

		QueueNode *currentNode = queue->rear;	

		queue->rear = currentNode = currentNode->nextNode = (QueueNode*) malloc (sizeof(QueueNode));
		currentNode->element = element;
		currentNode->nextNode = NULL;

		return TRUE;
	}

	int QueueLinkedList_PriorityEnqueue(Queue queue, QueueElement element)
	{
		if (QueueLinkedList_IsFull(queue))
		{
			return FALSE;
		}

		if (QueueLinkedList_IsEmpty(queue))
		{
			queue->rear = queue->front = (QueueNode*) malloc (sizeof(QueueNode));
			QueueNode *currentNode = queue->front;
			currentNode->element = element;
			currentNode->nextNode = NULL;
			return TRUE;
		}

		QueueNode *previousNode = NULL;		
		QueueNode *currentNode = queue->front;	
		
		while (currentNode)
		{
			if (currentNode->element.burstTime > element.burstTime)
			{
				if (!previousNode)
				{
					QueueNode* newNode = (QueueNode*) malloc (sizeof(QueueNode));
					newNode->element = element;					

					queue->front = newNode;
					newNode->nextNode = currentNode;
					
					return TRUE;
				}
				else
				{
					QueueNode* newNode = (QueueNode*) malloc (sizeof(QueueNode));
					newNode->element = element;					
					
					previousNode->nextNode = newNode;
					newNode->nextNode = currentNode;

					return TRUE;
				}		
			}
			else
			{
				previousNode = currentNode;
				currentNode = currentNode->nextNode;
			}
		}

		queue->rear = currentNode = previousNode->nextNode = (QueueNode*) malloc (sizeof(QueueNode));
		currentNode->element = element;
		currentNode->nextNode = NULL;

		return TRUE;
	}

	QueueElement QueueLinkedList_Dequeue(Queue queue)
	{
		if (QueueLinkedList_IsEmpty(queue))
		{
			QueueElement randomElement;
			return randomElement;
		}

		QueueElement returningElement;

		returningElement = (queue->front)->element;

		queue->front = (queue->front)->nextNode;

		return returningElement;
	}

	void QueueLinkedList_Clear(Queue queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}

	int QueueLinkedList_Size(Queue queue)
	{
		int size = 0;

		QueueNode *currentNode = queue->front;

		while (currentNode)
		{
			currentNode = currentNode->nextNode;

			size++;
		}

		return size;
	}

	QueueElement QueueLinkedList_Front(Queue queue)
	{
		return (queue->front)->element;
	}

	QueueElement QueueLinkedList_Rear(Queue queue)
	{
		return (queue->rear)->element;
	}

	int QueueLinkedList_Traverse(Queue queue, void (*doStuff)(QueueElement))
	{
		if (QueueLinkedList_IsEmpty(queue))
		{
			return FALSE;
		}

		QueueNode *currentNode = queue->front;

		while (currentNode)
		{
			doStuff(currentNode->element);
			currentNode = currentNode->nextNode;
		}

		return TRUE;
	}

#endif
