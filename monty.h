#ifndef MONTY_H
#define MONTY_H

/* For dprintf and getline support */
#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <syscall.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_s - monty struct
 * @count: count
 */
typedef struct monty_s
{
	FILE *file;
	int line;
	char *buffer;
	int lifo;
	stack_t *stack;
	char *arg;

} monty_t;

/* Declaration of the global variable */
extern monty_t monty;
monty_t monty;

void (*get_fn(char *opc))(stack_t **stack, unsigned int line_number);
void fn_push(stack_t **stack, unsigned int line_number);
void fn_pall(stack_t **stack, unsigned int line_number);
void fn_pint(stack_t **stack, unsigned int line_number);
void fn_pop(stack_t **stack, unsigned int line_number);
void fn_swap(stack_t **stack, unsigned int line_number);
void fn_add(stack_t **stack, unsigned int line_number);
void fn_nop(stack_t **stack, unsigned int line_number);

int _isdigit(char *str);

#endif /* MONTY_H */