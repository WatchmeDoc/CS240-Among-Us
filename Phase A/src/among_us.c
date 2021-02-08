/***************************************************
 *                                                 *
 * file: among_us.c                                *
 *                                                 *
 * @Author  Antonios Peris                         *
 * @Version 20-10-2020                             *
 * @email   csdp1196@csd.uoc.gr                    *
 *                                                 *
 * @brief   Implementation of among_us.h           *
 *                                                 *
 ***************************************************
 */

#include "among_us.h"

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize()
{ // Ta inits opws zhtountai sta sxhmata apo oti katalava + mia global variable pou evala egw, ta distributed tasks
    int i;
    distributed_tasks = 0;
    players_head = malloc(1 * sizeof(struct Players));
    tasks_head = malloc(1 * sizeof(struct Head_GL));
    tasks_stack = malloc(1 * sizeof(struct Head_Completed_Task_Stack));
    if (players_head == NULL || tasks_head == NULL)
    {
        return 0;
    }
    players_head->evidence = -1;
    players_head->is_alien = -1;
    players_head->pid = -1;
    players_head->next = NULL;
    players_head->prev = NULL;

    tasks_head->head = NULL;
    for (i = 0; i < 3; i++)
    {
        tasks_head->tasks_count[i] = 0;
    }

    tasks_stack->count = 0;
    tasks_stack->head = NULL;
    return 1;
}

