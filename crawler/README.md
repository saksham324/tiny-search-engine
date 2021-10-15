## Saksham Arora
### Crawler for Tiny Search Engine
#### Lab 4 Submission

The TSE crawler is a standalone program that crawls the web and retrieves webpages starting from a `seed` URL. It parses the seed webpage, extracts any embedded URLs, then retrieves each of those pages, recursively, but limiting its exploration to a given `depth`.

### Compiling

The user should type `make` on the command line, in the *crawler* directory.
To test, type `make test`.

### Usage

`./crawler seedUrl pageDirectory maxDepth`

* `seedUrl` is used as the initial URL (must be an internal URL)
* `pageDirectory` is the pathname for an existing directory in which to write downloaded webpages
* `maxDepth` is a non-negative integer representing the maximum crawl depth

output:

* writes each page to the `pageDirectory` with a unique document `id`, wherein the document `id` starts at 1 and increments * by 1 for each new page
* the 1st line of the file is the `url`
* the 2nd line of the file is the depth
* the rest of the file is the page content, i.e. the HTML unchanged

### Exit status

0 - Success
1-4 - Invalid command line arguments

### Assumptions

It is assumed that the `common.a` archive exists in the common directory.
It is assumed that the directory in which to store output files has already been created.

### Limitations

`maxDepth` has to be a small number, especially when crawling sites with many embedded `url`s. This is because there is a pause between page fetches, and a large `maxDepth` would take a long time.