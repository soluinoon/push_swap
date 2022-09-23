#include <stdio.h>
#include "push_swap.h"

void    free_tmp(char **tmp)
{
    int i;

    i = 0;
    while (tmp[i])
    {
        free(tmp[i]);
        i++;
    }
    free(tmp);
}

void    ft_perror(void)
{
    write(2, "Error\n", 6);
    exit(0);
}

int check_digit(char *str) 
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (ft_isdigit(str[i]) == 0)
        {
            if (str[i] == ' ' || str[i] == '-')
            {
                if (ft_isdigit(str[i + 1]) == 0)
                    return (0);
            }
            else
                return (0);
        }
        i++;
    }
    return (1);
}

void    parsing(int argc, char **argv, deq_info *info) 
{
    char        **tmp;
    int         i;
    int         j;
    long        num_tmp;

    i = 1;
    while (i < argc)
    {
        if (!argv[i] || check_digit(argv[i]) != 1)
            ft_perror();
        tmp = ft_split(argv[i], ' ');
        j = 0;
        while (tmp[j] != NULL) // 다시확인
        {
            num_tmp = ft_atol(tmp[j]);
            if (num_tmp > 2147483647 || num_tmp < -2147483648)
                ft_perror();
            push_bot((int)num_tmp, &info->top_a, &info->bot_a);
            info->size_a++;
            j++;
        }
        free_tmp(tmp);
        i++;
    }
    printing(info);
}
// next -> 위
// prev -> 아래
// 첫인자가 탑으로
void    printing(deq_info *info)
{
    deq_t *node = info->top_a;
    printf("node = %d\n", node->data);
    printf("next = %d\n", node->prev->data);
    //rintf("prev = %d\n", node->next->data);

    printf("printing\n");

    while (node != NULL)
    {
        printf("%d\n", node->data);
        node = node->prev;
    }
}

void    init_info(deq_info *info)
{
    info->size_a = 0;
    info->size_b = 0;
    info->top_a = NULL;
    info->top_b = NULL;
    info->bot_a = NULL;
    info->bot_b = NULL;
}

int main(int argc, char** argv)
{
    deq_info info;

    if (1 < argc)
    {
        init_info(&info);
        parsing(argc, argv, &info);         
    }
    return (0);
}