Brian Rafferty -- cssc0852 -- redID: 816988452
---------------------
CS 570 Operating Systems, Summer 2019
---------------------
Program Assignment #1, Multithreading
---------------------
README.md
---------------------
Manifest:
    README.md
    player.cpp
    player.h
    Makefile
----------------------
Compiling executable:
    make
----------------------
Running executable:
    player 
----------------------
List/description of novel/significant design decisions:
Made the program as robust as possible, adding error checking
during every system call and allowed the program to gracefully
exit if any errors are reached.
----------------------
List/description of any extra features/algorithms/functionality 
you included which were not required:
I added a check to see if the file was created successfully,
which will then allow the PID to be printed to the file if it worked.
----------------------
List/description of all known deficiencies or bugs:
There is a warning upon compilation, which states:
cast to pointer from integer of different size.
----------------------
Lessons Learned:
Strings are difficult to work with on the Linux system,
I had a tough time figuring out the appropriate methods
to convert strings from Unix. 