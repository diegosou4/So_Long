
#include "../includes/so_long.h"




char	*ft_strdup(const char *src)
{
	char	*dest;
	int	size;
	int	i;

	i = 0;
	size = ft_strlen((char *)src);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}