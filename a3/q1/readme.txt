Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

diff.text contains the diff between stock kernel and 
the kernel with new syscall.

test.c is the c program to test the syscall.


For this i made a new entry in arch/x86/entry/syscalls/syscall_64.tbl 
448	common	delay_process		sys_delay_process

This is the syscall table.

Next we define the syscall in kernel/sys.c
SYSCALL_DEFINE2(delay_process, int, pid, int, delay)
{
	//code
}
This takes 2 parameters pid and the delay in msec.
This syscall changes the delay variable which we added in sched_entity.

then we added a variable to struct sched_entity in include/linux/sched.h
u64	delay;
This is where we will store the delay provided by user.

Now in kernel/sched/core.c
p->se.delay = 0;
This is delay variable is initialized to 0.

Now in kernel/sched/fair.c
we make the required changes to the scheduler to fulfill the requirements 
of the question.
