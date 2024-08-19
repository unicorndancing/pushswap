# include "limits.h"
# include "../libft/libft.h"
#include "../push_swap.h"
#include "stdio.h"

enum {ERR = -1};

char	*trim_zero_and_sign(char *argv, int *psign)
{
	int	i;

	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
	{
		i++;
		if (argv[0] == '-')
			*psign = -1;
		else
			*psign = 1;
	}
	while (argv[i] == '0' && argv[i + 1] != '\0')
		i++;
	return (ft_substr(argv, i, ft_strlen(argv)));
}

int	verif_integer(char *argv)
{
	int	len;
	int	sign;
	int	sec;

	sec = 0;
	sign = 1;
	argv = trim_zero_and_sign(argv, &sign);
	if (!argv)
		return (ERR);
	len = ft_strlen(argv);
	if (len > 10)
		return (-1);
	if (len == 10)
	{
		if (sign == 1)
			sec = ft_strncmp("2147483647", argv, len);
		else
			sec = ft_strncmp("2147483648", argv, len);
	}
	free(argv);
	return (sec);
}

int	verif_value(char *argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
			&& argv[i][j + 1] != '\0' && j == 0)
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (ERR);
			j++;
		}
		if (verif_integer(argv[i]) < 0)
			return (ERR);
		i++;
		j = 0;
	}
	return (0);
}

int	check_double(char *argv[])
{
	int	i;
	int	j;

	j = 2;
	i = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ERR);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	verif_value_ini(char *argv[])
{
	if (!argv[1][0])
		return (ERR);
	if (verif_value(argv) != 0)
		return (ERR);
	if (check_double(argv) != 0)
		return (ERR);
	return (0);
}

int main (int argc, char **argv)
{
	if (verif_value_ini(argv) != 0)
		return (write (1, "arg", 3), 0);
	int i = 1;
	while (argv[i])
	{
		printf("%d\n", atoi(argv[i]));
		i++;
	}
	return (0);
}