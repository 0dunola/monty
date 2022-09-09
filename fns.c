#include "monty.h"

/**
 * fn_push - pushs a value to the stack
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_push(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *node;
	int value;

	if (!monty.arg || !_isdigit(monty.arg))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(monty.arg);

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = value;

	if (*stack == NULL)
	{
		*stack = node;
		return;
	}

	if (monty.lifo)
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
		return;
	}

	for (current = *stack; current->next; current = current->next)
		;

	current->next = node;
	node->prev = current;
}

/**
 * fn_pall - print all value of list
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * fn_pint - print all value of list
 *
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * fn_pop - removes the top element of the stack
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * fn_swap - removes the top element of the stack
 * @stack: first node in the list
 * @line_number: line  currently on
 */
void fn_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = *stack;
}

