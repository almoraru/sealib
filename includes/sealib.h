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
/*      Updated: 2025/08/26 15:46:56 by amoraru                               */
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
/* DEFINES  */



/* FUNCTIONS */

/* BOOLEANS  */
int	sea_isalpha(int c);
int	sea_isdigit(int c);
int	sea_isalnum(int c);
int	sea_isascii(int c);
int	sea_isprint(int c);

/* STRINGS */
size_t	sea_strlen(const char *s);
void	*sea_bzero(void *s, size_t n);

/* MEMORY */
void	*sea_memset(void *s, int c, size_t n);


#endif
