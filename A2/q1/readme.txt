Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

run make to execute.
NOTE: CHANGE FREQUENCY DEFINED IN E2 TO GET ACCURATE CONVERSION FROM TIME
STAMP TO HUMAN READABLE TIME.
>>>#define frequency 1.2
CURRENTLY SET TO 1.2 Ghz.

3 programs main.c, E1.c, E2.c

In main S1 was created first using fork(). 
S1 declared its SIGTERM handler as sig_handler1() in main.c
Then S1 was in a while(1){pause();} loop.

In parent we save the  pid of S1 in a variable pid1.
Now in parent process we create 2 more child using fork() - SR and ST.

SR and ST in turn call E1 and E2 respectively using execv().
We also pass argv to both which contains the pid1 in string form which
we converted using sprintf.

Now both E1 and E2 are similar.
The both declare their respective SIGALRM handlers.
They both convert the pid1 into integer from the argv using atoi.

Now all S1, SR and ST create a shared memory access for IPC.

They use ftok to generate a unique key. Then use shmget() to get the id for 
the shared memory.Now they can access the shared memory using shmat() and 
then detach it after using by shmdt().

Now in both SR and ST i set up a alarm using setitimer and gave it 
time interval of 1 second. In start i started ST after SR and gave 
a 0.5 second gap using usleep(500000). So now both will have timers 
that are 1 second interval and will be staggered and not clash.
setitimer sends SIGALRM at the specified intervals.

Now in their SIGALRM handler inmplemented the required functionality.
In SR:
unsigned long num;
asm( "rdrand %0" : "=r" ( num ));

In ST:
unsigned long long hi, lo;
asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
unsigned long long val =lo| hi<<32 ;
this gives us the time stamp in variable val.
Next we divide this by the frequency defined at top*10^9.
Originally the frequency is at 1.2 Ghz. Change this to get more accuracy.
Now we convert this into hr:mm:sec by dividing it by taking mod by 60.


Now they access the shared memory and put these numbers into it 
using sprintf.

Then i sent the SIGTERM to S1 using its pid. In S1 it reads the
shared memory and prints it to the console.

This keeps repeating until we stop it.

sample output:
SIGALRM received(SR)
Random number: 1646505996896865000

SIGTERM received(S1)
message: 1646505996896865000
----------

SIGALRM received(ST)
time stamp: 1322316023570
time: 00:18:21

SIGTERM received(S1)
message: 00:18:21
----------

SIGALRM received(SR)
Random number: 16383351981391642026

SIGTERM received(S1)
message: 16383351981391642026
----------

SIGALRM received(ST)
time stamp: 1323407714009
time: 00:18:22

SIGTERM received(S1)
message: 00:18:22
----------

SIGALRM received(SR)
Random number: 3905357209429597252

SIGTERM received(S1)
message: 3905357209429597252
----------

SIGALRM received(ST)
time stamp: 1324607448605
time: 00:18:23

SIGTERM received(S1)
message: 00:18:23
----------

SIGALRM received(SR)
Random number: 16010548595079442757

SIGTERM received(S1)
message: 16010548595079442757
----------

SIGALRM received(ST)
time stamp: 1325789582173
time: 00:18:24

SIGTERM received(S1)
message: 00:18:24
----------

SIGALRM received(SR)
Random number: 8310832813630470293

SIGTERM received(S1)
message: 8310832813630470293
----------
