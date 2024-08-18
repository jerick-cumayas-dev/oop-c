#include "../headers/listint.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void showListElements(ListInt *self) {
  for (size_t i = 0; i < self->length; i++) {
    printf("%d ", self->data[i]);
  }
  printf("\n");
}

void resizeCapacity(ListInt *self) {
  self->capacity = self->capacity + 1;
  int *newData = realloc(self->data, self->capacity * sizeof(int));
  self->data = newData;
  self->length = self->length + 1;
}

void append(ListInt *self, int value) {
  if (self->length == self->capacity) {
    resizeCapacity(self);
  }
  self->data[self->length++] = value;
}

void insertAtIndex(ListInt *self, int value, int index) {
  resizeCapacity(self);

  if (self == NULL) {
    append(self, value);
    return;
  } else {
    if (index >= 0 && index <= self->length) {
      size_t lastIndex = self->length - 1;
      for (size_t i = lastIndex; i > index; i--) {
        self->data[i] = self->data[i - 1];
      }
      self->data[index] = value;
    }
  }
}

void reverseOrder(ListInt *self) {
  int *reversed = (int *)malloc(self->capacity * sizeof(int));

  size_t i = 0;
  size_t j = self->capacity - 1;
  for (size_t k = 0; k < self->capacity / 2; k++) {
    reversed[i] = self->data[j];
    i += 1;
    j -= 1;
  }

  self->data = reversed;
}

bool isEmpty(ListInt *self) { return self->length == 0; }

int getElementAtIndex(ListInt *self, size_t index) {
  if (index >= 0 && index < self->length) {
    return self->data[index];
  }
  return 0;
}

ListInt sublist(ListInt *self, size_t start, size_t end) {
  int difference;
  if (end > start) {
    difference = end - start;
  }

  ListInt sub = initListInt(difference);

  for (size_t i = start; i < end; i++) {
    sub.append(&sub, self->getElementAtIndex(self, i));
  }

  return sub;
}

ListInt initListInt(size_t capacity) {
  ListInt newList;

  newList.capacity = capacity;
  newList.data = (int *)malloc(capacity * sizeof(int));
  newList.length = 0;

  newList.showElements = showListElements;
  newList.append = append;
  newList.reverseOrder = reverseOrder;
  newList.insertAtIndex = insertAtIndex;
  newList.getElementAtIndex = getElementAtIndex;
  newList.sublist = sublist;
  newList.isEmpty = isEmpty;

  return newList;
}
