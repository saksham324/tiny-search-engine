# Saksham Arora Lab 6 Grade

## Total: 97/100

## (10/10) Delivery
* (3/3) proper git tag
* (3/3) git commit history
* (2/2) proper file structure
* (2/2) no executable files

## (11/12) Makefiles
* (-1) compiles from top level directory
* (4/4) querier makefile
* (4/4) common makefile
* (4/4) no compiler errors or warnings 

## (12/12) Documentation 
* (2/2) README.md
* (4/4) DESIGN.md
* (4/4) IMPLEMENTATION.md
* (2/2) testing.sh

## (6/6) Testing
* (5/5) testing.sh
* (1/1)  `testing.out` is output of `make test &> testing.out`

## (20/20) Coding Style

## (30/30) Functionality

## (8/10) Memory
* (4/4) free of memory errors
* (4/4) free of lost memory blocks
* (0/2) free of still reachable memory blocks *see below*

```
==3928== LEAK SUMMARY:
==3928==    definitely lost: 0 bytes in 0 blocks
==3928==    indirectly lost: 0 bytes in 0 blocks
==3928==      possibly lost: 0 bytes in 0 blocks
==3928==    still reachable: 252,836 bytes in 17,023 blocks
==3928==         suppressed: 0 bytes in 0 blocks
==3928== 
==3928== For counts of detected and suppressed errors, rerun with: -v
==3928== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```