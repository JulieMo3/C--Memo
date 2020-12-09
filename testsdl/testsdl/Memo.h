#include "GameTool.h"
#include "Header.h"

class Memo
{
public:
	Memo();
	~Memo();
	int CoordonneeX;
	int CoordonneeY;
	int value;

	void init(int tab[][6], int nbpair);
	int win(int pair);


private:

};



