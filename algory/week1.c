//
//  week1.c
//  algo
//
//  Created by 정순재 on 2023/09/05.
//

#include <stdio.h>

//1번 문제
int strlenRe(char* arr) {
    if(*arr == '\0') {
        return 0;
    }

    if (*arr != ' ') {
           return 1 + strlenRe(arr + 1);
       }

    return strlenRe(arr + 1);
}

//2번 문제
void decimalConversion(int n, int b) {
    int arr[1000], i = 0;
    
    if(b < 2 || b > 16) {
        printf("변환 불가.\n");
        return;
    }
    
    while(n >= b) {
        arr[i] = n % b;
        n /= b;
        i++;
    }
    arr[i] = n;
    
    printf("결과 : ");
    while (i >= 0) {
        if(arr[i] >= 10) {
            printf("%c", arr[i] + 55);
        } else {
            printf("%d", arr[i]);
        }
        i--;
    }
    printf("(%d)\n", b);
}

//3번 문제
int noname(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++) {
        if(arr[j] <= x) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    i++;
    int temp = arr[i];
    arr[i] = arr[r];
    arr[r] = temp;
    
    return i + 1;
}

void menu(void) {
    printf("----------------------------\n");
    printf("1. 재귀호출 문자열 길이\n");
    printf("2. 진수 변환\n");
    printf("3. 3번문제\n");
    printf("다른 숫자 입력시 종료.\n");
    printf("----------------------------\n");
    printf("입력 -> ");
}

int main(int argc, const char * argv[]) {
    char text[100];
    int n1, n2, b;
    int arr[100];
    
    while (1) {
        menu();
        scanf("%d", &n1);
        
        if(n1 == 1) {
            printf("\n문자열 입력 : ");
            scanf(" %[^\n]s", text);
            
            printf("결과 : %d\n", strlenRe(text));
        } else if(n1 == 2) {
            printf("\n숫자 진수 입력 : ");
            scanf("%d %d", &n2, &b);
            
            decimalConversion(n2, b);
        } else if(n1 == 3) {
            printf("\n자리수 입력 : ");
            int n3;
            scanf("%d", &n3);
            
            for (int i = 0; i < n3; i++) {
                scanf("%d", &arr[i]);
            }
            
            int p, r;
            printf("p & r : ");
            scanf("%d %d", &p, &r);
            
            printf("입력값 : ");
            for (int i = 0; i < n3; i++) {
                printf("%d", arr[i]);
            }
            
            printf("\n리턴 값 : %d\n", noname(arr, p, r) - 1);
            printf("함수 호출 후 값 : ");
            for (int i = 0; i < n3; i++) {
                printf("%d", arr[i]);
            }
            printf("\n");
        } else {
            break;
        }
    }
    
    return 0;
}

