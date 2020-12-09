#ifndef DEF_GAME
#define DEF_GAME
#include "Header.h"


class GameTool
{
public:
	GameTool();
	~GameTool();
	bool Init();
	void addobject1(int value,int x, int y,std::string name, char * imagepath);
	void addpokemon(int value, int x, int y, std::string name, char * imagepath);
	void addfind(int value, int x, int y);
	void Clearpokemons();
	void Clear();
	void Render(int x, int y); //position du curseur
	bool Running(bool quit);
	bool GameWin();
	void win();


	
private:
	
	SDL_Window * m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_textureBackground;
	SDL_Texture *m_textureCurseur;
	SDL_Texture *m_textureWin;
	int m_cnt;
	bool m_win;
	std::vector <Object*>m_objects;
	std::vector <Object*>m_pokemons;
	std::vector <Object*>m_find;

};
#endif