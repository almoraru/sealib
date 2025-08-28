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
/*      Updated: 2025/08/28 23:28:05 by espadara                              */
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
/* DEFINES  */



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

/* CONVERSIONS */
int	sea_atoi(const char *nptr);

#endif
