/**************************************************
 *                                                *
 * file: among_us.h                               *
 *                                                *
 *                                                *
 * @Author  Skerdi Basha                          *
 * @Version 1-12-2020                             *
 * @email   sbash@csd.uoc.gr                      *
 *                                                *
 * @brief   Header file for the needs of CS-240   *
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
#include <assert.h>
#include <time.h>

/**
 * Structure defining a node of the players double linked tree
 * tree
 */
struct Player
{
    int pid;                /*Player's identifier*/
    int is_alien;           /*Alien flag*/
    int evidence;           /*Amount of evidence*/
    struct Player *parrent; /*Pointer to the parent node*/
    struct Player *lc;      /*Pointer to the left child node*/
    struct Player *rc;      /*Pointer to the right child node*/
    struct Task *tasks;     /*Pointer to the head of player's task tree*/
};

/**
 * Structure defining a node of the tasks sorted tree
 */
struct Task
{
    int tid;         /*Task's identifier*/
    int difficulty;  /*Task's difficulty*/
    int lcnt;        /*Node's left child's node counter*/
    struct Task *lc; /*Pointer to the left child node*/
    struct Task *rc; /*Pointer to the right child node*/
};

struct HT_Task
{
    int tid;              /*Task's identifier*/
    int difficulty;       /*Task's difficulty*/
    struct HT_Task *next; /*Pointer to the next node*/
};

struct General_Tasks_HT
{
    int count;              /*Count of tasks*/
    struct HT_Task **tasks; /*General tasks hash table*/
};

struct Completed_Tasks_PQ
{
    int size;              /*Count of completed tasks*/
    struct HT_Task *tasks; /*Completed tasks priority queue*/
};

unsigned int max_tasks_g; /* Max number of tasks */
unsigned int max_tid_g;   /* Max task tid */
unsigned int p;           /* Min prime number who's greater than max_tid_g */

/* Hash function parameters */
unsigned int a, b;

/* Primes for your universal hashing implementation */
extern unsigned int primes_g[650];

/* Global variable, pointer to the head of the players tree */
struct Player *players_tree;

/* Global variable, pointer to the guard node of the players tree */
struct Player *tree_guard;

/* Global variable, pointer to the head of the tasks tree */
struct General_Tasks_HT general_tasks_ht;

/* Global variable, pointer to the top of the completed task's priority queue */
struct Completed_Tasks_PQ completed_tasks_pq;

/* Global variable, used in task distribution */
struct HT_Task *curr_task;

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize();

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien);

/**
 * @brief Insert Task in the general task hash table
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
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks();

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid);

/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2);

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses);

/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid);

/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence);

/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2);

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
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq();

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree();

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void);

/**
 * @brief adds a new player to the tree structure
 *
 * @return 1 on success
 *         0 on failure
 */
int add_to_players_tree(struct Player *, struct Player *);

/**
 * @brief Prints players and their 2 fields (PID and is_alien) recursively
 * @return 1 on success
 *         0 on failure
 */
int print_players_recursively(struct Player *curr);

/**
 * @brief Universal hash function for a key.
 * @return hash value
 */
int H(int);

/**
 * @brief Hash Table task copy
 * @return a Task copy of HT_Task node
 */
struct Task *HT_task_copy(struct HT_Task *node);

/**
 * @brief Add a Task to a player's task tree.
 */
void add_task_to_player(struct Task *, struct Player *);

/**
 * @brief Distribute tasks to players recursively, read its comments for its complexity
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks_recursively(int, struct Player *);

/**
 * @brief Traverses through players_tree and prints their tasks.
 */
void print_double_tree_recursively(struct Player *player);

/**
 * @brief Prints a tasks' tree.
 */
void print_tasks_tree(struct Task *);

/**
 * @brief Finds and removes the task with the given tid from player's tasks_tree.
 * @pre task with tid must be on player's tasks_tree.
 */
struct Task *remove_task(int tid, struct Player *player);

/**
 * @brief Add task to completed tasks priority queue/heap
 * @return 1 on success
 *         0 on failure
 */
int heap_insert(struct Task *);

/**
 * @brief Finds the player with the given pid.
 * @return pointer to struct Player if pid was found
 *         null if pid was not found
 */
struct Player *search_pid(int pid);

/**
 * @brief Function that takes a player1, takes his tasks tree and merges it with player2's task tree, returning the merged tree
 * @return pointer to merged tasks tree
 *         null if both trees are empty
 */
struct Task *merge_task_trees(struct Player *player1, struct Player *player2);

/**
 * @brief counts tasks in the given tree.
 * @return task count
 */
int task_count(struct Task *tree);

/**
 * @brief creates a binary search tree from a given array.
 * @return the tree
 */
struct Task *array_to_tree(struct Task **arr, int start, int end);

/**
 * @brief creates an array from a binary search tree
 * @pre arr array must have been allocated first.
 * @return the number of elements in arr array
 */
int tree_to_array(struct Task *task, struct Task **arr, int index);

/**
 * @brief returns the previous player in order
 * @return pointer to player on success
 *         null on failure
 */
struct Player *FindInOrderPredecessor(struct Player *);

/**
 * @brief returns the next player in order
 * @return pointer to player on success
 *         null on failure
 */
struct Player *FindInOrderSuccessor(struct Player *);

/**
 * @brief Returns the element in front of the priority queue
 * @return pointer to the 1st element of pq
 *         null if pq is empty
 */
struct HT_Task *heap_pop();

/**
 * @brief Finds the player with the most evidence
 * @return pointer to the player with max evidence
 *         null if player's list is empty
 */
struct Player *find_max_evidence(struct Player *);

/**
 * @brief Optional Function I created to check out lcnts on a tasks tree
 * @return -1 if they are incorrect
 *         a positive integer if they are ok
 */
int check_counters(struct Task *);

/**
 * @brief Splits a tasks tree in 2
 * @return pointer to 2 pointers, the 2 trees
 *         null if tree is empty
 */
struct Task **split_tasks(struct Task *, int);

/**
 * @brief Counts aliens and crewmates using tree guard's pid and evidence elements (pid for crewmates, evidence for aliens)
 */
void count_players(struct Player *);

/**
 * @brief Free player tree's allocated memory, as well as their tasks
 */
void free_double_tree(struct Player *);

/**
 * @brief Free a task tree
 */
void free_tasks(struct Task *);

/**
 * @brief Free all hash_Table elements
 */
void free_hash_table();

/**
 * @brief print all players with evidence
 */
void print_double_tree_with_evidence(struct Player *player);

#endif /* __AMONG_US_H_ */
