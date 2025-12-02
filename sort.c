#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Utility */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

/* Bubble Sort */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-1-i; ++j)
            if (arr[j] > arr[j+1]) {
                int t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t;
            }
}

/* Selection Sort */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j)
            if (arr[j] < arr[minIdx]) minIdx = j;
        int t = arr[i]; arr[i] = arr[minIdx]; arr[minIdx] = t;
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

/* Merge Sort */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}
void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

/* Quick Sort (Lomuto) */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
        }
    }
    int t = arr[i+1]; arr[i+1] = arr[high]; arr[high] = t;
    return i+1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

/* Main: read array and choose sort */
int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *orig = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        printf("Element %d: ", i+1);
        scanf("%d", &orig[i]);
    }

    printf("Choose sort:\n1) Bubble\n2) Merge\n3) Insertion\n4) Selection\n5) Quick\nChoice: ");
    int choice; if (scanf("%d", &choice) != 1) choice = 1;

    int *arr = (int*)malloc(n * sizeof(int));
    memcpy(arr, orig, n * sizeof(int));

    switch (choice) {
        case 1: bubbleSort(arr, n); printf("Bubble sorted: "); break;
        case 2: mergeSort(arr, 0, n-1); printf("Merge sorted: "); break;
        case 3: insertionSort(arr, n); printf("Insertion sorted: "); break;
        case 4: selectionSort(arr, n); printf("Selection sorted: "); break;
        case 5: quickSort(arr, 0, n-1); printf("Quick sorted: "); break;
        default: printf("Invalid choice, showing original: "); break;
    }
    printArray(arr, n);

    free(orig); free(arr);
    return 0;
}