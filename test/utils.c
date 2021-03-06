#include <header.h>

void	print_title(int log, char *title){
	dprintf(log, "~~~~~~ %s ~~~~~~\n", title);
	printf("\e[96m~~~~~~ %s ~~~~~~\e[0m\n", title);
}

void	print_result(int n_error){
	if (n_error)
		printf("\e[31m[FAIL]\e[0m\n");
	else
		printf("\e[32m[OK]\e[0m\n");
}