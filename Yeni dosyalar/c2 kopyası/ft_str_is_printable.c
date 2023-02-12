#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 33 && str [i] <= 126))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main()
{
	printf("%d", ft_str_is_printable("01948987493"));
	printf("\n%d", ft_str_is_printable("0484882j8995489"));
	printf("\n%d", ft_str_is_printable("-_jsdsdc67sdlkc,"));
	printf("\n%d", ft_str_is_printable("\n\t\v\f"));
}
