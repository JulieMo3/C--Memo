//#include "Header.h"
#include "GameTool.h"
#include "Memo.h"
using namespace std;

const int taille = 6;
int pair = 0;

char * temp = new char[50];

int main(int argc, char *argv[])
{
	SDL_Event event;
	int pair = 0;
	int coups = 0;
	int curseurX = 0;
	int curseurY = 0;
	Memo *memoCarte1 = NULL;
	Memo *memoCarte2 = NULL;
	Memo *plateau = NULL;
	int tab[6][6];
	std::string chemin;
	bool quit = false;
	int nbclick = 0;
	GameTool *game = NULL;
	game = new GameTool();
	game->Init();
	memoCarte1 = new Memo();
	memoCarte2 = new Memo();
	plateau = new Memo();
	int playe = 0;
	plateau->init(tab, taille);
	//add ici toutes les cartes 
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			game->addobject1(0, i * 120 + 20, j * 120 + 20, "carte", "assets/dos.jpg");
		}
	}
	//random du posé de carte, sdl visu, tab pour la mechanique
	while (game->Running(quit))
	{

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_DOWN:
					curseurY++;
					if (curseurY > taille - 1) {
						curseurY--;
					}
					break;
				case SDLK_UP:
					curseurY--;
					if (curseurY < 0) {
						curseurY++;
					}
					break;
				case SDLK_LEFT:
					curseurX--;
					if (curseurX < 0) {
						curseurX++;
					}
					break;
				case SDLK_RIGHT:
					curseurX++;
					if (curseurX > taille - 1) {
						curseurX--;
					}
					break;

				case SDLK_SPACE:
					if (playe != 1)
					{
						if (tab[curseurX][curseurY] != -1) {  //verification que la carte clicker n'est pas deja une paire validé
							nbclick++;

							if (nbclick > 2) { //recherche d'une nouvelle pair

							//effece
								game->Clearpokemons();
								nbclick = 1;
							}
							if (nbclick == 1) {
								memoCarte1->value = tab[curseurX][curseurY];
								memoCarte1->CoordonneeX = curseurX;
								memoCarte1->CoordonneeY = curseurY;

								idCarte(memoCarte1->value);
								game->addpokemon(0, curseurX * 120 + 20, curseurY * 120 + 20, "pokemon1", temp);
							}
							if (nbclick == 2) {
								memoCarte2->value = tab[curseurX][curseurY];
								memoCarte2->CoordonneeX = curseurX;
								memoCarte2->CoordonneeY = curseurY;

								//verification de si c'est la meme carte que l'on vérifie (exemple carte en 2,2 avec la 2,2)
								if ((memoCarte1->CoordonneeX == memoCarte2->CoordonneeX) && (memoCarte1->CoordonneeY == memoCarte2->CoordonneeY))
								{
									nbclick--;
								}
								else
								{
									coups++;
									idCarte(memoCarte2->value);
									game->addpokemon(0, curseurX * 120 + 20, curseurY * 120 + 20, "pokemon2", temp);
									if (memoCarte1->value == memoCarte2->value) {
										pair++;

										game->addfind(0, memoCarte1->CoordonneeX * 120 + 20, memoCarte1->CoordonneeY * 120 + 20);
										game->addfind(0, memoCarte2->CoordonneeX * 120 + 20, memoCarte2->CoordonneeY * 120 + 20);

										tab[memoCarte1->CoordonneeX][memoCarte1->CoordonneeY] = -1;
										tab[memoCarte2->CoordonneeX][memoCarte2->CoordonneeY] = -1;
										playe = plateau->win(pair);
										if (playe == 1) {
											cout << "vous avez gagne en " << coups << " coups, felicitation !" << endl;;
											game->win();
											game->Render(curseurX, curseurY);
										}
									}
								}
							}
						}
					}
					break; 
				
				case SDLK_ESCAPE:
					quit = true;
					break;
				/*
					//fait apparaitre graphiquement l'image de victoire

				case SDLK_w:
					game->win();
					break;*/
				}			
				break;
			}
			game->Render(curseurX, curseurY);
		}
	}
	game->Clear();
	return 0;
}


void idCarte(int id) {
	std::string path;
	switch (id)
	{
	case 0:
		path = "assets/mewtwo.jpg";
		break;
	case 1:
		path = "assets/artikodin.jpg";
		break;
	case 2:
		path = "assets/brasegali.jpg";
		break;
	case 3:
		path = "assets/caninos.jpg";
		break;
	case 4:
		path = "assets/dracaufeu.jpg";
		break;
	case 5:
		path = "assets/ectoplasma.jpg";
		break;
	case 6:
		path = "assets/evoli.jpg";
		break;
	case 7:
		path = "assets/exagide.jpg";
		break;
	case 8:
		path = "assets/florizarre.jpg";
		break;
	case 9:
		path = "assets/jungko.jpg";
		break;
	case 10:
		path = "assets/lippoutou.jpg";
		break;
	case 11:
		path = "assets/lugia.jpg";
		break;
	case 12:
		path = "assets/magicarpe.jpg";
		break;
	case 13:
		path = "assets/mew.jpg";
		break;
	case 14:
		path = "assets/noctalimentali.jpg";
		break;
	case 15:
		path = "assets/pikachu.jpg";
		break;
	case 16:
		path = "assets/tortank.jpg";
		break;
	case 17:
		path = "assets/nostenfer.jpg";
		break;
	default:
		path = "assets/dos.jpg";
		break;
	}
	strcpy(temp, path.c_str());

}