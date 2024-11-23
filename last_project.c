#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct details{
    char title[100];
    char description[100];
    char date[11];
    int priority;
};
// fonction to make writing date in the right way 
int verify_day(int day, int month, int year) { 
        if (year < 1000 && year > 9999) 
        return 0; 
        if (month < 1 && month > 12) 
        return 0; 
        if (day < 1 && day > 31) 
        return 0; 
    // Check for February 
    if (month == 2) { 
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { 
            if (day > 29) 
            return 0; 
        } else { 
            if (day > 28) 
            return 0; 
        } 
    } // Check for months with 30 days 
    if (month == 4 || month == 6 || month == 9 || month == 11) { 
        if (day > 30) 
        return 0; 
    } 
    return 1; 
} 


void addTask(struct details tasks[], int *tk) { 
    int day, month, year, quit;
    printf("\n<<<<<<<<<<<<<<add task>>>>>>>>>>>>>>>\n"); 

    printf("Task title: "); 
    scanf(" %[^\n]", tasks[*tk].title);

    printf("Task description: "); 
    scanf(" %[^\n]", tasks[*tk].description);
    while (1) { 
            printf("Task date (MM-DD-YYYY): "); 
            scanf("%d-%d-%d", &month, &day, &year); 
            if (verify_day(day, month, year)) { 
                sprintf(tasks[*tk].date, "%02d-%02d-%04d", month, day, year); 
                break; 
            } else { 
                printf("Invalid date. Please enter a valid date in MM-DD-YYYY format.\n"); 
            } 
        } 
    printf("Task priority (1 for high, 0 for low): "); 
    scanf("%d", &tasks[*tk].priority); 
    if (tasks[*tk].priority != 1 || tasks[*tk].priority != 0){
        printf("invalide number \nplease enter a valide number \n");
    }
    printf("\n<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>\n");
    (*tk)++;
}



void viewTasks(struct details tasks[], int tk) { 
    printf("\n<<<<<<<<<<<<<<view tasks>>>>>>>>>>>>>>>\n"); 
    for (int i = 0; i < tk; i++) { 
        printf("Task %d:\n", i + 1); 
        printf("Title: %s\n", tasks[i].title); 
        printf("Description: %s\n", tasks[i].description); 
        printf("Date: %s\n", tasks[i].date); 
        printf("Priority: %s\n", tasks[i].priority ? "High" : "Low"); 
        printf("\n"); 
        }
}



void editTask(struct details tasks[], int tk) { 
    int taskNumber; 
    printf("\n<<<<<<<<<<<<<<edit task>>>>>>>>>>>>>>>\n"); 
    printf("Enter the task number to edit: "); 
    scanf("%d", &taskNumber); 
    if (taskNumber > 0 && taskNumber <= tk) { 
        taskNumber--; // Adjust for zero-based index 
        printf("Editing Task %d:\n", taskNumber + 1); 
        printf("New title: "); 
        scanf(" %[^\n]", tasks[taskNumber].title); 
        printf("New description: "); 
        scanf(" %[^\n]", tasks[taskNumber].description); 
        printf("New date (MM-DD-YYYY): "); 
        scanf(" %[^\n]", tasks[taskNumber].date); 
        printf("New priority (1 for high, 0 for low): "); 
        scanf("%d", &tasks[taskNumber].priority); 
        } else { 
            printf("Invalid task number.\n"); 
        }
}



void deleteTask(struct details tasks[], int *tk) { 
    int taskNumber; 
    printf("\n<<<<<<<<<<<<<<delete task>>>>>>>>>>>>>>>\n"); 
    printf("Enter the task number to delete: "); 
    scanf("%d", &taskNumber); 
    if (taskNumber > 0 && taskNumber <= *tk) { 
        taskNumber--; // Adjust for zero-based index 
        for (int i = taskNumber; i < *tk - 1; i++) { 
            tasks[i] = tasks[i + 1]; 
            } 
            (*tk)--; 
            printf("Task %d deleted.\n", taskNumber + 1); 
            } else { 
                printf("Invalid task number.\n"); 
            }
}


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
}


int main(){

    struct details tasks[100]; 
    int tk = 0; 
    int capacity = 2; 
    int option;
    int quit = 1;

    while (quit == 1){
    // this line for take a option and display the menu
        printf("\n<<<<<<<<<<<<<<<<menu>>>>>>>>>>>>>>>>>>>\n");
        printf("1 .    add a task      . \n");
        printf("\n2 .  view all tasks    . \n");
        printf("\n3 .    edit a task     . \n");
        printf("\n4 .   delete a task    . \n");
        printf("\n5 . filter by Priority . \n");
        printf("\n6 .       Quit         . \n");
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
        printf("\nEnter an option for 1 to 6 : ");
        scanf("%d", &option);
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        
        //---------------------------------------------------------
        if (option >= 1 || option <= 6){
            switch (option){
            case 1:
                addTask(tasks, &tk);
                break;
            case 2:        
            viewTasks(tasks, tk);
                break;
            case 3:
                editTask(tasks, tk);
                break;
            case 4:
                deleteTask(tasks, &tk);
                break;
            case 5:
                int priority; 
                printf("Enter priority to filter by (1 for high, 0 for low): "); 
                scanf("%d", &priority); 
                filterByPriority(tasks, tk, priority); 
                break;
            case 6:
                quit = 0;
                break;
            // default
            }
        }
        printf("pleas enter another number : ");
    }
}