/**
 * @brief Register player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien)
{
    struct Players *curr = players_head->prev;
    struct Players *tmp = malloc(1 * sizeof(struct Players));
    struct Tasks *guard_node = malloc(1 * sizeof(struct Tasks));
    if (guard_node == NULL || tmp == NULL)
    {
        return 0;
    }
    tmp->evidence = 0;
    tmp->is_alien = is_alien;
    tmp->pid = pid;

    guard_node->tid = -1;
    guard_node->difficulty = 0;
    guard_node->next = NULL;

    tmp->tasks_head = guard_node;
    tmp->tasks_sentinel = guard_node;
    if (curr == NULL)
    { /// Periptwsh opou einai kenh h lista paiktwn
        curr = tmp;
        curr->prev = players_head;
        curr->next = players_head;
        players_head->next = curr;
        players_head->prev = curr;
    }
    else
    {
        tmp->prev = curr;
        tmp->next = players_head;
        players_head->prev = tmp;
        curr->next = tmp;
    }
    print_players();
    return 1;
}

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
int insert_task(int tid, int difficulty)
{
    struct Tasks *new_node = malloc(1 * sizeof(struct Tasks));
    struct Tasks *curr = tasks_head->head;
    struct Tasks *tmp;
    int pos = 0, i;
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->tid = tid;
    new_node->difficulty = difficulty;
    if (curr == NULL)
    { ///// adding the first task to the list
        new_node->next = NULL;
        tasks_head->head = new_node;
    }
    else
    {
        // The other way to do this was to simply iterate over the tasks list checking each time the node's difficulty
        // But my way finds out how many iterations do we have to do in order to position our item correctly before adding it to the list, skipping that difficulty check.
        // In some cases, the other way is more efficient, but in the worst case scenarios, my way is quite more efficient.
        for (i = 0; i < difficulty - 1; i++)
        {
            pos += tasks_head->tasks_count[i];
        }
        if (pos == 0)
        {
            tmp = tasks_head->head;
            tasks_head->head = new_node;
            new_node->next = tmp;
        }
        else
        {
            for (i = 0; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            tmp = curr->next;
            curr->next = new_node;
            new_node->next = tmp;
        }
    }
    tasks_head->tasks_count[difficulty - 1]++;
    print_tasks();
    return 1;
}

/**
 * @brief Distribute tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks()
{
    // to flag einai apla mia metavlhth pou xrhsimopoiw gia na dw an uparxoun mono aliens sto ship
    int flag = 1;
    struct Players *curr = players_head->next;
    struct Tasks *tmp = tasks_head->head, *new_node;
    if (tmp == NULL || curr == NULL)
    {
        return 0;
    }
    distributed_tasks += tasks_head->tasks_count[0] + tasks_head->tasks_count[1] + tasks_head->tasks_count[2];
    while (tmp != NULL)
    {
        while (curr->is_alien == 1 || curr == players_head)
        {
            if (curr == players_head && flag == 1)
            { // Periptwsh opou uparxoun mono aliens sto diasthmoploio
                return 0;
            }
            curr = curr->next;
        }
        flag = 0;
        new_node = task_copy(tmp);
        tmp = tmp->next;
        if (curr->tasks_sentinel->next == NULL)
        { // Periptwsh opou o paikths den exei katholou tasks
            curr->tasks_sentinel->next = new_node;
            curr->tasks_head = new_node;
        }
        else
        {
            curr->tasks_sentinel->next->next = new_node;
            curr->tasks_sentinel->next = new_node;
        }
        new_node->next = curr->tasks_sentinel;
        curr = curr->next;
    }
    print_double_list();
    return 1;
}

/**
 * 
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param difficulty The task's difficuly
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int difficulty)
{
    struct Players *tmp = players_head->next;
    struct Tasks *completed_task, *prev;
    if (tmp == NULL || tmp <= 0)
    {
        return 0;
    }
    tmp = find_pid(pid);
    if (tmp == NULL)
    { // Periptwsh opou den vrethike to PID
        return 0;
    }

    completed_task = tmp->tasks_head;
    if (completed_task == tmp->tasks_sentinel)
    { // periptwsh opou uparxei mono o guard node
        return 0;
    }
    if (completed_task->difficulty == difficulty || completed_task->next == tmp->tasks_sentinel)
    { // periptwsh opou diagrafoume prwto node
        tmp->tasks_head = completed_task->next;
        if (completed_task->next == tmp->tasks_sentinel)
        { // periptwsh opou meta to prwto node einai to task sentinel
            tmp->tasks_sentinel->next = NULL;
        }
    }
    else
    {
        prev = completed_task;
        // aksiopoioume ton sentinel
        tmp->tasks_sentinel->difficulty = difficulty;
        while (completed_task->next->difficulty != difficulty)
        {
            prev = completed_task;
            completed_task = completed_task->next;
        }
        if (completed_task->next != tmp->tasks_sentinel)
        { // an den stamathsame logw tou sentinel tote prepei na pame ena vhma mprosta
            prev = completed_task;
            completed_task = completed_task->next;
        }
        prev->next = completed_task->next;
        if (prev->next == tmp->tasks_sentinel)
        { // Periptwsh opou diagrafoume 1 komvo prin to task sentinel
            tmp->tasks_sentinel->next = prev;
        }
    }
    stack_push(completed_task);
    tasks_stack->count++;
    print_double_list();
    return 1;
}

/**
 * @brief Eject Player
 * 
 * @param pid The ejected player's id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid)
{
    // Epitides ulopoiw to part auto se allh sunarthsh opou den tupwnei tipota gia na einai reusable apo ta alla events
    if (throw_player(find_pid(pid)))
    {
        print_double_list();
        return 1;
    }
    else
    {
        return 0;
    }
}

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
int witness_eject(int pid, int pid_a, int number_of_witnesses)
{
    struct Players *curr = players_head->next;
    if (throw_player(find_pid(pid)) == 0)
    { // An den kataferame na petaksoume ton paikth me pid gia kapoio logo
        return 0;
    }
    curr = find_pid(pid_a);
    if (curr == NULL)
    {
        return 0;
    }
    curr->evidence += number_of_witnesses;
    print_double_list_evidence();
    return 1;
}

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
int sabbotage(int pid, int number_of_tasks)
{
    struct Players *curr = players_head->next, *sabotaged;
    struct Tasks *tmp;
    int i = 0;
    if (curr == NULL)
    {
        return 0;
    }
    while (curr != players_head && curr->pid != pid)
    {
        curr = curr->next;
    }
    sabotaged = curr;
    if (sabotaged == players_head)
    { // Periptwsh opou de vrhkame ton PID paikth
        return 0;
    }
    while (i < number_of_tasks / 2)
    {
        sabotaged = sabotaged->prev;
        if (sabotaged == players_head)
        {
            sabotaged = sabotaged->prev;
        }
        i++;
    }
    while (sabotaged->is_alien == 1)
    {
        sabotaged = sabotaged->next;
        if (sabotaged == players_head)
        {
            sabotaged = sabotaged->next;
        }
    }
    for (i = 0; i < number_of_tasks; i++)
    {
        tmp = stack_pop();
        if (tmp == NULL)
        { // An number_of_tasks > tasks_stack->count h pop tha epistrepsei NULL kapoia stigmh, emeis apla kanoume distribute ola ta upoloipa stous paiktes
            break;
        }
        Insert_Task_To_Player(sabotaged, tmp);
        do
        {
            sabotaged = sabotaged->next;
        } while (sabotaged->is_alien == 1 || sabotaged == players_head);
    }
    print_double_list();
    return 1;
}

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
int vote(int pid, int vote_evidence)
{
    struct Players *curr = players_head->next, *ejected = players_head;
    if (curr == NULL)
    {
        return 0;
    }
    while (curr->pid != pid && curr != players_head)
    {
        curr = curr->next;
    }
    if (curr == players_head)
    {
        return 0;
    }
    curr->evidence += vote_evidence;
    for (curr = players_head->next; curr != players_head; curr = curr->next)
    {
        if (curr->evidence > ejected->evidence)
        { // Auto douleuei epeidh sthn arxh to ejected deixnei sto players_head, ara exei evidence -1 pou einai to mikrotero apo olous outws h allws
            // epomenws akoma k o 1os player me 0 evidence tha exei megalutero apo auto.
            ejected = curr;
        }
    }
    if (throw_player(ejected) == 0)
    {
        return 0;
    }
    print_double_list_evidence();
    return 1;
}

/**
 * @brief Give Away Work
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work()
{
    struct Players *pmax = NULL, *pmin = NULL, *curr = players_head->next;
    struct Tasks *pmin_cut, *pmax_cut, *tasks_sentinel;
    int max = -1, min = ((unsigned int)-1) / 2, tmp;
    if (curr == NULL)
    {
        return 0;
    }
    while (curr != players_head)
    { // Briskoume edw min k max tautoxrona
        if (curr->is_alien == 0)
        {
            tmp = count_tasks(curr);
            if (max < tmp)
            {
                max = tmp;
                pmax = curr;
            }
            if (min > tmp)
            {
                min = tmp;
                pmin = curr;
            }
        }
        curr = curr->next;
    }
    if (pmin == pmax)
    { // se periptwsh opou uparxei mono 1 zwntanos crewmate
        return 0;
    }
    tasks_sentinel = pmin->tasks_sentinel;
    if (max != 1 && max != 0)
    { // An exei mono 1 task o pmax, tote den thn metaferw ston pmin. Profanws oute otan exei 0 tasks.
        // pmin_cut k antistoixa pmax_cut tha ginoun o 1os kai o teleutaios komvos ths listas pou theloume na paroume apo ton pmax kai na dwsoume ston pmin
        pmin_cut = pmax->tasks_head;
        pmax_cut = pmin_cut;
        for (tmp = 1; tmp < max / 2; tmp++)
        {
            pmax_cut = pmax_cut->next;
        }
        pmax->tasks_head = pmax_cut->next;
        if (min == 0)
        {
            pmin->tasks_head = pmin_cut;
            tasks_sentinel->next = pmax_cut;
        }
        else
        { // Edw akolouthw paromoia logikh me tou eject player :)
            struct Tasks *tcurr = pmin->tasks_head, *tprev;
            pmax_cut = pmax_cut->next;
            if (tcurr->difficulty > pmin_cut->difficulty)
            { // Ean xreiazetai na mpei prwto kapoio stoixeio ths listas pmin_cut
                pmin->tasks_head = pmin_cut;
                pmin_cut = pmin_cut->next;
                pmin->tasks_head->next = tcurr;
            }
            tprev = pmin->tasks_head;
            while (tcurr != tasks_sentinel)
            {
                if (tcurr->difficulty > pmin_cut->difficulty)
                {
                    tprev->next = pmin_cut;
                    tprev = pmin_cut;
                    pmin_cut = pmin_cut->next;
                    tprev->next = tcurr;
                    if (pmin_cut == pmax_cut)
                    {
                        break;
                    }
                }
                else
                {
                    tprev = tcurr;
                    tcurr = tcurr->next;
                }
            }
            if (pmin_cut != pmax_cut)
            { // Periptwsh opou den ekxwrithikan ola ta stoixeia tou kommatiou tou pmax
                tprev->next = pmin_cut;
                pmin_cut->next = tcurr;
                tasks_sentinel->next = pmax_cut;
            }
        }
    }
    print_double_list();
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
    int aliens = 0, humans = 0;
    struct Players *curr = players_head->next;
    if (curr == NULL)
    {
        return 0;
    }
    while (curr != players_head)
    {
        if (curr->is_alien)
        {
            aliens++;
        }
        else
        {
            humans++;
        }
        curr = curr->next;
    }
    if (aliens > humans)
    {
        printf("Aliens Win.\nDONE\n");
        return 1;
    }
    if (distributed_tasks == tasks_stack->count || aliens == 0)
    {
        printf("Crewmates Win.\nDONE\n");
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
    struct Players *curr = players_head->next;
    if (curr == NULL)
    {
        return 0;
    }
    printf("Players =");
    while (curr != players_head)
    {
        printf("  < %d : %d >", curr->pid, curr->is_alien);
        curr = curr->next;
    }
    printf("\nDONE\n");
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
    struct Tasks *curr = tasks_head->head;
    printf("List_Tasks =");
    while (curr != NULL)
    {
        printf("  < %d : %d >", curr->tid, curr->difficulty);
        curr = curr->next;
    }
    printf("\nDONE\n");
    return 1;
}

/**
 * @brief Print Stack
 *
 * @return 1 on success
 *         0 on failure
 */
