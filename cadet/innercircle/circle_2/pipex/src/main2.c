
#include "pipex.h"

int	main(int argc, char *argv[])
{
	if (is_valid_argument(argc) == FALSE)
		return (1);
	build_pipe_and_fork_process_parallel(argc, argv);
}
