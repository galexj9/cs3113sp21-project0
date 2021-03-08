#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "list.h"

//add a new node with data to the end of a list
Node* push(Node* head, wint_t data) {
  Node* newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;

  if(head->data == 0) {
    head = newNode;
  } else {
    Node* travel = head;
    while(travel->next != NULL) {
      travel = travel->next;
    }
    travel->next = newNode;
  }

  return head;
}

//return the Node pointer with given data
Node* get(Node* head, wint_t data) {
  Node* travel = head;
  while(travel != NULL) {
    if(travel->data == data){
      break;
    }
    travel = travel->next;
  }
  return travel;
}

//returns a new list sorted in descending order by count
Node* sort(Node* head) {
  return head;
}

//prints out a list with its data
void print(Node* head) {
  Node* travel = head;
  while(travel != NULL) {
    if(travel->data == '\n') {
	printf("\\n->%d\n", travel->count);
    } else {
    printf("\%lc", travel->data);
    printf("->%d\n", travel->count);
    }
    travel = travel->next;  
}
}
