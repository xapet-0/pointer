To remember the advice of Mr gynveal 
code Mr smile
# pointer
don't use C/C++ if you really really need to, I always found it beneficial to learn a bit of assembly (esp. memory operations / memory model as seen from a usermode application), and look at memory through a debugger first; and then learn the C rules for pointers (it's basically same as assembly memory access with type calculus sprinkled on top)
this makes me want to write a game where you get given an english language description of a pointer - e.g. "a pointer to a pointer to a pointer to a pointer to the value 42" - and a pwn style menu with 1) allocate 2) write 3) submit - the idea being that you allocate memory for the value and the chain of pointers using write to set the value 42 and the addresses of the pointers and then submit will deref and assert the value at end of the chain or and this is the fun part crash
