
void E1(int pid_t);
void E2(int pid_t);

struct msgbuf {
    long mtype;
    char mtext[100];
};
