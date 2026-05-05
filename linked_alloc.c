#include <stdio.h>
#include <stdlib.h>

struct block { int bno; struct block *next; };

int main() {
    int n, bno;
    struct block *start = NULL, *temp, *newnode;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        newnode = (struct block*)malloc(sizeof(struct block));
        printf("Enter block ID: "); scanf("%d", &newnode->bno);
        newnode->next = NULL;
        if(start == NULL) start = newnode;
        else {
            temp = start;
            while(temp->next != NULL) temp = temp->next;
            temp->next = newnode;
        }
    }
    printf("File linked: ");
    temp = start;
    while(temp) { printf("%d -> ", temp->bno); temp = temp->next; }
    printf("NULL\n");
    return 0;
}
