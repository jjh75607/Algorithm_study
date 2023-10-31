//
//  week3.c
//  algo
//
//  Created by 정순재 on 2023/09/19.
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

int count = 1;
int binarySearch(int arr[], int data, int first, int last) {
    int cnt = 1;
    
    while(first <= last) {
        int mid = (first + last) / 2;
        printf("위치 %d ~ %d 범위에서 중간위치 %d의 값 %d와 %d를 비교----%d\n", first, last, mid, arr[mid], data, cnt);
        
        if(data == arr[mid]) {
            return mid;
        } else if(data < arr[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
        count++;
        cnt++;
    }
    
    return -1;
}

int pemutaion_count = 0;
void pemutaion(int arr[], int first, int end, int size) {
    if(first == end) {
        pemutaion_count++;
        printArray(arr, size);
    }
 
    for (int i = first; i <= end; i++) {
        swap(&arr[i], &arr[first]);
        pemutaion(arr, first + 1, end, size);
        swap(&arr[first], &arr[i]);
    }
}

void selectionSort(int arr[], int size) {
    int minIdx = 0;
    int result = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int cnt = 0;
        minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
            cnt++;
        }
    
        swap(&arr[minIdx], &arr[i]);
        printArray(arr, size);
        printf("각 단계 비교횟수 : %d\n", cnt);
        result += cnt;
    }
    printf("전체 비교 횟수 : %d\n", result);
}



void bubbleSort(int arr[], int size, int isExit) {
    for (int i = 0; i < size - 1; i++) {
        int isSwap = 0;
        printf("%d 단계\n", i + 1);
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                isSwap = 1;
            }
            
            if(isSwap && isExit) {
                printArray(arr, size);
            } else if(!isExit) {
                printArray(arr, size);
            }
        }

        if (isSwap == 0 && isExit == 1) {
            printf("정렬이 완료되었습니다. 종료합니다.\n");
            return;
        }
    }
}

void menu(void) {
    printf("----------------------------\n");
    printf("1. 이진검색\n");
    printf("2. 순열 구하기\n");
    printf("3. 선택정렬\n");
    printf("4. 버블정렬\n");
    printf("다른 숫자 입력시 종료.\n");
    printf("----------------------------\n");
    printf("입력 -> ");
}

int main() {
    
    int n;
    
    while(1) {
        menu();
        scanf("%d", &n);
        
        if(n == 1) {
            printf("몇개의 숫자를 입력할지 정해주세요 : ");
            
            int n1, sum = 0;
            scanf("%d", &n1);
            int arr[n1], worst = -1;
            
            printf("숫자 입력 : ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            for (int i = 0; i < n1; i++) {
                count = 1;
                int result = binarySearch(arr, arr[i], 0, n1);
                
                if(result == -1) {
                    printf("존재하지 않는 값입니다.\n");
                } else {
                    printf("%d값은 arr[%d]에 존재하고, 반복 횟수는 %d입니다.\n\n", arr[i], i, count);
                    sum += count;
                    
                    if (count > worst) {
                        worst = count;
                    }
                }
            }
            
            
            printf("A(n) : %.2lf, W(n) : %d\n", (double)sum / n1, worst);
        } else if(n == 2) {
            printf("몇개의 숫자를 입력할지 정해주세요 : ");
            
            int n1;
            scanf("%d", &n1);
            int arr[n1];
            
            printf("숫자 입력 : ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            pemutaion(arr, 0, n1 - 1, n1);
            printf("총 횟수 : %d\n", pemutaion_count);
            pemutaion_count = 0;
            
        } else if(n == 3) {
            printf("몇개의 숫자를 입력할지 정해주세요 : ");
            
            int n1;
            scanf("%d", &n1);
            int arr[n1];
            
            printf("숫자 입력 : ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            printf("\nselectSort - result\n");
            selectionSort(arr, n1);
        } else if(n == 4) {
            printf("몇개의 숫자를 입력할지 정해주세요 : ");
            
            int n1;
            scanf("%d", &n1);
            int arr[n1];
            
            printf("숫자 입력 : ");
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            printf("정렬이 완료된다면 바로 종료하겠습니까? (1[yes] or 0[no]) : ");
            int isExit;
            scanf("%d", &isExit);
            
            bubbleSort(arr, n1, isExit);
        } else {
            break;
        }
    }
    
    return 0;
}
