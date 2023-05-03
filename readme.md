# Dang Programming Language
Computer Science 30 Project D (final project).
Dang comes from the name of the student working on this project and the word «language».
`D + lang = Dang`

## How does it work?
### Lexical Analysis
The source code is being lexically analyzed for keywords, numerical and string literals and special characters used as operators. Human-readable text translates to computer-readable elements called tokens.

Example:

    print "Hello, world!"

That piece of source Dang code turns into a collection of tokens (in C++)

    token(token_type::keyword_print);
    token(token_type::literal_string, "Hello, world!");
    

### Abstract Syntax Tree
Then tokens are being parsed. Different tokens tell the program what to do, what the next token expects and how to work with it. During this stage a collection of statements is being created.

Example:
When a program gets the `print` token it creates a print statement that accepts a value as a parameter, so the next token must either be a literal or a variable. In our case the next token is a `string literal` with value `"Hello, world!"`.

### Translation
All the created statements are being executed (translated to C++11).

### Compilation
The generated C++11 code is being compiled using the G++ compiler (bundled with the program).

## Getting Started
Download the latest release and unzip in a convenient location.

## Usage
To create a source C++ and an executable file use this syntax in the command line.

    dang [filename]

Example:
    
    dang main.dang
    
As output a `main.dang.cxx` and a `DangProgram.exe` are generated.

## Documentation

### Syntax
No semicolons or indentation or newlines are required to separate statements. They can be written in any way you want!

Example:

    println "Hello!" print "Hi!"
    var name = read<str>()

### Data Types
Currently only C++'s primitive data types and strings are available, no custom structures or classes YET. Data types are `int` `short` `long` `long long` with or without `unsigned` modifications, `float` `double` `long double` for floating points and `char` and `bool`. For strings use the keyword `str`.

### Comments
Single line comments must start with `//` in the beginning of the line. Block comment segment must start with `/*` and end with `*/`.

    // Single line comment
     // not a comment
    /* block comment */
    /* multiline
       comment */

### Standard Input/Output
Output:
`print` prints the value to the console and `println` also ends the line. These functions accept any value; have no return values. Those are not functions but are statements.

    print "Hi!"
    print 134
    println true

Input:
How input handling use generic function `read<type>() -> type`. Does not accept any parameters, return the value of the type specified in `<>`,

    read<int>()
    read<float>()
    read<str>()

### Variables and Constants
Variables have mutable values, but not types. Declared by using the `var` keyword followed by name and value or with optional type.

    var name = "Mike"
    var age : int = 31
    
Values can be reassigned

    name = "John"
    age += 2

All the assignment operators are `=` `+=` `-=` `*=` `/=` and `%=`. String concatenations is performed by the `+=` operator.

Constants' values are assigned only once during declaration.

    const pi = 3.141
    const user : str = "Admin"

### Expressions
#### Unary
 - `-` negates arithmetical value

    -42

 - `+` Basically does nothing. But can be used to explicitly write a positive value

    +42

 - `not` negates logical value.

    not false
#### Binary
Logical binary operators are `and`, `or` and `xor` (exclusive or).
And the rest are well-known `+` `-` `*` `/` `%`.

### If and Else statements
If statements accept a boolean expression as condition and execute the following statement or block of statements if the condition is true. Parenthesis are optional.

    if (3 > 2)
        print "True!"

    if 5 <= 5
    {
        print "5 is less than or equal to 5"
    }

If the condtion is false then `else` statement is executed.

    if pi == 3
        println "True!"
    else
        println "False"

Else statement can be followed by `if` because of the nature of the parser.

    if a == 1 {}
    else if a == 2 {}
    
### Loops
#### While
The statement of block of statements (which is also a statement) is executed while the boolean condition is true.

    while true { /* do smth*/ }
    
#### Do-While
The statement of block of statements (which is also a statement) is executed once unconditionally and then while the boolean condition is true.

    do { /* do smth*/ } while true
        
#### For
The for loop always accepts an iterator declaration statement, boolean conditional expression and iterator modification statement.

    for 
        var i = 0   /* iterator declaration */
        i < 10      /* boolean condition */
        i += 3      /* iterator modification */
    { /* do smth*/ }
    
### Flow Control
To immediately terminate execution of the program use the `exit` keyword with an exit code.

    exit 0
    
To skip an iteration of a loop use the `continue` and to stop the loop use `break`.

### Functions
A function can be declared with the `func` keyword followed by name and parenthesis with parameters (the parameters are optional). The return type can be specified after the parameters with `->` and return type (`void` for no return type). Then the body of the function is a single statement or a block of statements.

    func foo(val : int) -> bool
    {
        print "bar"
        return true
    }
    
    func square(x : int) -> int
        return x * x

### File Input/Output
To read all the content from a file as a string use the built-in function `readFile(str) -> str`.

    var fileContent : str
    fileContent = readFile("MyFile.txt")
    
    println fileContent
    
To write (replace) content in a file use the `writeFile(str, str) -> void` built-in function.

    writeFile("MyFile.txt", "New Text")
    
To append content in a file use the `appendFile(str, str) -> void` built-in function.

    appendFile("MyFile.txt", "New Text in addition to existing!")
    
To determine whether a file exists use the built-in function `fileExists(str) -> bool`.

    if fileExists("MyFile.txt")
        println "The File Exists!"
    els
        println "The File Does Not Exist!"
        
To delete a file use the built-in function `deleteFile(str) -> void`.

    deleteFile("MyFile.txt")
