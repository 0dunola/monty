#include "monty.h"

/**
 * setUp - set up resources
 * @filename: name of file
 */
void setUp(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	monty.buffer = NULL;
	monty.file = file;
	monty.line = 0;
	monty.lifo = 1;
	monty.stack = NULL;
	monty.arg = NULL;
}

/**
 * tearDown - clean up resources
 */
void tearDown(void)
{
	fclose(monty.file);
	if (monty.buffer)
		free(monty.buffer);

	if (monty.stack)
		free(monty.stack);
}

/**
 * runInterpreter - intepreter the file
 */
void runInterpreter(void)
{
	size_t n = 0;
	ssize_t flag;
	char *opcode;
	void (*fn)(stack_t **stack, unsigned int line_number);

	while ((flag = getline(&monty.buffer, &n, monty.file)) != -1)
	{
		monty.line++;
		opcode = strtok(monty.buffer, " \t\n\a\r");
		if (opcode && opcode[0] != '#')
		{
			monty.arg = strtok(NULL, " \t\n\a\r");
			fn = get_fn(opcode);
			if (!fn)
			{
				dprintf(2, "L%d: unknown instruction %s\n", monty.line, opcode);
				tearDown();
				exit(EXIT_FAILURE);
			}
			fn(&monty.stack, monty.line);
		}
	};
}

/**
 * main - run monty
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, otherwise 1
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	setUp(argv[1]);
	runInterpreter();
	tearDown();

	return (EXIT_SUCCESS);
}
