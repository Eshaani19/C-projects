//Eshaani Arvind
//U88155472

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//////////////////////
// data definitions //
//////////////////////
#define NAME_LEN 20
#define SIZE_LEN 3

struct job 
{
    char job_name [NAME_LEN+1], user_name [NAME_LEN+1];
    int num_cpus, num_gpus, memory, priority;
    double time;
    struct job *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read (char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority);
struct job * add_job (struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority);
struct job * pop_job (struct job *scheduler);
void list_user (struct job *scheduler, char *user_name);
void list_jobs (struct job *scheduler, int num_cpus, int num_gpus, int memory, double time);
void list_all_jobs(struct job *scheduler);
struct job * clear_jobs(struct job *scheduler);

///////////////////
// main function //
///////////////////

int main() 
{
    char code;
    char job_name [NAME_LEN+1], user_name [NAME_LEN+1];
    int num_cpus, num_gpus, memory, priority;
    double time;
    struct job *scheduler = NULL;
    help();
    printf("\n");
    for (;;) 
    {
        // read operation code
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
        ;
        // run operation
        switch (code) 
        {
            case 'h':
            help();
            break;
            case 'a':
                read (job_name, user_name, &num_cpus, &num_gpus, &memory, &time, &priority);
                scheduler = add_job(scheduler, job_name, user_name, num_cpus, num_gpus, memory, time, priority);
                break;
            case 'p':
                scheduler = pop_job(scheduler);
                break;
            case 'u':
                read (NULL, user_name, NULL, NULL, NULL, NULL, NULL);
                list_user (scheduler, user_name);
                break;
            case 'j':
                read(NULL, NULL, &num_cpus, &num_gpus, &memory, &time, NULL);
                list_jobs(scheduler, num_cpus, num_gpus, memory, time);
                break;
            case 'l':
                list_all_jobs(scheduler);
                break;
            case 'q':
                scheduler = clear_jobs(scheduler);
                return 0;
            default:
                printf("Illegal operation code!\n");
        }
        printf("\n");
    }
}

//////////////////////////
// function definitions //
//////////////////////////

void help() 
{
    printf("List of operation codes:\n");
    printf("\t'h' for help;\n");
    printf("\t'a' for adding a job to the scheduler;\n");
    printf("\t'p' for removing a job from the scheduler;\n");
    printf("\t'u' for searching jobs per user;\n");
    printf("\t'j' for searching jobs per capacity;\n");
    printf("\t'l' for listing all jobs;\n");
    printf("\t'q' for quit.\n");
}

void read (char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) 
{
    if (job_name != NULL) 
    {
        printf("Enter the name of the job: ");
        scanf("%s", job_name);
    }
    if (user_name != NULL) 
    {
        printf("Enter the name of the user: ");
        scanf("%s", user_name);
    }
    if (num_cpus != NULL) 
    {
        printf("Enter the number of CPUs: ");
        scanf("%d", num_cpus);
    }
    if (num_gpus != NULL) 
    {
        printf("Enter the number of GPUs: ");
        scanf("%d", num_gpus);
    }
    if (memory != NULL) 
    {
        printf("Enter the amount of memory: ");
        scanf("%d", memory);
    }
    if (time != NULL) 
    {
        printf("Enter the amount of time: ");
        scanf("%lf", time);
    }
    if (priority != NULL) 
    {
        printf("Enter the priority: ");
        scanf("%d", priority);
    }
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect. //
/////////////////////////////////////////////////////////

struct job * add_job (struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) 
{
    struct job *new_node;                    //new job = new node
    struct job *cur, *prev;                  //2 pointers to traverse through linke dlist
    new_node = malloc (sizeof(struct job));  //allocating space for 1 new job
    strcpy(new_node->job_name, job_name);    //assigning values to new job node 
    strcpy(new_node->user_name, user_name);
    new_node->num_cpus = num_cpus;
    new_node->num_gpus = num_gpus;
    new_node->memory = memory;
    new_node->priority = priority;
    new_node->time = time;
    new_node->next = NULL;              //setting next of new node to be NULL
    if (scheduler == NULL)              //if scheduler is empty, 1st job added
    {
        scheduler = new_node;
        return scheduler;
    }
    else          //else traversing though linked list to find last node
    {           
        for (cur = scheduler, prev = NULL; cur != NULL ; prev = cur, cur = cur->next)
        ;
        prev->next = new_node;          //adding new job to end of linked list
        free(cur);
        return scheduler;
    }
}

struct job * pop_job (struct job *scheduler) 
{
    //printing node to be removed according to FIFO
    if (scheduler == NULL)
        return scheduler;
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| Job name | User name | CPUs | GPUs | Mem. | Time | Priority |\n");
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler->job_name, scheduler->user_name, scheduler->num_cpus, scheduler->num_gpus, scheduler->memory, scheduler->time, scheduler->priority);
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    //removing node
    struct job *cur, *prev;
    cur = scheduler;
    prev = NULL;
    if (cur == NULL)            //if empty, does nothing
        return scheduler; 
    if (prev == NULL)           //otherwise removes node from linked list
        scheduler = scheduler->next; 
    //else
        //prev->next = cur->next; 
    free(cur);                  //memory of node deallocated
    return scheduler;
}

void list_user (struct job *scheduler, char *user_name) 
{
    if (scheduler == NULL || user_name == NULL)
        return ;
    struct job *p;
    int count = 0;
    for (p = scheduler; p != NULL; p = p->next)  //traversing though linked list using pointer
    {
        if (strcmp(p->user_name ,user_name)==0)  //checks if usernames are equal and prints if true
        {
            if (count == 0) 
            {
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                printf("| Job name | User name | CPUs | GPUs | Mem. | Time | Priority |\n");
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            }   
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");  
        count+=1;
        }
    }
}

void list_jobs (struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) 
{
    if (scheduler == NULL) 
    {
    //|| num_cpus == NULL || num_gpus == NULL || memory == NULL || time == NULL)
        return;
    }
    struct job *p;
    int count = 0;
    for (p = scheduler; p != NULL; p = p->next) //traversing though linked list
    {
        if(p->num_cpus == num_cpus && p->num_gpus == num_gpus && p->memory == memory  && p-> time == time)  //checks if all info match, otherwise returns nothing
        {   
            if (count == 0 ) 
            {
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
                printf("| Job name | User name | CPUs | GPUs | Mem. | Time | Priority |\n");
                printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            }    
            printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);
            printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
            count += 1;
        }  
    }
}

void list_all_jobs(struct job *scheduler) 
{
    if (scheduler == NULL)
        return ;
    struct job *p;
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    printf("| Job name | User name | CPUs | GPUs | Mem. | Time | Priority |\n");
    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    for (p = scheduler; p != NULL; p = p->next) //traversing through list and printing all nodes
    {
        printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", p->job_name, p->user_name, p->num_cpus, p->num_gpus, p->memory, p->time, p->priority);
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
    }
}

struct job * clear_jobs(struct job *scheduler) 
{
    if (scheduler == NULL)
        return scheduler;
    struct job *cur, *prev;
    for (cur = scheduler, prev = NULL; cur != NULL ; prev = cur, cur = cur->next)
    ;                   //traversing through list until last node is reached
    if (cur == NULL)    //if no elements
        return scheduler; 
    if (prev == NULL)   //if only 1 node present
        scheduler = scheduler->next; 
    else
        prev->next = cur->next; //more than 1 node present 
    free(cur);          //deallocating memory
    return scheduler;
}