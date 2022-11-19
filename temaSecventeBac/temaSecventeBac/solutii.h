#include "functii.h"
#pragma once

//TEZA 23, S2, 1:

//sa se afiseze numele oraselor si tarilor lor, pentru toate orasele care au o densitate mai mare de 15 loc/km2

void sol1() {
	Oras o[200];
	int n;
	//cout << densitatePop(123, 2.2);
	citireDateOras(o, n);
	/*for (int i = 0; i < n; i++) {
		cout << o[i].nume_oras << endl;
	}*/
	afisareOrase(o, n);
}


//TEZA 24, S2, 1:

//sa se determine si sa se afiseze suma totala incasata de cinemstograf, pentru toate filmele
//ce apartin genurilor comedie si istoric, difuzate in luna martie, anul 2018

void sol2() {
	Film f[1000];
	cout << suma(f);
}


//TEZA 25, S2, 3:

//sa se afiseze laturile triunghiului pentru care aria apartine intervalului [x,y]

void sol3() {
	Triunghi t[100];
	float x, y;
	int n;
	citireDateTriunghiuri(t, n, x, y);
	//cout << arie(6,5,6);
	afisareLaturi(t, n, x, y);
}


//TEZA 1, S2, 2:

//sa se afiseze numele elevului daca anul nasterii este egal cu 2000
//in caz contrar se afiseaza data nasterii

void sol4() {
	Elev e;
	citireDateElev(e);
	afisareElev(e);
}


//TEZA 18, S2, 1:

//sa se afiseze nr de fractii cu numitorul minim

void sol5() {
	Fractie x[20];
	int n;
	citireFractii(x, n);
	cout << nrFractii(x,n);
	/*for (int i = 0; i < n; i++) {
		cout << x[i].numarator<<' ';
		cout << x[i].numitor << endl;
	}*/
}


//TEZA 20, S2, 1:

//sa se determine nr de elevi care studiaza limba engleza ca prima sau a doua limba

void sol6() {
	ElevL e[30];
	cout << nrEleviEngleza(e);
}


//VARIANTA 1, S2, 1:

/*În declararea alăturată, câmpurile x şi y ale înregistrării pot memora 
coordonatele carteziene ale unui punct din planul xOy. Scrieţi o 
secvenţă de instrucţiuni prin executarea căreia se memorează în 
variabila C coordonatele mijlocului segmentului cu capetele în punctele 
ale căror coordonate sunt memorate în variabilele A şi B.
struct punct
{
 float x,y;
}A,B,C;*/


void sol7() {
	Punct A, B, C;
	citireCoordonate(A,B);
	coordonateMijloc(C, A, B);
	cout << C.x << ' ' << C.y;
}


//VARIANTA 3, S2, 1:

/*În declararea alăturată, câmpurile x şi y ale înregistrării pot 
memora numărătorul, respectiv numitorul unei fracţii. Scrieţi 
secvenţa de instrucţiuni prin executarea căreia se construieşte în 
variabila f o fracţie obţinută prin însumarea fracţiilor memorate în 
variabilele f1 şi f2
struct fractie
 {
 int x,y;
 }f,f1,f2;*/

void sol8() {
	Fractie2 f, f1, f2;
	citire2Fractii(f1, f2);
	insumareFractii(f, f1, f2);
	cout << f.x << ' ' << f.y;
}


//CULEGERE, ex2:

//sa se determine numarul de medalii de aur, numarul de medalii de argint si de bornz
//obtinute de sportivii din judetul Iasi in naul 2019

void sol9() {
	Medalie sp[500];
	cout << "medalii de aur: " << nrMedaliiAur(sp) << endl;
	cout << "medalii de argint: " << nrMedaliiArgint(sp) << endl;
	cout << "medalii de bronz: " << nrMedaliiBronz(sp) << endl;
}


//CULEGERE, ex3:

//sa se afiseze numele pacientilor programati pentru consultatii la data de 10 august 2019
//si numarul de pacienti programati la aceasta data

void sol10() {
	Consultatie c[100];
	int nr=0;
	afisarePacienti(c, nr);
	cout << "numar total pacienti: " << nr;

}


