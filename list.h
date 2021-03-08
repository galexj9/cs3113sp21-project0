//prevents header file from being processed twice
#ifndef LIST_H_
#define LIST_H_
#include <wchar.h>

typedef struct Node {
  int count;
  wint_t data;
  struct Node* next;
} Node;

extern Node* push(Node* head, Node* newNode);

extern Node* get(Node* head, wint_t data);

extern void sort(Node* head);

extern void print(Node* head);

#endif
