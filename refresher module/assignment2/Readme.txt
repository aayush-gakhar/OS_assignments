cd <path of assignment2 folder>

Run 'make'

then:
./q1

./q2a

./q2b

./q2c1

./q2c2

./q3

./q5



example runs:

aayushgakhar@MacBook-Air ~ % cd /Users/aayushgakhar/Desktop/assignment2

aayushgakhar@MacBook-Air assignment2 % make

gcc q1.c -o q1
gcc q2a.c -o q2a
gcc q2b.c -o q2b
gcc q2c1.c -o q2c1
gcc q2c2.c -o q2c2
gcc q3.c -o q3
gcc q5.c -o q5

#########################################################
1:
aayushgakhar@MacBook-Air assignment2 % ./q1

Enter no of rows: 3
Enter space separated lengths of 3 columns: 1 2 3
parr is the required array

#########################################################
2:
aayushgakhar@MacBook-Air assignment2 % ./q2a

A 12 2020 cse
B 15 2021 csd
C 13 2024 ece

#########################################################
aayushgakhar@MacBook-Air assignment2 % ./q2b

A 12 2020 cse
B 15 2021 csd
C 13 2024 ece

#########################################################
aayushgakhar@MacBook-Air assignment2 % ./q2c1

Stack:
U -> push x
O -> pop x
P -> peek
X -> exit
:U
Enter x: 1

:P
peek: 1

:U
Enter x: 3

:O
popped: 3 

:O
popped: 1 

:X

#########################################################
aayushgakhar@MacBook-Air assignment2 % ./q2c2

Queue:
E -> enqueue x
D -> dequeue x
P -> peek
X -> exit
:E
Enter x: 1

:E
Enter x: 2

:E
Enter x: 3

:D
popped: 1

:D
popped: 2

:D
popped: 3

:D
popped: Queue empty

:X

#########################################################
3:
aayushgakhar@MacBook-Air assignment1 % ./q3

a -> add
s -> sub
m -> mul
d -> div
e -> exp
x -> exit
:a
Enter 2 nos to add: 3 2
5

:s
Enter 2 nos to sub: 3 2
1

:m
Enter 2 nos to mul: 3 2
6

:d
Enter 2 nos to div: 3 2
1

:e
Enter 2 nos to exp: 3 2
9

:x

#########################################################
5:
aayushgakhar@MacBook-Air assignment2 % ./q5

Enter no of elements: 5
Enter space separated 5 elements: 45 25 75 15 35
Enter 0 for selection sort, 1 for bubblesort: 0
15 25 35 45 75
