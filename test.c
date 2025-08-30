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
/*      Updated: 2025/08/30 17:35:28 by espadara                              */
/*                                                                            */
/* ************************************************************************** */


#include "sealib.h"

#define PRINT_TEST(description, condition)                              \
    printf("  Test: %-50s -> %s\n", description, (condition) ? "OK" : "FAIL")

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
  puts("\n---MEMCMP---");
  {
    struct {
      const char *s1;
      const char *s2;
      size_t size;
      const char *description;
      int expected_sign; // 1 for positive, -1 for negative, 0 for zero
    } tests[] = {
      {"abcdef", "abcdef", 6, "Identical Blocks", 0},
      {"abcdeg", "abcdef", 6, "First Mismatch Positive", 1},
      {"abcdef", "abcdeg", 6, "First Mismatch Negative", -1},
      {"abcdef", "abc", 3, "Identical Up to n", 0},
      {"abcdef", "abcdeg", 3, "Different After n", 0},
      {"\0ghi", "\0jkl", 4, "Blocks With Null", -1},
      {"", "", 0, "Empty Blocks", 0},
      {"abc", "abx", 3, "Mismatch at End", -1},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
      {
        int real_result = memcmp(tests[i].s1, tests[i].s2, tests[i].size);
        int sea_result = sea_memcmp(tests[i].s1, tests[i].s2, tests[i].size);
        int real_sign = (real_result > 0) ? 1 : (real_result < 0 ? -1 : 0);
        int sea_sign = (sea_result > 0) ? 1 : (sea_result < 0 ? -1 : 0);
        int test_passed = (real_sign == sea_sign);
        if (test_passed && tests[i].expected_sign == 0) {
          test_passed = (real_result == sea_result);
        }

        printf("Test: %-25s | s1: \"%.*s\" | s2: \"%.*s\" | n: %zu -> %s\n",
               tests[i].description,
               (int)tests[i].size,
               tests[i].s1,
               (int)tests[i].size,
               tests[i].s2,
               tests[i].size,
               (test_passed) ? "OK" : "FAIL");
      }
  }

  puts("\n---ISWHITESPACE---");
  {
    // Array of characters to test
    char tests[] = {
        ' ',      // Space
        '\t',     // Tab
        '\n',     // Newline
        '\v',     // Vertical Tab
        '\f',     // Form Feed
        '\r',     // Carriage Return
        'a',      // Lowercase letter
        'Z',      // Uppercase letter
        '7',      // Digit
        '@',      // Symbol
        0         // Null terminator for the loop
    };

    for (int i = 0; tests[i] != 0; i++)
    {
        char c = tests[i];
        int real_result = isspace(c);
        int seal_result = sea_iswhitespace(c);

        printf("Test char (ASCII: %d): REAL=%d, SEAL=%d -> %s\n",
               c,
               real_result,
               seal_result,
               (!!real_result == !!seal_result) ? "OK" : "FAIL");
    }
  }
  puts("\n---ATOI---");
  {
    // A structure to hold atoi test cases
    struct {
        const char *str;
    } tests[] = {
        {"123"},
        {"-456"},
        {"+789"},
        {"  -42"},
        {"99balloons"},
        {"word"},
        {"+-5"},
        {"--2"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        int real_result = atoi(tests[i].str);
        int seal_result = sea_atoi(tests[i].str);

        printf("Test: atoi(\"%s\") | REAL: %d, SEAL: %d -> %s\n",
               tests[i].str,
               real_result,
               seal_result,
               (real_result == seal_result) ? "OK" : "FAIL");
    }
  }
  puts("\n---ATOI_BASE---");
  {
    struct {
        const char *str;
        int base;
    } tests[] = {
        {"123", 10},                      // Standard decimal
        {"  -ff", 16},                    // Hexadecimal with whitespace and sign
        {"10110", 2},                     // Binary
        {"1274", 8},                      // Octal with an invalid digit '7'
        {" \n\t+aB", 12}                  // Base 12 with mixed case and whitespace
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // The real function for this is strtol(string, NULL, base)
        int real_result = (int)strtol(tests[i].str, NULL, tests[i].base);
        int seal_result = sea_atoi_base(tests[i].str, tests[i].base);

        printf("Test: atoi_base(\"%s\", %d) | REAL: %d, SEAL: %d -> %s\n",
               tests[i].str,
               tests[i].base,
               real_result,
               seal_result,
               (real_result == seal_result) ? "OK" : "FAIL");
    }

  }
  puts("\n---ATOF---");
  {

    #define EPSILON 1e-9

    struct {
        const char *str;
    } tests[] = {
        {"123.456"},
        {"  -0.0123"},
        {"+500"},
        {".789"},
        {"42.9abc"}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        double real_result = atof(tests[i].str);
        double seal_result = sea_atof(tests[i].str);

        // CORRECT WAY TO COMPARE: Check if the absolute difference is negligible
        printf("Test: atof(\"%s\") | REAL: %f, SEAL: %f -> %s\n",
               tests[i].str,
               real_result,
               seal_result,
               (fabs(real_result - seal_result) < EPSILON) ? "OK" : "FAIL");
    }
  }
  puts("\n---ARENA ALLOCATOR---");
  {
    t_mem *arena = NULL;
    void *p1, *p2, *p3;

    // --- Initialization Tests ---
    printf("\n## Initialization\n");
    arena = sea_arena_init(0);
    PRINT_TEST("Initialize with size 0 returns non-NULL", arena != NULL);
    if (arena) {
        PRINT_TEST("Initialize with size 0 uses default size", arena->total == ARENA_DEFAULT);
    }
    sea_arena_free(arena);

    arena = sea_arena_init(128);
    PRINT_TEST("Initialize with custom size (128) returns non-NULL", arena != NULL);
    if (arena) {
        PRINT_TEST("Initialize with custom size (128) is correct", arena->total == 128);
    }
    sea_arena_free(arena);

    // --- Basic Allocation & Alignment Tests ---
    printf("\n## Basic Allocation & Alignment\n");
    arena = sea_arena_init(100); // Using a small size for easy testing
    p1 = sea_arena_alloc(arena, 1);
    PRINT_TEST("First allocation (1 byte) is not NULL", p1 != NULL);
    PRINT_TEST("Used size reflects alignment (1 byte -> 16)", arena ? arena->used == 16 : 0);

    p2 = sea_arena_alloc(arena, 10);
    PRINT_TEST("Second allocation (10 bytes) is not NULL", p2 != NULL);
    PRINT_TEST("Second allocation is at correct offset", p2 == (void*)(arena->mem + 16));
    PRINT_TEST("Used size is now 32 (16 + 16)", arena ? arena->used == 32 : 0);

    // --- Data Integrity Test ---
    strcpy((char*)p2, "testing");
    PRINT_TEST("Data integrity check", strcmp((char*)p2, "testing") == 0);
    sea_arena_free(arena);

    // --- Edge Case Allocation Tests ---
    printf("\n## Edge Case Allocations\n");
    arena = sea_arena_init(100);
    PRINT_TEST("Allocate 0 bytes returns NULL", sea_arena_alloc(arena, 0) == NULL);
    PRINT_TEST("Allocate from a NULL arena returns NULL", sea_arena_alloc(NULL, 10) == NULL);

    p1 = sea_arena_alloc(arena, 100 - ARENA_ALIGN); // Allocate almost everything
    p2 = sea_arena_alloc(arena, ARENA_ALIGN);       // Allocate the rest
    PRINT_TEST("Allocate exact remaining space works", p2 != NULL);
    sea_arena_free(arena);

    // --- Chaining Logic Tests ---
    printf("\n## Chaining Logic\n");
    arena = sea_arena_init(64); // Tiny arena to force chaining
    sea_arena_alloc(arena, 32);
    sea_arena_alloc(arena, 32); // Block 1 is now full (32+32=64)
    PRINT_TEST("First block is full", arena ? arena->used == 64 : 0);
    PRINT_TEST("No second block exists yet", arena ? arena->next == NULL : 0);

    p1 = sea_arena_alloc(arena, 1); // This should trigger chaining
    PRINT_TEST("Allocation triggering a new block is not NULL", p1 != NULL);
    PRINT_TEST("A second block was created", arena ? arena->next != NULL : 0);
    if (arena && arena->next) {
        PRINT_TEST("New block has correct used size (1 byte -> 16)", arena->next->used == 16);
    }

    // --- Large Allocation Test ---
    p2 = sea_arena_alloc(arena, ARENA_DEFAULT + 100); // Request larger than default
    PRINT_TEST("Large allocation ( > default) succeeds", p2 != NULL);
    if(arena && arena->next) {
        PRINT_TEST("Large allocation created a correctly sized block", arena->next->next->total >= ARENA_DEFAULT + 100);
    }
    sea_arena_free(arena);

    // --- Freeing Logic Tests ---
    printf("\n## Freeing Logic\n");
    arena = sea_arena_init(100);
    sea_arena_alloc(arena, 1000); // Create a chain of 2 blocks
    sea_arena_alloc(arena, 5000); // Create a chain of 3 blocks
    sea_arena_free(arena);
    PRINT_TEST("Freeing a chain of blocks (check with Valgrind)", 1); // This test passes if it doesn't crash

    sea_arena_free(NULL);
    PRINT_TEST("Freeing a NULL arena does not crash", 1);
  }
  void *sea_memcpy_fast(void *dest, const void *src, size_t n);

  puts("\n---MEMCPY_FAST---");
  {
    // A structure to hold memcpy test cases
    struct {
        size_t n;
        const char *description;
    } tests[] = {
        {0, "Zero-length copy"},
        {5, "Small copy (non-SIMD path)"},
        {15, "Boundary copy (non-SIMD path)"},
        {16, "Boundary copy (1 SIMD block)"},
        {17, "1 SIMD block + 1 byte tail"},
        {32, "2 full SIMD blocks"},
        {40, "2 SIMD blocks + 8 byte tail"},
        {100, "Large unaligned copy"},
        {8, "Copy data with null bytes"},
        {25, "Full buffer copy"}
    };

    const char *source_data = "This is the source string\0with nulls inside.";
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        // Allocate and prepare fresh buffers for each test
        char real_dest[128] = {0};
        char seal_dest[128] = {0};

        memcpy(real_dest, source_data, tests[i].n);
        sea_memcpy_fast(seal_dest, source_data, tests[i].n);

        printf("Test: %-32s (n=%zu) -> %s\n",
               tests[i].description,
               tests[i].n,
               (memcmp(real_dest, seal_dest, sizeof(real_dest)) == 0) ? "OK" : "FAIL");
    }
  }
  puts("\n---STRDUP (HEAP)---");
  {
    // A structure to hold the test cases
    struct {
        const char *source;
        const char *description;
    } tests[] = {
        {"A normal string", "Standard string"},
        {"", "Empty string"},
        {"a", "Single character string"},
        {"A very long string designed to trigger the fast SIMD copy path.", "Long string (SIMD)"},
        {"\t\n a string with whitespace \t\n", "String with whitespace"},
        {NULL, "NULL pointer input"}
    };
    int num_tests = 6;

    for (int i = 0; i < num_tests; i++)
    {
        // Test strdup itself
        char *seal_result = sea_strdup(tests[i].source);
        if (tests[i].source == NULL) {
            printf("Test: %-30s -> %s\n", "strdup(NULL)", (seal_result == NULL) ? "OK" : "FAIL");
        } else {
            int is_ok = (seal_result != NULL && strcmp(seal_result, tests[i].source) == 0);
            printf("Test: %-30s -> %s\n", tests[i].description, is_ok ? "OK" : "FAIL");
        }
        free(seal_result); // Must free the heap-allocated memory
    }

    // Additional specific tests
    char original[] = "original";
    char *dup = sea_strdup(original);
    strcpy(original, "changed");
    printf("Test: %-30s -> %s\n", "Memory independence", (dup && strcmp(dup, "original") == 0) ? "OK" : "FAIL");
    free(dup);

    dup = sea_strdup("test");
    printf("Test: %-30s -> %s\n", "Pointer is a new address", (dup != (void*)"test") ? "OK" : "FAIL");
    free(dup);

    dup = sea_strdup("len_check");
    printf("Test: %-30s -> %s\n", "Correct length + null terminator", (strlen(dup) == 9) ? "OK" : "FAIL");
    free(dup);

    dup = sea_strdup("another");
    printf("Test: %-30s -> %s\n", "Final sanity check", (strcmp(dup, "another") == 0) ? "OK" : "FAIL");
    free(dup);
  }

  puts("\n---ARENA_STRDUP (ARENA)---");
  {
    t_mem *arena = NULL;
    char *s1, *s2;

    arena = sea_arena_init(64);
    printf("Test: %-45s -> %s\n", "Arena initialization", (arena != NULL) ? "OK" : "FAIL");

    // Test 1 & 2: Standard duplication and 'used' pointer check
    s1 = sea_arena_strdup(arena, "first");
    printf("Test: %-45s -> %s\n", "Standard arena duplication", (strcmp(s1, "first") == 0) ? "OK" : "FAIL");
    size_t expected_used = (strlen("first") + 1 + ARENA_ALIGN - 1) & ~(ARENA_ALIGN - 1);
    printf("Test: %-45s -> %s\n", "Arena 'used' pointer advancement", (arena->used == expected_used) ? "OK" : "FAIL");

    // Test 4 & 5: Handle NULL inputs gracefully
    printf("Test: %-45s -> %s\n", "arena_strdup(arena, NULL)", (sea_arena_strdup(arena, NULL) == NULL) ? "OK" : "FAIL");
    printf("Test: %-45s -> %s\n", "arena_strdup(NULL, src)", (sea_arena_strdup(NULL, "test") == NULL) ? "OK" : "FAIL");

    // -- The New, More Robust Chaining Test --
    // We know 16 bytes are used. The total is 64. Remaining is 48.
    // Let's allocate exactly 48 bytes to fill the block. (3 * 16 = 48)
    sea_arena_alloc(arena, 1); // Uses 16 bytes. Total used: 32
    sea_arena_alloc(arena, 1); // Uses 16 bytes. Total used: 48
    sea_arena_alloc(arena, 1); // Uses 16 bytes. Total used: 64. BLOCK IS NOW FULL.

    printf("Test: %-45s -> %s\n", "First block is now full", (arena->used == 64) ? "OK" : "FAIL");
    printf("Test: %-45s -> %s\n", "No second block exists yet", (arena->next == NULL) ? "OK" : "FAIL");

    // This next allocation is GUARANTEED to fail in the first block.
    s2 = sea_arena_strdup(arena, "chain");

    printf("Test: %-45s -> %s\n", "Allocation forces a new block", (arena->next != NULL) ? "OK" : "FAIL");

    int is_in_new_block = 0;
    if (arena->next) { // Check if arena->next is valid before dereferencing
        is_in_new_block = (s2 >= (char*)arena->next->mem && s2 < (char*)arena->next->mem + arena->next->total);
    }
    printf("Test: %-45s -> %s\n", "Pointer is in the new arena block", is_in_new_block ? "OK" : "FAIL");

    // Final check that old data is still valid
    printf("Test: %-45s -> %s\n", "Data integrity of first string", (strcmp(s1, "first") == 0) ? "OK" : "FAIL");

    sea_arena_free(arena);
  }
  puts("\n---STRSUB (HEAP)---");
  {
    // A structure to hold strsub test cases
    struct {
        const char *s;
        unsigned int start;
        size_t len;
        const char *expected;
    } tests[] = {
        {"Hello World", 6, 5, "World"},          // Standard substring
        {"Hello World", 6, 10, "World"},         // Length is too long (clamps to end)
        {"test", 10, 5, ""},                     // Start is out of bounds
        {"abcdef", 0, 3, "abc"},                 // Extract from the beginning
        {"abcdef", 2, 1, "c"}                    // Extract a single character
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *seal_result = sea_strsub(tests[i].s, tests[i].start, tests[i].len);

        int is_ok = (seal_result != NULL && strcmp(seal_result, tests[i].expected) == 0);

        printf("Test: strsub(\"%s\", %u, %zu) -> %s\n",
               tests[i].s, tests[i].start, tests[i].len,
               is_ok ? "OK" : "FAIL");

        free(seal_result); // Important: free the heap-allocated memory
    }
  }
  puts("\n---ARENA_STRSUB---");
  {
    t_mem *arena = sea_arena_init(64); // Small arena to test chaining
    char *s1, *s2, *s3;
    size_t used_before, used_after;

    printf("Test: %-45s -> %s\n", "Arena initialization", arena != NULL ? "OK" : "FAIL");

    // Test 1: Standard substring & arena usage
    used_before = arena->used;
    s1 = sea_arena_strsub(arena, "Hello World", 6, 5); // "World"
    used_after = arena->used;
    printf("Test: %-45s -> %s\n", "Standard arena substring", (strcmp(s1, "World") == 0) ? "OK" : "FAIL");
    size_t expected_size1 = (strlen("World") + 1 + ARENA_ALIGN - 1) & ~(ARENA_ALIGN - 1);
    printf("Test: %-45s -> %s\n", "Arena 'used' pointer correct", (used_after == used_before + expected_size1) ? "OK" : "FAIL");

    // Test 3: Length is too long (should be clamped)
    s2 = sea_arena_strsub(arena, "short", 0, 10);
    printf("Test: %-45s -> %s\n", "Substring with clamped length", (strcmp(s2, "short") == 0) ? "OK" : "FAIL");

    // Test 4: Start is out of bounds (should be empty)
    s3 = sea_arena_strsub(arena, "test", 10, 5);
    printf("Test: %-45s -> %s\n", "Substring with start out of bounds", (strcmp(s3, "") == 0) ? "OK" : "FAIL");

    // Test 5: Force chaining
    sea_arena_alloc(arena, 64); // Fill the rest of the block
    sea_arena_strsub(arena, "force chain", 0, 5); // This must go in a new block
    printf("Test: %-45s -> %s\n", "Substring forces a new block", (arena->next != NULL) ? "OK" : "FAIL");

    sea_arena_free(arena);
  }
  puts("\n---STRJOIN (HEAP)---");
  {
    // A structure to hold strjoin test cases
    struct {
        const char *s1;
        const char *s2;
        const char *expected;
    } tests[] = {
        {"Hello, ", "World!", "Hello, World!"},
        {"First", "", "First"},
        {"", "Second", "Second"},
        {"", "", ""},
        {"A very long string...", "...and another long string.", "A very long string......and another long string."}
    };
    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        char *seal_result = sea_strjoin(tests[i].s1, tests[i].s2);

        int is_ok = (seal_result != NULL && strcmp(seal_result, tests[i].expected) == 0);

        printf("Test: strjoin(\"%s\", \"%s\") -> %s\n",
               tests[i].s1, tests[i].s2,
               is_ok ? "OK" : "FAIL");

        free(seal_result); // Important: free the heap-allocated memory
    }

    // Explicit NULL test
    char *null_result = sea_strjoin("abc", NULL);
    printf("Test: strjoin(\"abc\", NULL) -> %s\n", (null_result == NULL) ? "OK" : "FAIL");
  }
  puts("\n---ARENA_STRJOIN---");
  {
    t_mem *arena = sea_arena_init(64); // Small arena to test chaining
    char *s1, *s2;
    size_t used_before, used_after;

    printf("Test: %-45s -> %s\n", "Arena initialization", arena != NULL ? "OK" : "FAIL");

    // Test 1: Standard join & arena usage
    used_before = arena->used;
    s1 = sea_arena_strjoin(arena, "Hello, ", "World!");
    used_after = arena->used;
    printf("Test: %-45s -> %s\n", "Standard arena join", (strcmp(s1, "Hello, World!") == 0) ? "OK" : "FAIL");
    size_t expected_size1 = (strlen("Hello, World!") + 1 + ARENA_ALIGN - 1) & ~(ARENA_ALIGN - 1);
    printf("Test: %-45s -> %s\n", "Arena 'used' pointer correct", (used_after == used_before + expected_size1) ? "OK" : "FAIL");

    // Test 3: Joining with an empty string
    s2 = sea_arena_strjoin(arena, "Test", "");
    printf("Test: %-45s -> %s\n", "Joining with an empty string", (strcmp(s2, "Test") == 0) ? "OK" : "FAIL");

    // Test 4: Handle NULL inputs gracefully
    printf("Test: %-45s -> %s\n", "arena_strjoin(arena, NULL, s2)", (sea_arena_strjoin(arena, NULL, "s2") == NULL) ? "OK" : "FAIL");

    // Test 5: Force chaining
    sea_arena_strjoin(arena, "fill", "fill"); // Use up space
    sea_arena_strjoin(arena, "fill", "fill"); // Use up more space
    sea_arena_strjoin(arena, "force", "chain"); // This should force a new block
    printf("Test: %-45s -> %s\n", "Join forces a new block", (arena->next != NULL) ? "OK" : "FAIL");

    sea_arena_free(arena);
  }
  puts("\nDone!");
  return (0);
}
