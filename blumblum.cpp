/*
 * blumblum.cpp
 *
 *  Created on: 16-10-2014
 *      Author: konrad
 */

#include "blumblum.h"

void sleep(unsigned int );
void gwiazdki();

blumblum::blumblum(int first, int second) : p(first), q(second), stanX(0), stanX_1(0), M(0) {}


blumblum::~blumblum() {
	// TODO Auto-generated destructor stub
	cout << "\nKoniec!";
}
int blumblum::init(){
	int X0 = (czas_w_sekundach())%1000; //liczba od 0 do 1000;
	cout << "X0: "<< X0;
	if(p % 4 == 3 && q % 4 == 3 && X0 != 1)
	{
		M = p*q;
		cout << "\nM: " << M+1;
		while( nwd(M,X0) != 1) X0++;
		stanX = (X0*X0)%(M+1);
		cout << "\nstanX: " << stanX << endl;
	}
	else{
		cout << "\nInne liczby! p: ";
		cin >> p;
		cout << "q: ";
		cin >> q;
		blumblum::init();
	}
	return stanX;
}
int blumblum::generuj() {
	return stanX_1 = (stanX*stanX)%(M+1);
}
void blumblum::wypisz_n(int ilosc){
	int iterator = 0;
	while(iterator<ilosc){
		cout << "Liczba " << iterator+1 << " = " << generuj() << endl;
		sleep(500000);
		stanX = stanX_1;
		iterator++;
	}
}
int blumblum::czas_w_sekundach(){
	time_t timer;
	timer = time(&timer);
	return timer;
}
void blumblum::swichthem(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int blumblum::nwd(int &first, int &second)
{
	int a = first;
	int b = second;
	while(a!=b){
		if(a < b)
			b-=a;
		else
			a-=b;
	}
	return a;
}
void sleep(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int blumblum::test_zero_jeden(int max){
	int counter = 0;
	int temp;
	for(int i = 0; i < max; i++){
		temp = this->generuj();
		if(temp >= (M+1)/2)
			counter++;
		stanX = stanX_1;
	}
	return counter;
}
void blumblum::test_zero_jeden_UI(){
	int max;
	gwiazdki();
	cout << "Witaj w tescie zero-jedynkowym!" << endl;
	cout << "Dla ilu liczb przeprowadzić test? : " << endl;
	cin >> max;
	int result = this->test_zero_jeden(max);
	cout << "Oczekiwany wynik: 0.5" << endl;
	cout << "Wynik testu: " << ((double)result)/((double)max) << endl;
	gwiazdki();
}
int blumblum::test_bertrand_katy(int max){
	int counter = 0;
	int kat;
	for(int i = 0; i < max; i++){
		kat = this->generuj();
		if(kat > ((double)M)/3 && kat <= (((double)M)/3)*2)
			counter++;
		stanX = stanX_1;
	}
	return counter;
}
void blumblum::test_bertrand_katy_UI(){
	int max;
	gwiazdki();
	cout << "\nWitaj w tescie Bertranda (podejscie katowe)" << endl;
	cout << "Dla ilu liczb przeprowadzić test? : " << endl;
	cin >> max;
	int result = this->test_bertrand_katy(max);
	cout << setprecision(6) <<"Oczekiwany wynik: " << (double)1/3 << endl;
	cout << "Wynik testu: " << ((double)result)/((double)max) << endl;
	gwiazdki();
}
void gwiazdki(){
	cout << "*******************" << endl;
}
int blumblum::test_monte_carlo(int max,int bok){
	int counter = 0;
	int x0 = bok/2;
	int y0 = bok/2;
	int x,y;
	for(int i = 0; i < max; i++){
		x = (this->generuj()) % bok;
		y = (this->generuj()) % bok;
		if(sqrt( ((x-x0)*(x-x0)) + ((y-y0)*(y-y0)) ) <= bok/2)
			counter++;
		stanX = stanX_1;
	}
	return counter;
}
void blumblum::test_monte_carlo_UI(){
	int max;
	int bok;
	double pi = 3.14159265358979323846;
	gwiazdki();
	cout << "Witaj w tescie Monte Carlo" << endl;
	cout << "Dla ilu liczb przeprowadzić test? : " << endl;
	cin >> max;
	cout << "Jaki ma byc bok kwadratu? : " << endl;
	cin >> bok;
	int result = this->test_monte_carlo(max,bok);
	cout << setprecision(5) <<"Oczekiwany wynik: " << pi/4 << endl;
	cout << "Wynik testu: " << ((double)result)/((double)max) << endl;
	gwiazdki();
}
