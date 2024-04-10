#ifndef HQ_MALLOC_H
#define HQ_MALLOC_H
#include<stdio.h>

void *hq_malloc(size_t size);
void hq_free(void *p);

#endif