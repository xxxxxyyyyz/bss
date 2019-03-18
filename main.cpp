#include "blumblum.h"

int main(void){
	blumblum generatorek(7,15);
	generatorek.init();
	generatorek.test_zero_jeden_UI();
	generatorek.test_bertrand_katy_UI();
	generatorek.test_monte_carlo_UI();
	generatorek.wypisz_n(5);
	return 0;
}
