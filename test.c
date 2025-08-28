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
/*      Created: 2025/08/27 22:40:24 by espadara                              */
/*      Updated: 2025/08/28 08:45:44 by espadara                              */
/*                                                                            */
/* ************************************************************************** */


#include "sealib.h"

/* TEST STRUCTS */
struct TestCase {
    const char *string;
    int character;
};

int main(void)
{
  printf("CONDUCTING TESTS!!!\n");

  puts("\n---ISALPHA---");
  {
    char tests[] = {'a', 'G', 'z', 'Z', '5', '@', 0};
    for (int i = 0; tests[i]; i++) {
        int real = isalpha(tests[i]);
        int seal = sea_isalpha(tests[i]);
        printf("Test '%c': REAL=%d, SEAL=%d -> %s\n", tests[i], real, seal,
               (!!real == !!seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---ISDIGIT---");
  {
    char tests[] = {'5', '0', '9', 'a', 'Z', '#', 0};
    for (int i = 0; tests[i]; i++) {
        int real = isdigit(tests[i]);
        int seal = sea_isdigit(tests[i]);
        printf("Test '%c': REAL=%d, SEAL=%d -> %s\n", tests[i], real, seal,
               (!!real == !!seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---ISALNUM---");
  {
    char tests[] = {'a', 'Z', '5', '0', 'g', '9', '@', 0};
    for (int i = 0; tests[i]; i++) {
        int real = isalnum(tests[i]);
        int seal = sea_isalnum(tests[i]);
        printf("Test '%c': REAL=%d, SEAL=%d -> %s\n", tests[i], real, seal,
               (!!real == !!seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---ISASCII---");
  {
    int tests[] = {'a', 127, 0, 128, -1, 255, 0};
    for (int i = 0; tests[i]; i++) {
        int real = isascii(tests[i]);
        int seal = sea_isascii(tests[i]);
        printf("Test %d: REAL=%d, SEAL=%d -> %s\n", tests[i], real, seal,
               (!!real == !!seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---ISPRINT---");
  {
    int tests[] = {'a', '~', ' ', 31, 127, 200, 0};
    for (int i = 0; tests[i]; i++) {
        int real = isprint(tests[i]);
        int seal = sea_isprint(tests[i]);
        printf("Test %d ('%c'): REAL=%d, SEAL=%d -> %s\n", tests[i], tests[i], real, seal,
               (!!real == !!seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---STRLEN---");
  {
    const char *tests[] = {"hello", "", "a", "1234567890", NULL};
    for (int i = 0; tests[i]; i++) {
        size_t real = strlen(tests[i]);
        size_t seal = sea_strlen(tests[i]);
        printf("Test \"%s\": REAL=%zu, SEAL=%zu -> %s\n", tests[i], real, seal,
               (real == seal) ? "OK" : "FAIL");
    }
  }

  puts("\n---MEMSET---");
  {
    struct { int c; size_t len; } tests[] = {
        {'A', 5}, {'B', 10}, {'\0', 3}, {'$', 0}, {'Z', 1}
    };
    for (int i = 0; i < 5; ++i) {
        char real_buf[11] = "xxxxxxxxxx";
        char seal_buf[11] = "xxxxxxxxxx";
        memset(real_buf, tests[i].c, tests[i].len);
        sea_memset(seal_buf, tests[i].c, tests[i].len);
        printf("Test: memset(buf, '%c', %zu) | Result: \"%s\" -> %s\n",
               (char)tests[i].c, tests[i].len, seal_buf,
               (memcmp(real_buf, seal_buf, 11) == 0) ? "OK" : "FAIL");
    }
  }

  puts("\n---BZERO---");
  {
    size_t tests[] = {5, 10, 0, 1, 8};
    for (int i = 0; i < 5; ++i) {
        char real_buf[11] = "xxxxxxxxxx";
        char seal_buf[11] = "xxxxxxxxxx";
        bzero(real_buf, tests[i]);
        sea_bzero(seal_buf, tests[i]);
        printf("Test: bzero(buf, %zu) -> %s\n", tests[i],
               (memcmp(real_buf, seal_buf, 11) == 0) ? "OK" : "FAIL");
    }
  }

  puts("\n---MEMCPY---");
  {
    struct { const char *src; size_t len; } tests[] = {
        {"copy this", 5}, {"abc", 4}, {"", 1}, {"test", 0}, {"single", 1}
    };
    for (int i = 0; i < 5; ++i) {
        char real_dest[20] = {0};
        char seal_dest[20] = {0};
        memcpy(real_dest, tests[i].src, tests[i].len);
        sea_memcpy(seal_dest, tests[i].src, tests[i].len);
        printf("Test: memcpy(dest, \"%s\", %zu) | Result: \"%s\" -> %s\n",
               tests[i].src, tests[i].len, seal_dest,
               (memcmp(real_dest, seal_dest, 20) == 0) ? "OK" : "FAIL");
    }
  }

  puts("\n---MEMMOVE---");
  {
    char r1[] = "abcdefghij", s1[] = "abcdefghij";
    memmove(r1 + 2, r1, 5); sea_memmove(s1 + 2, s1, 5);
    printf("Test: memmove(\"abcdefghij\"+2, src, 5) | Result: \"%s\" -> %s\n", s1, (strcmp(r1, s1) == 0) ? "OK" : "FAIL");

    char r2[] = "abcdefghij", s2[] = "abcdefghij";
    memmove(r2, r2 + 2, 5); sea_memmove(s2, s2 + 2, 5);
    printf("Test: memmove(dst, \"abcdefghij\"+2, 5) | Result: \"%s\" -> %s\n", s2, (strcmp(r2, s2) == 0) ? "OK" : "FAIL");

    char r3[] = "abcdefghij", s3[] = "abcdefghij";
    memmove(r3 + 5, r3, 5); sea_memmove(s3 + 5, s3, 5);
    printf("Test: No Overlap | Result: \"%s\" -> %s\n", s3, (strcmp(r3, s3) == 0) ? "OK" : "FAIL");

    char r4[] = "abcdefghij", s4[] = "abcdefghij";
    memmove(r4, r4, 0); sea_memmove(s4, s4, 0);
    printf("Test: Zero Length | Result: \"%s\" -> %s\n", s4, (strcmp(r4, s4) == 0) ? "OK" : "FAIL");

    char r5[] = "abcdefghij", s5[] = "abcdefghij";
    memmove(r5, r5, 10); sea_memmove(s5, s5, 10);
    printf("Test: Full Move | Result: \"%s\" -> %s\n", s5, (strcmp(r5, s5) == 0) ? "OK" : "FAIL");
  }

  puts("\n---STRLCPY---");
  {
    const char *src = "a long string to copy";
    struct { size_t size; } tests[] = { {10}, {30}, {1}, {0}, {22} };
    for (int i = 0; i < 5; ++i) {
        char real_dest[30] = {0};
        char seal_dest[30] = {0};
        size_t real_ret = strlcpy(real_dest, src, tests[i].size);
        size_t seal_ret = sea_strlcpy(seal_dest, src, tests[i].size);
        printf("Test: strlcpy(dest, \"%s\", %zu) | Result: \"%s\", ret: %zu -> %s\n",
               src, tests[i].size, seal_dest, seal_ret,
               (strcmp(real_dest, seal_dest) == 0 && real_ret == seal_ret) ? "OK" : "FAIL");
    }
  }

  puts("\n---STRLCAT---");
  {
    const char *src = " add this";
    struct { const char* initial_dst; size_t size; } tests[] = {
        {"start", 20}, {"start", 10}, {"start", 6}, {"start", 0}, {"", 20}
    };
    for (int i = 0; i < 5; ++i) {
        char real_dest[25], seal_dest[25];
        strcpy(real_dest, tests[i].initial_dst);
        strcpy(seal_dest, tests[i].initial_dst);
        size_t real_ret = strlcat(real_dest, src, tests[i].size);
        size_t seal_ret = sea_strlcat(seal_dest, src, tests[i].size);
        printf("Test: strlcat(\"%s\", \"%s\", %zu) | Result: \"%s\", ret: %zu -> %s\n",
               tests[i].initial_dst, src, tests[i].size, seal_dest, seal_ret,
               (strcmp(real_dest, seal_dest) == 0 && real_ret == seal_ret) ? "OK" : "FAIL");
    }
  }

  puts("\n---TOUPPER & TOLOWER---");
  {
    char tests[] = {'a', 'Z', 'g', 'H', '5', '#', ' ', '\t', 0};
    printf("Input | REAL u/l | SEAL u/l | Status\n");
    printf("------|----------|----------|--------\n");
    for (int i = 0; tests[i]; i++)
    {
        char c = tests[i];
        int real_upper = toupper(c);
        int seal_upper = sea_toupper(c);
        int real_lower = tolower(c);
        int seal_lower = sea_tolower(c);
        const char *status = (real_upper == seal_upper && real_lower == seal_lower) ? "OK" : "FAIL";
        printf("  '%c' |  '%c'/'%c'  |  '%c'/'%c'  | %s\n",
               c, real_upper, real_lower, seal_upper, seal_lower, status);
    }
  }

  puts("\n---STRCHR & STRRCHR ---");
  {
    struct TestCase tests[] = {
        {"hello world", 'l'},
        {"test", 't'},
        {"bonjour", 'z'},
        {"find the end", '\0'},
        {"abracadabra", 'a'}
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < num_tests; i++) {
        const char *s = tests[i].string;
        int c = tests[i].character;
        char *real_chr = strchr(s, c);
        char *seal_chr = sea_strchr(s, c);
        char *real_rchr = strrchr(s, c);
        char *seal_rchr = sea_strrchr(s, c);

        printf("strchr(\"%s\", '%c'): -> %s | ", s, c, (real_chr == seal_chr) ? "OK" : "FAIL");
        printf("strrchr(\"%s\", '%c'): -> %s\n", s, c, (real_rchr == seal_rchr) ? "OK" : "FAIL");
    }
  }
  puts("\n---STRSTR---");
  {
    // A structure to hold test cases for clarity
    struct {
        const char *haystack;
        const char *needle;
    } tests[] = {
        {"Hello world, this is a test.", "world"}, // Standard case
        {"Hello world", "earth"},                  // No match
        {"Another test", ""},                      // Empty needle
        {"Start of string", "Start"},              // Match at the beginning
        {"Match at the end", "end"}                // Match at the end
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *real_result = strstr(tests[i].haystack, tests[i].needle);
        char *seal_result = sea_strstr(tests[i].haystack, tests[i].needle);

        printf("Test: strstr(\"%s\", \"%s\") | Result: \"%s\" -> %s\n",
               tests[i].haystack,
               tests[i].needle,
               seal_result ? seal_result : "(null)",
               (real_result == seal_result) ? "OK" : "FAIL");
    }
  }
puts("\n---STRCMP---");
  {
    // A structure to hold strcmp test cases
    struct {
        const char *s1;
        const char *s2;
    } tests[] = {
        {"Hello", "Hello"},      // Equal strings
        {"Hella", "Hello"},      // s1 < s2
        {"Testing", "Test"},     // s1 > s2 (is a prefix of s1)
        {"", ""},                // Both empty
        {"abc", "abd"}           // Difference at the end
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        int real_ret = strcmp(tests[i].s1, tests[i].s2);
        int seal_ret = sea_strcmp(tests[i].s1, tests[i].s2);

        // Normalize results to -1, 0, or 1 to safely compare
        int real_sign = (real_ret > 0) - (real_ret < 0);
        int seal_sign = (seal_ret > 0) - (seal_ret < 0);

        printf("Test: strcmp(\"%s\", \"%s\") -> %s\n",
               tests[i].s1, tests[i].s2,
               (real_sign == seal_sign) ? "OK" : "FAIL");
    }
  }

  puts("\n---STRNCMP---");
  {
    // A structure to hold strncmp test cases
    struct {
        const char *s1;
        const char *s2;
        size_t n;
    } tests[] = {
        {"Testabc", "Testing", 4}, // Equal for n bytes
        {"Testabc", "Testing", 7}, // Different before n bytes
        {"abc", "def", 0},         // n is zero
        {"abc", "abcdef", 5},      // s1 ends before n
        {"abc", "abc", 10}         // n is larger than string length
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        int real_ret = strncmp(tests[i].s1, tests[i].s2, tests[i].n);
        int seal_ret = sea_strncmp(tests[i].s1, tests[i].s2, tests[i].n);

        // Normalize results to -1, 0, or 1 to safely compare
        int real_sign = (real_ret > 0) - (real_ret < 0);
        int seal_sign = (seal_ret > 0) - (seal_ret < 0);

        printf("Test: strncmp(\"%s\", \"%s\", %zu) -> %s\n",
               tests[i].s1, tests[i].s2, tests[i].n,
               (real_sign == seal_sign) ? "OK" : "FAIL");
    }
  }
  puts("\n---STRNSTR---");
  {
    // A structure to hold strnstr test cases
    struct {
        const char *haystack;
        const char *needle;
        size_t n;
    } tests[] = {
        {"lorem ipsum dolor sit amet", "ipsum", 20}, // Standard match
        {"lorem ipsum dolor sit amet", "dolor", 10}, // Match exists, but its start is after n
        {"find the needle here", "needle", 20},      // Another standard match
        {"a test with an empty needle", "", 5},      // Empty needle
        {"short", "a longer needle", 5}              // Needle is longer than haystack
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *real_result = strnstr(tests[i].haystack, tests[i].needle, tests[i].n);
        char *seal_result = sea_strnstr(tests[i].haystack, tests[i].needle, tests[i].n);

        printf("Test: strnstr(\"%s\", \"%s\", %zu) | Result: \"%s\" -> %s\n",
               tests[i].haystack,
               tests[i].needle,
               tests[i].n,
               seal_result ? seal_result : "(null)",
               (real_result == seal_result) ? "OK" : "FAIL");
    }
  }
  puts("\n---MEMCHR---");
  {
    // A special memory block containing a null byte to test against.
    char mem_with_null[] = {'a', 'b', '\0', 'd', 'e'};

    // A structure to hold the test cases
    struct {
        const void *mem_block;
        int char_to_find;
        size_t size;
        const char *description;
    } tests[] = {
        {"abcdef", 'c', 6, "Standard Match"},
        {"abcdef", 'x', 6, "No Match"},
        {mem_with_null, 'd', 5, "Match After Null"},
        {mem_with_null, '\0', 5, "Find Null Byte"},
        {"abcdef", 'f', 4, "Match Outside n"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        void *real_result = memchr(tests[i].mem_block, tests[i].char_to_find, tests[i].size);
        void *seal_result = sea_memchr((void *)tests[i].mem_block, tests[i].char_to_find, tests[i].size);

        printf("Test: %-18s (char: '%c', n: %zu) -> %s\n",
               tests[i].description,
               (char)tests[i].char_to_find,
               tests[i].size,
               (real_result == seal_result) ? "OK" : "FAIL");
    }
  }
  puts("\nDone!");
  return (0);
}
