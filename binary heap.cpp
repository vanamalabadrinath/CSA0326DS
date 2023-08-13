#include <stdio.h>
#define MAX_HEAP_SIZE 100
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int heap[], int size, int i) {
    int largest = i;     
    int left = 2 * i + 1; 
    int right = 2 * i + 2;
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, size, largest);
    }
}
void insert(int heap[], int* size, int value) {
    if (*size == MAX_HEAP_SIZE) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }
    int i = *size;
    heap[i] = value;
    while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1)/ 2;
    }
    (*size)++;
}
void displayHeap(int heap[], int size) {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}
int main() {
    int heap[MAX_HEAP_SIZE];
    int size = 0;
    int value;
    printf("Binary Heap Program\n");
    while (1) {
        printf("\n");
        printf("1. Insert element\n");
        printf("2. Display heap\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                insert(heap, &size, value);
                break;
            case 2:
                displayHeap(heap, size);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}



