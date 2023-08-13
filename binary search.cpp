#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target) {
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid] == target)
return mid;
if (arr[mid] < target)
left = mid + 1;
else
right = mid - 1;
}
return -1;
}
int main() {
int size;
printf("Enter the number of elements in the array: ");
scanf("%d", &size);

int arr[size];
printf("Enter the elements in sorted order:\n");
for (int i = 0; i < size; i++) {
printf("Enter element %d: ", i + 1);
scanf("%d", &arr[i]);
}
int target;
printf("Enter the target value to search for: ");
scanf("%d", &target);

int result = binarySearch(arr, 0, size - 1, target);

if (result == -1)
printf("Target value not found in the array.\n");
else
printf("Target value found at index %d.\n", result);
return 0;
}

