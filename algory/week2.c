//
//  week2.c
//  algo
//
//  Created by 정순재 on 2023/09/12.
//

#include <stdio.h>
#include <math.h>

int count = 0;

int digitSumLoop(int n) {
    int result = 0;
    
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    
    return result;
}

int digitSumRecursion(int n) {
    if (n < 10) {
        return n;
    }
    
    return n % 10 + digitSumRecursion(n / 10);
}

int binarySearch(int arr[], int first, int last, int findValue, int cnt) {
    if(first > last) {
        return -1;
    }
    
    int mid = (first + last) / 2;
    printf("위치 %d ~ %d 범위에서 중간위치 %d의 값 %d와 %d를 비교----%d\n", first, last, mid, arr[mid], findValue, cnt);
    
    if(findValue == arr[mid]) {
        count = cnt;
        return mid;
    } else if(findValue > arr[mid]) {
        return binarySearch(arr, mid + 1, last, findValue, cnt + 1);
    } else {
        return binarySearch(arr, first, mid - 1, findValue, cnt + 1);
    }
}

int cn = 0;
void hanoi(int n, char a, char b, char c) {
    if(n == 1) {
        cn++;
        printf("<%d> 원판을 <%c>에서 <%c>로 옮긴다.\n", n, a, c);
    } else {
        hanoi(n - 1, a, c, b);
        cn++;
        printf("<%d> 원판을 <%c>에서 <%c>로 옮긴다.\n", n, a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    int arr[10] = {2, 6, 87, 99, 100, 101, 104, 206, 304, 505};
    int size = sizeof(arr) / sizeof(int);
    

    while (1) {
        double result = 0;
        
        int n;
        scanf("%d", &n);
        
        if(n == 1) {
            int n1;
            scanf("%d", &n1);
            
            printf("%d\n", digitSumLoop(n1));
            printf("%d\n", digitSumRecursion(n1));
        } else if(n == 2) {
            for (int i = 0; i < size; i++) {
                int n = binarySearch(arr, 0, size - 1, arr[i], 1);

                if(n == -1) {
                    printf("존재하지 않는 값입니다.\n");
                } else {
                    printf("====%d위치에 있습니다.====\n", n);
                }
                
                result += count;
            }
            
            printf("\n==평균 : %.2lf / worst case : %.0lf==\n", result / size, ceil(log2(size)));
        } else if(n == 3) {
            int n1;
            scanf("%d", &n1);
            hanoi(n1, 'a', 'b', 'c');
            printf("\n총 횟수 : %d\n", cn);
            cn = 0;//순서변경
        } else {
            break;
        }
    }
    
    return 0;
}
