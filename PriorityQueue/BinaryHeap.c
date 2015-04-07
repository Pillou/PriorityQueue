#include "BinaryHeap.h"

#include <stdio.h>


Heap_state_t GetHeapState( const Heap_t * heap ){
    return heap->state;
}

void PrintHeap( const Heap_t * heap ){
    unsigned int i, j;
    printf("HEAP STATE = %d\n", heap->state);
    printf("0: -\n");
    for(i = 1; i <= heap->size; i*=2){
        for(j = 0; i+j <= heap->size && j<i; j++){
            printf("%d: %d ", i+j, heap->array[i+j]);
        }
        printf("\n");
    }
}


void TestPrintHeap(void){
    Heap_t heap_1 = {
        .state = HEAP_OK,
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 11
    };

    Heap_t heap_2 = {
        .state = HEAP_EMPTY,
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 0
    };

    Heap_t heap_3 = {
        .state = HEAP_OK,
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 1
    };
    PrintHeap(&heap_1);
    PrintHeap(&heap_2);
    PrintHeap(&heap_3);
}
