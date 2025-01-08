# Cheat Sheet GDB

[GDB Manual](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)

# Quick Access

- [Running a program](#running-a-program)
- [Break](#breakpoints)
- [Continuing and Stepping](#continuing-and-stepping)
	- [Step](#stepping)
	- [Next](#next)
	- [Finish](#finish)
	- [Continue](#continue)
- [Print and set variables](#variables)
- [Stack](#stack)
	- [Backtrace](#backtrace)
	- [Frame](#frame)

## Running a program

Start gdb with

```sh
gdb <program>
```

This will start gdb and load all debug information from the executable

You can then [set breakpoints](#breakpoints) and run a program with it's arguments

```sh
run [...args]
```

## Breakpoints

Creates a breakpoint, this breakpoint is a point in the code at which execution will stop and allow you to take control of the execution.

`<where>` can be a function name or a line in the code (`filename:line`)

```sh
break <where>
```

## Continuing and Stepping

This is how you control the execution of the program.

### Stepping

When stepping, gdb will execute the current line but in case the current line is a function call, it will step into it meaning debugging will continue inside the function.

```sh
step (N)	# steps N times, step once if N is unspecified
```

### Next

Using next is just like using [steps](#stepping) except it won't go into a function call, this just goes to the next line N times (1 if unspecified).

```sh
next (N)
```

### Finish

If you think you're done debugging a function and want to go back one [stack](#stack) [frame](#frame) you can use `finish`, it will continue execution until the current function returns, the returned value will also be printed out.

```sh
finish
```

### Continue

If you want to go back to normal execution and wait for another breakpoint to be reached, you can `continue`.

```
continue
```

## Variables

You can print and edit variable content at any point in the code allowing you to check if your logic is right or not.

`<expressions>` can be a variable name or any 'valid' c expression, this can be usefull to cast or dereference pointers.

```sh
print <expression>
set <name>=<value>
display <expressopn>	# will print <expression> at each step in the code.
info locals				# prints all local variables for the current scope
```

## Stack

These commands are mostly usefull in case of a crash or unexpected infinite loop, they can be tricky to understand!

### Backtrace

Shows the backtrace for the current execution, it will show the history of function calls used to reach this state.

The optional argument `full` can be used to show all parameters for each function call.

Each function call will be printed along with it's [frame](#frame) number.

```sh
backtrace (full)
```

### Frame

If you ever want to [print variables](#variables) from previous function call from a [backtrace](#backtrace), you can go back in the stack with frame.

```sh
frame <N>
```
