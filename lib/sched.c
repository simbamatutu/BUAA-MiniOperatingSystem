#include <env.h>
#include <pmap.h>
#include <printf.h>

/* Overview:
 *  Implement simple round-robin scheduling.
 *
 *
 * Hints:
 *  1. The variable which is for counting should be defined as 'static'.
 *  2. Use variable 'env_sched_list', which is a pointer array.
 *  3. CANNOT use `return` statement!
 */
/*** exercise 3.14 ***/
void sched_yield(void)
{
    static int count = 0; // remaining time slices of current env
    static int point = 0; // current env_sched_list index
    
    /*  hint:
     *  1. if (count==0), insert `e` into `env_sched_list[1-point]`
     *     using LIST_REMOVE and LIST_INSERT_TAIL.
     *  2. if (env_sched_list[point] is empty), point = 1 - point;
     *     then search through `env_sched_list[point]` for a runnable env `e`, 
     *     and set count = e->env_pri
     *  3. count--
     *  4. env_run()
     *
     *  functions or macros below may be used (not all):
     *  LIST_INSERT_TAIL, LIST_REMOVE, LIST_FIRST, LIST_EMPTY
     */

	static struct Env *e = NULL;
        if(e!=NULL && e->env_status != ENV_RUNNABLE){
                LIST_REMOVE(e,env_sched_link);
                e = NULL;
                count = 0;
        }
        if(count == 0) {
                if(LIST_FIRST(&env_sched_list[point]) == NULL){
                        point = 1 - point;
                }
                e = LIST_FIRST(&env_sched_list[point]);
                count = e->env_pri;
                LIST_REMOVE(e,env_sched_link);
                LIST_INSERT_HEAD(&env_sched_list[1-point],e,env_sched_link);
        }
        count = count - 1;
	env_run(e);
}
