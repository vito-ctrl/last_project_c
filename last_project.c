#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct details {
    char title[100];
    char description[100];
    char date[11];
    int priority;
};

//---------------------------------------------------
// functions call 
int addTask(struct details tasks[], int tk);
int verify_day(int day, int month, int year);
void viewTasks(struct details tasks[], int tk);
void editTask(struct details tasks[], int tk);
int deleteTask(struct details tasks[], int tk);
void filterByPriority(struct details tasks[], int tk, int priority);

//-------------------------------------------------------------------

int main() {
    struct details tasks[100];
    int tk = 0;
    int capacity = 2;
    int option;
    int quit = 1;

    do {
        // Display the menu
        printf("\n<<<<<<<<<<<<<<<<menu>>>>>>>>>>>>>>>>>>>\n");
        printf("\n1 .    add a task      . \n");
        printf("2 .  view all tasks    . \n");
        printf("3 .    edit a task     . \n");
        printf("4 .   delete a task    . \n");
        printf("5 . filter by Priority . \n");
        printf("6 .       Quit         . \n");
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Enter an number option from 1 to 6: ");
        scanf("%d", &option);
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

        // Execute function based on user input
        if (option >= 1 && option <= 6) {
            switch (option) {
                case 1:
                    tk = addTask(tasks, tk);
                    break;
                case 2:
                    viewTasks(tasks, tk);
                    break;
                case 3:
                    editTask(tasks, tk);
                    break;
                case 4:
                    tk = deleteTask(tasks, tk);
                    break;
                case 5:
                    int priority;
                    printf("Enter priority to filter by (1 for high, 0 for low): ");
                    scanf("%d", &priority);
                    filterByPriority(tasks, tk, priority);
                    break;
                case 6:
                    printf("thank you for using One Hand Task Manager. Goodbye!");
                    quit = 0; 
                    break;
            }
        }else if(option > 6 || option < 1){
            printf("invalide operation !");
        }
    }while(quit == 1);
    return 0;
}


// ------------------------------------------------------------------------

int verify_day(int day, int month, int year) {
    if (year < 1000 || year > 9999) 
        return 0;
    if (month < 1 || month > 12) 
        return 0;
    if (day < 1 || day > 31) 
        return 0;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29)
                return 0;
        } else {
            if (day > 28)
                return 0;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return 0;
    }
    return 1;
}

//----------------------------------------------------------------------------
int addTask(struct details tasks[], int tk) {
    int day, month, year;
    printf("\n<<<<<<<<<<<<<<add task>>>>>>>>>>>>>>>\n");
    printf("\nTask title: ");
    scanf(" %[^\n]", tasks[tk].title);
    printf("\nTask description: ");
    scanf(" %[^\n]", tasks[tk].description);

    // while function for valide date
    while (1) {
        printf("\nTask date in this format (MM-DD-YYYY): ");
        scanf("%d-%d-%d", &month, &day, &year);
        if (verify_day(day, month, year)) {
            sprintf(tasks[tk].date, "%02d-%02d-%04d", month, day, year);
            break;
        } else {
            printf("Invalid date. Please enter a valid date in MM-DD-YYYY format.\n");
        }
    }

    // do loop for invalid priority
    do{
    printf("\nTask priority (1 for high, 0 for low): ");
    scanf("%d", &tasks[tk].priority);
    if (tasks[tk].priority != 1 && tasks[tk].priority != 0) {
        printf("Invalid number. Please enter a valid number.\n");
    }
    }while (tasks[tk].priority != 1 && tasks[tk].priority != 0);
    printf("\nYour task has been successfully added !");
    
    printf("\n<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
    return tk + 1;
}

//--------------------------------------------------------------------------------

void viewTasks(struct details tasks[], int tk) {
    printf("\n<<<<<<<<<<<<<<view tasks>>>>>>>>>>>>>>>\n");
    for (int i = 0; i < tk; i++) {
        printf("\nTask %d:\n", i + 1);
        printf("\nTitle: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Date: %s\n", tasks[i].date);
        printf("Priority: %s\n", tasks[i].priority ? "High" : "Low");
        printf("\n");
    }
    printf("No tasks to display. Please add a task ");
}

//------------------------------------------------------------------------------

void editTask(struct details tasks[], int tk) {
    int day, month, year;
    int taskNumber;
    printf("\n<<<<<<<<<<<<<<edit task>>>>>>>>>>>>>>>\n");

    // do loop for invalide task number
    do{
    printf("\nEnter the task number to edit: ");
    scanf("%d", &taskNumber);

    }while(taskNumber > tk || taskNumber < tk);
    if (taskNumber > 0 && taskNumber <= tk) {
        taskNumber--; // Adjust for zero-based index
        printf("Editing Task number %d:\n", taskNumber + 1);
        printf("\nNew title: ");
        scanf(" %[^\n]", tasks[taskNumber].title);
        printf("\nNew description: ");
        scanf(" %[^\n]", tasks[taskNumber].description);

        // while loop for valide edit date 
        while (1) {
        printf("\nTask date in this format (MM-DD-YYYY): ");
        scanf("%d-%d-%d", &month, &day, &year);
        if (verify_day(day, month, year)) {
            sprintf(tasks[taskNumber].date, "%02d-%02d-%04d", month, day, year);
            break;
        } else {
            printf("Invalid date. Please enter a valid date in MM-DD-YYYY format.\n");
            }
        }
        // do loop for valide priority
        do{
            printf("\nNew priority (1 for high, 0 for low): ");
            scanf("%d", &tasks[taskNumber].priority);
        }while(tasks[taskNumber].priority != 0 && tasks[taskNumber].priority != 1);
        printf("Task updated successfully!");
    }
}

//---------------------------------------------------------------------------------

int deleteTask(struct details tasks[], int tk) {
    int taskNumber;
    printf("\n<<<<<<<<<<<<<<delete task>>>>>>>>>>>>>>>\n");
    printf("Enter the task number to delete: ");
    scanf("%d", &taskNumber);
    if (taskNumber > 0 && taskNumber <= tk) {
        taskNumber--; // Adjust for zero-based index
        for (int i = taskNumber; i < tk - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        tk--; // Decrement the number of tasks
        printf("Task %d deleted successfully!\n", taskNumber + 1);
    } else {
        printf("Invalid task number.\n");
    }
    return tk; // Return the updated number of tasks
}
//-----------------------------------------------------------------------------

void filterByPriority(struct details tasks[], int tk, int priority) {
    printf("\n<<<<<<<<<<<<<<filter tasks>>>>>>>>>>>>>>>\n");
    for (int i = 0; i < tk; i++) {
        if (tasks[i].priority == priority) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Date: %s\n", tasks[i].date);
            printf("Priority: %s\n", tasks[i].priority ? "High" : "Low");
            printf("\n");
        }
    }
            printf("No tasks found");
}