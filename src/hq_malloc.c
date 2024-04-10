#include<stdlib.h>
#include <string.h>
#include "hq_malloc.h"
#include "general_def.h"

#ifdef BES_PLATFORM
#include"speech_memory.h"
#endif

void *hq_malloc(size_t size)
{  
    #ifdef BES_PLATFORM
    void *p = speech_malloc(size);
    #else
    void *p = malloc(size);
    #endif
    if (p == NULL)
        return NULL;
    memset(p, 0, size);
    return p;
}

void hq_free(void *p)
{
    if (p != NULL){
        #ifdef BES_PLATFORM
            speech_free(p);
        #else
            free(p);
        #endif
    }
}
