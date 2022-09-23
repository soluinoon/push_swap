#include "push_swap.h"

deq_t *create_node(int data)
{
    deq_t *node;

    node = (deq_t*)malloc(sizeof(deq_t));
    if(!node)
        return (NULL);
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void    push_top(int data, deq_t **top, deq_t **bot)
{
    deq_t *node;

    node = create_node(data);
    if (node == NULL)
        return;
    if (*top == NULL)
    {
        *bot = node;
        *top = node;
    }
    else
    {
        (*top)->next = node;
        node->prev = *top;
        *top = node;
    }
}

void    push_bot(int data, deq_t **top, deq_t **bot)
{
    deq_t   *node;

    node = create_node(data);
    if (node == NULL)
        return;
    if (*bot == NULL)
    {
        *bot = node;
        *top = node;
    }
    else
    {
        (*bot)->prev = node;
        node->next = *bot;
        *bot = node;
    }
}