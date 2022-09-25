#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct deque
{
    int             data;
    struct deque  *prev;
    struct deque  *next;

}   deq_t;

typedef struct deq_info
{
    int size_a;
    int size_b;
    deq_t *top_a;
    deq_t *top_b;
    deq_t *bot_a;
    deq_t *bot_b;
} deq_info;

void    free_tmp(char **tmp);
void    ft_perror(void);
int check_digit(char *str);
void    parsing(int argc, char **argv, deq_info *info);
void    init_info(deq_info *info);
int main(int argc, char** argv);
static void	free_strs(char **strs);
static size_t	fill_it(char **strs, char const *str, size_t size, size_t index);
static size_t	how_many_strs(char const *str, char c);
static char	**make_strs(char const *str, char c, size_t *size);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
long	ft_atol(const char *str);
void    printing(deq_info *info);
deq_t *create_node(int data);
void    push_top(int data, deq_t **top, deq_t **bot);
void    push_bot(int data, deq_t **top, deq_t **bot);
int pop_top(int *data, deq_t **top, deq_t **bot);
int pop_bot(int *data, deq_t **top, deq_t **bot);
void    free_node(deq_t *node);

#endif