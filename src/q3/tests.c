#include <stdio.h>
#include "tests.h"
#include "genericLinkedList.h"

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

void printInt(void* data) { 
	printf("%d\n", *(int*)data);
}

void printStr(void* data) {
	printf("%s\n", (char*)data);
}

void printDoub(void* data){
	printf("%f\n", *(double*)data);
}

void runTests(){
  printf("Tests running...\n");
  int testInt = 16;
  double testDoub = 1.78;
  char testChar = 'c';
  
  listElement* l = createEl(&testInt, 30, &printInt);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30, &printStr);
  insertAfter(l2, &testChar, 30, &printChar);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");
  
  int len = length(l);
  printf("Number of elements in l: %d\n", len);
  
  
  printf("Pushing el to head of l:\n\n");
  push(&l,&testDoub, 30, &printDoub);
  
  traverse(l);
  printf("\n");
  
  printf("popping element from head:\n");
  listElement* poppedL = pop(&l);
  
  traverse(l);
    printf("\n");
	
    printf("enqueing element to head:\n");
  enqueue(&l,"new enqueued head(5)", 30, &printStr);
  
  traverse(l);
    printf("\n");
	
     printf("dequeing element to head:\n");
  listElement* dequeuedEl = dequeue(l);
  
  traverse(l);

  printf("\nTests complete.\n");
}
