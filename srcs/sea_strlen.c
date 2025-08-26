#include "sealib.h"


size_t	sea_strlen(const char *s)
{
  size_t size = 0;
  while (s[size] != '\0')
    size++;
  return (size);
}
