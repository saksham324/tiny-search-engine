/* 
- crawler.c

*/

#include <stdio.h>
#include <stdlib.h>
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../libcs50/bag.h"
#include "../libcs50/hashtable.h"

char* PAGE_DIRECTORY; 
webpage_t* pageFetcher(char* seedUrl, const int depth); 
void pageSaver(webpage_t* page, char* dirName, int id); 

int main(const int argc, char *argv[])
{
	bag_t *bag = bag_new();
    hashtable_t *hashtable = hastable_new(50); 


    char* program = argv[0];  // program name

	// check input arguments: # of arguments
	if (argc != 4) {
		fprintf(stderr, "usage: %s seedURL pageDirectory maxDepth\n", program);
		return 1; 
	}
	// check input arguments: URL validity
	char* seedUrl = malloc(sizeof(argv[1] + 1)); 
	strcpy(seedUrl, argv[1]); 
	if (!NormalizeURL(seedUrl)) {
		fprintf(stderr, "%s cannot be normalized\n", seedUrl);
		return 2;
	}

    if (!IsInternalURL(seedUrl)) {
		fprintf(stderr, "%s is not an internal URL\n", seedUrl);
		return 3;
	}

    PAGE_DIRECTORY = argv[3]; 

    webpage_t *seedPage = webpage_new(seedUrl, 0, NULL); 
    bag_insert(bag, seedPage); 
    hashtable_insert(hashtable, seedUrl, seedPage); 

    
    void* bagNext; 
    while ((bagNext = bag_extract(bag)) != NULL) {
        webpage_t* page = pageFetcher(bagNext, 1); 
    }
	return 0;
}

webpage_t* pageFetcher(char* url, const int depth) {
    // char* url = malloc(sizeof(url+ 1)); 
    // strcpy(url, url); 
    if (!NormalizeURL(url)) {
		fprintf(stderr, "%s cannot be normalized\n", url);
		return NULL;
	}

    if (!IsInternalURL(url)) {
		fprintf(stderr, "%s is not internal\n", url);
		return NULL;
	}

    webpage_t *page = webpage_new(url, depth, NULL); 
    if(!webpage_fetch(page)) {
        return page; 
    } else {
        return NULL; 
    }
}

void pageScanner(webpage_t* page, bag_t *bag, hashtable_t *ht) {
    int pos = 0; 
    char *result; 

    while((result = webpage_getNextURL(page, &pos)) != NULL) {
        webpage_t *page_new = pageFetcher(result, webpage_getDepth(page) + 1); 
        if (page_new != NULL) {
            hashtable_insert(ht, result, result); 
            bag_insert(bag, page_new);
        }
    }
    free(result); 
}

void pageSaver(webpage_t* page, char* dirName, int id) {
    int id_length = snprintf(NULL, 0, '%d', id); 
    char* idStr = malloc(id_length + 1); 
    char* filePath = malloc(strlen(dirName) + strlen(idStr) + 2); 

    filePath[0] = '\0'; 
    strcat(filePath, dirName); 
    strcat(filePath, "/"); 
    strcat(filePath, idStr); 

    FILE *fp = fopen(filePath, "w"); 
    free(idStr); 

    if (fp != NULL){
        fprintf(fp, "%s\n", webpage_getURL(page));
        fprintf(fp, "%s\n", webpage_getDepth(page)); 
        fprintf(fp, "%s\n", webpage_getHTML(page)); 
    } else {
        fprintf("Error making file %s\n", filePath); 
    }

    free(filePath);

}



