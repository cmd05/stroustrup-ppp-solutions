#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void init(struct List* lst);               /* initialize lst to empty */
struct List* create();                          /* make a new empty list on free store */
void clear(struct List* lst);               /* free all elements of lst */
void destroy(struct List* lst);          /* free all elements of lst, then free lst */
void push_back(struct List* lst, struct Link* p);        /* add p at end of lst */
void push_front(struct List*, struct Link* p);            /* add p at front of lst */

/* insert q before p in lst: */
void insert(struct List* lst, struct Link* p, struct Link* q);
struct Link* erase(struct List* lst, struct Link* p);  /* remove p from lst */
/* return link n “hops” before or after p: */
struct Link* advance(struct Link* p, int n);

struct List {
          struct Link* first;
          struct Link* last;
};
struct Link {    /* link for doubly-linked list */
          struct Link* pre;
          struct Link* suc;
};

void init(struct List* lst)         /* initialize *lst to the empty list */
{
          assert(lst); // check that lst is not a nullptr at compile time
          lst->first = lst->last = 0;
}

struct List* create()             /* make a new empty list */
{
          struct List* lst = (struct List*)malloc(sizeof(struct List));
          init(lst);
          return lst;
}

void clear(struct List* lst)            /* free all elements of lst */
{
    assert(lst);
    {
        struct Link* curr = lst->first;
        while(curr) {
                    struct Link* next = curr->suc;
                    free(curr); // Links are allocated on the free store (Link* is initialized using malloc)
                                // (Link* l = malloc(sizeof(Link*)))
                                // If Links are not allocated on the free store, we should not use free() on
                                // Link*

                                // free(curr) does not free (free-store allocated) memory held by Link members
                                // those must freed manually before calling free(curr) (see chapter_work.c#L309)
                    curr = next;
        }
        lst->first = lst->last = 0;
    }
}

void destroy(struct List* lst)       /* free all elements of lst; then free lst */
{
          assert(lst);
          clear(lst);
          free(lst);
}

void push_back(struct List* lst, struct Link* p)    /* add p at end of lst */
{
    assert(lst);
    {
        struct Link* last = lst->last;
        if (last) {
                    last->suc = p;           /* add p after last */
                    p->pre = last;
        }
        else {
                    lst->first = p;          /* p is the first element */
                    p->pre = 0;
        }
        lst->last = p;            /* p is the new last element */
        p->suc = 0;
    }
}

struct Link* erase(struct List* lst, struct Link* p)
/*
          remove p from lst;
         return a pointer to the link after p
*/
{
    assert(lst);
    if (p==0) return 0;                /* OK to erase(0) */
    if (p == lst->first) {
            if (p->suc) {
                        lst->first = p->suc;     /* the successor becomes first */
                        p->suc->pre = 0;
                        return p->suc;
            }
            else {
                        lst->first = lst->last = 0;    /* the list becomes empty */
                        return 0;
            }
    }
    else if (p == lst->last) {
            if (p->pre) {
                        lst->last = p->pre;       /* the predecessor becomes last */
                        p->pre->suc = 0;
            }
            else {
                        lst->first = lst->last = 0;    /* the list becomes empty */
                        return 0;
            }
    }
    else {
            p->suc->pre = p->pre;
            p->pre->suc = p->suc;
            return p->suc;
    }
}

struct Name {
          struct Link lnk;           /* the Link required by List operations */
          char* p;                       /* the name string */
};

struct Name* make_name(char* n)
{
          struct Name* p = (struct Name*)malloc(sizeof(struct Name));
          p->p = n; 
          return p;
}

int main() {
    int count = 0;
    struct List names;            /* make a list */
    struct List* curr;
    init(&names);
    /* make a few Names and add them to the list: */
    push_back(&names,(struct Link*)make_name("Norah"));
    push_back(&names,(struct Link*)make_name("Annemarie"));
    push_back(&names,(struct Link*)make_name("Kris"));
    /* remove the second name (with index 1): */
    erase(&names,advance(names.first,1));
    curr = names.first;         /* write out all names */
    for (; curr!=0; curr=curr->suc) {
            count++;
            printf("element %d: %s\n", count, ((struct Name*)curr)->p);
    }
}