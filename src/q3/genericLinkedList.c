#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct{
  void* data;
  size_t size;
  void (*printType)();
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* type){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memcpy(dataPointer, data, size);
  e->data = dataPointer;
  e->printType = type;
  e->size = size;
  e->next = NULL;
  return e;
}

int length(listElement* list){
	listElement* current = list;
	int counter = 1;
	
	while (current->next != NULL) {
		counter++;
		current = current->next;
	}
	return counter;
}

void push(listElement** list, void* data, size_t size, void* type){
	listElement* new = createEl(data,size,type);
	new->next = *list;
	*list = new;
}

listElement* pop(listElement** list){
	listElement* l = *list;
	*list = l->next;
	return l;
}

void enqueue(listElement** list, void* data, size_t size, void* type){
	listElement* new = createEl(data,size,type);
	new->next = *list;
	*list = new;
}

listElement* dequeue(listElement* list){
	listElement* current = list;
	while (current->next->next != NULL){
		current = current->next;
	}
	listElement* dequeued = current-> next;
	deleteAfter(current);
	return dequeued;
	
	
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->printType(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size, void* type){
  listElement* newEl = createEl(data, size,type);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
