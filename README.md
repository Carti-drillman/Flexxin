# Flexxin

![Image](https://github.com/user-attachments/assets/c5919136-88bb-4fe5-bef2-d399b64e54b7)

Flexxin is a programming language that was created in C and Makefile.

## Features

Variables: Declare and use variables with `var x = 10`.

Printing: Print strings or variable values with `print "Hello"` or `print x`.

Arithmetic: Perform basic arithmetic operations like `x = x + 5`,` x = x - 2`,` x = x * 3`, and `x = x / 2`.

Conditionals: Use if-else statements for decision-making.

Loops: Use for and while loops for iteration.

Comments: Add comments using `#`.

## How to install Flexxin to your system

Open Terminal and type this command. Make sure that you copied the Repository. If you are using linux or wsl, you must type these commands.

```bash
make
```

```bash
sudo make install
```

## How to write a script in Flexxin?

You need to make a file that extension is `.flex`.

If you installed Flexxin on the system, use this command to run `.flex` files.

```bash
Flexxin source.flex
```

Here is an example code in Flexxin.

`example.flex`

```python
# This is a comment
var x = 10
print "Hello, Flexxin!"
print x

# Arithmetic operations
x = x + 5
print x
x = x - 3
print x
x = x * 2
print x
x = x / 4
print x

# Conditional statement
if x == 6
    print "x is 6"
else
    print "x is not 6"
endif

# For loop
for i = 1 to 5
    print i
endfor

# While loop
var y = 3
while y != 0
    print y
    y = y - 1
endwhile
```

The output:

```bash
Hello, Flexxin!
10
15
12
24
6
x is 6
1
2
3
4
5
3
2
1
```
