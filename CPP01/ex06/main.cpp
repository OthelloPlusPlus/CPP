
#include "Harl.hpp"
#include "colors.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	int	i;

	i = 1;
	while (i < argc)
	{
		harl.complain(argv[i]);
		i++;
	}
	
	return (0);
}
