# BF++ Compiler
> A Brainfuck++ compiler
---
This is a compiler that convert your Brainfuck++ code into C++ code and then compiles it to a binary.

# Brainfuck++
## Okay but what is Brainfuck++ ?
Brainfuck++ is an improved version of [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) language.
It can be considered as an extension of the original language with some more functionnalities such as code include, function declarations etc.<br>
<br>
> **Note: this functionnalities are not available for the moment.**<br>
> Also, more functionnalities might come later, and some notations might change.

## Commands
### Classic Brainfuck
These commands are still the same:
- `[` Start loop if value at memory position != 0, skip to the end of loop if not.
- `]` End the loop (go back to corresponding `[` if the value at memory position !=, else goes forward)
- `+` Increase the value at memory position
- `-` Decrease the value at memory position
- `<` Move to previous memory position
- `>` Move to next memory position
- `.` Print to the console the char associated to extended ASCII value of the memory position
- `,` Read a console input of one char

### New commands
- `!` Pause: wait for a key press to continue
- `?` Debug: print the memory array values and indicate the cursor position
- `\functionName\ {the code goes here}` function declaration
- `/functionName/` function call
- `*` exit from current function<br>
- `#{path/to/fileNameToInclude.bf}` includes the content of an external brainfuck file at the current position of the program
> The following commands are still not available<br>
- *`:{path/to/output/file.txt}` Append character to file (like `.` but outputs in file)*
- *`;{path/to/input/file.txt}` Store each character of the input file in the memory (like `,` but use file as input)*

# Compiler
To build the compiler:
```bash
./cmakecompile --release
```
Then you can use the following command to get help to use the compiler:
```bash
build/bfpp --help
```

For instance, you can do:
```bash
build/bfpp brainfuck/hello.b
```
Now you should be able to do
```bash
brainfuck/hello.o
```