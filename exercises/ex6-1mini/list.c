#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// put char into a newly created node
Node * create_node(char ch) {
  Node * node = (Node *) malloc(sizeof(Node));
  assert(node); //confirm malloc didn't fail

  node->data = ch;
  node->next = NULL;
  return node;
}

// output the list iteratively
void print(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

int length(const Node * cur)
{
  int i = 0;
  while (cur!=NULL)
  {
    i++;
    cur = cur->next;
  }
  return i;
}

void add_after(Node* cur, char value)
{
  Node *n = (Node *) malloc(sizeof(Node));
  assert(n);
  n->data = value;
  if (cur->next == NULL)
  {
    n->next = NULL;
  }
  else
  {
    n->next = cur->next;
  }
  cur->next = n;
}
//TODO: use recurison.
void reverse_print(Node* cur)
{
  int i = length(cur);
  int index = --i;
  Node* seen[i];
  while(cur != NULL)
  {
    seen[index] = cur;
    cur = cur->next;
    index--;
  }
  for (int x = 0; x < index; ++x)
  {
    printf("%c", seen[x]->data);
  }
}

