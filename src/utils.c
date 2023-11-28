#include "../includes/so_long.h"

static int	ft_countwordls(unsigned int n)
{
	int	wordls;

	wordls = 0;
	if (n == 0)
		wordls++;
	while (n != 0)
	{
		n = n / 10;
		wordls++;
	}
	return (wordls);
}

static char	*ft_putintchar(unsigned int n, char *str, size_t len, int negative)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		str[0] = '0';
	}
	while (n != 0)
	{
		i = n % 10;
		str[len] = i + '0';
		n = n / 10;
		len--;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len_str;
	int				negative;
	unsigned int	num;

	num = n;
	len_str = 0;
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		len_str = 1;
		num *= -1;
	}
	len_str += (ft_countwordls(num) + 1);
	str = (char *)malloc(len_str *  sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_putintchar(num, str, (len_str - 2), negative);
    str[len_str - 1] = '\0';
	return (str);
}
int     len_str(char **str)
{
    int i;
    i = 0;
    while(str[i])
        i++;
    return(i);
}
char    **ft_dstrjoin(char **str, char *buffer)
{
    char **new_str;
    int i;
    int j;
    int k;
    i = 0;
    j = 0;
    k = 0;
    if(!str)
    {
        str = (char **) malloc (sizeof(char *) * 1);
        str[0] = NULL;
    }
    if(!str || !buffer)
        return(NULL);
    new_str = (char **)malloc((1 + len_str(str)) + 1 * sizeof(char *));
    if(!new_str)
        return(NULL);
    while(str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    while(buffer && buffer[j])
    {
        new_str[i][j] = buffer[j];
        j++;
    }
    new_str[i + j] = '\0';
    return(new_str);
}