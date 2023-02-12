#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str [i] <= 90))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main()
{
	printf("%d", ft_str_is_uppercase("ASDADADSASDA"));
	printf("\n%d", ft_str_is_uppercase("0484882sdada*123j8995489"));
	printf("\n%d", ft_str_is_uppercase("1231312,"));
}
