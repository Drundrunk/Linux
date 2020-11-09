#include <stdio.h>
#include <stdlib.h>
 
#define M_500M (500 * 1024 * 1024)
 
typedef struct list {
    struct list *prev;
    void *mem;
} list;
 
list *head;
list *cur;
int count = 0;
int max = 0;
 
void malloc_mem()
{
    list *p = NULL;
 
    do {
        p = (list *)malloc(sizeof(list));
 
        if (p == NULL) {
            max = count;
            return;
        }
 
        p->prev = cur;
 
        p->mem = malloc(M_500M);
 
        if (p->mem == NULL) { // Malloc failed
            free(p);
            max = count;
            return;
        }
 
        count++;
//        printf("malloc count %d, malloc addr %p\n", count, p->mem);
        cur = p;
    } while (1);
}
 
 
void free_mem()
{
    list *p = NULL;
 
    do {
        if (cur == head)
            return;
        p = cur;
        cur = cur->prev;
 
//        printf("free count %d, malloc addr %p\n", count, p->mem);
        count--;
 
        free(p->mem);
        free(p);
    } while (1);
}
 
int main()
{
	/*
    int count = 0;
    while(malloc(1<<20))
    {
        count++;
    }
    printf("%d\n",count);
*/
    head = malloc(sizeof(list));
    cur = head;
 
    malloc_mem();
    free_mem();
 
    printf("we malloced %dG\n", (max / 2));
}
