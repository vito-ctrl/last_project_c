#include<stdio.h>
#include<string.h>


struct details{
    char title[50];
    char description[50];
    char date[11];
    int priority;
};

/*void edit(struct details *task){
    printf("\n<<<<<<<<<<<<<<<<update>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("new title : ");
    scanf("%s", task->title);
    printf("new descrition : ");
    scanf("%s", task->description);
    printf("new date : ");
    scanf("%s", task->date);
    printf("new priority : ");
    scanf("%d", task->priority);
// }*/

int main(){
    // this line for take a option and display the menu
    struct details task;

    int option;
    int quit = 1;
    // char nt[50];

    while (quit == 1){
        printf("\n<<<<<<<<<<<<<<<<menu>>>>>>>>>>>>>>>>>>>\n");
        printf("1 .   add a task   : \n");
        printf("\n2 . view all tasks : \n");
        printf("\n3 .  edit a task   : \n");
        printf("\n4 . delete a task  : \n");
        printf("\n5 .      Quit      : \n");
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\nEnter an option for 1 to 4 : ");
        scanf("%d", &option);
        
        // hjdsgnsfjgnvjsfgjfsjfjkf
        if (option == 1){
            printf("\n<<<<<<<<<<<<<<add task>>>>>>>>>>>>>>>\n");
            printf("task title : ");
            scanf("%s", task.title);
            printf("task description : ");
            scanf("%s", task.description);
            printf("task date (MM-DD-YYYY) : ");
            scanf("%s", &task.date);
            printf("task priority (1 for high) or (0 for low) : ");
            scanf("%d", &task.priority);
            quit == 1;
        }
        if (option == 2){
            printf("\n<<<<<<<<<<<<<<<<view all>>>>>>>>>>>>>>>>>>\n");
            printf("\ntitle : %s\n", task.title);
            printf("\ndescription : %s\n", task.description);
            printf("\ndate (MM-DD-YYYY) :( %s )\n", task.date);
            if(task.priority == 0){
                printf("\npriority  :  low\n");
            }else{
                printf("\npriority  :  high\n");
            }
            quit == 1;
        }
        // if(option == 3){
            // printf("enter title of task you want to update : ");
            // scanf("%s", nt);
            
        // }
        if(option == 5){
            quit = 0;
        }
    }
}
    
