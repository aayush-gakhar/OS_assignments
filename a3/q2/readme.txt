Name : Aayush Gakhar
Roll no : 2020006
Section : A
Branch : CSE

First we generate a random array of 50 strings.

socket:
in p1.
we get the server file descriptor server_fd = socket(AF_INET, SOCK_STREAM, 0);
Then we use setsockopt to change the socket options of the corresponding server_fd.
Then we use a struct sockaddr_in and bind the socket to a particular port.
struct sockaddr_in {
    short            sin_family;
    unsigned short   sin_port;
    struct in_addr   sin_addr;
    char             sin_zero[8];
};
Then listen function is used to listen for client connections.
and accept function takes the first connection request from client and connects to it.
Then we use a for loop to iterate over out string array.
We concatenate 5 strings in each iteration and use send() function to send the concatenated
string to p2.Then we use the read function to wait for message back from p2.

Now p2 uses socket() and connect() function to connect to the port number. Then it reads the 
message from p1 and then sends back the max ID it recieved.


fifo:
in p1.
we create a fifo using mkfifo.
Then we use open() function to get the file descriptor for the fifo.
We create out message and write() it into the fifo.
then we close the fifo for p2 then again open it and read the message p2 sent us.

in p2 again we open() the fifo and read the message. then write back the id.


queue:
in p1.
we create a key using ftok().
then we create messageID using msgget().
for sending messages we use struct msgbuffer.
struct msgbuffer {
    long msgtype;
    char msgtext[100]; 
};
we store out message in msgtext and use msgsnd() to send it to queue.
then we use msgrcv() to get message from p2. we can use different numbers 
in msgtype to selectively recieve messages of that type. so from p1 to p2 
msgtype is 1 and back is 4.

in p2 we open() the queue and get the msgid. then we receive the message.
after that we send back the maxID.
