
# About [compiler flags](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)
On using -g, -g1, -g2, -g3...

> -g Request debugging information and also use level to specify how much information. 
> The default level is 2.
> - Level 0 produces no debug information at all. Thus, -g0 negates -g.
> - Level 1 produces minimal information, enough for making backtraces in parts of the program that you don’t plan to debug. This includes descriptions of functions and external variables, and line number tables, but no information about local variables.
> - Level 3 includes extra information, such as all the macro definitions present in the program. 

> Some debuggers support macro expansion when you use -g3.


# Valgrind documentation
- [Command line flags](https://www.cs.cmu.edu/afs/cs/academic/class/15213-s03/labs-save/L4/share/doc/valgrind/manual.html#flags)
- [Connecting to a remote GDB server](https://valgrind.org/docs/manual/manual-core-adv.html#manual-core-adv.gdbserver)

# [GDB documentation](https://sourceware.org/gdb/current/onlinedocs/gdb)

# Valgrind cheatsheet

- [Common Valgrind errors](https://bytes.usc.edu/cs104/wiki/valgrind/)