#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <math.h>
using namespace std;

#define Top(S) (S).Top
#define info(S) (S).info

#define head(Q) (Q).head
#define tail(Q) (Q).tail
#define infoQ(Q) (Q)->infoQ
#define next(Q) (Q)->next


typedef char infotype;

struct stack{
    infotype info[15];
    int Top;
};

typedef int infotype2;

struct stack2{
    infotype2 info[15];
    int Top;
};

struct data {
    string Nama;
    string Ekspresi;
    int hasil;
};

typedef struct element *adr;
struct element{
    data infoQ;
    adr next;
};

struct listQ{
    adr head;
    adr tail;
};

// Bagian Adhie Haqqi R.S

void createStack (stack &S);
bool isEmpty (stack S);
bool isFull (stack S);
void push (stack &S, infotype x);
char pop (stack &S);
int getAscii (char c);
bool operand (char c);
int operators (char c);
string InfixtoPostfix (string infix, stack S);
void showsStack (stack S);

void createStack2(stack2 &S);
void push2 (stack2 &S, infotype2 x);
char pop2 (stack2 &S);
int calculate_Postfix(string  post_exp);

// Bagian Nasywan

void Create_Queue(listQ &Q);
void Create_Element(string nama,string ekspresi, adr &pQ);
void Enqueue(listQ &Q, adr pQ);
void Dequeue(listQ &Q, adr &pQ);
void ShowQueue(listQ Q);
int Select_Menu();

#endif // STACK_H_INCLUDED
