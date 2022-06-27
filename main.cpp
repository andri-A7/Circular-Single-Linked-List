/*
 * NAMA  : ANDRI PEBRIYANTO
 * NIM   : 21.11.3971
 * KELAS : 21-IF-O3
 * 
 * PRAKTIKUM 1O // STRUKTUR DATA
 */
#include <iostream>

using namespace std;
int jumlah = 0;
void reverse(int tahunTerbit);
struct Buku
{
    string judul, pengarang;
    int tahunTerbit;

	Buku* next;
};
Buku* head, * tail, *cur, *newNode , *del,*before,*urut;
void createSingleLinkedList(string Judul, string pengarang,int tB)
{
        head = new Buku();
        head->judul = Judul;
        head->pengarang = pengarang;
        head->tahunTerbit = tB;
        tail = head;
        tail->next = head;
    
}
void addFirst(string judul, string pengarang, int tB) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

int countSingleLinkedList()
{
    
    if (head == NULL)
    {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else
    {
        
        cur = head;
        while (cur->next != head)
        {
            jumlah++;
            cur = cur->next;
        }
        return jumlah;
    }
    
}
void addLast(string judul, string pengarang, int tB) {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        newNode = new Buku();
        newNode->judul = judul;
        newNode->pengarang = pengarang;
        newNode->tahunTerbit = tB;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

// add Middle
void addMiddle(string judul,string pengarang,int tB, int posisi)
{
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        if (posisi == 1) {
            cout << "Posisi satu bukan posisi tengah!!!" << endl;
        }
        else {
            newNode = new Buku();
            newNode->judul = judul;
            newNode->pengarang = pengarang;
            newNode->tahunTerbit = tB;

            // tranversing
            int nomor = 1;
            cur = head;
            while (nomor < posisi - 1)
            {
                cur = cur->next;
                nomor++;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
    }
}

// remove First
void removeFirst() {
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        del = head;
        head = head->next;
        tail->next = head;
        delete del;
    }
}

// remove last
void removeLast()
{
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        del = tail;
        cur = head;
        while (cur->next != tail) {
            cur = cur->next;
        }
        tail = cur;
        tail->next = head;
        delete del;
    }
}

// remove middle
void removeMiddle(int posisi)
{
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        // tranversing
        int nomor = 1;
        cur = head;
        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }
        del = cur->next;
        cur->next = del->next;
        delete del;
    }
}
void changeFirst(string judul, string pengarang, int tB)
{
    head->judul = judul;
    head->pengarang = pengarang;
    head->tahunTerbit = tB;
}
void changeLast(string judul, string pengarang, int tB)
{
    tail->judul = judul;
    tail->pengarang = pengarang;
    tail->tahunTerbit = tB;
}
void changeMiddle(string judul, string pengarang, int tB, int posisi)
{
    if (posisi < 1 || posisi > countSingleLinkedList())
    {
        cout << "Posisi Diluar Jangkauan" << endl;
    }
    else if (posisi == 1 || posisi == countSingleLinkedList())
    {
        cout << "Posisi bukan ditengah" << endl;
    }
    else
    {
        cur = head;
        int nomor = 1;
        while (nomor < posisi)
        {
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->pengarang = pengarang;
        cur->tahunTerbit = tB;
    }
}
void search()  
{   
    int item,i=0,flag=1;  
    cur = head;   
    if(cur == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("masukan data yang akan dicari berdasarkan tahun Terbit  :\n");   
        scanf("%d",&item);  
        if(cur ->tahunTerbit == item)  
        {  
        cout << "\n\n";
		printf(" Data ada ke - %d ", jumlah+1);cout<<endl;
        cout << "________________________________________________________________" << endl;
        cout << "| Judul\t\t|\tPengarang\t|\tTahun Terbit\t|" << endl;
        cout << "|_______________________________________________________________|" << endl;
        cout << endl;              
        cout << "| " << cur->judul << "\t| " << cur->pengarang << "\t\t| " << cur->tahunTerbit<<"\t\t\t|"<< endl;
        cout << "_________________________________________________________________" << endl;
        flag = 0;
        cout << endl;  
        return; 
        }  
        else   
        {  
        while (cur->next != head)  
        {  

            if(cur->tahunTerbit == item)  
            {  
                cout << "\n\n";
		        printf(" Data ada ke - %d ", jumlah+1);cout<<endl;
                 cout << "________________________________________________________________" << endl;
                 cout << "| Judul\t\t|\tPengarang\t|\tTahun Terbit\t|" << endl;
                 cout << "|_______________________________________________________________|" << endl;
                 cout << endl;
                 
                 cout << "| " << cur->judul << "\t| " << cur->pengarang << "\t\t| " << cur->tahunTerbit<<"\t\t\t|"<< endl;
                 cout << "_________________________________________________________________" << endl;
                 flag = 0;
                 cout << endl;  
                 return;
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            cur = cur-> next;  
        }  
        }  
        if(flag != 0)  
        {  
            printf("create data dulu !!");  
            return;  
        }  
    }     
          
}
void reverse()
{
    cur = head;
    urut = NULL;
    while (cur != NULL)
    {
        cur->next = cur;cur->next;
        cur->tahunTerbit;cur->next = urut;
        urut = cur;
        cur = cur->next;
    }
    head = urut;
}
void printCircular()
{
    if (head == NULL) {
        cout << "Buat Linked List dulu!!" << endl;
    }
    else {
        cout << "\n\n";
        cout << "Data Mahasiswa " << countSingleLinkedList()<<endl;
        cout << "________________________________________________________________" << endl;
        cout << "| Judul\t\t|\tPengarang\t|\tTahun Terbit\t|" << endl;
        cout << "|_______________________________________________________________|" << endl;
        cur = head;
        
        while (cur->next != head)
        {
            // print
           
            cout << "| " << cur->judul<< "\t| " << cur->pengarang<< "\t\t| " << cur->tahunTerbit << "\t\t\t|" << endl;
            cur = cur->next;
        }

        cout << "| " << cur->judul << "\t| " << cur->pengarang << "\t\t| " << cur->tahunTerbit<<"\t\t\t|"<< endl;
        cout << "_________________________________________________________________" << endl;
    }
}

int main()

{
     
    int pilihan;
    createSingleLinkedList("Pasti Mumet", "Munaroh", 2018); printCircular();cout << "\n\n" << endl;
    addFirst("Informatika", "Juned Janedi", 2010);printCircular();cout << "\n\n" << endl;
    addLast("Ayok Masuk", "Maimunah", 2001);cout << "\n\n" << endl;
    printCircular();
    cout << "CIRCULAR LINKED LIST\n\n";
    cout <<"1. seraching data sinih tod\n";
    cout <<"2. Urutkn data berdasarkan Tahunterbit\n";

    cin >>pilihan;
    switch(pilihan)
    {
        case 1:
        {
            
            search();
            break;
        }
        case 2:
        {
            removeLast();
            addFirst("Ayok Masuk", "Maimunah", 2001);cout << "\n\n" << endl;
            printCircular();
            break;
        }
    }
}
