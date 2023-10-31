//
//  sorted.c
//  algo
//
//  Created by 정순재 on 10/14/23.
//

#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//선택정렬
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
void maxSelectionSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int max = i;
        for (int j = 0; j < i + 1; j++) {
            if(arr[max] < arr[j]) {
                max = j;
            }
        }
        swap(&arr[max], &arr[i]);
    }
}

//버블정렬
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//삽입정렬
void insertSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int x = arr[i], j;
        for (j = i - 1; j >= 0 && arr[j] > x; j--) {
            arr[j + 1] = arr[j];
        }
        
        arr[j + 1] = x;
        printArray(arr, size);
    }
}

//병합정렬
void merge(int arr[], int p, int q, int r) {
    int temp[5];
    int left = p, right = q + 1, n = p;
    
    while(left <= q && right <= r) {
        if(arr[left] < arr[right]) {
            temp[n++] = arr[left++];
        } else {
            temp[n++] = arr[right++];
        }
    }
    
    while(left <= q) {
        temp[n++] = arr[left++];
    }
    
    while(right <= r) {
        temp[n++] = arr[right++];
    }
    
    for (int c = p; c <= r; c++) {
        arr[c] = temp[c];
    }
}
void mergeSort(int arr[], int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

//퀵정렬
//파티션 맨앞
int pa1(int arr[], int p, int r) {
    int x = arr[p];
    int i = p;
    
    for (int j = p + 1; j <= r; j++) {
        if(arr[j] < x) {
            swap(&arr[++i], &arr[j]);
        }
    }
    
    swap(&arr[i], &arr[p]);
    
    return i;
}
//파티션 맨 뒤
int pa2(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        if(arr[j] < x) {
            swap(&arr[++i], &arr[j]);
        }
    }
    
    swap(&arr[++i], &arr[r]);
    
    return i;
}
void quickSort(int arr[], int p, int r) {
    if(p < r) {
        int q = pa1(arr, p, r);
        
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}
//힙정렬
void heapify(int arr[], int root, int size) {
    int left = root * 2, right = left + 1;
    int min;
    
    if(right <= size) {
        if(arr[left] < arr[right]) {
            min = right;
        } else {
            min = left;
        }
    } else if(left <= size) {
        min = left;
    } else {
        return ;
    }
    
    if(arr[min] > arr[root]) {
        swap(&arr[min], &arr[root]);
        heapify(arr, min, size);
    }
}
void bulidHeap(int arr[], int size) {
    for (int i = size / 2; i > 0; i--) {
        heapify(arr, i, size);
    }
    
    printArray(arr, 6);
}
void heapSort(int arr[], int size) {
    bulidHeap(arr, size);
    
    for (int i = size; i > 1; i--) {
        swap(&arr[1], &arr[i]);
        
        heapify(arr, 1, i - 1);
    }
}

//기수정렬
int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int getMaxDig(int max) {
    int cnt = 0;
    while (max > 0) {
        max /= 10;
        cnt++;
    }
            
    return cnt;
}
void radixSort(int arr[], int size) {
    int cnt = 1;
    int o[size];
    
    for (int i = 0; i < getMaxDig(getMax(arr, size)); i++) {
        int b[10] = {0};
        
        for (int j = 0; j < size; j++) {
            b[arr[j] / cnt % 10]++;
        }
        
        for (int j = 1; j < 10; j++) {
            b[j] += b[j - 1];
        }
        
        for (int j = size - 1; j >= 0; j--) {
            o[b[arr[j] / cnt % 10] - 1] = arr[j];
            b[arr[j] / cnt % 10]--;
        }
        
        for (int j = 0; j < size; j++) {
            arr[j] = o[j];
        }
        
        cnt *= 10;
    }
}


int main(void) {
//    int arr[8] = {12, 70, 30, 20, 55, 25, 40, 50};
//    int arr[6];
//    arr[1] = 31;
//    arr[2] = 8;
//    arr[3] = 48;
//    arr[4] = 73;
//    arr[5] = 11;
    
//    pa1(arr, 1, 7);
    int b[8] = {12, 50, 30, 20, 55, 25, 40, 70};
    printArray(b, 8);
    printf("=============\n");
//    selectionSort(arr, 6);
//    bubbleSort(arr, 6);
//    insertSort(arr, 6);
//    mergeSort(arr, 0, 4);
//    quickSort(b, 0, 7);
//    heapSort(arr, 5);
    radixSort(b, 7);
//    ra(b, 7);
//    maxSelectionSort(arr, 6);
    printf("=============\n");
    printArray(b, 8);
    
    return 0;
}
