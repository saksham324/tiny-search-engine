## Saksham Arora

### common subdirectory for Tiny Search Engine

The Common directory contains `pagedir.c` and `pagedir.h`.

### Compiling

The user should type `make` on the command line, in the *common* directory.

### Usage

Running the `make` command creates common.a. The functions in pagedir.h can be used by any other modules.

```c
// checks to see if the directory exists and can be written into
bool validateDirectory(char * dirname);

// saves a webpage
bool pageSaver(webpage_t* page, char *pageDir, const int id);

```

### Assumptions

No assumptions beyond what is stated in the specifications.