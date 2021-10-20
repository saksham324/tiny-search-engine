# Lab 4 Rubric

## Grader: Elorm Coch
## Total: 93/100

#### Delivery (20/20)
 * 5 points: proper use of git (submitted via git, with the right tag)
 * 3 points: Follow the required file structures without extra data files, .o files, backup files, etc...
 * 5 points: Makefiles provided that can build all targets and includes a 'clean' target.
 * 5 points: "make" compiles properly with correct flags, produces 'crawler';
 * 2 points: "make clean" does what it should

#### Documentation & Testing (16/22)
All required documentation (README.md and IMPLEMENTATION.md) is provided and is complete, accurate, well-written, and informative. Each source code file (shell script, .c, .h, makefile, etc.) should have a comment header describing the purpose of the file, and the author.

 * 4 points has well-written README.md (but -1 if they wrote txt not md)
 * -6 points has well-written IMPLEMENTATION.md (but -1 if they wrote txt not md)
 * 4 points for well-written testing.sh summarizing representative test cases
 * 2 points documented assumptions
 * 6 points source files and scripts have relevant and necessary comments

#### Code Quality (20/20)
  * 10 points: Well-structured and easy to follow; very readable, with meaningful comments. cohesive and concise.
    * 10 points off if duplicate urls detected, 8 points off if the student mentions it in README
    * 5 points off if the whole crawler is written in `main`
    * clear, modular design with proper function designs (avoid super long functions, divide a long/complicated task into smaller pieces/functions)
    * avoid deep nested loops or conditional blocks
  * 10 points: Follows [CS50 style](http://www.cs.dartmouth.edu/~cs50/Resources/CodingStyle.html);
    * meaningful identifiers (variables and functions).
    * consistent indentation and spacing.
    * check and handle null pointers.
    * the data-structures library should be rigorous in checking for NULL return from malloc/calloc, and responding appropriately.
    * the application code (crawler) must also check for NULL return from malloc/calloc, but it is ok for it to print an error and die if they ever return NULL. in short, the code need not unwind elegantly from an out-of-memory error.
    * the application code (crawler) should also check the file pointer after fopen() function and handle errors in file I/O gracefully.

#### Functionality (37/38)

**Memory leaks**
-1 for leaks in input checking testcases
* T2:
  Command  
  ./crawler http://cs50tse.cs.dartmouth.edu/tse/ target2 -4
  Expected value: incorrect value
  ```
  ==39861== LEAK SUMMARY:
  ==39861==    definitely lost: 37 bytes in 1 blocks
  ==39861==    indirectly lost: 0 bytes in 0 blocks
  ==39861==      possibly lost: 0 bytes in 0 blocks
  ==39861==    still reachable: 0 bytes in 0 blocks
  ==39861==         suppressed: 0 bytes in 0 blocks
  ```


