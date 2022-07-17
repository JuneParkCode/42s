#include "pipex.h"

int	main(int argc, char *argv[])
{
	if (check_argument(argc, argv) == FAILED)
		return (FAILED);
	else
		do_pipe(argc, argv);
	return (SUCCESS);
}