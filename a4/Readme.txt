Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

diff.text contains the diff between stock kernel and 
the kernel with new syscall.

test.c is the c program to test the syscall.


For this we make a new entry in arch/x86/entry/syscalls/syscall_64.tbl 
+448	common	writer			sys_writer
+449	common	reader			sys_reader

This is the syscall table. We add both the new syscalls.

Next we define the syscalls in kernel/sys.c
SYSCALL_DEFINE1(writer, long*, num){
	//code
}
SYSCALL_DEFINE1(reader, long*, num){
    //code
}

This takes 1 parameter the address of long in user space.

Then we use __copy_from_user and __copy_to_user respectively to bring the 
data from/to user space to/from kernel space respectively.

Now we make a queue in kernel/sys.c using kmalloc to allocate memory.
The queue implementation is array based.
We implement enqueue and dequeue functions. 

The queue has length of 100. it can store 100 long.