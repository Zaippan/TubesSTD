#include <iostream>
#include "list.h"
using namespace std;

int main(){
    listRuangan L;
    adrRuangan r;
    createListRuangan(L);

    r = createElemenRuangan("R001","MELATI 1",3,1,8);
    addRuangan(L,r);

    r = createElemenRuangan("R002", "MELATI 2", 3, 1, 8);
    addRuangan(L, r);

    r = createElemenRuangan("R003", "MELATI 3", 3, 1, 6);
    addRuangan(L, r);

    r = createElemenRuangan("R004", "ANGGREK 1", 2, 2, 6);
    addRuangan(L, r);

    r = createElemenRuangan("R005", "ANGGREK 2", 2, 2, 4);
    addRuangan(L, r);

    r = createElemenRuangan("R006", "KAMELIA 1", 1, 3, 4);
    addRuangan(L, r);

    r = createElemenRuangan("R007", "KAMELIA 2", 1, 3, 2);
    addRuangan(L, r);

    r = createElemenRuangan("R008", "ICU 1", 0, 3, 2);
    addRuangan(L, r);

    r = createElemenRuangan("R009", "VIP A", 1, 4, 2);
    addRuangan(L, r);

    r = createElemenRuangan("R010", "VIP B", 1, 4, 1);
    addRuangan(L, r);

    int pilih;
    pilih = -1;
    while(pilih!=0){
        menu();
        cin>>pilih;
        if(pilih == 1){
            string idpenginap;
            string namapenginap;
            string diagnosa;
            int lamainap;
            cout<<"Masukan Nama ID pasien: ";
            cin>>idpenginap;
            cout<<"Masukan Nama Pasien: ";
            cin>>namapenginap;
            cout<<"Masukan Diagnosa Pasien: ";
            cin>>diagnosa;
            cout<<"Berapa Hari Inapnya: ";
            cin>>lamainap;
            tampilRuangan(L);

            string idr;
            cout<<"Masukan ID Tempat Ruangan Pasien Menginap: ";
            cin>>idr;
            adrRuangan hasil;
            hasil = searchRuangan(L,idr);
            if(hasil!=nullptr){
                addPenginap(hasil,createElemenPenginap(idpenginap,namapenginap,diagnosa,lamainap));
                cout<<"Pasien telah diinput"<<endl;
            }else{
                cout<<"ID Ruangan Tidak Ditemukan"<<endl;
            }
        }else if(pilih == 2){
            tampilRuangan(L);
        }else if(pilih == 7){
            int pilihtampil;
            cout<<"1. Tampilkan Semua Kamar Dan Penghuninya\n";
            cout<<"2. Tampilkan Penghuni Salah Satu Kamar\n";
            cout<<"Pilihan: ";
            cin>>pilihtampil;
            if(pilihtampil==1){
                tampilRuanganbesertaPenghuni(L);
            }else if(pilihtampil == 2){
                tampilRuangan(L);
                string cekruangan;
                adrRuangan hasilcekkamar;
                cout<<"Masukan ID kamar yang ingin di cek penghuninya: ";
                cin>>cekruangan;
                hasilcekkamar = searchRuanganById(L,cekruangan);
                if(hasilcekkamar != nullptr){
                    adrPenginap hasilpenginap = hasilcekkamar->firstPenginap;
                    if(hasilpenginap == nullptr){
                        cout << "Ruangan ini belum punya penghuni.\n";
                    }else{
                        cout << "\nDaftar penghuni kamar " << cekruangan << ":\n\n";
                        while (hasilpenginap != nullptr){
                        cout << "Nama      : " << hasilpenginap->info.namapenginap <<endl;
                        cout << "ID        : " << hasilpenginap->info.idpenginap <<endl;
                        cout << "Diagnosa  : " << hasilpenginap->info.diagnosa << endl;
                        cout << "Lama inap : " << hasilpenginap->info.lamainap << " hari\n";
                        cout << "-----------------------------\n";
                            hasilpenginap = hasilpenginap->next;
                        }
                    }
                }else{
                    cout << "ID kamar " << cekruangan << " tidak ditemukan.\n";
                }
            }

        }
    }

}

