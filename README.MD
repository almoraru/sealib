                       ______
                    .-"      "-.
                   /            \
       _          |              |          _
      ( \         |,  .-.  .-.  ,|         / )
       > "=._     | )(__/  \__)( |     _.=" <
      (_/"=._"=._ |/     /\     \| _.="_.="\_)
             "=._ (_     ^^     _)"_.="
                 "=\__|IIIIII|__/="
                _.="| \IIIIII/ |"=._
      _     _.="_.="\          /"=._"=._     _
     ( \_.="_.="     `--------`     "=._"=._/ )
      > _.="                            "=._ <
     (_/                                    \_)

# 🌊 SEALIB 🏴‍☠️

**A modern C utility library, charting a course through the seven seas of code!**

> *"Why sail with the standard library when ye can navigate with yer own?"*

## 📜 About This Treasure

**Sealib** be a mighty C utility library, crafted by the hands of **Swittzy/espadara** aboard the good ship *Code Kraken*. This library be a personal voyage to reimplement and improve upon standard C functions, exploring modern techniques for speed and efficiency. The name be a play on "C Library" and the pirate/sea theme that represents navigating the treacherous low-level waters of C programming!

## ⚓ Features

- ✨ **Standard C Library Functions** - A robust collection of re-implemented libc functions for strings, memory, character classification, and more
- 🎯 **High-Performance Arena Allocator** - A region-based memory manager that be faster than a privateer's ship, avoiding malloc overhead by allocating objects with similar lifetimes together
- 🚀 **SIMD-Accelerated Functions** - Includes `sea_memcpy_fast` that uses SSE2 instructions to accelerate memory copying like wind in yer sails!
- 🌊 **Comprehensive Linked List API** - A full suite of functions for creating and manipulating linked lists, with both standard (heap) and arena-based allocation options
- ⚔️ **Built for Performance** - Zero-copy operations and efficient data structures fit for battle!

## 🗺️ Installation & Compilation

