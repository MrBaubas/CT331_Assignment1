#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");
  
  int len = length(l);
  printf("Number of elements in l: %d\n", len);
  
  
  printf("Pushing el to head of l:\n\n");
  push(&l,"new head(4)", 30);
  
  traverse(l);
  printf("\n");
  
  printf("popping element from head:\n");
  listElement* poppedL = pop(&l);
  
  traverse(l);
    printf("\n");
	
    printf("enqueing element to head:\n");
  enqueue(&l,"new enqueued head(5)", 30);
  
  traverse(l);
    printf("\n");
	
     printf("dequeing element to head:\n");
  listElement* dequeuedEl = dequeue(l);
  
  traverse(l);

  printf("\nTests complete.\n");
}
