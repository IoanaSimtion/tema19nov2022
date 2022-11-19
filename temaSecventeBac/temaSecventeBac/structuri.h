using namespace std;
#include <iostream>
#include <string.h>
#pragma once

struct Oras {
	char tara[30], nume_oras[20];
	int nr_locuitori_oras;
	float suprafata_oras;
};



struct Data {
	int zi, luna, an;
};

struct Film {
	char nume_film[40], gen_film[20];
	Data difuzare;
	int suma;

};



struct Triunghi {
	float l1, l2, l3;
};



struct DataN {
	int zi, luna, an;
};

struct Elev {
	char nume[21];
	DataN dn;
};



struct Fractie {
	int numitor, numarator;
};



struct ElevL {
	char l1[30], l2[30];
	char nume[40];
};



struct Punct {
	float x, y;
};



struct Fractie2 {
	int x, y;
};



struct Medalie {
	char nume[20], judet[30], nume_medalie[10];
	int an;
};



struct DataC {
	int zi, luna, an;
};

struct Consultatie {
	char pacient[20], cabinet[40];
	DataC data_cons;
};



struct DataE {
	int zi, luna, an;
};

struct Excursie {
	char nume[30], oras[40], tara[30];
	DataE data_exc;
};



struct Angajat {
	char nume[30], functie[20], departament[30];
	int salariu_baza, ora_sp, nr_ore_sp, total_sporuri, salariu_obt;
};



struct Student {
	char nume[20], grupa[10], bursa[3];
	int an_studiu, nr_credite;
};



struct Examinare {
	char tip_examinare[10], disciplina[20];
	int nr_credite;
};

struct Stud {
	char nume[20], grupa[10];
	Examinare e[10];
	int an_studiu, nr_total_credite;
};



struct DataSpect {
	int zi, luna, an;
};

struct Spectacol {
	char denumire[30], autor[20];
	DataSpect data_sp;
	int nr_bilete, pret;
};



struct DataConferinta {
	int zi, luna, an;
};

struct Conferinta {
	char denumire[30], oras[20], tara[25], tematica[20];
	DataConferinta data_conf;
	char nume[20], tip_inreg[20];
};



struct Melodie {
	char nume[30], autor[20], tara[20];
	int loc_top, an_top;
};



struct ElevMedii {
	int matricol;
	float med1, med2;
};



struct ElevNota {
	char nume[20];
	float nota;
};



struct Cuvant {
	char cuv[30];
	int frecv;
};
