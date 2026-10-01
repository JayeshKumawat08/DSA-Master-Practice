#include <stdio.h>
#include <stdbool.h>

#define MAX_CAPACITY 100
#define BATCH_SIZE 20

typedef struct {
    int isAdult; // 1 for Adult, 0 for Child
    int isVIP;   // 1 for VIP, 0 for Regular
} Rider;

// Queue ADT structure
typedef struct {
    Rider arr[MAX_CAPACITY];
    int front;
    int rear;
    int adultCount;
    int childCount;
} RollerCoasterQueue;

// Initialize the queue
void initQueue(RollerCoasterQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->adultCount = 0;
    q->childCount = 0;
}

bool isEmpty(RollerCoasterQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

bool isFull(RollerCoasterQueue *q) {
    return (q->rear == MAX_CAPACITY - 1);
}

void enqueue(RollerCoasterQueue *q, int isAdult) {
    if (isFull(q)) {
        printf("Queue is full! Wait for the next round.\n");
        return;
    }
    
    if (q->front == -1) q->front = 0; // Set front if first element
    
    q->rear++;
    q->arr[q->rear].isAdult = isAdult;
    q->arr[q->rear].isVIP = 0;
    
    if (isAdult) q->adultCount++;
    else q->childCount++;
}

void enqueueVIP(RollerCoasterQueue *q, int isAdult) {
    if (isFull(q)) {
        printf("Queue is full! Cannot accommodate VIP right now.\n");
        return;
    }

    if (q->front == -1) {
        // Queue is empty, just insert normally
        q->front = 0;
        q->rear = 0;
        q->arr[q->front].isAdult = isAdult;
        q->arr[q->front].isVIP = 1;
    } else {
        q->rear++;
        for (int i = q->rear; i > q->front; i--) {
            q->arr[i] = q->arr[i - 1];
        }
        // Insert VIP at the very front
        q->arr[q->front].isAdult = isAdult;
        q->arr[q->front].isVIP = 1;
    }

    if (isAdult) q->adultCount++;
    else q->childCount++;
    
    printf("VIP %s entered at the front of the queue!\n", isAdult ? "Adult" : "Child");
}

void startRide(RollerCoasterQueue *q) {
    if (isEmpty(q)) {
        printf("\nNo riders in queue. The ride is waiting...\n");
        return;
    }

    printf("\n--- STARTING ROLLER COASTER RIDE ---\n");
    printf("Boarding riders:\n");
    
    int boarded = 0;
    
    // Dequeue to BATCH_SIZE (20) riders
    while (!isEmpty(q) && boarded < BATCH_SIZE) {
        Rider current = q->arr[q->front];
        q->front++; // Move front pointer forward
        boarded++;
        
        // Print passenger details
        printf("Passenger %d: %s %s\n", boarded, 
               current.isVIP ? "[VIP]" : "", 
               current.isAdult ? "Adult" : "Child");
    }
    
    printf("Ride is now departing with %d passengers!\n", boarded);
    printf("Remaining Adults in Queue: %d\n", q->adultCount);
    printf("Remaining Children in Queue: %d\n", q->childCount);
    printf("------------------------------------\n");
}

int main() {
    RollerCoasterQueue rideQueue;
    initQueue(&rideQueue);

    printf("Simulating Theme Park Queue...\n\n");

    // Adding 15 Adults and 7 Children
    for(int i = 0; i < 15; i++) enqueue(&rideQueue, 1);
    for(int i = 0; i < 7; i++) enqueue(&rideQueue, 0);
    
    printf("Total waiting - Adults: %d, Children: %d\n", rideQueue.adultCount, rideQueue.childCount);

    enqueueVIP(&rideQueue, 1); // VIP Adult
    enqueueVIP(&rideQueue, 1); // VIP Adult
    enqueueVIP(&rideQueue, 0); // VIP Child

    startRide(&rideQueue);

    //next ride for the remaining people
    startRide(&rideQueue);

    return 0;
}