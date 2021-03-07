#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//read stdin to get the binary of a valid UTF-8 file
//count occurence of each character (even invisible ones)
//write a list to stdout with each char in descending order of count
int main() {
  //my list of all unicode characters (stored as lists) and their count
  Node* list = (Node *) malloc(sizeof(Node));

  int c; //getChar() returns an unsigned int (8 bits) cast to int
  //loop through stdin to construct the unicode count list
  while((c = getchar()) != EOF) {
    //create a new list to store a single unicode character
    Node* character = (Node *) malloc(sizeof(Node));
    //if the first bit is 1, there are more characters to follow
    while(c & 0x80 == 1) {
      push(character, c);
      c = getchar();
    }
    //if the first bit is 0 then c is the final or only char in the unicode
    push(character, &c);
    //add the completed character to the unicode list
      if (get(list, &character) == NULL)
        push(list, &character);
      //increment the count
      get(list, &character)->count += 1;
  }

  //sort the list in descending order of occurrence
  list = sort(list);

  //print out the sorted list (to stdout)
  print(list);
  return 0;
}