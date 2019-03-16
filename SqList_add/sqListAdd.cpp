#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;
}ListNode,*LNode;

ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
    int carry = 0;
    ListNode *sum;
    sum = (ListNode *)malloc(sizeof(ListNode));
	if(sum == NULL){
		printf("空间分配失败.\n");
		exit(0);
	}
    ListNode *r,*p11,*p22,*s;
    r = sum;
	p11 = l1->next;
	p22 = l2->next;
    while(p11 != NULL && p22 != NULL){
        s = (ListNode *)malloc(sizeof(ListNode));
		if(s == NULL){
			printf("空间分配失败.\n");
			exit(0);
		}
        s->val = (p11->val + p22->val + carry)%10;
		if(p11->val + p22->val != 9)
			carry = 0;
        r->next = s;
        r = s;
        carry = (p11->val + p22->val + carry)/10;
        p11 = p11->next;
        p22 = p22->next;
    }
    while(p11 != NULL){
        s = (ListNode *)malloc(sizeof(ListNode));
		if(s == NULL){
			printf("空间分配失败.\n");
			exit(0);
		}
        s->val = p11->val  + carry;
        r->next = s;
        r = s;
		p11 = p11->next;
        carry = 0;
    }
    while(p22 != NULL){
        s = (ListNode *)malloc(sizeof(ListNode));
		if(s == NULL){
			printf("空间分配失败.\n");
			exit(0);
		}
        s->val = p22->val + carry;
        r->next = s;
        r = s;
		p22 = p22->next;
        carry = 0;
    }
	if(carry != 0){                                 //处理两个等长链表相加完后最高位的进位
		s = (ListNode *)malloc(sizeof(ListNode));
		if(s == NULL){
			printf("空间分配失败.\n");
			exit(0);
		}
        s->val = carry;
        r->next = s;
        r = s;
	}
	r->next = NULL;
    return sum;
}
//头插法建立单链表
ListNode *creatList(){
	int x;
	LNode L = (ListNode *)malloc(sizeof(ListNode));
	if(L == NULL){
		printf("空间分配失败.\n");
		exit(0);
	}
	ListNode *s;
	L->next = NULL;
	scanf_s("%d",&x);
	while(x != -999){
		s = (ListNode *)malloc(sizeof(ListNode));
		if(s == NULL){
			printf("空间分配失败.\n");
			exit(0);
		}
		s->val = x;
		s->next = L->next;
		L->next = s;
		scanf_s("%d",&x);
	}
	return L;
}
//尾插法建立单链表
ListNode *creatList2(){
	int x;
	ListNode *L;
	L = (ListNode *)malloc(sizeof(ListNode));
	ListNode *s,*r = L;
	scanf_s("%d",&x);
	while(x != -999){
		s = (ListNode *)malloc(sizeof(ListNode));
		s->val = x;
		r->next = s;
		r = s;
		scanf_s("%d",&x);
	}
	r->next = NULL;
	return L;
}
int main(){
	ListNode *L1,*L2,*L;
	L1 = creatList();
	ListNode *p,*p1,*p2;
	p1 = L1->next;
	while(p1 != NULL){
		printf("%d->",p1->val);
		p1 = p1->next;
	}
	printf("\n");
	L2 = creatList();
	p2 = L2->next;
	while(p2 != NULL){
		printf("%d->",p2->val);
		p2 = p2->next;
	}
	printf("\nresult:\n");
	L = addTwoNumbers(L1,L2);
	p = L->next;
	while(p != NULL){
		printf("%d->",p->val);
		p = p->next;
	}
	system("pause");
	return 0;
}