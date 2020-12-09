#pragma once
#ifndef DEF_PLAYER
#define DEF_PLAYER
#include "Header.h"

class Object
{
public:
	Object(int value, int x, int y,std::string name, SDL_Renderer  *render,char * path);
	~Object();
	SDL_Texture* GetTexture();
	float GetWidth();
	float GetHeight();
	float GetX();
	float GetY();

private:
	std::string m_name;
	SDL_Texture* m_texture;
	SDL_Renderer *m_renderer;
	SDL_Rect m_rect;
	float m_x;
	float m_y;
	
	float m_height, m_width;
};


#endif