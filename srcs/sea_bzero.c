#include "sealib.h"

void	*sea_bzero(void *s, size_t n)
{
  return(sea_memset(s, 0, n));
}
