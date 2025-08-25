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
/*      Updated: 2025/08/23 18:45:33 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEALIB_H
# define SEALIB_H

/* INCLUDES */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
/* DEFINES  */



/* FUNCTIONS */

/* BOOLEANS  */
int	sea_isalpha(int c);
int	sea_isdigit(int c);
int	sea_isalnum(int c);
int	sea_isascii(int c);
int	sea_isprint(int c);

#endif
