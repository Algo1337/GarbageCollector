#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "gc.h"

GarbageCollector *gc = NULL;

int main() { 
    gc = start_gc(1);
    int bin_id = gc->CreateBin(gc);

    char *foo = strdup("foo");

    gc->AddToBin(gc, bin_id, GARBAGE_STRING, (void *)foo);

    gc->DestroyBin(gc, bin_id);
    gc->DestroyGC(gc);

    free(gc);
    foo = NULL; // remove dangling pointer
    return 0;
}