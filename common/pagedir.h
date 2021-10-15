#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../libcs50/file.h"

// checks to see if the directory exists and can be written into
bool validateDirectory(char* pageDir);

// saves a webpage
bool pageSaver(webpage_t* page, char* pageDir, const int id);