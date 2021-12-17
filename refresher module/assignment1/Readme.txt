cd <path of assignment1 folder>

Run 'make'

then:
./q1 <source path> <destination path>

./q2 <a as a string of 32 char> <b as a string of 32 char>

./q3 

./q4 <String>

./q5 

example runs:


aayushgakhar@MacBook-Air ~ % cd /Users/aayushgakhar/Desktop/assignment1

aayushgakhar@MacBook-Air assignment1 % make

gcc q1.c -o q1
gcc q2.c -o q2
gcc q3.c -o q3
gcc q4.c -o q4
gcc q5.c -o q5

1:
aayushgakhar@MacBook-Air assignment1 % ./q1 /Users/aayushgakhar/Desktop/in1.txt /Users/aayushgakhar/Desktop/out.txt

2:
aayushgakhar@MacBook-Air assignment1 % ./q2 11111111111111111111111111111111 11111111111111111111111111111111

bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb

3:
aayushgakhar@MacBook-Air assignment1 % ./q3

Enter 0 to swap 2 int; 1 to swap 2 arrays: 0
Enter 2 space separated integers(a b): 1 4
integers before swap: a=1 b=4
integers after swap : a=4 b=1

aayushgakhar@MacBook-Air assignment1 % ./q3

Enter 0 to swap 2 int; 1 to swap 2 arrays: 1
Enter no of elements: 3
Enter 3 space separated elements elements of arr1: 1 2 3
Enter 3 space separated elements elements of arr2: 4 5 6
Swapping...
arr1 after swap: 4 5 6 
arr2 after swap: 1 2 3 

4:
aayushgakhar@MacBook-Air assignment1 % ./q4 asdfghjkl

reversed: lkjhgfdsa

5:
aayushgakhar@MacBook-Air assignment1 % ./q5

Enter the length of array: 4
Enter 4 space separated integers: 
10 20 30 40
Enter no to find index.To exit type -1: 10
Index: 0

Enter next no. (-1 for exit): 30
Index: 2

Enter next no. (-1 for exit): -1
