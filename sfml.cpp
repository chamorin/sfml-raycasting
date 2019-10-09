#include <SFML/Graphics.hpp>
#include "Constant.h"
#include "Camera.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH_SCREEN, HEIGHT_SCREEN), "WORKING");

	Camera camera(window);

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
		window.display();
	}

	return 0;
}
