#ifndef LIST_H
#define LIST_H

#include "data-type.h"
#include <stddef.h>

typedef struct Data {
  void *value;
  Type type;
} Data;

typedef struct List {
  Data *data;
  size_t length;
  size_t capacity;

  void (*showElements)(struct List *);
} List;

void showElements(List *self);
#endif // !DEBUG
