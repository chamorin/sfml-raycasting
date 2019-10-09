#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "Camera.h"
#include "Level.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "WORKING");

	Level level(window);
	Camera camera(window, level);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		camera.update();
		window.clear();

		camera.draw();
		level.draw();
		window.display();
	}

	return 0;
}
