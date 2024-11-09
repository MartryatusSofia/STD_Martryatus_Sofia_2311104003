# include <iostream>

using namespace std;

typedef char infotype;

struct stack{
    infotype info[15];
    int Top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
int pop(stack &S);
void printInfo(stack S);



