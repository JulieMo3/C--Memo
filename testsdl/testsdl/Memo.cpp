#include "Memo.h"




Memo::Memo()
{
	CoordonneeX = 0;
	CoordonneeY = 0;
	value = 0;

}

Memo::~Memo()
{

}

void Memo::init(int tab[][6], int length) {


	std::vector<int> indice = { 0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17 };
	int max = 36;
	int random;
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			random = rand() % max;
			tab[i][j] = indice[random];
			max--;
			indice.erase(indice.begin() + random);

		}
	}
}

int Memo::win(int pair) {
	if (pair == 18) {
		return 1;
	}
	else {
		return 0;
	}
}