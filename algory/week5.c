//
//  week5.c
//  algo
//
//  Created by 정순재 on 2023/10/03.
//

#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printSeqAraay(int arr[], int p, int r) {
    printf("범위 : %d ~ %d\n", p, r);
    printArray(arr, r + 1);
    printf("\n");
}

//맨 마지막 위치를 피봇으로
int partition1(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        if(arr[j] <= x) {
            swap(&arr[++i], &arr[j]);
        }
    }
    
    swap(&arr[++i], &arr[r]);
    
    printSeqAraay(arr, p, r);
    
    return i;
}

//맨 앞의 위치를 피봇으로
int partition2(int arr[], int p, int r) {
    int x = arr[p];
    int i = p;
    
    for (int j = p + 1; j <= r; j++) {
        if(arr[j] <= x) {
            swap(&arr[++i], &arr[j]);
        }
    }
    
    swap(&arr[i], &arr[p]);
    
    printSeqAraay(arr, p, r);
    
    return i;
}

int p(int arr[], int left, int right) {
    int i = arr[left];
    int leftI = left + 1;
    int rightI = right;
    
    while (leftI <= rightI) {
        while (arr[leftI] < i) {
            leftI++;
        }
        
        while (arr[rightI] > i) {
            rightI--;
        }
        
        if(leftI < rightI) {
            swap(arr[leftI], arr[rightI])l
        }
    }
}

//정렬할 범위를 직접 선택하는 코드
int partition3(int arr[], int left, int right) {
    int pivotValue = arr[left]; //피벗
    int leftMark = left + 1;
    int rightMark = right;
    
    while(leftMark <= rightMark) {
        while (arr[leftMark] <= pivotValue) {
            leftMark++;
        }
        while(arr[rightMark] > pivotValue) {
            rightMark--;
        }
        
        if(leftMark < rightMark) {
            swap(&arr[leftMark], &arr[rightMark]);
        }
    }
    swap(&arr[left], &arr[rightMark]);
    
    printSeqAraay(arr, left, right);
    
    return rightMark;
}

void quickSort(int arr[], int p, int r, int n) {
    if(p < r) {
        int q = 0;
        
        if(n == 1) {
            q = partition1(arr, p, r);
        } else if(n == 2) {
            q = partition2(arr, p, r);
        } else {
            q = partition3(arr, p, r);
        }
        
        quickSort(arr, p, q - 1, n);
        quickSort(arr, q + 1, r, n);
    }
}

int main(void) {
    while (1) {
        int n1;
        printf("1. 피벗이 맨 마지막, 2. 맨 앞, 3. 정렬할 범위 지정\n>>");
        scanf("%d", &n1);
        
        if(n1 <= 0 || n1 > 3) {
            printf("범위 내의 숫자 입력\n");
            continue;
        }
        
        int n;
        
        printf("몇개의 숫자를 입력하시겠습니까 : ");
        scanf("%d", &n);
        
        if(n <= 0) {
            break;
        }
        
        int arr[n];
        
        printf("숫자 입력 : ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        printf("정렬 전 : ");
        printArray(arr, n);
        printf("\n");
        
        if(n1 == 3) {
            int p, r;
            printf("시작 값, 끝 값 : ");
            scanf("%d %d", &p, &r);
            
            quickSort(arr, p, r, n1);
        } else {
            quickSort(arr, 0, n - 1, n1);
        }
        
        printf("끝 : ");
        printArray(arr, n);
    }
    
    return 0;
}
