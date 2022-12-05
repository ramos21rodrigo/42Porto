#include "../includes/push_swap.h"

void push_by_chunks(t_stack *a_stack, t_stack *b_stack, int chunks)
{
	int middle_point;

	middle_point = find_middle_point(0, a_stack);
	while (a_stack->list[a_stack->top] < middle_point)
		execute(PB, a_stack, b_stack);
	while (a_stack->list[0] < middle_point)
	{
		execute(RRA, a_stack, b_stack);
		execute(PB, a_stack, b_stack);
	}
	while (a_stack->top - 1 > b_stack->top / chunks)
	{
		if (a_stack->list[a_stack->top] < middle_point)
			execute(PB, a_stack, b_stack);
		else
			execute(RA, a_stack, b_stack);
	}
}

void push_by_order(t_stack *a_stack, t_stack *b_stack)
{
	int i;
	int bigger;

	i = 1;
	bigger = find_bigger_one(b_stack);
	if (b_stack->list[b_stack->top - 1] == bigger)
		execute(SB, a_stack, b_stack);
	while (b_stack->list[b_stack->top] != bigger)
	{
		execute(RB, a_stack, b_stack);
		i++;
	}
	execute(PA, a_stack, b_stack);
	while (--i != 0)
		execute(RRB, a_stack, b_stack);
}