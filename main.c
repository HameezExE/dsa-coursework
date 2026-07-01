#include <stdio.h>
#include <stdlib.h>

// Use this to define the size of the registrations list
#define MAX_REG 5

// Below explains how to the system should work

// Define student struct: name, id

// Linked list for student registered list: add, remove, search by id and display
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



Node *registeredHead = NULL;
Node *waitingFront = NULL;
Node *waitingRear = NULL;
Node *dropHistoryTop = NULL;

// Function prototypes needs to be implemented by each team member

Node* createNode(Student student); // Hameez - DONE 

void registerStudentList(Student student); // Dinil - DONE

Node * searchStudent(int studentID); // Mohomed - DONE

void displayRegisteredStudents(); // Chirath -Done

void enqueueWaiting(Student student); // Sadew - DONE
void displayWaitingQueue(); //  Sadew - DONE

Student dequeueWaiting(); //Shalitha - DONE


void pushDropHistory(Student student); // Hirusha
Student popDropHistory();
void displayDropHistory(); // Hirusha


Student inputStudent(); // Vihanga
int countRegisteredStudents();
int isCourseFull(); // Vihanga

Student removeRegisteredStudent(int studentID);


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

void registerStudentList(Student student) // Dinil
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

void enqueueWaiting(Student student) // Sadew
{
    Node *newNode = createNode(student);

    if (waitingRear == NULL)
    {
        waitingFront = newNode;
        waitingRear = newNode;
    }
    else
    {
        waitingRear->next = newNode;
        waitingRear = newNode;
    }

    printf("Student added to waiting queue successfully.\n");
}

Student dequeueWaiting()//Shalitha
{
    Student emptyStudent;
    emptyStudent.id = -1;
    emptyStudent.name[0] = '\0';

    if (waitingFront == NULL)
    {
        printf("Waiting queue is empty.\n");
        return emptyStudent;
    }

    Node *temp = waitingFront;
    Student removedStudent = temp->data;

    waitingFront = waitingFront->next;

    if (waitingFront == NULL)
    {
        waitingRear = NULL;
    }

    free(temp);

    return removedStudent;
}

void displayWaitingQueue() { // Sadew
    if (waitingFront == NULL)
    {
        printf("Waiting queue is empty.\n");
        return;
    }

    Node *current = waitingFront;

    printf("\n--- Waiting Queue ---\n");

    while (current != NULL)
    {
        printf("Student ID: %d\n", current->data.id);
        printf("Student Name: %s\n", current->data.name);
        printf("----------------------\n");

        current = current->next;
    }
}

Node * searchStudent(int studentID){ // mohamed
   
    Node *current = registeredHead;

    while(current != NULL){
        if(current->data.id == studentID){
            return current;
        }
        
        current = current->next;
    }

    return NULL;
}

void displayRegisteredStudents() // Chirath
{
    if (registeredHead == NULL)
    {
        printf("No students are currently registered.\n");
        return;
    }

    Node *current = registeredHead;

    printf("\n--- Registered Students ---\n");
    
    while (current != NULL)
    {
        printf("Student ID: %d\n", current->data.id);
        printf("Student Name: %s\n", current->data.name);
        printf("---------------------------\n");
        
        current = current->next;
    }
}

Student removeRegisteredStudent(int studentID){


    Student empty = {-1, ""};

    Node *temp = registeredHead;
    Node *prev = NULL;

    while(temp != NULL)
    {
     if(temp->data.id == studentID)
        {
            Student removed = temp->data;

            if(prev == NULL)
            {
                registeredHead = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            return removed;
        }

        prev = temp;
        temp = temp->next;
    }

    return empty;

} // Yohan


void pushDropHistory(Student student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Could not record drop.\n");
        return;
    }

    newNode->data = student;
    newNode->next = dropHistoryTop;   
    dropHistoryTop = newNode;         

    dropHistoryTop = newNode;        
    printf("Student %d (%s) added to drop history.\n", student.id, student.name);
}


Student popDropHistory() {
    Student empty = {-1, ""}; 

    if (dropHistoryTop == NULL) {
        printf("Drop history is empty. Nothing to undo.\n");
        return empty;
    }

    Node* temp = dropHistoryTop;
    Student poppedStudent = temp->data;

    dropHistoryTop = dropHistoryTop->next;  
    free(temp);

    return poppedStudent;
}


void displayDropHistory() {
    if (dropHistoryTop == NULL) {
        printf("Drop history is empty.\n");
        return;
    }

    printf("\n--- Drop History (most recent first) ---\n");
    Node* current = dropHistoryTop;
    while (current != NULL) {
        printf("ID: %d, Name: %s\n", current->data.id, current->data.name);
        current = current->next;
    }
    printf("-----------------------------------------\n");
}
//hirusha
