#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void ft_base_dec(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_base_dec(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void	ft_base_bi(int nbr)
{
	char	restes[100];
	int		index;

	restes[0] = '\0';
	index = 1;
	while (nbr > 0)
	{
		restes[index] = ((nbr % 2) + '0'); 
		nbr = nbr / 2;
		index++;
	}
	index -= 1;
	while (index >= 0)
	{
		ft_putchar(restes[index]);
		index--;
	}
}

void	ft_base_hexa(int nbr)
{

}

void ft_putnbr_base(int nbr, char *base)
{
	if (base[0] == '0' && base[9] == '9' && base[10] == '\0')
		ft_base_dec(nbr);
	if (base[0] == '0' && base[2] == '\0')
		ft_base_bi(nbr);
	if (base[11] == 'A')
		ft_base_hexa(nbr);
	else
		(void)nbr;
}



int main()
{
	ft_putnbr_base(4873, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(4873, "01");
}