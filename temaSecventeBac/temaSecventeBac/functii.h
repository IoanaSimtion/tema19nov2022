using namespace std;
#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>
#include "structuri.h"
#pragma once

//todo functie ce citeste datele unui oras

void citireDateOras(Oras o[], int& n) {
	ifstream f("dateOrase.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> o[i].nume_oras;
		f >> o[i].tara;
		f >> o[i].nr_locuitori_oras;
		f >> o[i].suprafata_oras;
	}
}

//todo functie ce calculeaza densitatea populatiei

float densitatePop(int loc, float supr) {
	float dens = loc / supr;
	return dens;
}

//todo functie ce afiseaza numele oraselor si tarilor lor, pentru toate orasele care au o densitate mai mare de 15 loc/km2

void afisareOrase(Oras o[], int n) {
	for (int i = 0; i < n; i++) {
		if (densitatePop(o[i].nr_locuitori_oras, o[i].suprafata_oras) > 15) {
			cout << o[i].nume_oras << ' ' << o[i].tara << endl;
		}
	}
}

//todo functie ce verifica daca un film se incadreaza in categoria ceruta

bool categorie(Film f) {
	if (strcmp(f.gen_film, "comedie") || strcmp(f.gen_film, "istoric") == 0) {
		if (f.difuzare.an == 2018 && f.difuzare.luna == 3) {
			return true;
		}
	}
	return false;
}

//todo functie ce returneaza suma incasata de cinematograf

int suma(Film f[]) {
	int s = 0;
	for (int i = 0; i < 1000; i++) {
		if (categorie(f[i])) {
			s = s + f[i].suma;
		}
	}
	return s;
}

//todo functie ce citeste datele desrpre n triunghiuri

void citireDateTriunghiuri(Triunghi t[], int& n, float& x, float& y) {
	ifstream f("dateTriunghiuri.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> t[i].l1;
		f >> t[i].l2;
		f >> t[i].l3;
	}
	f >> x >> y;
}

//todo functie ce returneaza aria unui triunghi

float arie(int a, int b, int c) {
	float p = (a + b + c) / 3;
	float aria = sqrt(p * (p - a) * (p - b) * (p - c));
	return aria;
}

//todo functie ce afiseaza laturile triunghiului pentru care aria apartine intervalului [x,y]

void afisareLaturi(Triunghi t[], int n, float x, float y) {
	for (int i = 0; i < n; i++) {
		if (arie(t[i].l1, t[i].l2, t[i].l3) >= x && arie(t[i].l1, t[i].l2, t[i].l3) <= y) {
			cout << t[i].l1 << ' ' << t[i].l2 << ' ' << t[i].l3 << '*';
		}
	}
}

//todo functie ce citeste datele despre un elev

void citireDateElev(Elev& e) {
	ifstream f("dateElev.txt");
	f >> e.nume;
	f >> e.dn.zi;
	f >> e.dn.luna;
	f >> e.dn.an;
}

void afisareElev(Elev e) {
	if (e.dn.an == 2000) {
		cout << e.nume;
	}
	else {
		cout << e.dn.zi << ' ' << e.dn.luna << ' ' << e.dn.an;
	}
}

//todo functie ce citeste n fractii

void citireFractii(Fractie x[], int& n) {
	ifstream f("fractii.txt");
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> x[i].numarator;
		f >> x[i].numitor;
	}

}

//todo functie ce determina nr de fractii cu numitorul minim

