/* 
- crawler.c
- Lab 4 Submission 
- Author : Saksham Arora
*/

#include <stdio.h>
#include <stdlib.h>
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../libcs50/bag.h"
#include "../libcs50/hashtable.h"
#include "../common/pagedir.h"

// function prototypes 
bool pageFetcher(webpage_t *page); 
void pageSaver(webpage_t* page, char* dirName, int id);
void url_delete(void *url);  

int main(const int argc, char *argv[]){

    // define variables 
    char *seedUrl; 
    int maxDepth;
    char pageDirectory[50];
    char* program = argv[0];  // program name
    int id = 1; 
  

	// check input arguments: # of arguments
	if (argc != 4) {
		fprintf(stderr, "usage: %s seedURL pageDirectory maxDepth\n", program);
		return 1; 
	}

	// check input arguments: URL validity
	if (IsInternalURL(argv[1])) {
        seedUrl = assertp(count_malloc((strlen(argv[1]) + 1)*sizeof(char)), "seedUrl");
        strcpy(seedUrl, argv[1]);
    }
    else {
        fprintf(stderr, "Invalid seedUrl.\n");
        return 2;
    }

    // validating maxDepth
    maxDepth = atoi(argv[3]);
    if (maxDepth < 0){
        fprintf(stderr, "maxDepth has to be > 0.\n");
        return 3;
    }

    // validating directory
    strcpy(pageDirectory, argv[2]);
    if (!isValidDirectory(argv[2])) {
        return 4;
    }

    // define bag with pages to crawl
    bag_t *pagesToCrawl = bag_new();

    // define hashtable for seen urls
    hashtable_t *urlSeen = hastable_new(200);

    // define seed page from seedUrl
    webpage_t *seedPage = webpage_new(seedUrl, 0, NULL); 
 
    // insert seedPage to bag
    bag_insert(pagesToCrawl, seedPage); 

    // add seedUrl to ht of seen urls
    hashtable_insert(urlSeen, seedUrl, ""); 
    
    // define webpage last extracted from bag
    webpage_t *lastExtracted; 

    while ((lastExtracted = bag_extract(pagesToCrawl)) != NULL) {
        if (pageFetcher(lastExtracted)){
            char dirName[50]; 
            strcpy(dirName, pageDirectory); 
            pageSaver(lastExtracted, dirName, id); // save the webpage
            id++; 
        } 

        // if depth of webpage is less than max depth continue scanning
        if (webpage_getDepth(lastExtracted) < maxDepth) {
            pageScanner(lastExtracted, pagesToCrawl, urlSeen); // scan webpage for more urls and add to bag
        }

        // delete webpage 
        webpage_delete(lastExtracted); 
    }

    // delete bag once we're done
    bag_delete(pagesToCrawl, webpage_delete); 

    // delete hashtable once we're done 
    hashtable_delete(urlSeen, url_delete); 

	return 0;
}

// pagefetcher function definition
bool pageFetcher(webpage_t *page) {
    return webpage_fetch(page);
}

// pagescanner function definition 
void pageScanner(webpage_t* page, bag_t *bag, hashtable_t *ht) {
    int pos = 0; 
    char *result; 

    while((result = webpage_getNextURL(page, &pos)) != NULL) {
       if (IsInternalURL(result)){
            if(hashtable_insert(ht, result, "")){
                webpage_t *new = webpage_new(result, webpage_getDepth(page) + 1, NULL);
                bag_insert(bag, new);
            } else {
                // free the URL if it wasn't inserted in the hashtable
                free(result);
            }
        } else {
            // free the URL if it's not internal
            free(result);
        }
    }
}

// function to delete url 
void url_delete(void *url) {
    if (url != NULL) {
        url = NULL;
    }
}





