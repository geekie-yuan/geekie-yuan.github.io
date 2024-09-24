#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
typedef int ElemType;  // 定义元素类型
typedef int Status;    // 定义返回状态类型
typedef struct Node
{
    ElemType data;    // 数据域
    struct Node *next; // 指针域，指向下一个节点
} Node;
typedef struct Node *LinkList;

// 读取链表函数
Status GetElem(LinkList L, int i, ElemType *e) // 输入链表、读取数据链表的位置、存储读取数的地址
{
    int j;
    LinkList p;
    p = L->next;
    j = 1; // 计数器
    while (p && j < i) // 如果链表p不为空、计数器没有等于i
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) // 链表p为空、j超出链表的总数
        return ERROR;
    *e = p->data;
    return OK;
}

// 插入单链表
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;  // 计数器
    LinkList p, s;
    p = *L; // 将p指向链表
    j = 1;
    while (p && j < i) // 当链表p不为空、取值i在链表j内
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node)); // malloc用于生成一个节点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 单链表的删除
Status ListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) // 遍历到第i-1个节点
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i) // 若第i个节点不存在
        return ERROR;
    q = p->next;
    p->next = q->next; // 跳过第i个节点
    *e = q->data;
    free(q); // 释放第i个节点的内存
    return OK;
}

// 单链表的整表创建(头插法)
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0)); // 初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; // 创建带头结点的单链表
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; // 生成1到100之间的随机数
        p->next = (*L)->next;
        (*L)->next = p; // 插到表头
    }
}

// 单链表的整表创建（尾插法）
void CreateListTail(LinkList *L, int n)
{
    LinkList p, r;
    int i;
    srand(time(0)); // 初始化随机数种子
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; // r指向链表尾部
    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; // 生成1到100之间的随机数
        r->next = p;
        r = p; // r指向新的尾部
    }
    r->next = NULL; // 尾结点的next指针置为空
}

// 单链表的清空
Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p); // 释放节点内存
        p = q;
    }
    (*L)->next = NULL; // 头结点的next置为空
    return OK;
}

// 主函数
int main()
{
    LinkList L;
    ElemType e;

    CreateListHead(&L, 5); // 创建5个随机元素的链表（头插法）
    
    // 获取第3个元素
    if (GetElem(L, 3, &e) == OK)
    {
        printf("第3个元素是: %d\n", e);
    }
    else
    {
        printf("获取元素失败\n");
    }

    ListInsert(&L, 3, 99); // 在第3个位置插入99
    
    // 获取第3个元素
    if (GetElem(L, 3, &e) == OK)
    {
        printf("插入后第3个元素是: %d\n", e);
    }

    ListDelete(&L, 3, &e); // 删除第3个位置的元素
    printf("删除的元素是: %d\n", e);

    ClearList(&L); // 清空链表

    return 0;
}
