#include "Object.h"


Object::Object(int value, int x, int y,std::string name,SDL_Renderer *renderer, char * path)
{
	m_name = name;
	SDL_Surface* m_surface;
	m_x = x;
	m_y = y;
	m_surface = IMG_Load(path);
	m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
	m_height = m_surface->h;
	m_width = m_surface->w;
	SDL_FreeSurface(m_surface);
}
Object::~Object()
{

}

SDL_Texture* Object::GetTexture()
{
	return m_texture;
}

float Object::GetWidth()
{
	return m_width;
}

float Object::GetHeight()
{
	return m_height;
}

float Object::GetX()
{
	return m_x;
}

float Object::GetY()
{
	return m_y;
}
