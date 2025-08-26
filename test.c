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
/*      Filename: test.c                                                      */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/08/23 15:38:40 by espadara                              */
/*      Updated: 2025/08/26 23:14:47 by espadara                              */
/*                                                                            */
/* ************************************************************************** */

#include "sealib.h"

int main(void)
{
  printf("CONDUCTING TESTS!!!\n");
  puts("\n---ISALPHA---");
  /* isalpha */
  printf("1 - isalpha!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'a', '4', 'Z', isalpha('a'), isalpha('4'), \
         isalpha('Z'), sea_isalpha('a'), sea_isalpha('4'),sea_isalpha('Z'));
  printf("2 - isalpha!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'A', '@', 'v', isalpha('A'), isalpha('@'), \
         isalpha('v'), sea_isalpha('A'), sea_isalpha('@'),sea_isalpha('v'));
  printf("3 - isalpha!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'x', '0', ')', isalpha('x'), isalpha('0'), \
         isalpha(')'), sea_isalpha('x'), sea_isalpha('0'),sea_isalpha(')'));
  /* isdigit */
  puts("\n---ISDIGIT---");
  printf("1 - isdigit!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'a', '4', 'Z', isdigit('a'), isdigit('4'), \
         isdigit('Z'), sea_isdigit('a'), sea_isdigit('4'),sea_isdigit('Z'));
  printf("2 - isdigit!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'A', '@', 'v', isdigit('A'), isdigit('@'), \
         isdigit('v'), sea_isdigit('A'), sea_isdigit('@'),sea_isdigit('v'));
  printf("3 - isdigit!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'x', '0', ')', isdigit('x'), isdigit('0'), \
         isdigit(')'), sea_isdigit('x'), sea_isdigit('0'),sea_isdigit(')'));
  /* isalnum */
  puts("\n---ISALNUM---");
  printf("1 - isalnum!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'a', '4', 'Z', isalnum('a'), isalnum('4'), \
         isalnum('Z'), sea_isalnum('a'), sea_isalnum('4'),sea_isalnum('Z'));
  printf("2 - isalnum!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'A', '@', 'v', isalnum('A'), isalnum('@'), \
         isalnum('v'), sea_isalnum('A'), sea_isalnum('@'),sea_isalnum('v'));
  printf("3 - isalnum!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'x', '0', ')', isalnum('x'), isalnum('0'), \
         isalnum(')'), sea_isalnum('x'), sea_isalnum('0'),sea_isalnum(')'));
  /* isascii */
    puts("\n---ISASCII---");
  printf("1 - isascii!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'a', '4', 'Z', isascii('a'), isascii('4'), \
         isascii('Z'), sea_isascii('a'), sea_isascii('4'),sea_isascii('Z'));
  printf("2 - isascii!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'A', '@', 'v', isascii('A'), isascii('@'), \
         isascii('v'), sea_isascii('A'), sea_isascii('@'),sea_isascii('v'));
  printf("3 - isascii!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 250, '0', ')', isascii(250), isascii('0'), \
         isascii(')'), sea_isascii(250), sea_isascii('0'),sea_isascii(')'));
  /* isprint */
      puts("\n---ISPRINT---");
  printf("1 - isprint!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'a', '4', 'Z', isprint('a'), isprint('4'), \
         isprint('Z'), sea_isprint('a'), sea_isprint('4'),sea_isprint('Z'));
  printf("2 - isprint!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 'A', '@', 'v', isprint('A'), isprint('@'), \
         isprint('v'), sea_isprint('A'), sea_isprint('@'),sea_isprint('v'));
  printf("3 - isprint!!!\nCHARS |%c| |%c| |%c|\nREAL: |%d| |%d| |%d|\n\
SEAL: |%d| |%d| |%d|\n", 250, '0', ')', isprint(250), isprint('0'), \
         isprint(')'), sea_isprint(250), sea_isprint('0'),sea_isprint(')'));


  char *strlen_test_one = "hey I AM A REAL STRING";
  char *strlen_test_two = "";
  char *strlen_test_three = "a";
  char *strlen_test_four = "1234\01234";
  char *strlen_test_five = "xyz";

  puts("\n---STRLEN---");
  printf("1 - strlen ! STRS:\n|%s|\n|%s|\n|%s|\n|%s|\n|%s|\nREAL: |%ld| \
|%ld| |%ld| |%ld| |%ld|\nSEAL: |%ld| |%ld| |%ld| |%ld| |%ld|\n", \
         strlen_test_one, strlen_test_two, strlen_test_three, strlen_test_four, \
         strlen_test_five, strlen(strlen_test_one), strlen(strlen_test_two),\
         strlen(strlen_test_three),strlen(strlen_test_four),strlen(strlen_test_five),\
         sea_strlen(strlen_test_one),sea_strlen(strlen_test_two),sea_strlen(strlen_test_three), \
         sea_strlen(strlen_test_four), sea_strlen(strlen_test_five));

  puts("\n---MEMSET---");
  char memset_test_real_one[] = "hey boy";
  char memset_test_seal_one[] = "hey boy";
  printf("REAL STR BEFORE: |%s|\n", memset_test_real_one);
  memset(&memset_test_real_one, '0', 2);
  printf("REAL STR AFTER : |%s|\n", memset_test_real_one);
  printf("SEAL STR BEFORE: |%s|\n", memset_test_seal_one);
  memset(&memset_test_seal_one, '0', 2);
  printf("SEAL STR AFTER : |%s|\n", memset_test_seal_one);

  puts("\n---BZERO---");
  char bzero_real_one[]= "YO I AM STRING";
  char bzero_seal_one[]= "YO I AM STRING";
  printf("REAL STR BEFORE: |%s|\n", bzero_real_one);
  bzero(&bzero_real_one, sizeof(bzero_real_one));
  printf("REAL STR AFTER : |%s|\n", bzero_real_one);
  printf("SEAL STR BEFORE: |%s|\n", bzero_seal_one);
  bzero(&bzero_seal_one, sizeof(bzero_seal_one));
  printf("SEAL STR AFTER : |%s|\n", bzero_seal_one);

  puts("\n---MEMCPY---");
  char memcpy_real_dest[] = "00000000";
  char memcpy_real_src[] = "Ayo wtf dawg";
  char memcpy_seal_dest[] = "00000000";
  char memcpy_seal_src[] = "Ayo wtf dawg";
  printf("REAL MEMCPY RESULT: |%s| \n", memcpy(memcpy_real_dest, memcpy_real_src, 7));
  printf("SEAL MEMCPY RESULT: |%s| \n", sea_memcpy(memcpy_seal_dest, memcpy_seal_src, 7));

  puts("\n---MEMMOVE---");
   char memmove_real_buffer[] = "abcdefghij";
   char memmove_seal_buffer[] = "abcdefghij";
    printf("--- Overlap Test ---\n");
    printf("Original REAL buffer: |%s|\n", memmove_real_buffer);
    printf("Original SEAL buffer: |%s|\n\n", memmove_seal_buffer);
    memmove(memmove_real_buffer + 2, memmove_real_buffer, 5);
    printf("REAL MEMMOVE RESULT:  |%s|\n", memmove_real_buffer);
    sea_memmove(memmove_seal_buffer + 2, memmove_seal_buffer, 5);
    printf("SEAL MEMMOVE RESULT:  |%s|\n", memmove_seal_buffer);

  puts("Done!");
  return (0);
}
