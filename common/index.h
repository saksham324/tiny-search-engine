#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "pagedir.h"
#include "../libcs50/hashtable.h"
#include "../libcs50/counters.h"
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../common/word.h"

// builds the inverted-index data structure and writes it into a file
void writeIndex(FILE *indexFile, char *pageDirectory);

// writes a line to the index file, in the specified format
void writeWord(void *arg, const char *key, void *item);

// writes the docID count pairs
void writeCount(void *arg, const int key, const int count);