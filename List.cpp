#include <iostream>
#include "list.h"

using namespace std;

void menu(){
        cout << "\n=== MENU SISTEM RAWAT INAP ===\n";
        cout << "1. Input pasien\n";
        cout << "2. Tampilkan semua ruangan\n";
        cout << "3. Cari ruangan tempat pasien menginap\n";
        cout << "4. Hapus pasien\n";
        cout << "5. Hapus ruangan\n";
        cout << "6. Sorting Ruangan Berdasarkan Kelas/Lantai\n";
        cout << "7. Tampilkan Penghuni Kamar\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
}

void createListRuangan(listRuangan &L){
    L.first = nullptr;
    L.last  = nullptr;
}
bool isEmptyRuangan(listRuangan L){
    return L.first == nullptr;
}
bool isEmptyPenginap(adrRuangan p){
    return p->firstPenginap == nullptr;
}
adrRuangan createElemenRuangan(string idruangan, string namaruangan, int kelas, int lantai, int kapasitas){
    adrRuangan p;
    p = new elemenRuangan;
    p->info.idruangan = idruangan;
    p->info.namaruangan = namaruangan;
    p->info.kelas = kelas;
    p->info.lantai = lantai;
    p->info.kapasitas = kapasitas;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstPenginap = nullptr;

    return p;
}
adrPenginap createElemenPenginap(string idpenginap, string namapenginap, string diagnosa, int lamainap){
    adrPenginap p;
    p = new elemenPenginap;
    p->info.idpenginap = idpenginap;
    p->info.namapenginap = namapenginap;
    p->info.diagnosa = diagnosa;
    p->info.lamainap = lamainap;
    p->next = nullptr;
    p->prev = nullptr;

    return p;
}
void addRuangan(listRuangan &L, adrRuangan p){
    if (isEmptyRuangan(L)){
        L.first = p;
        L.last  = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}
void addPenginap(adrRuangan &p, adrPenginap q){
    adrPenginap k;
    if (isEmptyPenginap(p)){
        p->firstPenginap = q;
    } else if (p->firstPenginap->next == nullptr){
        p->firstPenginap->next = q;
        q->prev = p->firstPenginap;
    } else {
        k = p->firstPenginap;
        while (k->next != nullptr){
            k = k->next;
        }
        k->next = q;
        q->prev = k;
    }
}
void tampilRuangan(listRuangan L){
    adrRuangan p = L.first;
    while (p != nullptr){
        cout << "\nID Ruangan : " << p->info.idruangan << endl;
        cout << "Nama       : " << p->info.namaruangan << endl;
        cout << "Kelas      : " << p->info.kelas << endl;
        cout << "Lantai     : " << p->info.lantai << endl;
        cout << "Kapasitas  : " << p->info.kapasitas << " kasur\n";
        p = p->next;
    }
}
#include "list.h"
using namespace std;

void tampilRuanganbesertaPenghuni(listRuangan L){
    adrRuangan p = L.first;
    while (p != nullptr) {
        cout << "\nID Ruangan : " << p->info.idruangan << endl;
        cout << "Nama       : " << p->info.namaruangan << endl;
        cout << "Kelas      : " << p->info.kelas << endl;
        cout << "Lantai     : " << p->info.lantai << endl;
        cout << "Kapasitas  : " << p->info.kapasitas << " bed\n";
        adrPenginap q = p->firstPenginap;
        if (q == nullptr) {
            cout << "  (Belum ada pasien)\n";
        } else {
            cout << "  Daftar pasien:\n";
            while (q != nullptr) {
                cout << "    - " << q->info.idpenginap << " | "
                     << q->info.namapenginap
                     << " (" << q->info.diagnosa
                     << ", " << q->info.lamainap << " hari)\n";
                q = q->next;
            }
        }
        p = p->next;
    }
}

adrRuangan searchRuangan(listRuangan L, string idruangan){
    adrRuangan p;
    p = L.first;
    while(p!=nullptr){
        if(p->info.idruangan == idruangan){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
adrRuangan searchRuanganById(listRuangan L, string idruangan) {
    adrRuangan p;
    p = L.first;
    while (p != nullptr){
        if(p->info.idruangan == idruangan){
        return p;
    }
    p = p->next;
    }
    return nullptr;
}


