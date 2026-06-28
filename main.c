#include <stdio.h>
#include <stdlib.h>

// Use this to define the size of the registrations list
#define MAX_REG 5

// Below explains how to the system should work

// Define student struct: name, id

// Linked list for student registered list: add, remove, search by id, display
// Linked list queue for waiting list: add when registration is full, remove when space is available, display
// Linked list stack for drop history: push when a student drops, pop when a student undo it, display
//
// 1. First accommodate 5 registered students
// 2. When registration is full, add students to the waiting list
// 3. When a student drops the course: remove from the registrations list, add to drop history stack, move first student from waiting to registered list
// 4. When a student undoes a drop: if space available in registrations list, remove from drop history stack and add to registered list, else move to waiting list

// Implement main menu

typedef struct Student
{
    int id;
    char name[100];
} Student;

typedef struct Node
{
    Student data;
    struct Node *next;
} Node;

// Function prototypes needs to be implemented by each team member

Node* createNode(Student student); // Hameez

void registerStudentList(Student student); // Dinil

Student removeRegisteredStudent(int studentID); // Yohan

Node * searchStudent(int studentID); // Mohomed

void displayRegisteredStudents(); // Chirath

void enqueueWaiting(Student student); // Sadwew
Student dequeueWaiting();
void displayWaitingQueue(); // Sadwew

void pushDropHistory(Student student); // Hirusha
Student popDropHistory();
void displayDropHistory(); // Hirusha


Student inputStudent(); // Vihanga
int countRegisteredStudents();
int isCourseFull(); // Vihanga

Node *registeredHead = NULL;

int main(){
    // Hameez
    return 0;
}

Node* createNode(Student student)
{
    Node *new = (Node *)malloc(sizeof(Node));


    if (new == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new->data = student;
    new->next = NULL;

    return new;
}

void registerStudentList(Student student)
{
    Node *newNode = createNode(student);

    if (registeredHead == NULL)
    {
        registeredHead = newNode;
        return;
    }

    Node *temp = registeredHead;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}