//CULEGERE, ex4:

//sa se afiseze destinatia si data pentru fiecare excursie la care s-a inscris
//persoana cu numele memorat prin variabila numed sau se va afisa mesajul
//Nicio excursie, daca persoana nu s-a inscris la nicio excursie

void sol11() {
	Excursie e[300];
	char numed[30];
	bool excursii = 0;
	afisareDestinatii(e, numed, excursii);
	if (excursii == 0) {
		cout << "Nicio excursie" << endl;
	}
}


//CULEGERE, ex5:

//a) completarea campului salariu_obt
//b) afisarea salariului de valoare max din departamentul productie
//c) afisare nr total de ore suplimentare din departamentul marketing

void sol12() {
	Angajat a[300];
	completareCamp(a);
	cout << salMaxProductie(a) << endl;
	cout << nrOreSup(a) << endl;
}


//CULEGERE, ex6:

//a) sa se completeze campul bursa
//b) sa se afiseze datele studetilor care primesc bursa

void sol13() {
	Student st[300];
	completareBursa(st);
	afisareDateStudenti(st);
}


//CULEGRE, ex7

//a) sa se completeze campul nr_total_credite
//b) sa se afiseze datele studentilor care au obtinut credite la proiecte
//c) sa se afiseze nr total de credite de val max obtinut

void sol14() {
	Stud st[200];
	completareCredite(st);
	afisareStud(st);
	cout << nrTotalMaxCredite(st);
}


//CULEGERE, ex8

//a) sa se afiseze suma incasata pt toate spectacolele din luna mai din anul 2019
//b) sa se afiseze datele calendaristice in care au fost sustinute spectacole cu piese de I.L.Caragiale

void sol15() {
	Spectacol s[50];
	cout << sumaIncasata(s);
	afisareDateSpectacole(s);
}


//CULEGERE, ex9

//a) numele lectorilor care au prezentat articole in anul 2019, la conferinte IT in Romania, SUA si Japonia
//b) numele participantilor din luna aprilie, anul 2019, la conferinte de medicina la Iasi si numarul lor

void sol16() {
	Conferinta c[100];
	afisareLectori(c);
	int nr = 0;
	afisareParticipanti(c, nr);
	cout << nr << endl;
}

//CULEGERE, ex1:

//a) sa se afiseze melodiile din Top 3 in Romania in anul 2018
//b) sa se afiseze melodiile in ordine alfabetica dupa nume
//c) sa se afiseze melodiile in ordine alfabetica dupa tara (pt aceeasi tara, in ordine crescatoare dupa loc_top)

void sol17() {
	Melodie m[200];
	afisareTop3(m);

}

//VARIANTA 49, S2, 1:
/*Variabila x, declarată alăturat, memorează în câmpurile med1 şi 
med2 mediile semestriale ale unui elev. Scrieţi o expresie a cărei 
valoare va fi media anuală a acestui elev. 
struct elev {
 int matricol;
 float med1,med2;
}x; */

void sol18() {
	ElevMedii x;
	citireMedii(x);
	cout << medieAnuala(x);
}


//VARIANTA 71, S2, 1:

/*Fiecare dintre variabilele declarate alăturat memorează numele 
şi nota câte unui elev. 
Scrieţi secvenţa de instrucţiuni prin care se citesc de la 
tastatură numele şi nota pentru fiecare dintre variabilele e1 şi 
e2 şi apoi se afişează numele elevului cu nota cea mai mare. 
Dacă cele două note sunt egale, se va afişa numele elevului 
memorat în variabila e1.
struct elev{
 char nume[20];
 float nota;
};
elev e1,e2;
*/

void sol19() {
	ElevNota e1, e2;
	citireNumeNota(e1, e2);
	afisareElevNotaMax(e1, e2);
}


//TEZA 19, S2, 1:

//sa se afiseze lungimea maxima a cuvintelor memorate care au frecventa mai mare decat 2

void sol20() {
	Cuvant c[20];
	cout << lungimeMax(c);
}