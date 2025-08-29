/* ************************************************************************** */
/*                                                                            */
/*                        ______                                              */
/*                     .-"      "-.                                           */
/*                    /            \                                          */
/*        _          |              |          _                              */
/*       ( \         |,  .-.  .-.  ,|         / )                             */
/*        > "=._     | )(__/  \__)( |     _.=" <                              */
/*       (_/"=._"=._ |/     /\     \| _.="_.="\_)                             */
/*              "=._ (_     ^^     _)"_.="                                    */
/*                  "=\__|IIIIII|__/="                                        */
/*                 _.="| \IIIIII/ |"=._                                       */
/*       _     _.="_.="\          /"=._"=._     _                             */
/*      ( \_.="_.="     `--------`     "=._"=._/ )                            */
/*       > _.="                            "=._ <                             */
/*      (_/                                    \_)                            */
/*                                                                            */
/*      Filename: sealib.h                                                    */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/08/23 15:35:18 by espadara                              */
/*      Updated: 2025/08/29 23:24:37 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEALIB_H
# define SEALIB_H

/* INCLUDES */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <bsd/string.h>
# include <math.h>

/* DEFINES  */

# define ARENA_DEFAULT 4096
# define ARENA_ALIGN 16

/* STRUCTURES */

typedef struct	s_list
{
  void *content;
  size_t size;
  struct s_list *next;
}				t_list;

typedef struct	s_mem
{
  struct s_mem *next;
  size_t total;
  size_t used;
  unsigned char *mem;
}				t_mem;
/* FUNCTIONS */

/* BOOLEANS  */
int	sea_isalpha(int c);
int	sea_isdigit(int c);
int	sea_isalnum(int c);
int	sea_isascii(int c);
int	sea_isprint(int c);
int	sea_iswhitespace(char c);

/* STRINGS */
size_t	sea_strlen(const char *s);
char	*sea_strcpy(char *dest, const char *src);
char	*sea_strncpy(char *dest, const char *src, size_t dsize);
size_t	sea_strlcpy(char *dst, const char *src, size_t size);
size_t	sea_strlcat(char *dst, const char *src, size_t size);
void	*sea_bzero(void *s, size_t n);
int	sea_toupper(int c);
int	sea_tolower(int c);
char	*sea_strchr(const char *s, int c);
char	*sea_strrchr(const char *s, int c);
char	*sea_strstr(const char *haystack, const char *needle);
int	sea_strcmp(const char *s1, const char *s2);
int	sea_strncmp(const char *s1, const char *s2, size_t n);
char	*sea_strnstr(const char *haystack, const char *needle, size_t len);

/* MEMORY */
void	*sea_memset(void *s, int c, size_t n);
void	*sea_memcpy(void *dest, const void *src, size_t n);
void	*sea_memmove(void *dest, const void *src, size_t n);
void	*sea_memchr(void *s, int c, size_t n);
int	sea_memcmp(const char *s1, const char *s2, size_t n);
t_mem	*sea_arena_init(size_t size);
void	*sea_arena_alloc(t_mem *arena, size_t size);
void	sea_arena_free(t_mem *arena);

/* CONVERSIONS */
int	sea_atoi(const char *nptr);
int	sea_atoi_base(const char *str, int base);
double	sea_atof(const char *str);
#endif
