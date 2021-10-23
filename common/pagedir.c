#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pagedir.h"
#include "../libcs50/webpage.h"
#include "../libcs50/memory.h"
#include "../libcs50/file.h"

// function prototypes
// bool validateDirectory(char * dirname);
// bool pageSaver(webpage_t* page, char *pageDir, const int id);

bool validateDirectory(char *pageDir)
{
    // name of the file (.crawler or ./crawler depending on the formatting)
    char filename[11 + strlen(pageDir)];
    strcpy(filename, pageDir);
    char *extension;

    // user can give directory as either pageDir/ or pageDir
    if (pageDir[strlen(pageDir) - 1] != '/'){
        extension = "/.crawler";
        strcat(filename, extension);
    }
    else {
        extension = ".crawler";
        strcat(filename, extension);
    } 

    // open the file
    FILE * fp = fopen(filename, "w");

    // if a valid fp is returned, the directory is valid.
    if (fp == NULL){
        fprintf(stderr, "Provide an existing pageDirectory.\n");
        return false;
    }
    else {
        fclose(fp);
        return true;
    }
}


// saves a page in the directory specified by pageDir with a file name of id
bool pageSaver(webpage_t* page, char* pageDir, const int id){
    bool status; // have we successfully saved the page?
    char filename[strlen(pageDir) + 5];
    strcpy(filename, pageDir);
    // if the filename does not end with a '/', concatenate it
    if (pageDir[strlen(pageDir) - 1] != '/') {
        strcat(filename, "/");
    }

    char idName[4];

    // converting int id to string  
    sprintf(idName, "%d", id);

    // concatenating filename and id into an absolute path
    strcat(filename, idName);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL){
        fprintf(stderr, "pageSaver: Error saving the webpage.\n");
        status = false;
    }
    // if the file was successfully created, start writing into it.
    else {
        fprintf(fp, "%s\n", webpage_getURL(page));
        fprintf(fp, "%d\n", webpage_getDepth(page));
        fprintf(fp, "%s\n", webpage_getHTML(page));
        fclose(fp);
        status = true;
    }
    return status;   
}

// reads a single webpage file produced by crawler and loads it into a webpage str
webpage_t *loadPage(char *pathname){
    FILE *fp = fopen(pathname, "r");
    if (fp != NULL){
        char *url = freadlinep(fp);
        char *d = freadlinep(fp);
        int depth = atoi(d);
        free(d);
        char *html = freadfilep(fp);
        fclose(fp);

        webpage_t *page = webpage_new(url, depth, html);
        return page;
    }
    return NULL;
}



