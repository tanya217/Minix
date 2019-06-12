#ifndef QUEUE_LINKED_LIST_FUNCTION_PROTOTYPES

	#define QUEUE_LINKED_LIST_FUNCTION_PROTOTYPES 3

	Queue QueueLinkedList_Create();
	int QueueLinkedList_IsEmpty(Queue queue);
	int QueueLinkedList_IsFull(Queue queue);
	int QueueLinkedList_Enqueue(Queue queue, QueueElement element);
	QueueElement QueueLinkedList_Dequeue(Queue queue);
	void QueueLinkedList_Clear(Queue queue);
	int QueueLinkedList_Size(Queue queue);
	QueueElement QueueLinkedList_Front(Queue queue);
	QueueElement QueueLinkedList_Rear(Queue queue);
	int QueueLinkedList_Traverse(Queue queue, void (*doStuff)(QueueElement));

#endif
