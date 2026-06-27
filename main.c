#include <stdio.h>
#include <stdlib.h>

// Define student struct: name, id
//
// Linked list for student registered list: add, remove, search by id, display
// Linked list queue for waiting list: add when registration is full, remove when space is available, display
// Linked list stack for drop history: push when a student drops, pop when a student undo it, display
//
// 1. First accommodate 5 registered students
// 2. When registration is full, add students to the waiting list
// 3. When a student drops the course: remove from the registrations list, add to drop history stack, move first student from waiting to registered list
// 4. When a student undoes a drop: if space available in registrations list, remove from drop history stack and add to registered list, else move to waiting list
//
// Implement main menu

int main(){
    printf("Hello World! \n");
}
