#include <stdio.h>     // Standard input/output functions
#include "SDB.h"       // Include header for student database definitions

#define MAX_STUDENTS 10   // Maximum number of students that can be stored

student database[MAX_STUDENTS]; // Array to store student records
uint8 current_size = 0;         // Tracks how many students are currently in the database

// Check if the database is full
bool SDB_IsFull(void) {
    return current_size >= MAX_STUDENTS;
}

// Return the number of students currently stored
uint8 SDB_GetUsedSize(void) {
    return current_size;
}

// Add a new student to the database
bool SDB_AddEntry(void) {
    if (SDB_IsFull()) return false; // If full, return false

    student s; // Temporary student struct to hold data
    printf("Enter Student ID: "); scanf("%u", &s.Student_ID);             // Input student ID
    printf("Enter Student Year: "); scanf("%u", &s.Student_year);         // Input year
    printf("Enter Course 1 ID and Grade: "); scanf("%u %u", &s.Course1_ID, &s.Course1_grade); // Input course 1
    printf("Enter Course 2 ID and Grade: "); scanf("%u %u", &s.Course2_ID, &s.Course2_grade); // Input course 2
    printf("Enter Course 3 ID and Grade: "); scanf("%u %u", &s.Course3_ID, &s.Course3_grade); // Input course 3

    database[current_size++] = s; // Add to database and increment size
    return true;
}

// Delete a student entry by ID
void SDB_DeletEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; ++i) {
        if (database[i].Student_ID == id) {  // Match found
            for (uint8 j = i; j < current_size - 1; ++j) {
                database[j] = database[j + 1]; // Shift entries left
            }
            current_size--;  // Reduce size
            printf("Student ID %u deleted.\n", id);
            return;
        }
    }
    printf("Student ID %u not found.\n", id); // ID not found
}

// Read and display student data by ID
bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < current_size; ++i) {
        if (database[i].Student_ID == id) {
            student s = database[i];
            printf("ID: %u, Year: %u\n", s.Student_ID, s.Student_year);
            printf("Course1: ID=%u, Grade=%u\n", s.Course1_ID, s.Course1_grade);
            printf("Course2: ID=%u, Grade=%u\n", s.Course2_ID, s.Course2_grade);
            printf("Course3: ID=%u, Grade=%u\n", s.Course3_ID, s.Course3_grade);
            return true;
        }
    }
    return false; // ID not found
}

// Get a list of all student IDs and the count
void SDB_GetList(uint8* count, uint32* list) {
    *count = current_size; // Set count
    for (uint8 i = 0; i < current_size; ++i) {
        list[i] = database[i].Student_ID; // Fill ID list
    }
}

// Check if a student ID exists in the database
bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < current_size; ++i) {
        if (database[i].Student_ID == id) return true; // Found
    }
    return false; // Not found
}
