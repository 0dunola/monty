#include "monty.h"

/**
 * get_fn - maps an appropriate function with opcode
 * @opc: opcode
 * Return: function
 */
void (*get_fn(char *opc))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t fns[] = {
		{ "push", fn_push },
		{ "pall", fn_pall },
		{ "pint", fn_pint },
		{ "pop", fn_pop },
		{ "swap", fn_swap },
		{ "add", fn_add },
		{ "nop", fn_nop },
		{ NULL, NULL }
	};

	for (i = 0; fns[i].opcode; i++)
	{
		if (strcmp(fns[i].opcode, opc) == 0)
			return (fns[i].f);
	}
	return (NULL);
}
