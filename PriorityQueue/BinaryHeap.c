/** \file BinaryHeap.c
 *  \brief
 * TODO : make automatic tests
 * TODO : switch from unsigned int to arbritary type
 * TODO : finish documentation
 */
#include "BinaryHeap.h"

#ifdef HEAP_TEST
#include <stdio.h>
#endif // HEAP_TEST

/** \brief void InitHeap( Heap_t * heap )
 * Initialize the heap structure
 * \param Heap_t * heap
 * \return void
 */
void InitHeap( Heap_t * heap ){
    heap->size = 0;
}

/** \brief static void _Swap(unsigned int *array, unsigned int a, unsigned int b)
 * local function which swap the value of of index a and index b in the array
 * \param unsigned int *array
 * \param unsigned int a
 * \param unsigned int b
 * \return void
 */
static void _Swap(unsigned int *array, unsigned int a, unsigned int b){
    unsigned int buffer;
    buffer = array[a];
    array[a] = array[b];
    array[b] = buffer;
}

/** \brief static void _HeapSwim( Heap_t * heap, unsigned int index )
 * local function which swim up the element starting at position index
 * \param Heap_t * heap
 * \param unsigned int index
 * \return void
 */
static void _HeapSwim( Heap_t * heap, unsigned int index ){
    while(index > 1 && heap->array[index]<heap->array[index/2]){
        _Swap(heap->array, index, index/2);
        index = index / 2;
    }
}

/** \brief Heap_state_t HeapInsert( Heap_t * heap, unsigned int data)
 *
 * \param Heap_t * heap
 * \param unsigned int data
 * \return Heap_state_t
 */
Heap_state_t HeapInsert( Heap_t * heap, unsigned int data){
    if( heap->size >= HEAP_MAX_SIZE-1 )     return HEAP_ERROR;
    heap->size++;
    heap->array[heap->size] = data;
    _HeapSwim(heap, heap->size);
    if( heap->size >= HEAP_MAX_SIZE-1 )     return HEAP_FULL;
    return HEAP_OK;
}

/** \brief static void _HeapSink( Heap_t * heap, unsigned int index )
 *
 * \param Heap_t * heap
 * \param unsigned int index
 * \return void
 */
static void _HeapSink( Heap_t * heap, unsigned int index ){
    while(2*index <= heap->size){
        unsigned int j = 2*index;
        if( j+1 <= heap->size && heap->array[j]>heap->array[j+1]){
            j++;
        }
        if( heap->array[j] > heap->array[index]){
            break;
        }
        _Swap(heap->array, index, j);
        index = j;
    }
}

/** \brief Heap_state_t HeapGetMin(Heap_t * heap, unsigned int *data )
 *
 * \param Heap_t * heap
 * \param unsigned int *data
 * \return Heap_state_t
 */
Heap_state_t HeapGetMin(Heap_t * heap, unsigned int *data ){
    if( heap->size == 0)    return HEAP_ERROR;
    *data = heap->array[1];
    _Swap(heap->array, 1, heap->size);
    heap->size--;
    _HeapSink(heap, 1);
    if( heap->size == 0)    return HEAP_EMPTY;
    return HEAP_OK;
}



#ifdef HEAP_TEST
static const char *_StateName( Heap_state_t t )
{
    switch(t) {
        case HEAP_OK:       return "HEAP_OK";
        case HEAP_EMPTY:    return "HEAP_EMPTY";
        case HEAP_FULL:     return "HEAP_FULL";
        case HEAP_ERROR:    return "HEAP_ERROR";
        default:            return "BAD STATE";
    }
}

void PrintHeap( const Heap_t * heap ){
    unsigned int i, j;
    printf("Size = %d\n", heap->size);

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
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 11
    };

    Heap_t heap_2 = {
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 0
    };

    Heap_t heap_3 = {
        .array = {0, 1,2,3,4,5,6,7,8,9,10},
        .size = 1
    };

    printf("\nStart testing TestPrintHeap:\n");
    PrintHeap(&heap_1);
    PrintHeap(&heap_2);
    PrintHeap(&heap_3);
}

void TestHeapInsert(void){
    printf("\nStart testing TestHeapInsert:\n");
    Heap_t h;
    InitHeap(&h);
    PrintHeap(&h);
    HeapInsert(&h, 5);
    PrintHeap(&h);
    HeapInsert(&h, 4);
    PrintHeap(&h);
    HeapInsert(&h, 3);
    PrintHeap(&h);
    HeapInsert(&h, 2);
    PrintHeap(&h);
    HeapInsert(&h, 6);
    PrintHeap(&h);
    HeapInsert(&h, 59);
    PrintHeap(&h);
    HeapInsert(&h, 12);
    HeapInsert(&h, 14);
    HeapInsert(&h, 18);
    HeapInsert(&h, 7);
    HeapInsert(&h, 11);
    HeapInsert(&h, 8);
    HeapInsert(&h, 9);
    HeapInsert(&h, 51);
    HeapInsert(&h, 21);
    HeapInsert(&h, 10);
    HeapInsert(&h, 1);
    HeapInsert(&h, 541);
    HeapInsert(&h, 51);
    PrintHeap(&h);
    HeapInsert(&h, 58);
    PrintHeap(&h);
    HeapInsert(&h, 60);
    PrintHeap(&h);
}


void TestHeapGetMin(void){
    unsigned int data;
    printf("\nStart testing TestHeapGetMin:\n");
    Heap_t h;
    InitHeap(&h);
    HeapInsert(&h, 5);
    HeapInsert(&h, 4);
    HeapInsert(&h, 3);
    HeapInsert(&h, 2);
    HeapInsert(&h, 6);
    HeapInsert(&h, 59);
    HeapInsert(&h, 12);
    HeapInsert(&h, 14);
    HeapInsert(&h, 18);
    HeapInsert(&h, 7);
    HeapInsert(&h, 11);
    HeapInsert(&h, 8);
    HeapInsert(&h, 9);
    PrintHeap(&h);
    while(HeapGetMin(&h,&data) == HEAP_OK){
        printf("Get data %d\n", data);
        PrintHeap(&h);
    }
    printf("Get data %d\n", data);
    PrintHeap(&h);
}
#endif // HEAP_TEST
