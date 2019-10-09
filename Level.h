#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Constant.h"

using namespace std;

class Level
{
protected:
    sf::RenderWindow &m_renderWindow;
    vector<vector<unsigned int>> m_vecLevel;
    vector<sf::RectangleShape>m_vecBox;
public:
    Level(sf::RenderWindow &renderWindow);
    void draw();
    bool checkLevelCase(unsigned int dx, unsigned int dy);
};

#endif