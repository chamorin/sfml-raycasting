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

    for (unsigned int i = 0; i < WIDTH_SCREEN; ++i)
    {
        sf::VertexArray ray(sf::Lines, 2);
        ray[0].color = sf::Color::Red;
        ray[1].color = sf::Color::Red;

        m_vecRays.push_back(ray);
    }
}

void Camera::draw()
{
    for (auto &vec : m_vecRays)
    {
        m_renderWindow.draw(vec);
    }
    m_renderWindow.draw(m_camera);
}

void Camera::update()
{
    sf::Time dt = m_clock.restart();
    checkKeyboardEvent(dt);

    m_camera.setPosition(m_position);
    m_camera.setRotation(m_angle);
    projection();
}

void Camera::projection()
{
    for (unsigned int i = 0; i < m_vecRays.size(); ++i)
    {
        m_vecRays[i][0].position = m_position;
        m_vecRays[i][1].position = {m_position.x + m_rayLength * dCos((m_angle + m_fov / 2) - i * (m_fov / WIDTH_SCREEN)),
                                    m_position.y + m_rayLength * dSin((m_angle + m_fov / 2) - i * (m_fov / WIDTH_SCREEN))};
    }
}

void Camera::checkKeyboardEvent(sf::Time dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        m_position.x += dCos(m_angle) * m_speedMove * dt.asSeconds();
        m_position.y += dSin(m_angle) * m_speedMove * dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_position.x -= dCos(m_angle) * m_speedMove * dt.asSeconds();
        m_position.y -= dSin(m_angle) * m_speedMove * dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_angle += m_speedAngle * dt.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_angle -= m_speedAngle * dt.asSeconds();
    }

    if (m_angle > 360)
        m_angle = 0;
    if (m_angle < 0)
        m_angle = 360;

    m_camera.setPosition(m_position);
    m_camera.setRotation(m_angle);
}

Camera::~Camera()
{
}