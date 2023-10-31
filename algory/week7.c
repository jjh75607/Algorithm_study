//
//  week7.c
//  algo
//
//  Created by 정순재 on 10/17/23.
//

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

typedef struct bucket{
    int data;
    struct bucket *node;
} bucket;

void init(bucket *b) {
    b->data = 0;
    b->node = NULL;
}

void insert(bucket *n, int item) {
    bucket *p = NULL;
    
    bucket *newNode = (bucket *)malloc(sizeof(bucket));
    newNode->data = item;
    newNode->node = NULL;
    
    if(n->node == NULL) {
        n->node = newNode;
        return;
    }
    
    p = n;
    
    while(p->node != NULL) {
        p = p->node;
    }
    
    p->node = newNode;
}

int delete(bucket *data) {
    bucket *p, *n;
    int item;
    
    p = data;
    n = data->node;
    
    if(p == NULL) {
        printf("empty\n");
        return -1;
    }
    
    item = n->data;
    p->node = n->node;
    free(n);
  
    return item;
}


//자리수
int getMax(int arr[], int n) {
    int max = arr[0];
    
    for (int i = 1; i < n; i++)
        if (arr[i] > max) {
            max = arr[i];
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
    int max = getMax(arr, size);
    int cnt = 1;

    bucket bucket[BUCKET_SIZE];
    
    for (int i = 0; i < BUCKET_SIZE; i++) {//0 ~ 9
        init(&bucket[i]);
    }
    
    for (int i = 0; i < getMaxDig(max); i++) { //4
        for (int j = 0; j < size; j++) { // 10
            insert(&bucket[(arr[j] / cnt) % 10], arr[j]);
        }
        
        for (int j = 0, k = 0; j < BUCKET_SIZE; j++) {
            while (bucket[j].node != NULL) {
                arr[k++] = delete(&bucket[j]);
            }
        }
        
        printArray(arr, size);
        cnt *= 10;
    }
}

void display(bucket *p) {
    while (p != NULL) {
        printf("%d => ", p->data);
        p = p->node;
    }
    printf("NULL\n");
}

void sortList(bucket *p1, bucket *p2) {
    bucket *temp = NULL;
    bucket *list = NULL;

    if (p1->data < p2->data) {
        list = p1;
        p1 = p1->node;
    } else {
        list = p2;
        p2 = p2->node;
    }

    temp = list;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            temp->node = p1;
            p1 = p1->node;
        } else {
            temp->node = p2;
            p2 = p2->node;
        }
        temp = temp->node;
    }

    while (p1 != NULL) {
        temp->node = p1;
        temp = temp->node;
        p1 = p1->node;
    }

    while (p2 != NULL) {
        temp->node = p2;
        temp = temp->node;
        p2 = p2->node;
    }

    temp->node = NULL;
    temp = list;
}


void menu(void) {
    printf("------------\n");
    printf("1. 기수정렬\n");
    printf("2. 정렬\n");
    printf("------------\n");
    printf("입력 --> ");
}

int main(void) {
    while(1) {
        menu();
        
        int n;
        scanf("%d", &n);
        
        if(n == 1) {
            printf("몇 자리의 숫자를 입력하시겠습니까. >>");
            
            int n1;
            scanf("%d", &n1);
            int arr[n1];
            
            printf("%d개 숫자 입력 : ", n1);
            for (int i = 0; i < n1; i++) {
                scanf("%d", &arr[i]);
            }
            
            printf("입력된 배열 : ");
            printArray(arr, n1);
            
            radixSort(arr, n1);
            
            printf("정렬된 배열 : ");
            printArray(arr, n1);
        } else if(n == 2) {
            bucket *a1 = (bucket *)malloc(sizeof(bucket));
            bucket *a2 = (bucket *)malloc(sizeof(bucket));
            bucket *a3 = (bucket *)malloc(sizeof(bucket));
            bucket *a4 = (bucket *)malloc(sizeof(bucket));
            
            a1->data = 5;
            a1->node = a2;

            a2->data = 7;
            a2->node = a3;
            
            a3->data = 24;
            a3->node = a4;
            
            a4->data = 56;
            a4->node = NULL;
            
            
            bucket *b1 = (bucket *)malloc(sizeof(bucket));
            bucket *b2 = (bucket *)malloc(sizeof(bucket));
            bucket *b3 = (bucket *)malloc(sizeof(bucket));
            bucket *b4 = (bucket *)malloc(sizeof(bucket));
            bucket *b5 = (bucket *)malloc(sizeof(bucket));
            
            b1->data = 19;
            b2->data = 45;
            b3->data = 61;
            b4->data = 79;
            b5->data = 82;
            
            b1->node = b2;
            b2->node = b3;
            b3->node = b4;
            b4->node = b5;
            b5->node = NULL;
            
            sortList(a1, b1);
            display(a1);
          
        } else {
            break;
        }
    }
    
    return 0;
}


