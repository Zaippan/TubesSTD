#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct elemenRuangan *adrRuangan;
typedef struct elemenPenginap *adrPenginap;

struct Ruangan {
    string idruangan;
    string namaruangan;
    int kelas;
    int lantai;
    int kapasitas;
};

struct Penginap {
   string idpenginap;
   string namapenginap;
   string diagnosa;
   int lamainap;
};

struct elemenRuangan {
    Ruangan    info;
    adrRuangan next;
    adrRuangan prev;
    adrPenginap firstPenginap;
};

struct elemenPenginap {
    Penginap      info;
    adrPenginap   next;
    adrPenginap   prev;
};

struct listRuangan {
    adrRuangan first;
    adrRuangan last;
};


void createListRuangan(listRuangan &L);
bool isEmptyRuangan(listRuangan L);
bool isEmptyPenginap(adrRuangan p);
adrRuangan createElemenRuangan(string idruangan, string namaruangan, int kelas, int lantai, int kapasitas);
adrPenginap createElemenPenginap(string idpenginap, string namapenginap, string diagnosa, int lamainap);
void addRuangan(listRuangan &L, adrRuangan p);
void addPenginap(adrRuangan &p, adrPenginap q);
void menu();
void tampilRuangan(listRuangan L);
adrRuangan searchRuangan(listRuangan L, string idruangan);
void tampilRuanganbesertaPenghuni(listRuangan L);
adrRuangan searchRuanganById(listRuangan L, string idruangan);

#endif // LIST_H_INCLUDED
