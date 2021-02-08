/**************************************************
 *                                                *
 * file: among_us.h                               *
 *                                                *
 *                                                *
 * @Author  Antonios Peris                        *
 * @Version 20-10-2020                            *
 * @email   csdp1196@csd.uoc.gr                   *
 *                                                *
 * @brief   Header file for the needs of cs-240   *
 * project 2020, with the structures and function *
 * prototypes                                     * 
 *                                                *
 **************************************************
 */

#ifndef __AMONG_US_H_
#define __AMONG_US_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/**
 * Structure defining a node of the players double linked list
 * tree
 */
struct Players
{
    int pid;                      /*Player's identifier*/
    int is_alien;                 /*Alien flag*/
    int evidence;                 /*Amount of evidence*/
    struct Players *prev;         /*Pointer to the previous node*/
    struct Players *next;         /*Pointer to the next node*/
    struct Tasks *tasks_head;     /*Pointer to the head of player's task list*/
    struct Tasks *tasks_sentinel; /*Pointer to the sentinel of player's task list*/
};

/**
 * Structure defining a node of the tasks sorted linked list
 */
struct Tasks
{
    int tid;            /*Task's identifier*/
    int difficulty;     /*Task's difficulty*/
    struct Tasks *next; /*Pointer to the next node*/
};

struct Head_GL
{
    int tasks_count[3]; /*Count of tasks*/
    struct Tasks *head; /*Pointer to the head of general list*/
};
struct Head_Completed_Task_Stack
{
    int count;          /*Count of completed tasks*/
    struct Tasks *head; /*Pointer to the top element of the stack*/
};

/* Global variable, pointer to the head of the players list */
struct Players *players_head;

/* Global variable, pointer to the head of the tasks list */
struct Head_GL *tasks_head;

/* Global variable, pointer to the top of the completed task's stack */
struct Head_Completed_Task_Stack *tasks_stack;

/* Global variable, number of distributed tasks, Updated only when D event occurs.*/
unsigned int distributed_tasks;

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize();

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien);

/**
 * @brief Insert task in the general task list
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty);

/**
 * @brief Distribute tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks();

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty);

/**
 * @brief Eject Player
 * 
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid);

/**
 * @brief Witness Eject Player
 *
 * @param pid_a The alien's pid
 * 
 * @param pid The crewmate's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid, int pid_a, int number_of_witnesses);

/**
 * @brief Sabbotage
 *
 * @param pid The player's id
 *
 * @param number_of_tasks The number of tasks to be popped
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabbotage(int pid, int number_of_tasks);

/**
 * @brief Vote
 *
 * @param pid The player's id
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid, int vote_evidence);

/**
 * @brief Give Away Work
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work();

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate();

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players();

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks();

/**
 * @brief Print Stack
 *
 * @return 1 on success
 *         0 on failure
 */
int print_stack();

/**
 * @brief Print Players & Task List
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_list();

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void);

// My Functions
/**
 * @brief Player Ejection & Task Distribution without printing
 * 
 * @return 1 on success
 *         0 on failure
 */
int throw_player(struct Players *);

/**
 * @brief Pops Completed Tasks Stack
 * 
 * @return popped element on success
 *         NULL on failure
 */
struct Tasks *stack_pop();

/**
 * @brief Pushes Completed Task to Stack
 * 
 * @return popped element on success
 *         NULL on failure
 */
void stack_push(struct Tasks *);

/**
 * @brief Casual Stack Pop
 * 
 * @return top stack element on success
 *         NULL on failure
 */
struct Tasks *stack_top();

/**
 * @brief Inserts task to the end of Player's tasks list
 *  
 */
void Insert_Task_To_Player(struct Players *, struct Tasks *);

/**
 * @brief Finds player with the given pid
 * 
 * @return struct Players element on success
 *          NULL on failure
 */

struct Players *find_pid(int pid);

/**
 * Dustuxws to reusability/readability tou kwdika polles fores erxetai se antifash me to efficiency tou.
 * Tha mporousame na glutwsoume arketo stis find an htan mixed, analoga thn periptwsh, opws einai sto Event G -give_work().
 * Alla tis ekana se sunarthseis kuriws gia na einai pio euanagnwstos o kwdikas, kathws en telei den allazoun thn taksh ths xronikhs poluplokothtas tou
 * alla px sthn throw_player, anti na htan n + c einai 2*n + c to anw fragma.
 */
/**
 * @brief Finds the Player with the least tasks
 * 
 * @returns struct Players element on success
 *          NULL on failure
 */
struct Players *find_min_tasks();

/**
 * @brief Finds the Player with the most tasks
 * 
 * @returns struct Players element on success
 *          NULL on failure
 */
struct Players *find_max_tasks();

/**
 * @brief Counts Active Player's tasks.
 * 
 * @return 0 if there are none.
 */
int count_tasks(struct Players *);

/**
 * @brief Same with print_double_list() but includes evidence per player
 * 
 * @return 1 on success
 *         0 on failure
 */
int print_double_list_evidence();

/**
 * @brief Prints stack elements recursively
 */
void recursive_stack_print();

/**
 * @brief create a copy of the input struct Tasks element.
 */
struct Tasks *task_copy(struct Tasks *);

#endif /* __AMONG_US_H_ */
