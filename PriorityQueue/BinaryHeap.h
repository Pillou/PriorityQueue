#ifndef BINARYHEAP_H_INCLUDED
#define BINARYHEAP_H_INCLUDED

#define HEAP_MAX_SIZE           (20U)

typedef enum {
    HEAP_OK,
    HEAP_FULL,
    HEAP_EMPTY
} Heap_state_t;

typedef struct {
    Heap_state_t state;
    unsigned int size;
    unsigned int array[HEAP_MAX_SIZE];
} Heap_t;

void PrintHeap( const Heap_t * heap );
Heap_state_t GetHeapState( const Heap_t * heap );
void TestPrintHeap(void);

#endif // BINARYHEAP_H_INCLUDED
