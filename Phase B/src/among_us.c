/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Skerdi Basha                           *
 * @Version 1-12-2020                              *
 * @email   sbash@csd.uoc.gr                       *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

#include "among_us.h"
#define PRIME_COUNT 650 // total prime numbers, if you want to add more, change this variable as well.

unsigned int primes_g[650] = {
    179,
    181,
    191,
    193,
    197,
    199,
    211,
    223,
    227,
    229,
    233,
    239,
    241,
    251,
    257,
    263,
    269,
    271,
    277,
    281,
    283,
    293,
    307,
    311,
    313,
    317,
    331,
    337,
    347,
    349,
    353,
    359,
    367,
    373,
    379,
    383,
    389,
    397,
    401,
    409,
    419,
    421,
    431,
    433,
    439,
    443,
    449,
    457,
    461,
    463,
    467,
    479,
    487,
    491,
    499,
    503,
    509,
    521,
    523,
    541,
    547,
    557,
    563,
    569,
    571,
    577,
    587,
    593,
    599,
    601,
    607,
    613,
    617,
    619,
    631,
    641,
    643,
    647,
    653,
    659,
    661,
    673,
    677,
    683,
    691,
    701,
    709,
    719,
    727,
    733,
    739,
    743,
    751,
    757,
    761,
    769,
    773,
    787,
    797,
    809,
    811,
    821,
    823,
    827,
    829,
    839,
    853,
    857,
    859,
    863,
    877,
    881,
    883,
    887,
    907,
    911,
    919,
    929,
    937,
    941,
    947,
    953,
    967,
    971,
    977,
    983,
    991,
    997,
    1009,
    1013,
    1019,
    1021,
    1031,
    1033,
    1039,
    1049,
    1051,
    1061,
    1063,
    1069,
    1087,
    1091,
    1093,
    1097,
    1103,
    1109,
    1117,
    1123,
    1129,
    1151,
    1153,
    1163,
    1171,
    1181,
    1187,
    1193,
    1201,
    1213,
    1217,
    1223,
    1229,
    1231,
    1237,
    1249,
    1259,
    1277,
    1279,
    1283,
    1289,
    1291,
    1297,
    1301,
    1303,
    1307,
    1319,
    1321,
    1327,
    1361,
    1367,
    1373,
    1381,
    1399,
    1409,
    1423,
    1427,
    1429,
    1433,
    1439,
    1447,
    1451,
    1453,
    1459,
    1471,
    1481,
    1483,
    1487,
    1489,
    1493,
    1499,
    1511,
    1523,
    1531,
    1543,
    1549,
    1553,
    1559,
    1567,
    1571,
    1579,
    1583,
    1597,
    1601,
    1607,
    1609,
    1613,
    1619,
    1621,
    1627,
    1637,
    1657,
    1663,
    1667,
    1669,
    1693,
    1697,
    1699,
    1709,
    1721,
    1723,
    1733,
    1741,
    1747,
    1753,
    1759,
    1777,
    1783,
    1787,
    1789,
    1801,
    1811,
    1823,
    1831,
    1847,
    1861,
    1867,
    1871,
    1873,
    1877,
    1879,
    1889,
    1901,
    1907,
    1913,
    1931,
    1933,
    1949,
    1951,
    1973,
    1979,
    1987,
    1993,
    1997,
    1999,
    2003,
    2011,
    2017,
    2027,
    2029,
    2039,
    2053,
    2063,
    2069,
    2081,
    2083,
    2087,
    2089,
    2099,
    2111,
    2113,
    2129,
    2131,
    2137,
    2141,
    2143,
    2153,
    2161,
    2179,
    2203,
    2207,
    2213,
    2221,
    2237,
    2239,
    2243,
    2251,
    2267,
    2269,
    2273,
    2281,
    2287,
    2293,
    2297,
    2309,
    2311,
    2333,
    2339,
    2341,
    2347,
    2351,
    2357,
    2371,
    2377,
    2381,
    2383,
    2389,
    2393,
    2399,
    2411,
    2417,
    2423,
    2437,
    2441,
    2447,
    2459,
    2467,
    2473,
    2477,
    2503,
    2521,
    2531,
    2539,
    2543,
    2549,
    2551,
    2557,
    2579,
    2591,
    2593,
    2609,
    2617,
    2621,
    2633,
    2647,
    2657,
    2659,
    2663,
    2671,
    2677,
    2683,
    2687,
    2689,
    2693,
    2699,
    2707,
    2711,
    2713,
    2719,
    2729,
    2731,
    2741,
    2749,
    2753,
    2767,
    2777,
    2789,
    2791,
    2797,
    2801,
    2803,
    2819,
    2833,
    2837,
    2843,
    2851,
    2857,
    2861,
    2879,
    2887,
    2897,
    2903,
    2909,
    2917,
    2927,
    2939,
    2953,
    2957,
    2963,
    2969,
    2971,
    2999,
    3001,
    3011,
    3019,
    3023,
    3037,
    3041,
    3049,
    3061,
    3067,
    3079,
    3083,
    3089,
    3109,
    3119,
    3121,
    3137,
    3163,
    3167,
    3169,
    3181,
    3187,
    3191,
    3203,
    3209,
    3217,
    3221,
    3229,
    3251,
    3253,
    3257,
    3259,
    3271,
    3299,
    3301,
    3307,
    3313,
    3319,
    3323,
    3329,
    3331,
    3343,
    3347,
    3359,
    3361,
    3371,
    3373,
    3389,
    3391,
    3407,
    3413,
    3433,
    3449,
    3457,
    3461,
    3463,
    3467,
    3469,
    3491,
    3499,
    3511,
    3517,
    3527,
    3529,
    3533,
    3539,
    3541,
    3547,
    3557,
    3559,
    3571,
    3581,
    3583,
    3593,
    3607,
    3613,
    3617,
    3623,
    3631,
    3637,
    3643,
    3659,
    3671,
    3673,
    3677,
    3691,
    3697,
    3701,
    3709,
    3719,
    3727,
    3733,
    3739,
    3761,
    3767,
    3769,
    3779,
    3793,
    3797,
    3803,
    3821,
    3823,
    3833,
    3847,
    3851,
    3853,
    3863,
    3877,
    3881,
    3889,
    3907,
    3911,
    3917,
    3919,
    3923,
    3929,
    3931,
    3943,
    3947,
    3967,
    3989,
    4001,
    4003,
    4007,
    4013,
    4019,
    4021,
    4027,
    4049,
    4051,
    4057,
    4073,
    4079,
    4091,
    4093,
    4099,
    4111,
    4127,
    4129,
    4133,
    4139,
    4153,
    4157,
    4159,
    4177,
    4201,
    4211,
    4217,
    4219,
    4229,
    4231,
    4241,
    4243,
    4253,
    4259,
    4261,
    4271,
    4273,
    4283,
    4289,
    4297,
    4327,
    4337,
    4339,
    4349,
    4357,
    4363,
    4373,
    4391,
    4397,
    4409,
    4421,
    4423,
    4441,
    4447,
    4451,
    4457,
    4463,
    4481,
    4483,
    4493,
    4507,
    4513,
    4517,
    4519,
    4523,
    4547,
    4549,
    4561,
    4567,
    4583,
    4591,
    4597,
    4603,
    4621,
    4637,
    4639,
    4643,
    4649,
    4651,
    4657,
    4663,
    4673,
    4679,
    4691,
    4703,
    4721,
    4723,
    4729,
    4733,
    4751,
    4759,
    4783,
    4787,
    4789,
    4793,
    4799,
    4801,
    4813,
    4817,
    4831,
    4861,
    4871,
    4877,
    4889,
    4903,
    4909,
    4919,
    4931,
    4933,
    4937,
    4943,
    4951,
    4957,
    4967,
    4969,
    4973,
    4987,
    4993,
    4999,
    5003,
    5009,
    5011,
    5021,
    5023,
    5039,
    5051,
    5059,
    5077,
    5081,
    5087,
    5099,
    5101,
    5107,
    5113,
    5119,
    5147,
    5153,
    5167,
    5171,
    5179,
};
/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize()
{
    int i;
    srand(time(0));
    // Players tree initialization
    struct Player *guard_node = malloc(sizeof(struct Player));
    guard_node->pid = -1;
    guard_node->evidence = 0;
    guard_node->is_alien = -1; // Guard node MUST have is_alien value == -1
    guard_node->tasks = NULL;
    guard_node->rc = NULL;
    guard_node->lc = NULL;
    guard_node->parrent = NULL;
    players_tree = guard_node;
    tree_guard = guard_node;
    // Tasks hash table initialization
    for (i = 0; i < PRIME_COUNT; i++)
    {
        if (primes_g[i] > max_tid_g)
        {
            break;
        }
    }
    // p cannot be greater than 650
    assert(p < PRIME_COUNT);
    p = primes_g[i];
    general_tasks_ht.count = 0;
    general_tasks_ht.tasks = malloc(max_tasks_g * sizeof(struct Task *));
    for (i = 0; i < max_tasks_g; i++)
    {
        general_tasks_ht.tasks[i] = NULL;
    }
    // 1 <= a <= p - 1
    a = rand() % (p - 1) + 1;
    // 0 <= b <= p - 1
    b = rand() % p;
    // Priority Queue initialization
    completed_tasks_pq.tasks = malloc(max_tasks_g * sizeof(struct Task));
    completed_tasks_pq.size = 0;
    return 1;
}

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien)
{
    struct Player *new_player;
    assert(is_alien != -1); // assert is_alien != -1 because only the guard node can have that value on its is_alien attribute.
    if (players_tree == NULL)
    {
        return 0;
    }
    new_player = malloc(sizeof(struct Player));
    new_player->pid = pid;
    new_player->is_alien = is_alien;
    new_player->evidence = 0;
    new_player->tasks = NULL;

    if (players_tree == tree_guard)
    {
        new_player->lc = players_tree;
        new_player->rc = players_tree;
        new_player->parrent = NULL;
        players_tree = new_player;
    }
    else if (add_to_players_tree(new_player, players_tree) == 0)
    {
        return 0;
    }
    print_players();
    return 1;
}

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
int insert_task(int tid, int difficulty)
{
    struct HT_Task *new_node = malloc(sizeof(struct HT_Task));
    if (new_node == NULL)
    { // case where malloc failed
        return 0;
    }
    int pos = H(tid);
    new_node->tid = tid;
    new_node->difficulty = difficulty;
    new_node->next = general_tasks_ht.tasks[pos];
    general_tasks_ht.tasks[pos] = new_node;
    general_tasks_ht.count++;
    print_tasks();
    return 1;
}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks()
{
    curr_task = general_tasks_ht.tasks[0];
    distribute_tasks_recursively(0, players_tree);
    print_double_tree();
    return 1;
}

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
int implement_task(int pid, int tid)
{
    struct Player *player = search_pid(pid);
    if (player == NULL)
    {
        return 0;
    }
    if (heap_insert(remove_task(tid, player)) == 0)
    {
        return 0;
    }
    print_double_tree();
    return 1;
}

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
int eject_player(int pid_1, int pid_2)
{
    struct Player *player1 = search_pid(pid_1);
    struct Player *player2 = search_pid(pid_2);
    if (player1 == NULL || player2 == NULL)
    {
        return 0;
    }
    if (player2->is_alien == 1)
    {
        return 0;
    }
    player2->tasks = merge_task_trees(player1, player2);
    if (player1->rc != tree_guard && player1->lc != tree_guard)
    {
        struct Player *in_order = player1->rc;
        while (in_order->lc != tree_guard)
        { // find the next node in order
            in_order = in_order->lc;
        }
        if (in_order == player1->rc)
        { // if its the one just right from player1, we need to update player1's right child
            player1->rc = in_order->rc;
        }
        else
        {
            in_order->parrent->lc = in_order->rc;
        }
        if (in_order->rc != tree_guard)
        {
            in_order->rc->parrent = in_order->parrent;
        }
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = in_order;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = in_order;
            }
            else
            {
                player1->parrent->lc = in_order;
            }
        }
        in_order->parrent = player1->parrent;
        in_order->rc = player1->rc;
        player1->rc->parrent = in_order;
        in_order->lc = player1->lc;
        player1->lc->parrent = in_order;
    }
    else if (player1->rc != tree_guard)
    { // if player1 has only right subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->rc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->rc;
            }
            else
            {
                player1->parrent->lc = player1->rc;
            }
        }
        player1->rc->parrent = player1->parrent;
    }
    else if (player1->lc != tree_guard)
    { // if player1 has only a left subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->lc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->lc;
            }
            else
            {
                player1->parrent->lc = player1->lc;
            }
        }
        player1->lc->parrent = player1->parrent;
    }
    else
    { // if player1 has no children
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = tree_guard;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = tree_guard;
            }
            else
            {
                player1->parrent->lc = tree_guard;
            }
        }
    }
    free(player1);
    print_double_tree();
    return 1;
}

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
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses)
{ // just adds number_of_witnesses to suspect's evidence and ejects player with pid_1, but had to copy paste eject's algorithm to change the followup print :)
    struct Player *suspect = search_pid(pid_a);
    struct Player *player1 = search_pid(pid_1);
    struct Player *player2 = search_pid(pid_2);
    if (player1 == NULL || player2 == NULL || suspect == NULL)
    {
        return 0;
    }
    if (player2->is_alien == 1)
    {
        return 0;
    }
    suspect->evidence += number_of_witnesses;
    player2->tasks = merge_task_trees(player1, player2);
    if (player1->rc != tree_guard && player1->lc != tree_guard)
    {
        struct Player *in_order = player1->rc;
        while (in_order->lc != tree_guard)
        { // find the next node in order
            in_order = in_order->lc;
        }
        if (in_order == player1->rc)
        { // if its the one just right from player1, we need to update player1's right child
            player1->rc = in_order->rc;
        }
        else
        {
            in_order->parrent->lc = in_order->rc;
        }
        if (in_order->rc != tree_guard)
        {
            in_order->rc->parrent = in_order->parrent;
        }
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = in_order;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = in_order;
            }
            else
            {
                player1->parrent->lc = in_order;
            }
        }
        in_order->parrent = player1->parrent;
        in_order->rc = player1->rc;
        player1->rc->parrent = in_order;
        in_order->lc = player1->lc;
        player1->lc->parrent = in_order;
    }
    else if (player1->rc != tree_guard)
    { // if player1 has only right subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->rc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->rc;
            }
            else
            {
                player1->parrent->lc = player1->rc;
            }
        }
        player1->rc->parrent = player1->parrent;
    }
    else if (player1->lc != tree_guard)
    { // if player1 has only a left subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->lc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->lc;
            }
            else
            {
                player1->parrent->lc = player1->lc;
            }
        }
        player1->lc->parrent = player1->parrent;
    }
    else
    { // if player1 has no children
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = tree_guard;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = tree_guard;
            }
            else
            {
                player1->parrent->lc = tree_guard;
            }
        }
    }
    free(player1);
    print_double_tree_with_evidence(players_tree);
    return 1;
}

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
int sabotage(int number_of_tasks, int pid)
{
    struct Player *player = search_pid(pid), *pre, *succ, *flag;
    int pos = number_of_tasks / 2;
    if (player == NULL || pos < 0)
    {
        return 0;
    }
    pre = player;
    while (pos > 0)
    {
        pre = FindInOrderPredecessor(pre);
        if (pre == NULL)
        { // if FindInOrderPredecessor fails :)
            return 0;
        }
        pos--;
    }
    struct HT_Task *popped = heap_pop();
    if (popped == NULL)
    {
        return 0;
    }
    flag = pre;
    while (pre->is_alien == 1)
    {
        pre = FindInOrderPredecessor(pre);
        if (pre == flag || pre == NULL)
        { // case where we have only aliens on ship.
            return 0;
        }
    }
    add_task_to_player(HT_task_copy(popped), pre);
    number_of_tasks--;
    succ = pre;
    while (number_of_tasks > 0)
    {
        succ = FindInOrderSuccessor(succ);
        while (succ->is_alien == 1)
        {
            succ = FindInOrderSuccessor(succ);
        }
        popped = heap_pop();
        if (popped == NULL)
        {
            break;
        }
        add_task_to_player(HT_task_copy(popped), succ);
        number_of_tasks--;
    }
    print_double_tree();
    return 1;
}

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
int vote(int pid_1, int pid_2, int vote_evidence)
{
    struct Player *player1, *player2 = search_pid(pid_2), *suspect = search_pid(pid_1);
    if (player2 == NULL || suspect == NULL)
    {
        return 0;
    }
    if (player2->is_alien == 1)
    {
        return 0;
    }
    suspect->evidence += vote_evidence;
    player1 = find_max_evidence(players_tree);
    assert(player1);
    player2->tasks = merge_task_trees(player1, player2);
    if (player1->rc != tree_guard && player1->lc != tree_guard)
    {
        struct Player *in_order = player1->rc;
        while (in_order->lc != tree_guard)
        { // find the next node in order
            in_order = in_order->lc;
        }
        if (in_order == player1->rc)
        { // if its the one just right from player1, we need to update player1's right child
            player1->rc = in_order->rc;
        }
        else
        {
            in_order->parrent->lc = in_order->rc;
        }
        if (in_order->rc != tree_guard)
        {
            in_order->rc->parrent = in_order->parrent;
        }
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = in_order;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = in_order;
            }
            else
            {
                player1->parrent->lc = in_order;
            }
        }
        in_order->parrent = player1->parrent;
        in_order->rc = player1->rc;
        player1->rc->parrent = in_order;
        in_order->lc = player1->lc;
        player1->lc->parrent = in_order;
    }
    else if (player1->rc != tree_guard)
    { // if player1 has only right subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->rc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->rc;
            }
            else
            {
                player1->parrent->lc = player1->rc;
            }
        }
        player1->rc->parrent = player1->parrent;
    }
    else if (player1->lc != tree_guard)
    { // if player1 has only a left subtree
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = player1->lc;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = player1->lc;
            }
            else
            {
                player1->parrent->lc = player1->lc;
            }
        }
        player1->lc->parrent = player1->parrent;
    }
    else
    { // if player1 has no children
        if (player1 == players_tree)
        { // if player1 is root
            players_tree = tree_guard;
        }
        else
        {
            if (player1 == player1->parrent->rc)
            { // if player1 is the right child of his parent
                player1->parrent->rc = tree_guard;
            }
            else
            {
                player1->parrent->lc = tree_guard;
            }
        }
    }
    free(player1);
    print_double_tree_with_evidence(players_tree);
    return 1;
}

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
int give_work(int pid_1, int pid_2)
{
    struct Player *player1 = search_pid(pid_1), *new_player;
    struct Task **nodes;
    int k = 0;
    if (player1 == NULL)
    {
        return 0;
    }
    new_player = malloc(sizeof(struct Player));
    new_player->pid = pid_2;
    new_player->is_alien = 0;
    new_player->evidence = 0;

    if (add_to_players_tree(new_player, players_tree) == 0)
    {
        return 0;
    }
    k = task_count(player1->tasks);
    nodes = split_tasks(player1->tasks, k / 2);
    new_player->tasks = nodes[1];
    player1->tasks = nodes[0];
    free(nodes);
    print_double_tree();
    return 1;
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate()
{
    tree_guard->pid = 0;
    tree_guard->evidence = 0;
    // using guard's pid and evidence attributes, where we save on his pid the number of crewmates and on evidence the number of aliens
    count_players(players_tree);
    if (tree_guard->pid < tree_guard->evidence)
    {
        printf(" Aliens win.\n");
        return 1;
    }
    else if (tree_guard->evidence == 0 || general_tasks_ht.count == completed_tasks_pq.size)
    {
        printf(" Crewmates win.\n");
        return 1;
    }

    return 0;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players()
{
    if (players_tree == NULL || players_tree == tree_guard)
    { // case with just the guard node or null players_tree
        return 0;
    }
    printf("Players =");
    print_players_recursively(players_tree);
    printf("\n");
    return 1;
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks()
{
    int i;
    struct HT_Task *curr;
    for (i = 0; i < max_tasks_g; i++)
    {
        curr = general_tasks_ht.tasks[i];

        printf("Chain %d:", i);
        while (curr != NULL)
        {
            printf("  < %d : %d >", curr->tid, curr->difficulty);
            curr = curr->next;
        }
        printf("\n");
    }
    return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq()
{
    int i, N = completed_tasks_pq.size;
    struct HT_Task *curr = completed_tasks_pq.tasks;
    printf("Completed Tasks =");
    for (i = 0; i < N; i++)
    {
        printf(" < %d : %d >", curr[i].tid, curr[i].difficulty);
    }
    printf("\n");
    return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree()
{
    print_double_tree_recursively(players_tree);
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void)
{ // free all allocated memory, didn't free heap since it did not allocate any memory at all.
    free_double_tree(players_tree);
    free(tree_guard);
    free(completed_tasks_pq.tasks);
    free_hash_table();
    return 1;
}

/**
 * @brief adds a new player to the tree structure
 *
 * @return 1 on success
 *         0 on failure
 */
int add_to_players_tree(struct Player *new_player, struct Player *curr)
{
    if (curr->pid > new_player->pid)
    {
        if (curr->lc == tree_guard)
        {
            new_player->rc = curr->lc;
            new_player->lc = curr->lc;
            curr->lc = new_player;
            new_player->parrent = curr;
        }
        else
        {
            return add_to_players_tree(new_player, curr->lc);
        }
    }
    else if (curr->pid < new_player->pid)
    {
        if (curr->rc == tree_guard)
        {
            new_player->rc = curr->rc;
            new_player->lc = curr->rc;
            curr->rc = new_player;
            new_player->parrent = curr;
        }
        else
        {
            return add_to_players_tree(new_player, curr->rc);
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

/**
 * @brief Prints players and their 2 fields (PID and is_alien) recursively
 * @return 1 on success
 *         0 on failure
 */
int print_players_recursively(struct Player *curr)
{
    assert(curr);
    if (curr->lc != tree_guard)
    {
        print_players_recursively(curr->lc);
    }
    printf("  <%d : %d>", curr->pid, curr->is_alien);
    if (curr->rc != tree_guard)
    {
        print_players_recursively(curr->rc);
    }
    return 1;
}

/**
 * @brief Universal hash function for a key.
 * @return hash value
 */
int H(int key)
{
    return ((a * key + b) % p) % max_tasks_g;
}

/**
 * @brief Hash Table task copy, with complexity O(1)
 * @return a Task copy of HT_Task node
 */
struct Task *HT_task_copy(struct HT_Task *node)
{
    struct Task *new_node;
    if (node == NULL)
    {
        return NULL;
    }
    new_node = malloc(1 * sizeof(struct Task));
    new_node->difficulty = node->difficulty;
    new_node->tid = node->tid;
    new_node->lc = NULL;
    new_node->rc = NULL;
    new_node->lcnt = 0;

    return new_node;
}

/**
 * @brief Add a Task to a player's task tree.
 */
void add_task_to_player(struct Task *task, struct Player *player)
{
    struct Task *curr = player->tasks;
    if (curr == NULL)
    {
        player->tasks = task;
    }
    else
    {
        while (1)
        {
            if (curr->tid > task->tid)
            {
                curr->lcnt++;
                if (curr->lc == NULL)
                {
                    curr->lc = task;
                    break;
                }
                curr = curr->lc;
            }
            else
            {
                if (curr->rc == NULL)
                {
                    curr->rc = task;
                    break;
                }
                curr = curr->rc;
            }
        }
    }
}

/**
 * Complexity: O(n) where n == max_tasks_g, as T(n) = a*n + c + complexityof(add_task_to_player)
 * 
 * There's a worst case scenario where the tasks tree of 1 player becomes a list with length == n, could happen
 * if there's only 1 non-alien player and the tasks are sorted (in any order) on the hash table. On this case,
 * complexity of add_task_to_player is linear (O(n)) instead of logarithmic (O(logn)), but even so, the overall 
 * distribute_tasks() complexity is still O(n).
 */
int distribute_tasks_recursively(int index, struct Player *curr_player)
{
    while (curr_task == NULL)
    {
        index++;
        if (index == max_tasks_g)
        {
            return index;
        }
        curr_task = general_tasks_ht.tasks[index];
    }
    if (curr_player->lc != tree_guard)
    {
        index = distribute_tasks_recursively(index, curr_player->lc);
        if (index == max_tasks_g)
        {
            return index;
        }
    }
    if (curr_player->is_alien == 0)
    {
        add_task_to_player(HT_task_copy(curr_task), curr_player);
        curr_task = curr_task->next;
        while (curr_task == NULL)
        {
            index++;
            if (index == max_tasks_g)
            {
                return index;
            }
            curr_task = general_tasks_ht.tasks[index];
        }
    }
    if (curr_player->rc != tree_guard)
    {
        index = distribute_tasks_recursively(index, curr_player->rc);
    }
    if (curr_player == players_tree && index != max_tasks_g)
    {
        index = distribute_tasks_recursively(index, curr_player);
    }

    return index;
}

/**
 * @brief Traverses through players_tree and prints their tasks.
 */
void print_double_tree_recursively(struct Player *player)
{ // also prints player's evidence on purpose so this function can be used by event W as well.
    if (player == NULL)
    {
        return;
    }
    if (player->lc != tree_guard)
    {
        print_double_tree_recursively(player->lc);
    }
    printf("PID:%d =", player->pid);
    // assert(check_counters(player->tasks) != -1); // Optional assertion just to check our counters :)
    print_tasks_tree(player->tasks);
    printf("\n");
    if (player->rc != tree_guard)
    {
        print_double_tree_recursively(player->rc);
    }
}

/**
 * @brief Prints a tasks' tree.
 */
void print_tasks_tree(struct Task *tasks)
{
    if (tasks == NULL)
    {
        return;
    }
    if (tasks->lc != NULL)
    {
        print_tasks_tree(tasks->lc);
    }
    printf("  < %d : %d >", tasks->tid, tasks->difficulty);
    if (tasks->rc != NULL)
    {
        print_tasks_tree(tasks->rc);
    }
}

/**
 * @brief Finds and removes the task with the given tid from player's tasks_tree.
 */
struct Task *remove_task(int tid, struct Player *player)
{
    if (player == NULL)
    {
        return NULL;
    }
    if (player->tasks == NULL)
    {
        return NULL;
    }
    struct Task *curr = player->tasks, *parent = NULL;
    while (curr != NULL && curr->tid != tid)
    {
        parent = curr;
        if (tid < curr->tid)
        {
            curr = curr->lc;
        }
        else
        {
            curr = curr->rc;
        }
    }
    if (curr == NULL)
    {
        return NULL;
    }
    curr = player->tasks;
    while (curr->tid != tid)
    { // fix the tasks lcnt if curr was found
        if (tid < curr->tid)
        {
            curr->lcnt--;
            curr = curr->lc;
        }
        else
        {
            curr = curr->rc;
        }
    }
    if (curr->rc != NULL && curr->lc != NULL)
    {
        struct Task *in_order = curr->rc, *in_order_parent = NULL;
        while (in_order->lc != NULL)
        { // find the next node in order and its parent
            in_order->lcnt--;
            in_order_parent = in_order;
            in_order = in_order->lc;
        }

        if (in_order_parent != NULL)
        { // if it is not just the right one from curr, we have to keep its potential children
            in_order_parent->lc = in_order->rc;
        }
        else
        { // if it is, we must keep its right subtree.
            curr->rc = in_order->rc;
        }
        if (parent == NULL)
        { // if curr is the tree's root, we have to update player->tasks pointer
            player->tasks = in_order;
        }
        else
        {
            if (parent->rc == curr)
            { // if current is the right child of its parent
                parent->rc = in_order;
            }
            else
            {
                parent->lc = in_order;
            }
        }
        in_order->lcnt = curr->lcnt;
        in_order->lc = curr->lc;
        in_order->rc = curr->rc;
    }
    else if (curr->rc != NULL)
    {
        if (parent == NULL)
        { // if curr is the tree's root
            player->tasks = curr->rc;
        }
        else
        {
            if (parent->rc == curr)
            { // if current is the right child of its parent
                parent->rc = curr->rc;
            }
            else
            {
                parent->lc = curr->rc;
            }
        }
    }
    else if (curr->lc != NULL)
    {
        if (parent == NULL)
        { // if curr is the tree's root
            player->tasks = curr->lc;
        }
        else
        {
            if (parent->rc == curr)
            { // if curr is the right child of its parent
                parent->rc = curr->lc;
            }
            else
            {
                parent->lc = curr->lc;
            }
        }
    }
    else
    {
        if (parent == NULL)
        { // if curr is the tree's root
            player->tasks = NULL;
        }
        else
        {
            if (parent->rc == curr)
            { // if curr is the right child of its parent
                parent->rc = NULL;
            }
            else
            {
                parent->lc = NULL;
            }
        }
    }
    return curr;
}

/**
 * @brief Adds a task to completed tasks priority queue.
 * @return 1 on success
 *         0 on failure
 */
int heap_insert(struct Task *curr)
{
    if (completed_tasks_pq.size == max_tasks_g || curr == NULL)
    {
        return 0;
    }
    int m = curr->difficulty, i = completed_tasks_pq.size - 1;
    struct HT_Task *arr = completed_tasks_pq.tasks, curr_ht;
    while (i >= 0 && arr[i].difficulty < m)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    curr_ht.difficulty = curr->difficulty;
    curr_ht.tid = curr->tid;
    curr_ht.next = NULL;
    arr[i + 1] = curr_ht;
    free(curr);
    completed_tasks_pq.size++;
    return 1;
}

/**
 * @brief Finds the player with the given pid.
 * @return pointer to struct Player if pid was found
 *         null if pid was not found
 */
struct Player *search_pid(int pid)
{
    struct Player *curr = players_tree;
    tree_guard->pid = pid;
    while (curr->pid != pid)
    {
        if (curr->pid < pid)
        {
            curr = curr->rc;
        }
        else
        {
            curr = curr->lc;
        }
    }
    if (curr == tree_guard)
    {
        return NULL;
    }
    return curr;
}

/**
 * @brief Function that takes a player1, takes his tasks tree and merges it with player2's task tree, returning the merged tree
 * @return pointer to merged tasks tree
 *         null if both trees are empty
 */
struct Task *merge_task_trees(struct Player *player1, struct Player *player2)
{
    struct Task **arr1, **arr2, **arr12, *res;
    int n1 = task_count(player1->tasks), n2 = task_count(player2->tasks), i, j;
    if (n1 == 0 && n2 == 0)
    {
        return NULL;
    }
    else if (n2 == 0)
    {
        return player1->tasks;
    }
    else if (n1 == 0)
    {
        return player2->tasks;
    }
    arr1 = malloc(n1 * sizeof(struct Task));
    arr2 = malloc(n2 * sizeof(struct Task));
    arr12 = malloc((n1 + n2) * sizeof(struct Task));

    i = tree_to_array(player1->tasks, arr1, 0);
    j = tree_to_array(player2->tasks, arr2, 0);
    if (i != n1 || j != n2)
    {
        return NULL;
    }
    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i]->tid < arr2[j]->tid)
        {
            arr12[i + j] = arr1[i];
            i++;
        }
        else
        {
            arr12[i + j] = arr2[j];
            j++;
        }
    }
    while (i < n1)
    {
        arr12[i + j] = arr1[i];
        i++;
    }
    while (j < n2)
    {
        arr12[i + j] = arr2[j];
        j++;
    }
    free(arr1);
    free(arr2);
    res = array_to_tree(arr12, 0, n1 + n2 - 1);
    free(arr12);
    return res;
}

/**
 * Counts the nodes of a Task tree.
 * @return the number of nodes within a Tasks tree. 
 */
int task_count(struct Task *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    return tree->lcnt + 1 + task_count(tree->rc);
}

/**
 * Creates an array of Task nodes from a given tree.
 * @return array index, should be equal to the node count of the given tree.
 */
int tree_to_array(struct Task *task, struct Task **arr, int index)
{ // pretty straightforward, nothing to comment here :)
    if (arr == NULL || task == NULL)
    {
        return 0;
    }
    if (task->lc != NULL)
    {
        index = tree_to_array(task->lc, arr, index);
    }
    arr[index] = task;
    index++;
    if (task->rc != NULL)
    {
        index = tree_to_array(task->rc, arr, index);
    }
    return index;
}

/**
 * Creates a tree from a given array.
 * @return pointer to the tree
 */
struct Task *array_to_tree(struct Task **arr, int start, int end)
{ // uses array to create a binary search tree, obviously the median is always current node.
    struct Task *node;
    int median = (int)(start + end) / 2;
    if (arr == NULL)
    {
        return NULL;
    }
    if (start > end)
    {
        return NULL;
    }
    node = arr[median];
    node->lc = array_to_tree(arr, start, median - 1);
    node->lcnt = median - start;
    node->rc = array_to_tree(arr, median + 1, end);
    return node;
}

/**
 * @brief returns the previous player in order
 * @return pointer to player on success
 *         null on failure
 */
struct Player *FindInOrderPredecessor(struct Player *curr)
{
    if (curr == NULL || curr == tree_guard)
    {
        return NULL;
    }
    struct Player *pre;
    if (curr->lc == tree_guard)
    { // if it doesnt have a left child, you move all the way up until you reach the root or the predecessor
        pre = curr;
        while (pre->pid >= curr->pid && pre != players_tree)
        {
            pre = pre->parrent;
        }
        if (pre->pid < curr->pid)
        {
            return pre;
        }
        // if it passed the previous if, it means it reached the tree's root
        // thus we need to find the last element in order (the one with the greatest id)
        while (pre->rc != tree_guard)
        {
            pre = pre->rc;
        }
        return pre;
    }
    else
    { // case where it has a right child, you find the rightest child of its left child.
        pre = curr->lc;
        while (pre->rc != tree_guard)
        {
            pre = pre->rc;
        }
        return pre;
    }
}

/**
 * @brief returns the next player in order
 * @return pointer to player on success
 *         null on failure
 */
struct Player *FindInOrderSuccessor(struct Player *curr)
{
    if (curr == NULL || curr == tree_guard)
    {
        return NULL;
    }
    struct Player *successor;
    if (curr->rc == tree_guard)
    { // if it doesnt have a right child, you move all the way up until you reach the root or the successor
        successor = curr;
        while (successor->pid <= curr->pid && successor != players_tree)
        {
            successor = successor->parrent;
        }
        if (successor->pid > curr->pid)
        {
            return successor;
        }
        // if it passed the previous if, it means it reached the tree's root
        // thus we need to find the 1st element in order (the one with the smallest id)
        while (successor->lc != tree_guard)
        {
            successor = successor->lc;
        }
        return successor;
    }
    else
    { // case where it has a right child, you find the leftiest child of its right child.
        successor = curr->rc;
        while (successor->lc != tree_guard)
        {
            successor = successor->lc;
        }
        return successor;
    }
}

/**
 * @brief Returns the element in front of the priority queue
 * @return pointer to the 1st element of pq
 *         null if pq is empty
 */
struct HT_Task *heap_pop()
{
    if (completed_tasks_pq.size == 0)
    { // if heap is empty
        return NULL;
    }
    struct HT_Task *pick, *arr = completed_tasks_pq.tasks;
    pick = &arr[0];
    completed_tasks_pq.size--;
    int k = 0;
    while (k < completed_tasks_pq.size)
    { // move all elements 1 position to the left
        arr[k] = arr[k + 1];
        k++;
    }
    return pick;
}

/**
 * @brief Finds the player with the most evidence
 * @return pointer to the player with max evidence
 *         null if player's list is empty
 */
struct Player *find_max_evidence(struct Player *curr)
{ // we find the node with most evidence from the left and right children of each node, comparing them and returning the node with max evidence
    struct Player *maxl = tree_guard, *maxr = tree_guard, *maxt;
    if (curr == NULL || curr == tree_guard)
    {
        return NULL;
    }
    if (curr->lc != tree_guard)
    {
        maxl = find_max_evidence(curr->lc);
    }
    if (curr->rc != tree_guard)
    {
        maxr = find_max_evidence(curr->rc);
    }
    maxt = curr;
    if (maxl != tree_guard && maxl != NULL)
    {
        if (maxt->evidence < maxl->evidence)
        {
            maxt = maxl;
        }
    }
    if (maxr != tree_guard && maxr != NULL)
    {
        if (maxt->evidence < maxr->evidence)
        {
            maxt = maxr;
        }
    }
    return maxt;
}

/**
 * @brief Optional Function I created to check out lcnts on a tasks tree
 * @return -1 if they are incorrect
 *         a positive integer if they are ok
 */
int check_counters(struct Task *root)
{ // returns -1 if there is an incorrect counter
    int k = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->lc != NULL)
    {
        k = check_counters(root->lc);
        if (k == -1)
        {
            return -1;
        }
    }
    if (k != root->lcnt)
    {
        return -1;
    }
    if (root->rc != NULL)
    {
        k += check_counters(root->rc);
        if (k < 0)
        {
            return -1;
        }
    }
    return k + 1;
}

/**
 * @brief Splits a tasks tree in 2
 * @return pointer to 2 pointers, the 2 trees
 *         null if tree is empty
 */
struct Task **split_tasks(struct Task *D, int k)
{
    struct Task *D1 = NULL, *D2 = NULL, **nodes;
    if (D == NULL || k < 0)
    {
        return NULL;
    }
    if (k - D->lcnt == 0)
    {
        D1 = D->lc;
        D2 = D;
        D2->lcnt = 0;
        D2->lc = NULL;
    }
    else if (k - D->lcnt == 1)
    { // this is a different case than the difference being equivalent to 0 since we can just include this node to D1 subtree.
        D1 = D;
        D2 = D->rc;
        D1->rc = NULL;
    }
    else if (k - D->lcnt > 0)
    {
        if (D->rc != NULL)
        {
            nodes = split_tasks(D->rc, k - D->lcnt - 1);
            D1 = nodes[0];
            D2 = nodes[1];
            free(nodes);
            D->rc = D1;
            D1 = D;
        }
        else
        {
            D1 = D;
            D2 = NULL;
        }
    }
    else
    { // LC cannot be null on this case, thats why I didn't bother checking it, should lcnt counters be correct
        nodes = split_tasks(D->lc, k);
        D1 = nodes[0];
        D2 = nodes[1];
        free(nodes);
        D->lcnt -= task_count(D1);
        D->lc = D2;
        D2 = D;
    }
    nodes = malloc(2 * sizeof(struct Task *));
    nodes[0] = D1;
    nodes[1] = D2;
    return nodes;
}

/**
 * @brief Counts aliens and crewmates using tree guard's pid and evidence elements (pid for crewmates, evidence for aliens)
 */
void count_players(struct Player *curr)
{
    if (curr == NULL || curr == tree_guard)
    {
        return;
    }
    if (curr->lc != tree_guard)
    {
        count_players(curr->lc);
    }
    if (curr->is_alien == 1)
    { // case curr is an alien
        tree_guard->evidence++;
    }
    else
    { // case curr is a human
        tree_guard->pid++;
    }
    if (curr->rc != tree_guard)
    {
        count_players(curr->rc);
    }
}

/**
 * @brief Free player tree's allocated memory, as well as their tasks
 */
void free_double_tree(struct Player *player)
{ // accessing the players in a post order way, so we free both children and their successors before freeing this node, and the player afterwards.
    if (player == NULL)
    {
        return;
    }
    if (player->lc != tree_guard)
    {
        free_double_tree(player->lc);
        player->lc = tree_guard;
    }
    if (player->rc != tree_guard)
    {
        free_double_tree(player->rc);
        player->rc = tree_guard;
    }
    free_tasks(player->tasks);
    free(player);
}

/**
 * @brief Free all hash_Table elements
 */
void free_hash_table()
{ // Didn't free the general_tasks_ht variable since its not a pointer and just a variable, hence no memory allocated
    int i;
    for (i = 0; i < max_tasks_g; i++)
    {
        struct HT_Task *curr = general_tasks_ht.tasks[i], *prev;
        prev = curr;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            free(prev);
        }
    }
    free(general_tasks_ht.tasks);
}

/**
 * @brief Free a task tree
 */
void free_tasks(struct Task *tasks)
{ // post order traversal of tasks tree and freeing each child.
    if (tasks == NULL)
    {
        return;
    }
    if (tasks->lc != NULL)
    {
        free_tasks(tasks->lc);
        tasks->lc = NULL;
    }
    if (tasks->rc != NULL)
    {
        free_tasks(tasks->rc);
        tasks->rc = NULL;
    }
    free(tasks);
}

void print_double_tree_with_evidence(struct Player *player)
{
    if (player == NULL)
    {
        return;
    }
    if (player->lc != tree_guard)
    {
        print_double_tree_with_evidence(player->lc);
    }
    printf("PID %d : %d =", player->pid, player->evidence);
    // assert(check_counters(player->tasks) != -1); // Optional assertion just to check our counters :)
    print_tasks_tree(player->tasks);
    printf("\n");
    if (player->rc != tree_guard)
    {
        print_double_tree_with_evidence(player->rc);
    }
}