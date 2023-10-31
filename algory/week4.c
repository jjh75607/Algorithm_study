//
//  week4.c
//  algo
//
//  Created by 정순재 on 2023/09/26.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cnt = 0;
void insertSort(int arr[], int size) {
    int key;
    int j;
    
    for (int i = 1; i < size; i++) {
        int count = 0;
        key = arr[i];
        
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
            count++;
        }
        
        arr[j + 1] = key;
        
        if(count != i) {
            count += 1;
        }
        
        printf("%d번 비교 / 0번 인덱스 ~ %d번 : ", count, i);
//        printf("%d번 %d ~ %d %d단계 : ", count, i-1, key, i);
        printArray(arr, size);
     
        cnt += count;
    }
    printf("총 비교횟수 : %d\n", cnt);
}

void merge(int data[], int p, int q, int r, int size) {
    int i = p, j = q + 1, k = p;
    int tmp[size];
    
    printf("%d ~ %d 병합 정렬 >> \t", p, r);
    while(i <= q && j <= r) {
        if(data[i] <= data[j]) {
            tmp[k++] = data[i++];
        }
        else {
            tmp[k++] = data[j++];
        }
    }
    
    while(i <= q) {
        tmp[k++] = data[i++];
    }
    while(j <= r) {
        tmp[k++] = data[j++];
    }
    
    for(int a = p; a <= r; a++) {
        data[a] = tmp[a];
    }
    
    printArray(data, size);
}


void mergeSort(int data[], int p, int r, int size) {
    if(p < r) {
        int q = (p + r) / 2;
        mergeSort(data, p , q, size);
        mergeSort(data, q + 1, r, size);
        merge(data, p, q, r, size);
    }
}

void mergeBottom(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left[n1], Right[n2];

    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        }
        else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}


void mergeSortBotton(int arr[], int n) {
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;
            if (right_end >= n)
                right_end = n - 1;

            mergeBottom(arr, left_start, mid, right_end);
        }
    }
}

void menu(void) {
    printf("----------------------------\n");
    printf("1. 삽입정렬\n");
    printf("2. 재귀 병합정렬\n");
    printf("3. 반복 병합정렬\n");
    printf("다른 숫자 입력시 종료.\n");
    printf("----------------------------\n");
    printf("입력 -> ");
}


int main() {
    int n;
    
    while (1) {
        menu();
        scanf("%d", &n);
        
        if(n == 1) {
            int n1;
            
            printf("몇개의 숫자를 입력하시겠습니까 : ");
            scanf("%d", &n1);
            int arr[n1];
            
            printf(">> ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            insertSort(arr, n1);
            
            
        } else if(n == 2) {
            int n1;
            
            printf("몇개의 숫자를 입력하시겠습니까 : ");
            scanf("%d", &n1);
            
            int arr[n1];

            printf(">> ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            mergeSort(arr, 0, n1 - 1, n1);
            
            
        } else if(n == 3) {
            int n1;
            
            printf("몇개의 숫자를 입력하시겠습니까 : ");
            scanf("%d", &n1);
            
            int arr[n1];

            printf(">> ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            mergeSortBotton(arr, n1);
            printArray(arr, n1);
        } else {
            break;
        }
    }
    
    return 0;
}
