#include "../headers/list.h"
#include <stdio.h>

/*Data initializeItem(void *data, Type type) {}*/

void printElement(Data data) {
  switch (data.type) {
  case INT:
    printf("%d ", *(int *)data.value);
    break;
  case FLOAT:
    printf("%.2f ", *(float *)data.value);
    break;
  case CHAR:
    printf("%c ", *(char *)data.value);
    break;
  case STRING:
    printf("%s ", (char *)data.value);
    break;
  default:
    break;
  }
}

void showElements(List *self) {
  for (size_t i = 0; i < self->length; i++) {
    printElement(self->data[i]);
  }
}
