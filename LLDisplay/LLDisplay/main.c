#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n) {
    int i;
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i=1; i<n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void rDisplay(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data);
        rDisplay(p->next);
    }
}

int count(struct Node *p) {
    int l = 0;
    while (p != 0) {
        l++;
        p = p->next;
    }
    return l;
}

int rCount(struct Node *p) {
    if (p == 0) {
        return 0;
    }
    return rCount(p->next) + 1;
}

int sum(struct Node *p) {
    int sum = 0;
    while (p != 0) {
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int rSum(struct Node *p) {
    if (p == NULL) {
        return 0;
    }
    return rSum(p->next) + p->data;
}

int main(int argc, const char * argv[]) {
    int A[] = {3,5,7,10,16};
    create(A, 5);
    printf("%d \n", rSum(first));
    return 0;
}
