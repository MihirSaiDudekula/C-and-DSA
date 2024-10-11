#include <stdio.h>
#include <stdlib.h>

typedef struct Object {
    int marked;                // 0 for not marked, 1 for marked
    struct Object** references; // Array of pointers to referenced objects
    int num_references;        // Number of references
} Object;

typedef struct QueueNode {
    Object* obj;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, Object* obj) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->obj = obj;
    temp->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}

Object* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;
    QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    Object* obj = temp->obj;
    free(temp);
    return obj;
}

int is_queue_empty(Queue* queue) {
    return queue->front == NULL;
}

void destroy_queue(Queue* queue) {
    while (!is_queue_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

void mark_objects_bfs(Object** roots, int num_roots) {
    Queue* queue = create_queue();

    // Mark and enqueue all root objects
    for (int i = 0; i < num_roots; i++) {
        if (roots[i] && roots[i]->marked == 0) {
            roots[i]->marked = 1;
            enqueue(queue, roots[i]);
        }
    }

    // Perform BFS
    while (!is_queue_empty(queue)) {
        Object* current = dequeue(queue);

        // Traverse all references from the current object
        for (int i = 0; i < current->num_references; i++) {
            Object* referenced = current->references[i];
            if (referenced && referenced->marked == 0) {
                referenced->marked = 1;
                enqueue(queue, referenced);
            }
        }
    }

    destroy_queue(queue);
}

void sweep_objects(Object** objects, int num_objects) {
    for (int i = 0; i < num_objects; i++) {
        if (objects[i] && objects[i]->marked == 0) {
            // Free the object and its references
            free(objects[i]->references);
            free(objects[i]);
            objects[i] = NULL;
        } else if (objects[i]) {
            // Reset mark for the next collection
            objects[i]->marked = 0;
        }
    }
}

void garbage_collect(Object** roots, int num_roots, Object** all_objects, int num_objects) {
    mark_objects_bfs(roots, num_roots);
    sweep_objects(all_objects, num_objects);
}

int main() {
    // Example objects
    Object* obj1 = (Object*)malloc(sizeof(Object));
    Object* obj2 = (Object*)malloc(sizeof(Object));
    Object* obj3 = (Object*)malloc(sizeof(Object));

    // Setting up references
    obj1->references = (Object**)malloc(1 * sizeof(Object*));
    obj1->references[0] = obj2;
    obj1->num_references = 1;
    obj1->marked = 0;

    obj2->references = (Object**)malloc(1 * sizeof(Object*));
    obj2->references[0] = obj3;
    obj2->num_references = 1;
    obj2->marked = 0;

    obj3->references = NULL;
    obj3->num_references = 0;
    obj3->marked = 0;

    // Root objects
    Object* roots[] = { obj1 };
    Object* all_objects[] = { obj1, obj2, obj3 };

    // Perform garbage collection
    garbage_collect(roots, 1, all_objects, 3);

    // Check which objects were collected
    for (int i = 0; i < 3; i++) {
        if (all_objects[i] == NULL) {
            printf("Object %d was collected.\n", i + 1);
        } else {
            printf("Object %d is still alive.\n", i + 1);
        }
    }

    return 0;
}
