# Grader: Chahak Goyal

## Total Score: 84/100    

### Overall: 10/10  

* (3) Proper git tag `lab5submit`
* (3) git commit history - logical groupings of changes in each commit, and meaningful commit messages.
* (2) tse directory and subdirectories `indexer` and `common` exist, and `indexer` must include appropriate `.gitignore`.
* (2) no executable files, object files, core dump files, editor backup files, or extraneous files existing in any directory.

### Makefiles: 9/10  

* (4) `indexer/Makefile`  
* (3) directory `common/` exists; `common/Makefile`
* (3) Builds `indexer` and `indextest` with no compilation errors or warnings when compiled from the top-level directory
  * -1 for libcs50.a compile warning. It is detailed in `libcs50/README.md` that if using `libcs50-given.a`, you should change the target in the Makefile to copy `libcs50-given.a` to `libcs50.a` to get rid of the compiler warning.

### Documentation: 7/10   

* (1) `README.md`, how to build `indexer`.
* (4) `DESIGN.md`, the abstract design of the indexer with no language-specific details.
  * -1 for no mention of unit testing  
* (3) `IMPLEMENTATION.md`: Describes the implementation of `indexer`.
  * -2 for not having complete pseudocode of all functions. Please refer to the example `IMPLEMENTATION.md`.
* (2) `testing.sh`, which should have good comments.

### Testing: 8/10  

* (8) `tse/indexer/testing.sh` should have good test cases and good comments
  * -2 for not testing memory leaks and errors using valgrind
* (2) `tse/indexer/testing.out` should be the output of `make test &> testing.out`  

### Coding Style: 15/20  

* -5 for not decomposing `indexer` and `indextest` into functions  

### Functionality: 30/30  

* (6) Validation of command-line arguments in both `indexer` and `indextest`  
* (16) Correct outputs on a variety of test cases - compare with solution `indexer` and `indextest`.  
* (8)  `indextest` properly loads and saves the index the output index is equivalent to the input index.

### Memory leaks, according to valgrind: 10/10

* (4) free of memory errors.
* (4) free of lost memory blocks.
* (2) free of still reachable memory blocks.

### Overall deductions:

* -5 for no unit testing  



