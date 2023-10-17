#include <unistd.h>
#include <stdlib.h>

int		control(char *input);
int		ft_strlen(char *string);
void	ft_strcpy(char *dest, char *src);
void	check_arg(int argc, char **argv, char *dict);

int	main(int argc, char **argv)
{
	char	dict[100];

	check_arg(argc, argv, dict);
	return (0);
}

void	check_arg(int argc, char **argv, char *dict)
{
	int	key;

	key = 0;
	if (argc == 3)
	{
		ft_strcpy(dict, argv[1]);
		if (control(argv[2]) == (-1))
			write(2, "Error\n", 7);
		else
			key = control(argv[2]);
	}
	else if (argc == 2)
	{
		key = control(argv[1]);
		if (key == (-1))
			write(2, "Error\n", 7);
	}
	else
		write(2, "Error\n", 7);
}

int	control(char *input)
{
	int		int_input;
	int		i;
	char	*arg;

	int_input = 0;
	i = 0;
	arg = (char *)malloc((ft_strlen(input) + 1) * 1);
	if (arg == NULL)
		return (1);
	ft_strcpy(arg, input);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (-1);
		else
			int_input = int_input * 10 + (arg[i] - '0');
		i++;
	}
	free(arg);
	return (int_input);
}

int	ft_strlen(char *string)
{
	int	len;

	len = 0;
	while (*string)
	{
		string++;
		len++;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
