#include <stdio.h>
#include <stdlib.h>

//22 17 13 19 30 27 77 32 56 89 15 14
typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* newNode(int key) {
    TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = key;
    temp->left = temp->right = NULL;
    
    return temp;
}

TreeNode* insert(TreeNode* root, int key) {
    if(root == NULL) {
        return newNode(key);
    }
    
    if(key > root->data) {
        root->right = insert(root->right, key);
    } else if(key < root->data) {
        root->left = insert(root->left, key);
    }
    
    return root;
}

void inorder(TreeNode *root) {
    if(root) {
        inorder(root->left);
        printf("[%d]", root->data);
        inorder(root->right);
    }
}

void freeRoot(TreeNode *root) {
    if(root) {
        freeRoot(root->left);
        freeRoot(root->right);
        free(root);
    }
}

TreeNode* searchRecursive(TreeNode* root, int key){
    if(root == NULL) {
        return NULL;
    }
    
    if(root->data == key) {
        return root;
    } else if(root->data > key) {
        return searchRecursive(root->left, key);
    } else {
        return searchRecursive(root->right, key);
    }
}

TreeNode* searchLoop(TreeNode* root, int key) {
    while(root != NULL) {
        if(root->data == key) {
            return root;
        } else if(root->data > key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    
    return NULL;
};

TreeNode* findMaxValue(TreeNode* root) {
    while(root->right != NULL) {
        root = root->right;
    }
    
    return root;
}

TreeNode* findMinValue(TreeNode* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

void menu(void) {
    printf("------------\n");
    printf("1. 순환검색\n");
    printf("2. 반복검색\n");
    printf("3. 중위순회\n");
    printf("4. 제일큰값\n");
    printf("5. 제일작은값\n");
    printf("------------\n");
    printf("입력 --> ");
}

int main(void) {
    TreeNode *root = NULL;
    
    int c;
    printf("입력 할 수 : ");
    scanf("%d", &c);
    printf("%d개의 숫자 입력 : ", c);
    for (int i = 0; i < c; i++) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
//            root = insert(root, i);
    }
    
    while(1) {
        menu();
        
        int n;
        scanf("%d", &n);
        
        if(n == 1) {
            int key;
            printf("찾을 값 입력 : ");
            scanf("%d", &key);
            
            TreeNode * temp = searchRecursive(root, key);
            
            if(temp == NULL) {
                printf("찾는 값이 존재하지 않습니다.\n");
            } else {
                printf("%d는 입력된 배열안에 존재합니다.\n", temp->data);
            }
        } else if(n == 2) {
            int key;
            printf("찾을 값 입력 : ");
            scanf("%d", &key);
            TreeNode *temp = searchLoop(root, key);
            
            if(temp == NULL) {
                printf("찾는 값이 존재하지 않습니다.\n");
            } else {
                printf("%d는 입력된 배열안에 존재합니다.\n", temp->data);
            }
        } else if(n == 3) {
            inorder(root);
        } else if(n == 4) {
            TreeNode *temp = findMaxValue(root);
            printf("가장 큰 값은 %d입니다.\n", temp->data);
        } else if(n == 5) {
            TreeNode *temp = findMinValue(root);
            printf("가장 작은 값은 %d입니다.\n", temp->data);
        } else {
            break;
        }
    }
    
    freeRoot(root);
    return 0;
}
