# Cheat Sheet GDB

[GDB Manual](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)

# Quick Access

- [Running a program](#running-a-program)
- [Break](#breakpoints)
- [Continuing and Stepping](#continuing-and-stepping)
	- [Step](#stepping)
	- [Next](#next)
	- [Finish](#finish)
	- [Return](#return)
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

Once you're done debugging you can kill the running program with
```sh
kill
```

And you can then quit gdb with
```sh
quit
```

## Breakpoints

Creates a breakpoint, this breakpoint is a point in the code at which your program will stop and give you [control over execution](#continuing-and-stepping).

`<where>` can be a function name or a line in your code (`filename:line`)

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

### Return

You can also force a return value for a function. `return` skips the rest of the current function and allows you to specify what value it should return.
```sh
return <value>
```

### Continue

If you want to go back to normal execution and wait for another breakpoint to be reached, you can `continue`.

```
continue
```

## Variables

You can print and edit variable content at any point in the code allowing you to check if your logic is right or not.

`<expressions>` can be a variable name or any 'valid' c expression, this can be useful to cast or dereference pointers.

```sh
print <expression>
set variable <name>=<value>
display <expression>  # will print <expression> at each step in the code.
info locals           # prints all local variables for the current frame
```

## Stack

These commands are mostly usefull in case of a crash or unexpected infinite loop, they can be tricky to understand!

A stack [frame](#frame) is a point in a function call, navigating to one allows you to [print variables](#variables) from that point.

Taking a look at the [backtrace](#backtrace) allows you to know where in the code your function is called and with which parameters. **It can give you a general idea of the state of your program outside of the function you're debugging.**

### Backtrace

Shows the backtrace for the current execution. The backtrace is the history of function calls (frames) used to reach this state.

The optional argument `full` can be used to show all parameters and local variables for each function call.

Each function call will be printed along with it's unique [frame](#frame) index.

```sh
backtrace (full)
```

### Frame

If you ever want to inspect previous function call from a [backtrace](#backtrace), you can go back to previous calls from the stack using this command by passing the desired frame index.

Any [execution commands](#continuing-and-stepping) will still be executed from frame #0.

```sh
frame <N>
```
