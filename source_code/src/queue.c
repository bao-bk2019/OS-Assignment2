#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size == MAX_QUEUE_SIZE) return;
	q->proc[q->size++] = proc; //input process

}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	int i = 0, j;
	// find the process have a highest priority
	for (j = 1; j < q->size; j++) {
		if (q->proc[j]->priority < q->proc[i]->priority) {
			i = j;
		}
	}
	//assignment the process have a highest priority to "temp" and remove it from q
	// replace others together and decrease size of q 
	struct pcb_t * temp = q->proc[i];
	for (int k = i+1; k < q->size; k++) {
		q->proc[k-1] = q->proc[k];
	}
	q->size--;

	return temp;
}

