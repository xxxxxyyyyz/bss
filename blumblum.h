/*
 * blumblum.h
 *
 *  Created on: 16-10-2014
 *      Author: konrad
 */

#ifndef BLUMBLUM_H_
#define BLUMBLUM_H_

#include <iostream>
#include <ctime>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;

class blumblum {
public:
	blumblum(int, int);
	virtual ~blumblum();
	int init();
	int generuj();
	int nwd(int &,int &);
	int czas_w_sekundach();
	void swichthem(int &, int &);
	void wypisz_n(int );
	int test_zero_jeden(int);
	void test_zero_jeden_UI();
	int test_bertrand_katy(int);
	void test_bertrand_katy_UI();
	int test_monte_carlo(int,int);
	void test_monte_carlo_UI();
private:
	unsigned long int stanX; //dla init - pierwszy stan
	unsigned long int stanX_1; //stany kolejne
	int p;
	int q; //p*q = M - dzielnik
	int M;
};

#endif /* BLUMBLUM_H_ */
