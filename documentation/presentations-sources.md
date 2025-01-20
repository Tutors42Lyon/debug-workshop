
# About [compiler flags](https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html)
On using -g, -g1, -g2, -g3...

> -g Request debugging information and also use level to specify how much information. 
> The default level is 2.
> - Level 0 produces no debug information at all. Thus, -g0 negates -g.
> - Level 1 produces minimal information, enough for making backtraces in parts of the program that you don’t plan to debug. This includes descriptions of functions and external variables, and line number tables, but no information about local variables.
> - Level 3 includes extra information, such as all the macro definitions present in the program. 

> Some debuggers support macro expansion when you use -g3.

# [Valgrind Virtual CPU](https://en.wikipedia.org/wiki/Valgrind)

> Valgrind is in essence a virtual machine using just-in-time compilation techniques, including dynamic recompilation. Nothing from the original program ever gets run directly on the host processor. Instead, Valgrind first translates the program into a temporary, simpler form called intermediate representation (IR), which is a processor-neutral, static single assignment form-based form. After the conversion, a tool (see below) is free to do whatever transformations it would like on the IR, before Valgrind translates the IR back into machine code and lets the host processor run it. Valgrind recompiles binary code to run on host and target (or simulated) CPUs of the same architecture. It also includes a GDB stub to allow debugging of the target program as it runs in Valgrind, with "monitor commands" that allow querying the Valgrind tool for various information.

> A considerable amount of performance is lost in these transformations (and usually, the code the tool inserts); usually, code run with Valgrind and the "none" tool (which does nothing to the IR) runs at 20% to 25% of the speed of the normal program.[7][8] 

# Valgrind documentation
- [Command line flags](https://www.cs.cmu.edu/afs/cs/academic/class/15213-s03/labs-save/L4/share/doc/valgrind/manual.html#flags)
- [Connecting to a remote GDB server](https://valgrind.org/docs/manual/manual-core-adv.html#manual-core-adv.gdbserver)

# [GDB documentation](https://sourceware.org/gdb/current/onlinedocs/gdb)

# Valgrind cheatsheet

- [Common Valgrind errors](https://bytes.usc.edu/cs104/wiki/valgrind/)