int nrFractii(Fractie x[], int n) {
	int min = x[0].numitor, ct = 1;
	for (int i = 1; i < n; i++){
		if (x[i].numitor < min) {
			min = x[i].numitor;
			ct = 1;
		}
		else {
			if (x[i].numitor == min) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce determina nr de elevi care studiaza limba engleza ca prima sau a doua limba

int nrEleviEngleza(ElevL e[]) {
	int ct = 0;
	for (int i = 0; i < 30; i++) {
		if (strcmp(e[i].l1, "engleza") == 0 || strcmp(e[i].l2, "engleza") == 0) {
			ct++;
		}
	}
	return ct;
}

//todo functie ce citeste coordonatele a doua puncte

void citireCoordonate(Punct& A, Punct& B) {
	ifstream f("coordonate.txt");
	f >> A.x >> A.y;
	f >> B.x >> B.y;
}

//todo functie ce determina coordonatele mijlocului

void coordonateMijloc(Punct& C, Punct A, Punct B) {
	C.x = (A.x + B.x) / 2;
	C.y = (A.y + B.y) / 2;
}

//todo functie ce citeste 2 fractii

void citire2Fractii(Fractie2& f1, Fractie2& f2) {
	ifstream f("dateFractii.txt");
	f >> f1.x >> f1.y;
	f >> f2.x >> f2.y;
}

//todo functie ce insumeaza 2 fractii

void insumareFractii(Fractie2& f, Fractie2 f1, Fractie2 f2) {
	if (f1.y != f2.y) {
		f2.x = f2.x * f1.y;
		f1.y = f1.y * f2.y;
		f1.x = f1.x * f2.y;
		f2.y = f2.y * f1.y;
	}
	f.x = f1.x + f2.x;
	f.y = f1.y;
}

//todo functie ce determina nr de medalii de aur obtinute

int nrMedaliiAur(Medalie sp[]) {
	int ct = 0;
	for (int i = 0; i < 500; i++) {
		if (strcmp(sp[i].judet, "Iasi") == 0 && sp[i].an == 2019) {
			if (strcmp(sp[i].nume_medalie, "aur") == 0) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce determina nr de medalii de argint obtinute

int nrMedaliiArgint(Medalie sp[]) {
	int ct = 0;
	for (int i = 0; i < 500; i++) {
		if (strcmp(sp[i].judet, "Iasi") == 0 && sp[i].an == 2019) {
			if (strcmp(sp[i].nume_medalie, "argint") == 0) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce determina nr de medalii de bronz obtinute

int nrMedaliiBronz(Medalie sp[]) {
	int ct = 0;
	for (int i = 0; i < 500; i++) {
		if (strcmp(sp[i].judet, "Iasi") == 0 && sp[i].an == 2019) {
			if (strcmp(sp[i].nume_medalie, "bronz") == 0) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce afiseaza numele pacientilor programati pentru consultatii la data de 10 august 2019

void afisarePacienti(Consultatie c[], int& nr) {
	for (int i = 0; i < 100; i++) {
		if (strcmp(c[i].cabinet, "stomatologie") == 0) {
			if (c[i].data_cons.zi == 10 && c[i].data_cons.luna == 8 && c[i].data_cons.an == 2019) {
				cout << c[i].pacient << endl;
				nr++;
			}
		}
	}
}

//todo functie ce afiseaza destinatiile

void afisareDestinatii(Excursie e[], char numed[], bool& excursii) {
	for (int i = 0; i < 300; i++) {
		if (strcmp(numed, e[i].nume) == 0) {
			cout << e[i].oras << ' ' << e[i].tara << ' ' << e[i].data_exc.zi << ' ' << e[i].data_exc.luna << ' ' << e[i].data_exc.an << endl;
			excursii = 1;
		}
	}
}

//todo functie ce completeaza campul salariu_obt

void completareCamp(Angajat a[]) {
	for (int i = 0; i < 300; i++) {
		a[i].salariu_obt = a[i].salariu_baza + a[i].total_sporuri + a[i].ora_sp * a[i].nr_ore_sp;
	}
}

//todo functie ce returneaza salariului de valoare max din departamentul productie

int salMaxProductie(Angajat a[]) {
	int max = 0;
	for (int i = 0; i < 300; i++) {
		if (strcmp(a[i].departament, "productie") == 0) {
			if (a[i].salariu_obt > max) {
				max = a[i].salariu_obt;
			}
		}
	}
	return max;
}

//todo functie ce returneaza nr total de ore suplimentare din departamentul marketing

int nrOreSup(Angajat a[]) {
	int total = 0;
	for (int i = 0; i < 300; i++) {
		if (strcmp(a[i].departament, "marketing") == 0) {
			total = total + a[i].nr_ore_sp;
		}
	}
	return total;
}

//todo functie ce copleteaza campul bursa

void completareBursa(Student st[]) {
	for (int i = 0; i < 300; i++) {
		if (st[i].nr_credite >= 30) {
			strcpy_s(st[i].bursa, "Da");
		}
		else {
			strcpy_s(st[i].bursa, "Nu");
		}
	}
}

//todo functie ce afiseaza datele studetilor care primesc bursa

void afisareDateStudenti(Student st[]) {
	for (int i = 0; i < 300; i++) {
		if (strcmp(st[i].bursa, "Da") == 0) {
			cout << st[i].nume << ' ' << st[i].an_studiu << ' ' << st[i].grupa << endl;
		}
	}
}

//todo functie ce completeaza campul nr_total_credite

void completareCredite(Stud st[]) {
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 10; j++) {
			st[i].nr_total_credite = st[i].nr_total_credite + st[i].e[j].nr_credite;
		}
	}
}

//todo functie ce afiseaza datele studentilor care au obtinut credite la proiecte

void afisareStud(Stud st[]) {
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 10; j++) {
			if (st[i].e[j].nr_credite > 0 && strcmp(st[i].e[j].tip_examinare, "proiect") == 0) {
				cout << st[i].nume << ' ' << st[i].an_studiu << st[i].grupa << ' ' << st[i].e[j].disciplina;
			}
		}
	}
}

//todo functie ce returneaza nr total de credite de val max obtinut

int nrTotalMaxCredite(Stud st[]) {
	int ct = 0, max = 0;
	for (int i = 0; i < 200; i++) {
		if (st[i].nr_total_credite > max) {
			max = st[i].nr_total_credite;
			ct = 1;
		}
		else {
			if (st[i].nr_total_credite == max) {
				ct++;
			}
		}
	}
	return ct;
}

//todo functie ce returneaza suma incasata pt toate spectacolele din luna mai din anul 2019

int sumaIncasata(Spectacol s[]) {
	int suma = 0;
	for (int i = 0; i < 50; i++) {
		if (s[i].data_sp.luna == 5 && s[i].data_sp.an == 2019) {
			suma = suma + s[i].nr_bilete * s[i].pret;
		}
	}
	return suma;
}

//todo functie ce afiseaza datele calendaristice in care au fost sustinute spectacole cu piese de I.L.Caragiale

void afisareDateSpectacole(Spectacol s[]) {
	for (int i = 0; i < 50; i++) {
		if (strcmp(s[i].autor, "I.L.Caragiale") == 0) {
			cout << s[i].data_sp.zi << ' ' << s[i].data_sp.luna << ' ' << s[i].data_sp.an << endl;
		}
	}
}

//todo functiec ce afiseaza numele lectorilor care au prezentat articole in anul 2019,
//la conferinte IT in Romania, SUA si Japonia

void afisareLectori(Conferinta c[]) {
	for (int i = 0; i < 100; i++) {
		if (strcmp(c[i].tip_inreg, "lector") == 0 && c[i].data_conf.an == 2019) {
			if (strcmp(c[i].tematica, "IT") == 0) {
				if (strcmp(c[i].tara, "Romania") == 0 || strcmp(c[i].tara, "SUA") == 0, strcmp(c[i].tara, "Japonia") == 0) {
					cout << c[i].nume << endl;
				}
			}
		}
	}
}

//todo functie ce afiseaza numele participantilor din luna aprilie, 
//anul 2019, la conferinte de medicina la Iasi si numarul lor

void afisareParticipanti(Conferinta c[], int& nr) {
	for (int i = 0; i < 100; i++) {
		if (strcmp(c[i].tip_inreg, "participant") == 0) {
			if (c[i].data_conf.luna == 4 && c[i].data_conf.an == 2019) {
				if (strcmp(c[i].tematica, "medicina") == 0 && strcmp(c[i].oras, "Iasi") == 0) {
					cout << c[i].nume << endl;
					nr++;
				}
			}
		}
	}
}

//todo functie ce afiseaza melodiile din Top 3 in Romania in anul 2018

void afisareTop3(Melodie m[]) {
	for (int i = 0; i < 200; i++) {
		if (m[i].loc_top <= 3 && strcmp(m[i].tara, "Romania") == 0 && m[i].an_top == 2018) {
			cout << m[i].nume << endl;
		}
	}
}

//todo functie ce afiseaza melodiile in ordine alfabetica dupa nume

/*void afisareCrescNume(Melodie m[]) {
	Melodie aux[200];
	bool flag = 0;
	do {
		flag = 1;
		for (int i = 0; i < 199; i++) {
			if (strcmp(m[i].nume, m[i + 1].nume) > 0) {
				strcpy(aux, m[i]);
				strcpy(m[i], m[i + 1]);
				strcpy(m[i + 1], aux);
				flag = 0;
			}
		}
	} while (flag == 0);
}*/

//todo functie ce citeste mediile unui elev

void citireMedii(ElevMedii& e) {
	ifstream f("medii.txt");
	f >> e.med1;
	f >> e.med2;
}

//todo functie ce returneaza media anuala a elevului

float medieAnuala(ElevMedii x) {
	float medie = (x.med1 + x.med2) / 2;
	return medie;
}

//todo functie ce citeste numele si nota a 2 elevi

void citireNumeNota(ElevNota& e1, ElevNota& e2) {
	ifstream f("numeNota.txt");
	f >> e1.nume;
	f >> e1.nota;
	f >> e2.nume;
	f >> e2.nota;
}

//todo functie ce afiseaza numele elevului cu nota cea mai mare

void afisareElevNotaMax(ElevNota e1, ElevNota e2) {
	if (e1.nota < e2.nota) {
		cout << e2.nume;
	}
	else {
		cout << e1.nume;
	}
}

//todo functie ce returneaza lungimea maxima a cuvintelor memorate care au frecventa mai mare decat 2

int lungimeMax(Cuvant c[]) {
	int max = 0;
	for (int i = 0; i < 20; i++) {
		if (strlen(c[i].cuv) > max && c[i].frecv > 2) {
			max = strlen(c[i].cuv);
		}
	}
	return max;
}