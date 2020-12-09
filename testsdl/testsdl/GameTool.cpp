#include "GameTool.h"
#include "Object.h"

using namespace std;

SDL_Rect Position;

GameTool::GameTool()
{

}
GameTool::~GameTool()
{

}

bool GameTool::Init()
{
	// Initialisation
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) return false;
	SDL_Window *screen = SDL_CreateWindow("Memory Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0/*SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL*/);
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		//screen = SDL_CreateWindow("Memory Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0/*SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL*/);

		m_renderer = SDL_CreateRenderer(screen, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 170, 0, 255, 255);

		}

	}
	else
	{
		return false;
	}
	if (screen == NULL) return false;

	//SDL_WM_SetCaption("Memory", NULL);

	// Initialise random function
	srand(time(NULL));

	// prendre la texture du curseur

	SDL_Surface* curseurSurface = IMG_Load("assets/curseur.png");
	m_textureCurseur = SDL_CreateTextureFromSurface(m_renderer, curseurSurface);
	SDL_FreeSurface(curseurSurface);

	//prendre la texture du background

	SDL_Surface* backgroundSurface = IMG_Load("assets/background.jpg");
	m_textureBackground = SDL_CreateTextureFromSurface(m_renderer, backgroundSurface);
	SDL_FreeSurface(backgroundSurface);

	//prendre la texture du fond de victoire

	SDL_Surface* winSurface = IMG_Load("assets/win.jpg");
	m_textureWin = SDL_CreateTextureFromSurface(m_renderer, winSurface);
	SDL_FreeSurface(winSurface);

	m_win = false;

	return true;
}

// add an image(packet de carte)
void GameTool::addobject1(int value,int x, int y,std::string name, char * imagepath)
{
	this->m_objects.push_back(new Object(value, x, y,name, this->m_renderer, imagepath)); 
}

void GameTool::addpokemon(int value, int x, int y, std::string name, char * imagepath)
{
	this->m_pokemons.push_back(new Object(value, x, y, name, this->m_renderer, imagepath)); 
}

void GameTool::addfind(int value, int x, int y)
{
	this->m_find.push_back(new Object(value, x, y,"black", this->m_renderer, "assets/find.jpg")); 
}

void GameTool::Render(int x, int y)
{
	//clean renderer

	SDL_RenderClear(m_renderer);

	//wallpaper
	Position.x = 0;
	Position.y = 0;
	Position.w = 1280;
	Position.h = 720;
	SDL_RenderCopy(this->m_renderer, this->m_textureBackground, false, &Position);

	//cartes

	for (int i = 0; i < m_objects.size(); i++)
	{
		Position.x = m_objects[i]->GetX();
		Position.y = m_objects[i]->GetY();
		Position.w = 100;
		Position.h = 100;
		SDL_RenderCopy(this->m_renderer, this->m_objects[i]->GetTexture(), false, &Position);
	}

	//find
	
	for (int i = 0; i < m_find.size(); i++)
	{
		Position.x = m_find[i]->GetX();
		Position.y = m_find[i]->GetY();
		Position.w = 100;
		Position.h = 100;
		SDL_RenderCopy(this->m_renderer, this->m_find[i]->GetTexture(), false, &Position);
	}
	
	
	//cartes montree
	
	for (int i = 0; i < m_pokemons.size(); i++)
	{
		Position.x = m_pokemons[i]->GetX();
		Position.y = m_pokemons[i]->GetY();
		Position.w = 100;
		Position.h = 100;
		SDL_RenderCopy(this->m_renderer, this->m_pokemons[i]->GetTexture(), false, &Position);
	}
	

	//curseur

	Position.x = x * 120 + 20;
	Position.y = y * 120 + 20;
	SDL_RenderCopy(this->m_renderer, this->m_textureCurseur, false, &Position);

	//win

	if (this->GameWin())
	{
		Position.x = 864;
		Position.y = 50;
		Position.w = 256;
		Position.h = 60;

		SDL_RenderCopy(this->m_renderer, this->m_textureWin, false, &Position);
	}

	//update graphique

	SDL_RenderPresent(m_renderer);

}

//close window
void GameTool::Clear()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	printf("window close");
}

bool GameTool::Running(bool quit)
{
	if (quit) {
		return false;
	}
	else {
		return true;
	}
	
}

void GameTool::Clearpokemons()
{
	while (m_pokemons.size() != 0)
	{
		m_pokemons.pop_back();
	}
}

bool GameTool::GameWin()
{
	return m_win;
}

void GameTool::win()
{
	m_win = true;
}
