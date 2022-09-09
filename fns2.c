#include "monty.h"

/**
 * fn_add - removes the top element of the stack
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	fn_pop(stack, line_number);
}

/**
 * fn_nop - removes the top element of the stack
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
