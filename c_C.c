#include "ftprintf.h"

void	c_C(t_specifer *specifer, char *c, t_format *t_format)
{
  char	*res;
  int	i;

  res = ft_strnew(specifer->weight > 1 ? specifer->weight : 1);
  i = 0;
  if (specifer->weight > 0)
    while (i + 1 != specifer->weight)
	res[i++] = ' ';
  if (specifer->flag_minus)
    res = ft_strjoin(c, res);
  else
    res = ft_strjoin(res, c);
  ft_putstr(res);
  printf("len = %i, strlen(res) = %i\n", t_format->len, (int)ft_strlen(res));
  t_format->len += ft_strlen(res);  
}

//void	procent(t_specifer *specifer, t_format *t_format)
//{
// char		*res;

  /*
   * flags: 0, -,
   * accur, weight
   *
   *
   */
//}
