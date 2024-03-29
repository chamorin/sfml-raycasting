#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <math.h>

#include "Constant.h"
#include "Level.h"

using namespace std;

class Camera
{
protected:
    Level& m_level;
    sf::RenderWindow &m_renderWindow;
    sf::CircleShape m_camera;
    sf::Vector2f m_position, m_intesection;
    sf::Clock m_clock;
    float m_angle, m_fov, m_rayLength;
    float m_radius;
    float m_speedMove, m_speedAngle;
    vector<sf::VertexArray> m_vecRays;

public:
    Camera(sf::RenderWindow &renderWindow, Level& m_level);
    void draw();
    void update();
    void projection();
    bool intersect(unsigned int it);
    void checkKeyboardEvent(sf::Time dt);
    inline float toRadian(float degree) { return (PI/180)*degree; }
    inline float dCos(float degree) { return cos(toRadian(degree)); }
    inline float dSin(float degree) { return sin(toRadian(degree)); }
    ~Camera();
};

#endif