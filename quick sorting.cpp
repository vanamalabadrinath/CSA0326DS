#include <stdio.h>

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, n-1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1, j;
    for (j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}


