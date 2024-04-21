#include<stdio.h>
#include<stdlib.h>

void swap_in_arr(int* arr, int index1, int index2) {
    int temp;
    temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void insert_in_arr(int* arr, int length, int source_index, int target_index) {
    int temp = arr[source_index];
    for (int i = source_index; i > target_index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[target_index] = temp;
}

void print_arr(int* arr, int length) {
    printf("[");
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\b]\n");
}

void insertion_sort(int* arr, int length) {
    int i;
    for ( i = 1; i < length; i++) {
        print_arr(arr, length);
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int* arr, int length) {
    int i;
    for (i = 0; i < length - 1; i++) {
        print_arr(arr, length);
        int min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap_in_arr(arr, i, min_index);
        }
    }
}

void bubble_sort(int* arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        print_arr(arr, length);
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_in_arr(arr, j, j + 1);
            }
        }
    }
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1),j;

    for ( j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        int i;
        for (i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        int i;
        for (i = l; i <= r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        int i;
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for ( i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


int* copy_array(const int* source, int size) {
    int* destination = (int*)malloc(size * sizeof(int));

    if (destination == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < size; ++i) {
        destination[i] = source[i];
    }

    return destination;
}

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int* arr1 = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    int choice;
    while (1) {
        printf("\nSorting Algorithms Menu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int* arr;
        switch (choice) {
            case 1:
                arr = copy_array(arr1,n);
                printf("Applying Insertion Sort:\n");
                insertion_sort(arr, n);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 2:
                arr = copy_array(arr1,n);
                printf("Applying Selection Sort:\n");
                selection_sort(arr, n);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 3:
                arr = copy_array(arr1,n);
                printf("Applying Bubble Sort:\n");
                bubble_sort(arr, n);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 4:
                arr = copy_array(arr1,n);
                printf("Applying Quick Sort:\n");
                quickSort(arr, 0, n - 1);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 5:
                arr = copy_array(arr1,n);
                printf("Applying Merge Sort:\n");
                mergeSort(arr, 0, n - 1);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 6:
                arr = copy_array(arr1,n);
                printf("Applying Heap Sort:\n");
                heapSort(arr, n);
                printf("Sorted Array: ");
                print_arr(arr, n);
                free(arr);
                break;
            case 7:
                free(arr1);
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

