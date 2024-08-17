#include "definitions/listint.c"

int main() {
  ListInt myList = initListInt(0);
  printf("Is it empty: %s\n", myList.isEmpty(&myList) ? "true" : "false");

  myList = initListInt(3);
  myList.append(&myList, 1);
  myList.append(&myList, 2);
  myList.append(&myList, 3);
  printf("Length: %zu\n", myList.length);
  printf("Capacity: %zu\n", myList.capacity);
  myList.showElements(&myList);
  printf("Is it empty: %s\n", myList.isEmpty(&myList) ? "true" : "false");

  printf("\n");
  myList.insertAtIndex(&myList, 4, 0);
  printf("Length: %zu\n", myList.length);
  printf("Capacity: %zu\n", myList.capacity);
  myList.showElements(&myList);

  printf("\n");
  myList.insertAtIndex(&myList, 5, 1);
  printf("Length: %zu\n", myList.length);
  printf("Capacity: %zu\n", myList.capacity);
  myList.showElements(&myList);

  printf("\n");
  myList.insertAtIndex(&myList, 6, 4);
  printf("Length: %zu\n", myList.length);
  printf("Capacity: %zu\n", myList.capacity);
  myList.showElements(&myList);

  return 0;
}
