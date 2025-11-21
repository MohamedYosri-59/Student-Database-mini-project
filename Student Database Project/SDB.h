#ifndef SDB_H    // Include guard
#define SDB_H

#include "STD.h" // Include standard types and boolean enum
#define MAX_STUDENTS 10  // Maximum number of students

// Define structure for student data
typedef struct {
    uint32 Student_ID;        // Unique identifier for student
    uint32 Student_year;      // Year of enrollment or study
    uint32 Course1_ID;        // ID of first course
    uint32 Course1_grade;     // Grade in first course
    uint32 Course2_ID;        // ID of second course
    uint32 Course2_grade;     // Grade in second course
    uint32 Course3_ID;        // ID of third course
    uint32 Course3_grade;     // Grade in third course
} student;

// Function declarations for student database operations
bool SDB_IsFull(void);                       // Checks if database is full
uint8 SDB_GetUsedSize(void);                // Gets number of students in database
bool SDB_AddEntry(void);                    // Adds a new student entry
void SDB_DeletEntry(uint32 id);             // Deletes entry by student ID
bool SDB_ReadEntry(uint32 id);              // Reads and prints entry by student ID
void SDB_GetList(uint8* count, uint32* list); // Gets list of student IDs
bool SDB_IsIdExist(uint32 id);              // Checks if an ID exists


#endif // SDB_H
