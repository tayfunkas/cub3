# libft

Libft is a fundamental project at 42 programming school that involves recreating various standard C library functions. This project deepens understanding of basic algorithms and data structures, serving as a foundation for future projects at 42. Many of the files include commented out main functions to help with testing. The functions are written in line with norminette rules of 42 schools and they are reused in other projects.  

## Key Learnings

- **Memory Management**: Implementation of functions like `memset`, `memcpy`, and `memmove`.
- **String Manipulation**: Creating functions such as `strlen`, `strchr`, and `strdup`.
- **Linked Lists**: Bonus section introducing basic linked list operations.
- **Type Conversions**: Functions like `atoi` for string to integer conversion.
- **Character Operations**: Implementing `isalpha`, `isdigit`, and similar functions.

## Function Categories

### Libc Functions

- Character type checks: `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- String operations: `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strncmp`, `strnstr`
- Memory operations: `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`
- Type conversions: `atoi`, `toupper`, `tolower`
- Memory allocation: `calloc`, `strdup`

### Additional Functions

- String manipulation: `substr`, `strjoin`, `strtrim`, `split`, `itoa`
- Character operations: `strmapi`, `striteri`
- File descriptor operations: `putchar_fd`, `putstr_fd`, `putendl_fd`, `putnbr_fd`

### Bonus: Linked List Operations

- `ft_lstnew`: Create new list node
- `ft_lstadd_front`: Add node at beginning
- `ft_lstsize`: Count list elements
- `ft_lstlast`: Get last node
- `ft_lstadd_back`: Add node at end
- `ft_lstdelone`: Delete node content
- `ft_lstclear`: Delete and free list
- `ft_lstiter`: Apply function to list content
- `ft_lstmap`: Apply function and create new list
