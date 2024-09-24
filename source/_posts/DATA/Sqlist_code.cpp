#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

// 定义线性表
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} Sqlist;

// 获取线性表中的元素
Status GetElem(Sqlist L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {  // 验证线性表和索引的有效性
        return ERROR;
    }
    *e = L.data[i - 1];  // 获取第 i 个元素（注意索引从 0 开始）
    return OK;
}

// 插入元素到线性表
Status ListInsert(Sqlist *L, int i, ElemType e) {
    int k;
    if (L->length == MAXSIZE) {  // 线性表满了
        return ERROR;
    }
    if (i < 1 || i > L->length + 1) {  // 检查插入位置的有效性
        return ERROR;
    }
    if (i <= L->length) {  // 插入位置在当前范围内，将元素后移
        for (k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }
    L->data[i - 1] = e;  // 插入元素
    L->length++;  // 更新线性表长度
    return OK;
}

// 删除线性表中的元素
Status ListDelete(Sqlist *L, int i, ElemType *e) {
    int k;
    if (L->length == 0) {  // 线性表为空
        return ERROR;
    }
    if (i < 1 || i > L->length) {  // 检查删除位置的有效性
        return ERROR;
    }
    *e = L->data[i - 1];  // 保存被删除的元素
    if (i < L->length) {  // 将删除位置之后的元素前移
        for (k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
    }
    L->length--;  // 更新线性表长度
    return OK;
}

// 测试程序
int main() {
    Sqlist L;
    L.length = 0;  // 初始化线性表为空
    ElemType e;

    // 插入元素
    ListInsert(&L, 1, 10);
    ListInsert(&L, 2, 20);
    ListInsert(&L, 3, 30);

    // 获取第 2 个元素
    if (GetElem(L, 2, &e) == OK) {
        printf("第 2 个元素为: %d\n", e);
    } else {
        printf("获取元素失败\n");
    }

    // 删除第 2 个元素
    if (ListDelete(&L, 2, &e) == OK) {
        printf("删除的元素为: %d\n", e);
    } else {
        printf("删除元素失败\n");
    }

    // 打印删除后的线性表
    printf("线性表当前元素: ");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    return 0;
}
