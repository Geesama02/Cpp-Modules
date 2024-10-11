#include <iostream>

int main(int argc, char **argv)
{
	int	i = 1;
	char c;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			c = toupper(argv[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << '\n';
	return (0);
}