### Prerequisites
- `gcc` or `clang` compiler (a proper pirate's tools)
- `make` (to orchestrate the build)
- The `libbsd-dev` package (or equivalent) may be needed on some Linux systems for the standard `strlcpy` and `strlcat` functions used in the test file

### Setting Sail

1. **Clone the repository:**
```bash
git clone git@github.com:almoraru/sealib.git
cd sealib
```

2. **Build the library:**
```bash
make
```

This will compile all source files and create `sealib.a` - yer treasure chest of functions!

3. **Build and run the tests:**
```bash
make test
./a.out
```

This will build the library and compile `test.c` against it, creating an executable named `a.out`.

4. **Clean up object files:**
```bash
make clean
```

5. **Full cleanup (removes library and executables):**
```bash
make fclean
```

## 🏴‍☠️ Usage

### The Arena Allocator - A Pirate's Best Friend!

A key feature of Sealib be its fast, region-based arena allocator. Instead of calling `malloc` for every small object like a landlubber, ye can allocate a large "arena" and then rapidly "bump" a pointer to serve allocations from it. This be ideal for tasks where ye create many objects that are all freed at the same time - like plundering a ship and dividing the loot!

```c
#include "sealib.h"

int main(void)
{
    // 1. Initialize an arena with the default size (e.g., 4KB)
    t_mem *my_arena = sea_arena_init(0);

    // 2. Allocate strings and list nodes from the arena - no individual mallocs!
    char *s1 = sea_arena_strdup(my_arena, "hello from the arena");
    t_list *node1 = sea_arena_lstnew(my_arena, s1);
    t_list *node2 = sea_arena_lstnew(my_arena, "another node");

    // Link the nodes
    sea_lstadd_back(&node1, node2);

    // 3. When you're done, free EVERYTHING with a single call.
    sea_arena_free(my_arena);

    return (0);
}
```

### Compiling Your Project with Sealib

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lsealib -I includes -o your_program
```

## 📚 API Reference - The Captain's Manual

### Character Classification Functions

Based on `<ctype.h>` functionality:

```c
int sea_isalpha(int c);      // Be it a letter?
int sea_isdigit(int c);      // Be it a number?
int sea_isalnum(int c);      // Be it alphanumeric?
int sea_isascii(int c);      // Be it ASCII?
int sea_isprint(int c);      // Can ye print it?
int sea_iswhitespace(char c);// Be it whitespace?
int sea_toupper(int c);      // Make it SHOUT!
int sea_tolower(int c);      // Make it whisper
```

### Memory Functions

Based on `<string.h>` functionality:

```c
void *sea_memset(void *s, int c, size_t n);
void *sea_memcpy(void *dest, const void *src, size_t n);
void *sea_memmove(void *dest, const void *src, size_t n);
void *sea_memchr(void *s, int c, size_t n);
int  sea_memcmp(const char *s1, const char *s2, size_t n);
void *sea_bzero(void *s, size_t n);
```

### High-Performance Memory Functions

```c
// SIMD-accelerated (SSE2) memory copy. Faster than a cannonball!
// Warning: Does not handle overlap - plan yer course carefully!
void *sea_memcpy_fast(void *dest, const void *src, size_t n);
```

### Arena Allocator Functions

```c
// The arena management struct - yer treasure hold!
typedef struct s_mem t_mem;

// Initializes an arena. Use size 0 for the default.
t_mem *sea_arena_init(size_t size);

// Allocates zeroed memory from an arena - fast as lightning!
void *sea_arena_alloc(t_mem *arena, size_t size);

// Frees the entire arena and all memory allocated within it - one command to rule them all!
void sea_arena_free(t_mem *arena);
```

### String Functions

Based on `<string.h>` functionality:

```c
size_t sea_strlen(const char *s);
char   *sea_strchr(const char *s, int c);
char   *sea_strrchr(const char *s, int c);
char   *sea_strstr(const char *haystack, const char *needle);
char   *sea_strnstr(const char *haystack, const char *needle, size_t len);
int    sea_strcmp(const char *s1, const char *s2);
int    sea_strncmp(const char *s1, const char *s2, size_t n);
size_t sea_strlcpy(char *dst, const char *src, size_t size);
size_t sea_strlcat(char *dst, const char *src, size_t size);
```

**Heap-based allocation (the traditional way):**
```c
char   *sea_strdup(const char *s);
char   *sea_strsub(char const *s, unsigned int start, size_t len);
char   *sea_strjoin(char const *s1, char const *s2);
char   *sea_strtrim(char const *s1, char const *set);
char   **sea_split(char const *s, char c);
char   *sea_itoa(int n);
char   *sea_strmapi(char const *s, char (*f)(unsigned int, char));
void   sea_striteri(char *s, void (*f)(unsigned int, char *));
```

**Arena-based allocation (the pirate's way!):**
```c
char   *sea_arena_strdup(t_mem *arena, const char *src);
char   *sea_arena_strsub(t_mem *arena, char const *s, unsigned int start, size_t len);
char   *sea_arena_strjoin(t_mem *arena, char const *s1, char const *s2);
char   **sea_arena_split(t_mem *arena, char const *s, char c);
```

### Conversion Functions

Based on `<stdlib.h>` functionality:

```c
int    sea_atoi(const char *nptr);           // String to integer
int    sea_atoi_base(const char *str, int base); // String to integer with custom base
double sea_atof(const char *str);            // String to floating point
```

### File Descriptor Output Functions

```c
void sea_putchar_fd(char c, int fd);      // Write a character
void sea_putstr_fd(char const *s, int fd);// Write a string
void sea_putendl_fd(char *s, int fd);     // Write a string with newline
void sea_putnbr_fd(int n, int fd);        // Write a number
```

### Linked List Functions

```c
// The linked list node struct - for chaining yer data!
typedef struct s_list t_list;
```

**Heap-based allocation:**
```c
t_list *sea_lstnew(void *content);
```

**Arena-based allocation (faster than a mermaid's swim!):**
```c
t_list *sea_arena_lstnew(t_mem *arena, void *content);
```

**List manipulation:**
```c
void   sea_lstadd_front(t_list **lst, t_list *new); // Add to the bow
void   sea_lstadd_back(t_list **lst, t_list *new);  // Add to the stern
int    sea_lstsize(t_list *lst);                     // Count yer treasure
t_list *sea_lstlast(t_list *lst);                    // Find the last node
void   sea_lstdelone(t_list *lst, void (*del)(void*));     // Walk the plank!
void   sea_lstclear(t_list **lst, void (*del)(void*));     // Clear the deck!
```

## 🗂️ Project Structure

```
sealib/
├── includes/
│   └── sealib.h             # Main header file
├── srcs/
│   ├── [character functions]
│   ├── [memory functions]
│   ├── [string functions]
│   ├── [arena allocator]
│   ├── [linked list functions]
│   └── [conversion functions]
├── test.c                   # Test suite
├── Makefile                 # Build configuration
└── README.md                # Ye be here!
```

## 🧭 Makefile Commands

| Command | Description |
|---------|-------------|
| `make` or `make all` | Build the `sealib.a` library |
| `make test` | Build library and create test executable |
| `make clean` | Remove object files |
| `make fclean` | Remove all generated files |
| `make re` | Rebuild everything from scratch |

## ⚔️ Technical Details

- **Memory Management**: Uses arena allocation for efficient memory handling - no leaks on this ship!
- **Compilation Flags**: `-Wall -Wextra -Werror -g`
- **Output**: Static library `sealib.a`
- **Performance**: SIMD-accelerated functions and zero-copy operations

## 🎯 Performance Benefits

- **Arena Allocation**: Dramatically reduces allocation overhead for short-lived objects - like storing doubloons in a single chest instead of scattered across the ship!
- **SIMD Acceleration**: SSE2-optimized memory operations for improved throughput
- **Zero-Copy Operations**: Many functions designed to minimize unnecessary memory copying
- **Efficient Data Structures**: Optimized linked list implementations with both heap and arena variants

## 👥 Crew

- **Swittzy/espadara/almoraru** - *Captain of the Code Kraken*

## 🤝 Contributing

This be a personal learning project exploring modern C programming techniques. Feel free to explore the code, suggest improvements, or use it as inspiration for yer own voyages!


## 🌊 Fair Winds and Following Seas!

May yer allocations be swift and yer memory be leak-free! ☕🏴‍☠️

```
     ~    ~   ~  ~     ~    ~ ~  ~      ~     ~  ~
  ~    ~  ~    Navigate the seas of C!   ~    ~   ~
~    ~      ~     ~    ~    ~    ~   ~      ~    ~
```

---

*"In code we trust, in pirates we sail!"* ⚓