int print_stack()
{ // Exoume stack, epomenws gia na tupwsoume ta stoixeia prepei na ginoun arketa pops, gia auto k to ulopoiw anadromika - wste na mh ta xanw
    printf("Stack_Tasks =");
    recursive_stack_print();
    printf("\nDONE\n");
    return 1;
}

/**
 * @brief Print Players & Task List
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_list()
{
    struct Players *curr;
    struct Tasks *tmp, *tasks_sentinel;
    curr = players_head->next;
    if (curr == NULL)
    {
        printf("DONE\n");
        return 0;
    }
    while (curr != players_head)
    {
        printf("PID:%d =", curr->pid);
        tmp = curr->tasks_head;
        tasks_sentinel = curr->tasks_sentinel;
        while (tmp != tasks_sentinel)
        {
            printf("  < %d : %d >", tmp->tid, tmp->difficulty);
            tmp = tmp->next;
        }
        printf("\n");
        curr = curr->next;
    }
    printf("DONE\n");
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void)
{ // 3 Parts gia 3 tupou mallocs p ginontai, 1 gia to Players, 1 gia to General Tasks List kai 1 gia to Completed_Tasks_Stack
    struct Players *curr = players_head->next, *prev;
    struct Tasks *tmp, *tasks_sentinel, *tmpnext;
    // Part 1
    if (curr != NULL)
    {
        prev = curr;
        while (curr != players_head)
        {
            prev = curr;
            curr = curr->next;
            tmp = prev->tasks_head;
            tasks_sentinel = prev->tasks_sentinel;
            while (tmp != tasks_sentinel)
            {
                tmpnext = tmp;
                tmp = tmp->next;
                free(tmpnext);
            }
            free(tasks_sentinel);
            free(prev);
        }
    }
    free(players_head);

    // Part 2
    tmp = tasks_head->head;
    while (tmp != NULL)
    {
        tmpnext = tmp;
        tmp = tmp->next;
        free(tmpnext);
    }
    free(tasks_head);

    // Part 3
    tmp = stack_pop();
    while (tmp != NULL)
    {
        tmpnext = tmp;
        tmp = stack_pop();
        free(tmpnext);
    }
    free(tasks_stack);
    return 1;
}

// My Functions
int throw_player(struct Players *dead)
{
    struct Players *min_p = NULL;
    struct Tasks *tmp, *tasks_sentinel, *prev, *dead_curr = NULL;
    if (players_head->next == NULL || dead == NULL)
    {
        return 0;
    }
    if (players_head->next->next == players_head)
    { // Periptwsh opou exoume enan paikth mono sthn lista paiktwn
        prev = players_head->next->tasks_head;
        players_head->next->tasks_sentinel->next = NULL;
        tmp = prev;
        while (tmp != NULL)
        {
            tmp = tmp->next;
            free(prev);
            prev = tmp;
        }
        free(dead);
        players_head->next = NULL;
        players_head->prev = NULL;
        return 1;
    }
    dead->prev->next = dead->next;
    dead->next->prev = dead->prev;
    min_p = find_min_tasks();
    if (min_p == NULL)
    { // an den vrethike o minimum smh
        return 0;
    }

    if (min_p->tasks_head == min_p->tasks_sentinel)
    { // Periptwsh opou o paikths me ta ligotera tasks exei 0 tasks
        min_p->tasks_head = dead->tasks_head;
        free(min_p->tasks_sentinel);
        min_p->tasks_sentinel = dead->tasks_sentinel;
    }
    else if (dead->tasks_head != dead->tasks_sentinel)
    { // Merging the two Tasks lists sthn periptwsh opou o nekros den eixe oloklhrwsei ta tasks tou
        tasks_sentinel = min_p->tasks_sentinel;
        prev = min_p->tasks_head;
        tmp = prev;
        dead_curr = dead->tasks_head;

        if (tmp->difficulty >= dead_curr->difficulty)
        { // Periptwsh opou to 1o task tou nekrou paikth einai na mpei 1o sthn lista tou paikth me ta ligotera tasks
            min_p->tasks_head = dead_curr;
            dead_curr = dead_curr->next;
            min_p->tasks_head->next = tmp;
            prev = min_p->tasks_head;
        }
        if (dead_curr != dead->tasks_sentinel)
        { // Ean emeine mono o sentinel tote de xreiazetai na mpoume edw
            while (tmp != tasks_sentinel)
            {
                if (tmp->difficulty >= dead_curr->difficulty)
                {
                    prev->next = dead_curr;
                    dead_curr = dead_curr->next;
                    prev->next->next = tmp;
                    prev = prev->next;
                    if (dead_curr == dead->tasks_sentinel)
                    { // an ekxwrithikan ola ta tasks tou dead paikth ston min_p tote kanoume free to tasks_sentinel tou nekrou paikth
                        free(dead->tasks_sentinel);
                        break;
                    }
                }
                else
                {
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
        }
        if (dead_curr != dead->tasks_sentinel)
        { // Se periptwsh opou den ekxwrithikan ola ta tasks tou dead, ta ekxwroume meta to prev opws einai, kanontas free ton palio tasks sentinel k kratame auton
            // pou eixe o dead
            prev->next = dead_curr;
            min_p->tasks_sentinel = dead->tasks_sentinel;
            free(tmp);
        }
    }

    free(dead);
    // Parathrhsh, o parapanw algorithmos sugxwneushs tha kanei akrivws n1 + n2 prospelaseis twn listwn mono sthn periptwsh opou meta thn while exei perissepsei
    // 1 node sto tasks_list tou nekrou paikth opou einai k to worst case, eidallws tha ektelesei ligoteres (mexri kai 1 se kapoio senario!) prospelaseis.
    return 1;
}

struct Tasks *stack_pop()
{ //Casual stack_pop algorithmos
    struct Tasks *curr = tasks_stack->head, *prev;
    prev = curr;
    if (curr != NULL)
    {
        curr = curr->next;
        if (curr != NULL)
        {
            while (curr->next != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
        }
        else
        {
            curr = prev;
            tasks_stack->head = NULL;
        }
        tasks_stack->count--;
        return curr;
    }
    return NULL;
}

void stack_push(struct Tasks *elem)
{ // Casual stack push :D
    struct Tasks *top = stack_top();
    if (top == NULL)
    {
        tasks_stack->head = elem;
    }
    else
    {
        top->next = elem;
    }
    elem->next = NULL;
}

struct Tasks *stack_top()
{
    struct Tasks *res = tasks_stack->head, *prev = NULL;
    while (res != NULL)
    {
        prev = res;
        res = res->next;
    }
    return prev;
}

void Insert_Task_To_Player(struct Players *p, struct Tasks *t)
{ // Aplh insert sunarthsh wste h domh na paramenei taksinomhmenh
    struct Tasks *curr = p->tasks_head, *prev = NULL;
    int t_dif = t->difficulty;
    while (curr->difficulty < t_dif && curr != p->tasks_sentinel)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL)
    {
        p->tasks_head = t;
        t->next = curr;
    }
    else
    {
        prev->next = t;
        t->next = curr;
        if (curr == p->tasks_sentinel)
        {
            curr->next = t;
        }
    }
}

struct Players *find_min_tasks()
{
    struct Players *curr = players_head->next, *min = NULL;
    int cnt = ((unsigned int)-1) / 2, tmp;
    if (curr == NULL)
    {
        return NULL;
    }
    while (curr != players_head)
    {
        if (curr->is_alien != 1)
        {
            tmp = count_tasks(curr);
            if (tmp < cnt)
            {
                min = curr;
                cnt = tmp;
            }
        }
        curr = curr->next;
    }
    return min;
}

struct Players *find_max_tasks()
{
    struct Players *curr = players_head->next, *max;
    int cnt, tmp;
    if (curr == NULL)
    {
        return NULL;
    }
    max = curr;
    cnt = count_tasks(max);
    curr = curr->next;
    while (curr != players_head)
    {
        tmp = count_tasks(curr);
        if (tmp > cnt)
        {
            max = curr;
            cnt = tmp;
        }
        curr = curr->next;
    }
    return max;
}

struct Players *find_pid(int pid)
{ // Linear search giati den einai taksinomhmenh h lista
    struct Players *curr = players_head->next;
    while (curr != players_head)
    {
        if (curr->pid == pid)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

int count_tasks(struct Players *p)
{
    struct Tasks *curr = p->tasks_head, *tasks_sentinel = p->tasks_sentinel;
    int result = 0;
    while (curr != tasks_sentinel)
    {
        result++;
        curr = curr->next;
    }
    return result;
}

int print_double_list_evidence()
{
    struct Players *curr;
    struct Tasks *tmp, *tasks_sentinel;
    curr = players_head->next;
    if (curr == NULL)
    {
        printf("DONE\n");
        return 0;
    }
    while (curr != players_head)
    {
        printf("<PID:%d, %d> =", curr->pid, curr->evidence);
        tmp = curr->tasks_head;
        tasks_sentinel = curr->tasks_sentinel;
        while (tmp != tasks_sentinel)
        {
            printf("  < %d : %d >", tmp->tid, tmp->difficulty);
            tmp = tmp->next;
        }
        printf("\n");
        curr = curr->next;
    }
    printf("DONE\n");
    return 1;
}

void recursive_stack_print()
{
    struct Tasks *curr = stack_pop();
    if (curr == NULL)
    {
        return;
    }
    recursive_stack_print();
    printf("  < %d : %d >", curr->tid, curr->difficulty);
    stack_push(curr);
}

struct Tasks *task_copy(struct Tasks *node)
{
    struct Tasks *new_node = malloc(1 * sizeof(struct Tasks));
    new_node->difficulty = node->difficulty;
    new_node->tid = node->tid;
    new_node->next = NULL;
    return new_node;
}