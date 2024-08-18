#ifndef LISTINT_H
#define LISTINT_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ListInt {
  int *data;
  size_t length;
  size_t capacity;

  void (*showElements)(struct ListInt *);
  void (*append)(struct ListInt *, int);
  void (*insertAtIndex)(struct ListInt *, int, int);
  void (*reverseOrder)(struct ListInt *);

  bool (*isEmpty)(struct ListInt *);
  struct ListInt (*sublist)(struct ListInt *, size_t start, size_t end);
  int (*getElementAtIndex)(struct ListInt *, size_t index);

} ListInt;

ListInt initListInt(size_t capacity);
void showElements(ListInt *self);
void append(ListInt *self, int value);
void insertAtIndex(ListInt *self, int value, int index);
void reverseOrder(ListInt *self);
ListInt sublist(ListInt *self, size_t start, size_t end);
int getElementAtIndex(ListInt *self, size_t index);
void resizeCapacity(ListInt *self);
bool isEmpty(ListInt *self);

#endif // !LISTINT_H
