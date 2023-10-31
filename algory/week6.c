//
//  week6.c
//  algo
//
//  Created by 정순재 on 10/10/23.
//

#include <stdio.h>
#include <stdlib.h>


int heap[101];
int heapSize = 0;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isMaxHeapRecursive(int arr[], int n, int k) {
    int left = k * 2;
    int right = (k * 2) + 1;

    if (left <= n && arr[left] > arr[k]) {
        return -1;
    } else if (left <= n) {
        if(isMaxHeapRecursive(arr, n, left) == -1) {
            return -1;
        }
    }

    if (right <= n && arr[right] > arr[k]) {
        return -1;
    } else if (right <= n) {
        if(isMaxHeapRecursive(arr, n, right) == -1) {
            return -1;
        }
    }

    return 1;
}

int isMaxHeapLoop(int arr[], int n) {
    int i = 1;

    while (i <= n) {
        int left = i * 2;
        int right = left + 1;

        if (left <= n && arr[left] > arr[i]) {
            return -1;
        }

        if (right <= n && arr[right] > arr[i]) {
            return -1;
        }

        i++;
    }

    return 1;

}

void heapify(int arr[], int k, int n) {
    int left = k * 2;
    int right = (k * 2 )+ 1;
    int max;
    
    if(right <= n) {
        if(arr[left] > arr[right]) {
            max = left;
        } else {
            max = right;
        }
    } else if(left <= n) {
        max = left;
    } else {
        return;
    }
    
    if(arr[max] > arr[k]) {
        swap(&arr[max], &arr[k]);
        printf("heapify : ");
        printArray(arr, n);
        heapify(arr, max, n);
    }
}

void bulidHeap(int arr[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, i, n);
        
        printf("bulidHeap : ");
        printArray(arr, n);
    }
}

void heapSort(int arr[], int size) {
    bulidHeap(arr, size);
    
    for (int i = size; i > 1; i--) {
        swap(&arr[1], &arr[i]);
        heapify(arr, 1, i - 1);
        
        printf("heapsort : ");
        printArray(arr, size);
    }
}

void menu(void) {
    printf("----------------------------\n");
    printf("1. 힙정렬\n");
    printf("2. 최대힙인지 확인\n");
    printf("3. 우선순위 큐\n");
    printf("다른 숫자 입력시 종료.\n");
    printf("----------------------------\n");
    printf("입력 -> ");
}

void insertQueue(int data) {
    if(heapSize <= 100) {
        heap[++heapSize] = data;
        bulidHeap(heap, heapSize);
    } else {
        printf("is full\n");
    }
}

int deleteQueue(void) {
    if(heapSize == 0) {
        return -1;
    }
    
    int deleteItem = heap[1];
    heap[1] = heap[heapSize--];
    
    heapify(heap, 1, heapSize);
    
    return deleteItem;
}

int main(void) {
    while (1) {
        int ch;
        
        menu();
        scanf("%d", &ch);
        
        if(ch == 1) {
            int n;
            printf("몇개의 정수를 입력하시겠습니까.");
            scanf("%d", &n);
            int arr[n + 1];

            printf("==>");
            for (int i = 1; i <= n; i++) {
                scanf("%d", &arr[i]);
            }
            
            heapSort(arr, n);
        } else if(ch == 2) {
            printf("1 : 반복, 2 : 재귀 -->");
            int ch2;
            scanf("%d", &ch2);
            
            int n;
            printf("몇개의 정수를 입력하시겠습니까.");
            scanf("%d", &n);
            int arr[n + 1];
            
            printf("==>");
            for (int i = 1; i <= n; i++) {
                scanf("%d", &arr[i]);
            }
            
            if(ch2 == 1) {
                printf("%d\n", isMaxHeapLoop(arr, n));
            } else if(ch2 == 2) {
                printf("%d\n", isMaxHeapRecursive(arr, n, 1));
            }
        } else if(ch == 3) {
            printf("1. 삽입, 2. 삭제, 3. 출력 =>");
            
            int ch2;
            scanf("%d", &ch2);
            
            if(ch2 == 1) {
                printf("삽입 할 데이터 입력 : ");
                int n;
                scanf("%d", &n);
                insertQueue(n);
            } else if(ch2 == 2) {
                int temp = deleteQueue();
                
                if(temp == -1) {
                    printf("공백\n");
                } else {
                    printf("삭제된 데이터 : %d\n", temp);
                }
            } else if(ch2 == 3) {
                printArray(heap, heapSize);
            }
        } else {
            break;
        }
    }
}
