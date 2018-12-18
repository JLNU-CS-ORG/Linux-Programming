# Chapter1: Introduction of Unix/Linux/GNU

This chapter is introduction of Unix/Linux/GNU. Because of it's too easy, so
we have not so much introduction.

## hello.c
Just for describe the usage of "gcc" compiler.</br>
Please use command `gcc -o hello hello.c` on your linux shell. Conclude csh, bsh,
bash, ksh, etc.</br>
Then use command `./hello` on your linux shell.

## bill.c fred.c program.c
This three files describe how to use library.</br>
1. First, we use command `gcc -c bill.c fred.c program.c` on your shell. Then it will produce three object files.
2. Second, we use command `ar crv libfoo.a bill.o fred.o` on your shell. Then it will produce a "libfoo.a" file.
3. Third(Optional), we use command `ranlib libfoo.a` on your shell. Then this libraray is already can use.
Next, We can use this function library. We use command `gcc -o program program.o libfoo.a` on your shell. It will produce a execute ELF file.
