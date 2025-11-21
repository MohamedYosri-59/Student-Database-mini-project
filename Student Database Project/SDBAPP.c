#include <stdio.h> // For input/output
#include "SDB.h"   // Include database operations

// Perform action based on user choice
void SDB_action(uint8 choice) {
    uint32 id;            // For user input of ID
    uint8 count;          // For storing number of students
    uint32 ids[MAX_STUDENTS]; // Temporary array for student IDs


    switch (choice) {
        case 1: // Add entry
            if (!SDB_AddEntry())
                printf("Failed to add entry. Database may be full.\n");
            break;
        case 2: // Get size
            printf("Used Size: %d\n", SDB_GetUsedSize());
            break;
        case 3: // Read data by ID
            printf("Enter ID to read: ");
            scanf("%u", &id);
            if (!SDB_ReadEntry(id))
                printf("ID not found.\n");
            break;
        case 4: // Get list of IDs
            SDB_GetList(&count, ids);
            printf("Total IDs: %d\n", count);
            for (uint8 i = 0; i < count; ++i)
                printf("ID[%d]: %u\n", i + 1, ids[i]);
            break;
        case 5: // Check if ID exists
            printf("Enter ID to check: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id))
                printf("ID exists.\n");
            else
                printf("ID does not exist.\n");
            break;
        case 6: // Delete student
            printf("Enter ID to delete: ");
            scanf("%u", &id);
            SDB_DeletEntry(id);
            break;
        case 7: // Check if full
            printf("Is Full: %s\n", SDB_IsFull() ? "Yes" : "No");
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Main application loop
void SDB_APP(void) {
    uint8 choice; // Store user menu choice
    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add entry\n");
        printf("2. Get used size\n");
        printf("3. Read student data\n");
        printf("4. Get list of IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%hhu", &choice); // Read user input

        if (choice == 0) break; // Exit loop
        SDB_action(choice);     // Handle menu choice
    }
}
