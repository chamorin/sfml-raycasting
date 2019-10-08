#include "./Camera.h"

Camera::Camera(sf::RenderWindow &renderWindow) : m_renderWindow(renderWindow)
{
    m_radius = 5;
    m_camera.setRadius(m_radius);
    m_camera.setFillColor(sf::Color::Green);
    m_camera.setOrigin(sf::Vector2f(m_radius, m_radius));

    m_speedMove = 200.0f;
    m_speedAngle = 100.0f;

    m_position = {128, 128};

    m_fov = 60;
    m_rayLength = 200;
}