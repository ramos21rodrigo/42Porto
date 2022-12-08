#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "../../libft/libft.h"
#include <stdbool.h>
#include <limits.h>

#define SA "sa"
#define SB "sb"
#define SS "ss"
#define PA "pa"
#define PB "pb"
#define RA "ra"
#define RB "rb"
#define RR "rr"
#define RRA "rra"
#define RRB "rrb"
#define RRR "rrr"

typedef struct s_stack
{
	int stack_size;
	int *list;
	int top;
} t_stack;

int *parse_input(int argc, const char **argv);
void execute(char *op, t_stack *a_s, t_stack *b_s);
bool is_empty(t_stack *stack);
bool is_in_order(t_stack *stack);

#endif