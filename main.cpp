#include "stack.h"

int main()
{
    int N,i,pilihan = 0;
    adr pQ;
    string nama,ekspresi;

    listQ Q;
    listQ Q2;

    stack S;

    Create_Queue(Q);
    Create_Queue(Q2);

    createStack(S);

    pilihan = Select_Menu();

    while (pilihan != 0){
        if (pilihan == 1){
            cout << "Jumlah Data yang akan ditambahkan: "; cin >> N; cout << endl;
            i = 0;
            while (i < N){
                cout << "Masukkan Nama: "; cin >> nama;
                cout << "Masukkan Ekspresi: "; cin >> ekspresi;
                Create_Element(nama,ekspresi,pQ);
                Enqueue(Q,pQ);
                i++;
                cout << endl;
            }
        }else if (pilihan == 2){
            cout << "Pilih nama yang ingin di ganti menjadi postfix : "; cin >> nama;
            Dequeue(Q,pQ);
            if ((pQ->infoQ.Nama) == nama){
                string op = InfixtoPostfix(pQ->infoQ.Ekspresi, S);
                cout << "Setelah Konversi: ";
                cout << op << endl;
                pQ->infoQ.hasil = calculate_Postfix(op);
                cout << "Hasil: " << calculate_Postfix(op) << endl;
                Enqueue(Q,pQ);
            }
        }else if (pilihan == 3){
            ShowQueue(Q);
        }
        string tanya;
        cout << "Kembali ke menu utama (Y) atau Keluar Program (N) ? ";
        cin >> tanya;
        if(tanya=="Y"||tanya=="y")
        {
            cout << endl;
            pilihan = Select_Menu();
        }
        else if (tanya=="N"||tanya=="n")
        {
            cout<<"Anda telah keluar dari program"<<endl;
            pilihan = 0;
        }else{
            cout << "Error" <<endl;
            cout << "Memaksa keluar dari program" << endl;
            cout<<"Anda telah keluar dari program"<<endl;
            pilihan = 0;
        }
    }





    return 0;
}
