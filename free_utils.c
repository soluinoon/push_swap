#include "push_swap.h"

void    free_node(deq_t *node)
{
    free(node);
    node = NULL;
}