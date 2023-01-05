#include "stack.h"

void createStack (stack &S)
{
    Top(S) = -1;
}

bool isEmpty (stack S)
{
    if (Top(S) == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull (stack S)
{
    if (Top(S) == 14){
        return true;
    }else{
        return false;
    }
}

void push (stack &S, infotype x)
{
    if (!isFull(S)){
        Top(S)++;
        info(S)[Top(S)] = x;
    }else{
        cout << "Array Penuh" << endl;
    }
}

char pop (stack &S)
{
    infotype x;
    x = info(S)[Top(S)];
    Top(S) = Top(S)-1;
    return x;
}

int getAscii (char c)
{
    c = int(c);

    return c;
}

bool operand (char c)
{
    int i;
    i = getAscii (c);
    if (i >= 48 and i <= 57){
        return true;
    }
    return false;
}

int operators (char c)
{
    if (c == '+' || c == '-'){
        return 1;
    }else if (c == '*' || c == '/'){
        return 2;
    }else if (c == '^'){
        return 3;
    }
    return 0;
}

string InfixtoPostfix (string infix, stack S)
{
    int i;
    char c;
    string postfix;
    infotype pops;

    postfix = "";
    i = 0;
    while (infix[i] != '.'){

        c = infix[i];
        if (operand (c)){
            postfix += c;
        }else{

            if (c == '('){
                push (S,c);

            }else if( c == ')'){

                while (info(S)[Top(S)] != '('){

                    pops = pop (S);
                    postfix += pops;
                }

                pops = pop (S);

            }else{
                while (!isEmpty (S) && operators (infix[i]) <= operators (S.info[S.Top])){
                    pops = pop (S);
                    postfix += pops;

                }

                push (S,c);
            }
        }
        i++;

    }


    while (!isEmpty (S)){
        pops = pop (S);
        postfix += pops;
    }

    return postfix;
}

void showsStack (stack S)
{
    for (int i = Top(S); i>0;i--){
        cout << info(S)[i];
    }
}


void Create_Queue(listQ &Q){
    head(Q) = NULL;
    tail(Q) = NULL;
}

void Create_Element(string nama, string ekspresi, adr &pQ){
    data P;
    P.Nama = nama;
    P.Ekspresi = ekspresi;
    pQ = new element;
    infoQ(pQ) = P;
    next(pQ) = NULL;
}

void Enqueue(listQ &Q, adr pQ){
    if (head(Q) == NULL) {
        head(Q) = pQ;
        tail(Q) = pQ;
        next(head(Q)) = head(Q);
    }else {
        next(tail(Q)) = pQ;
        tail(Q) = pQ;
        next(tail(Q)) = head(Q);
    }
}

void Dequeue(listQ &Q, adr &pQ){
    if (head(Q) == NULL) {
        cout << "Queue Empty" << endl;
    }else if (head(Q) == tail(Q)) {
        pQ = head(Q);
        head(Q) = NULL;
        tail(Q) = NULL;
    }else {
        pQ = head(Q);
        head(Q) = next(pQ);
        next(pQ) = NULL;
        next(tail(Q)) = head(Q);
    }
}

void ShowQueue(listQ Q){
    adr pQ;
    pQ = head(Q);
    do{
        cout << "Nama: " << infoQ(pQ).Nama << endl;
        cout << "Ekspresi: " << infoQ(pQ).Ekspresi << endl;
        cout << "Hasil: " << infoQ(pQ).hasil << endl << endl;
        pQ = next(pQ);
    }while(pQ != head(Q));
}

// The function calculate_Postfix returns the final answer of the expression after calculation
int calculate_Postfix(string  post)
{
    stack2 S;
    createStack2 (S);
    int len = post.length();
    for (int i = 0; i < len; i++)
    {
        if (operand(post[i]))
        {
            push2( S,post[i] - '0');
        }
        else
        {
            int a = info(S)[Top(S)];
            pop2(S);
            int b = info(S)[Top(S)];
            pop2(S);
            switch (post[i])
            {
                case '+': // addition
                          push2(S,b + a);
                          break;
                case '-': // subtraction
                          push2(S,b - a);
                          break;
                case '*': // multiplication
                          push2(S,b * a);
                          break;
                case '/': // division
                          push2(S,b / a);
                          break;
                case '^': // exponent
                          push2(S,pow(b,a));
                          break;
            }
        }
    }
    return S.info[Top(S)];
}

void createStack2(stack2 &S)
{
    Top(S) = -1;
}

void push2 (stack2 &S, infotype2 x)
{
    if (Top(S) != 14){
        Top(S)++;
        info(S)[Top(S)] = x;
    }else{
        cout << "Array Penuh" << endl;
    }
}
char pop2 (stack2 &S)
{
    infotype x;
    x = info(S)[Top(S)];
    Top(S) = Top(S)-1;
    return x;
}

int Select_Menu(){
    cout << "=================== MENU ===================" << endl;
    cout << "1. Menambah data baru" << endl;
    cout << "2. Tampilkan operasi infix to postfix dan hasilnya" << endl;
    cout << "3. Tampilkan isi queue" << endl;
    cout << "0. Exit" << endl << endl;
    cout << "Pilih Menu: ";
    int x = 0;
    cin >> x;
    cout << endl;

    return x;
}
