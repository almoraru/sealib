#include "sealib.h"

void	*sea_memset(void *s, int c, size_t n)
{
  unsigned char *src = (unsigned char *)s;
  size_t index = 0;

  while (index < n)
    {
      src[index] = c;
      index++;
    }
  return (s);
}
