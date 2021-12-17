Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

diff.text contains the diff between stock kernel and 
the kernel with new syscall.

test.c is the c program to test the syscall.


First i made the linux kernel source a git repository using 
$ git init

Then i added the files to git using 
$ git add arch/x86/entry/syscalls/syscall_64.tbl
$ git add kernel/sys.c

Then i commited using 
$ git commit -m init

This saved their original state. Now i edited them for the new syscall.

For this i made a new entry in arch/x86/entry/syscalls/syscall_64.tbl file 
448	common	kernel_2d_memcpy	sys_kernel_2d_memcpy

This is the syscall table.

Next i defined the syscall in kernel/sys.c
SYSCALL_DEFINE4(kernel_2d_memcpy, float**, dest, float**, source, int, rows, int, cols){
    // code
}

The syscall takes 4 parameters dest array, source array and the no of rows and columns.
I used __copy_from_user() to copy the source to kernel space.
Then __copy_to_user() to copy from kernel space to the destination.

Now the changes were done. Then i got the diff using
$ git diff >> /path_to_q2_folder/diff.txt

Now i compiled the kernel 
$ make -j4 CC="ccache gcc"

Then installing the modules and other steps.

Then running the test.c by cd into q2 and make.
I have hardcoded a array (arr) into test.c
Then i use the syscall to copy that into another array (arr2).

expected output:
original array
1.500000 2.500000 3.500000 
4.500000 5.500000 6.500000 
7.500000 8.500000 9.500000 
10.500000 11.500000 12.500000 

copied array
1.500000 2.500000 3.500000 
4.500000 5.500000 6.500000 
7.500000 8.500000 9.500000 
10.500000 11.500000 12.500000 