#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* type);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, void* type);

//Delete the element after the given el
void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list, void* data, size_t size, void* type);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, void* type);

listElement* dequeue(listElement* list);


#endif
