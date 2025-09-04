# Sealib 🌊

A modern C utility library, charting a course through high-performance memory management with an Arena Allocator and SIMD-accelerated functions.

Welcome aboard the Sealib project! This library is a personal journey to reimplement and improve upon standard C functions, exploring modern techniques for speed and efficiency. The name is a play on "C Library" and the pirate/sea theme that represents navigating the low-level details of C programming.

## 🚀 Key Features

- **Standard C Library Functions**: A robust collection of re-implemented libc functions for strings, memory, character classification, and more
- **High-Performance Arena Allocator**: A region-based memory manager that dramatically speeds up allocations for objects with a similar lifetime by avoiding malloc overhead
- **SIMD-Accelerated Functions**: Includes `sea_memcpy_fast` that uses SSE2 instructions to accelerate memory copying
- **Comprehensive Linked List API**: A full suite of functions for creating and manipulating linked lists, with both standard (heap) and arena-based allocation options

## 🛠️ Getting Started

### Requirements

- A C compiler like `gcc` or `clang`
- `make` for building the project
- The `libbsd-dev` package (or equivalent) may be needed on some Linux systems for the standard `strlcpy` and `strlcat` functions used in the test file

### Compilation

The included Makefile handles the entire build process.

**Compile the static library `sealib.a`:**
```bash
make
```

**Compile and run the tests:**
```bash
make test
./a.out
```
This will build the library and compile `test.c` against it, creating an executable named `a.out`.

**Clean up object files:**
```bash
make clean
```

**Full cleanup (removes library and executables):**
```bash
make fclean
```

## 🏟️ The Arena Allocator

A key feature of Sealib is its fast, region-based arena allocator. Instead of calling `malloc` for every small object, you can allocate a large "arena" and then rapidly "bump" a pointer to serve allocations from it. This is ideal for tasks where you create many objects that are all freed at the same time.

### Example Usage

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

## 📚 API Reference

### Character Classification Functions

Based on `<ctype.h>` functionality:

```c
int sea_isalpha(int c);
int sea_isdigit(int c);
int sea_isalnum(int c);
int sea_isascii(int c);
int sea_isprint(int c);
int sea_iswhitespace(char c);
int sea_toupper(int c);
int sea_tolower(int c);
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
// SIMD-accelerated (SSE2) memory copy. Does not handle overlap.
void *sea_memcpy_fast(void *dest, const void *src, size_t n);
```

### Arena Allocator Functions

```c
// The arena management struct.
typedef struct s_mem t_mem;

// Initializes an arena. Use size 0 for the default.
t_mem *sea_arena_init(size_t size);

// Allocates zeroed memory from an arena.
void *sea_arena_alloc(t_mem *arena, size_t size);

// Frees the entire arena and all memory allocated within it.
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

**Heap-based allocation:**
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

**Arena-based allocation:**
```c
char   *sea_arena_strdup(t_mem *arena, const char *src);
char   *sea_arena_strsub(t_mem *arena, char const *s, unsigned int start, size_t len);
char   *sea_arena_strjoin(t_mem *arena, char const *s1, char const *s2);
char   **sea_arena_split(t_mem *arena, char const *s, char c);
```

### Conversion Functions

Based on `<stdlib.h>` functionality:

```c
int    sea_atoi(const char *nptr);
int    sea_atoi_base(const char *str, int base);
double sea_atof(const char *str);
```

### File Descriptor Output Functions

```c
void sea_putchar_fd(char c, int fd);
void sea_putstr_fd(char const *s, int fd);
void sea_putendl_fd(char *s, int fd);
void sea_putnbr_fd(int n, int fd);
```

### Linked List Functions

```c
// The linked list node struct.
typedef struct s_list t_list;
```

**Heap-based allocation:**
```c
t_list *sea_lstnew(void *content);
```

**Arena-based allocation:**
```c
t_list *sea_arena_lstnew(t_mem *arena, void *content);
```

**List manipulation:**
```c
void   sea_lstadd_front(t_list **lst, t_list *new);
void   sea_lstadd_back(t_list **lst, t_list *new);
int    sea_lstsize(t_list *lst);
t_list *sea_lstlast(t_list *lst);
void   sea_lstdelone(t_list *lst, void (*del)(void*));
void   sea_lstclear(t_list **lst, void (*del)(void*));
```

## 🎯 Performance Benefits

- **Arena Allocation**: Dramatically reduces allocation overhead for short-lived objects
- **SIMD Acceleration**: SSE2-optimized memory operations for improved throughput
- **Zero-Copy Operations**: Many functions designed to minimize unnecessary memory copying
- **Efficient Data Structures**: Optimized linked list implementations with both heap and arena variants

## 🤝 Contributing

This is a personal learning project exploring modern C programming techniques. Feel free to explore the code, suggest improvements, or use it as inspiration for your own projects.

## 📜 License

This project is licensed under the MIT License - see below for details:

```
MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

*Navigate the seas of C programming with Sealib! ⚓*
