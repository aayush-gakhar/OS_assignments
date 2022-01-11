Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

make to compile.

./p1 , ./p2 , ./p3

1.
Normal dining philosopher's problem. There are 5 philosophers and 5 forks.
A philosopher needs two forks to eat. The fork should be to left and right.
We create 5 threads, 1 for each philosopher. We solve this using 6 semaphores.
One is for mutex which allows only one thread to access the critical sections of code.
Each philosopher also has a semaphore for whether he is eating.
Now we make a array for storing the current state of each philosopher.
Then {sleep -> take_fork_and_eat -> sleep -> put_fork} we iterate over this.
For each thread we check if left and right philosopher are not eating and then they can eat.


2.
There are 5 philosophers and 5 forks and 4 bowls. A philosopher needs one fork to eat.
They also need one bowl out of the four there are.
We create 5 threads, 1 for each philosopher. We also create 6 semaphores like previous.
We create a counter to count the number of bowls left on the table. 
Now for each thread we check if there are any bowls left.If the conditions are satisfied then
we allow the philosopher to eat and then decrement the counter.


3.
There are 5 philosophers and 5 forks. A philosopher needs two forks to eat.
They also need one bowl out of the four there are.
We create 5 threads, 1 for each philosopher. We also create 6 semaphores like previous.
We create a counter to count the number of bowls left on the table. 
Now for each thread we check if there are any bowls left and then 
check if left and right philosopher are not eating. If the conditions are satisfied then
we allow the philosopher to eat and then decrement the counter.
This also unlocks the semaphore of that philosopher.
they can then go into the put function.