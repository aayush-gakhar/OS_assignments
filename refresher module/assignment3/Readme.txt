cd <path of assignment3 folder>

Run 'make'

then:
./q1.sh MM YYYY

./q2.sh <add/sub/mul/div/exp> <space separated operands>

./q3a

./q3b

./q4



example runs:

aayushgakhar@MacBook-Air ~ % cd /Users/aayushgakhar/Desktop/assignment3

aayushgakhar@MacBook-Air assignment3 % make

gcc q3a.c -o q3a
gcc q3b.c -o q3b
gcc q4.c -o q4


#########################################################
1:
aayushgakhar@MacBook-Air assignment3 % ./q1.sh 2 2032
   February 2032      
Su Mo Tu We Th Fr Sa  
 1  2  3  4  5  6  7  
 8  9 10 11 12 13 14  
15 16 17 18 19 20 21  
22 23 24 25 26 27 28  
29

#########################################################
2:
aayushgakhar@MacBook-Air assignment3 % ./q2.sh add 1 2 3 4

10

#########################################################
3:

aayushgakhar@MacBook-Air assignment3 % ./q3a or ./q3b

BST / AVL tree:
I -> insert x
D -> delete x
P -> print inorder
E -> exit
I
Enter x: 10
done
I
Enter x: 20
done
I
Enter x: 30
done
P
Inorder traversal: 10 20 30 

D
Enter x: 10
done
P
Inorder traversal: 20 30 

E

#########################################################
4:
aayushgakhar@MacBook-Air assignment3 % ./q4

Enter no of elements: 5
Enter space separated 5 elements: 45 25 75 15 35
Enter 0 for selection sort, 1 for bubblesort: 0
15 25 35 45 75
