#include <SFML/Graphics.hpp>
#include <math.h>

#include "./Constant.h"

using namespace std;

class Camera
{
protected:
    sf::RenderWindow &m_renderWindow;
    sf::CircleShape m_camera;
    sf::Vector2f m_position, m_intesection;
    sf::Clock m_clock;
    float m_angle, m_fov, m_rayLength;
    float m_radius;
    float m_speedMove, m_speedAngle;
    vector<sf::VertexArray> m_vecRays;

public:
    Camera(sf::RenderWindow &renderWindow);
    void draw();
    void update();
    void projection();
    inline float toRadian(float degree) { return (PI/180)*degree; }
    inline float dCos(float degree) { return cos(toRadian(degree)); }
    inline float dSin(float degree) { return sin(toRadian(degree)); }
    ~Camera();
};
