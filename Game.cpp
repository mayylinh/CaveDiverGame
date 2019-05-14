// score increases as miner dives deeper down cave
	// score displays live during play time
// player loses if miner hits cave rock
// player becomes indestructible for 5 seconds if they collect pickaxe

// cave sides have random lengths
// continuously generate cave until player hits rock

#include "pch.h"
#include <SFML/Graphics.hpp> //using namespace sf
#include <time.h>
#include <iostream>
#include <sstream>

//globals dimensions for window
int num_vertBox = 90, num_horzBox = 44;
int size = 16; //number of pixels
int direction = 0, score = 0;
int w = size * num_horzBox;	//background number of pixels in width
int h = size * num_vertBox;	//background number of pixels in height

float delay = 0.1f;
int random = 0;
sf::Texture t1, t2;
sf::Sprite sprite1, sprite2;

//window that we can play the game in
sf::RenderWindow window(sf::VideoMode(w, h), "Cave Diver");

struct Miner
{
	int x, y;
}miner;

struct Cave
{
	int x, y;
}cave;

void move()
{
	//if user presses left
	if (direction == -1)
		miner.x -= 1;

	//if user presses right
	if (direction == 1)
		miner.x += 1;

	// if miner hits cave rock, player loses
	{
		if ((miner.x == cave.x) && (miner.y == cave.y))
		{
			window.clear();
			sf::Text playerScore;
			std::stringstream ss;
			ss << score;

			playerScore.setString(ss.str().c_str());
			playerScore.setPosition(18, 45);
			window.draw(playerScore);
		}
	}
}

//cave generated from bottom to top as miner dives deeper		
void caveShift()
{
	cave.y -= 1;
}

/*void randomNum()
{
	caveL = (rand() % (19 + 1 - 13)) + 13;
	caveR = (rand() % (19 + 1 - 13)) + 13;
}*/

int main()
{
	//setting pseudorandom time
	srand(time(0));

	//textures load an image into the GPU
	t1.loadFromFile("images/brown.jpg");
	t2.loadFromFile("images/miner.png");

	//sprite has physical dimensions
	sf::Sprite sprite1(t1);
	sf::Sprite sprite2(t2);


	sf::Clock clock;
	float timer = 0.0f;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event e;

		while (window.pollEvent(e))
		{
			//check when the window is closed
			if (e.type == sf::Event::Closed)
				window.close();
		}

		//control for miner by user
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			direction = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			direction = 1;

		if (timer > delay)
		{
			timer = 0; //reset timer
			score++;
			move(); //move miner	
			caveShift(); //cave generated from bottom to top as miner dives deeper		
			//randomNum(); //generate random lengths for cave
		}

		//draw in window
		window.clear(); //get rid of all frame

		//draw background
		for (int j = 0; j < 18; j++)
		{
			//ONE
			for (int i = 0; i < (15 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 0))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 15; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 0))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (15 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 0))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (18 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 0)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 18; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 0)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (18 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 0)) * size);
				window.draw(sprite1);
			}

			//TWO
			for (int i = 0; i < (12 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 1))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 12; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 1))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (12 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 1))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (14 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 1)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 14; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 1)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (14 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 1)) * size);
				window.draw(sprite1);
			}

			//THREE
			for (int i = 0; i < (18 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 2))) * size);
				window.draw(sprite1);

			}
			for (int i = 0; i < 18; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 2))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (18 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 2))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (17 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 2)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 17; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 2)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (17 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 2)) * size);
				window.draw(sprite1);
			}

			//FOUR
			for (int i = 0; i < (17 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 3))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 17; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 3))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (17 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 3))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (19 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 3)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 19; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 3)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (19 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 3)) * size);
				window.draw(sprite1);
			}

			//FIVE
			for (int i = 0; i < (14 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 4))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 14; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 4))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (14 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 4))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (17 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 4)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 17; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 4)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (17 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 4)) * size);
				window.draw(sprite1);
			}

			//SIX
			for (int i = 0; i < (19 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 5))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 19; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 5))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (19 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 5))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (16 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 5)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 16; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 5)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (16 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 5)) * size);
				window.draw(sprite1);
			}

			//SEVEN
			for (int i = 0; i < (16 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 6))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 16; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 6))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (16 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 6))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (19 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 6)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 19; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 6)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (19 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 6)) * size);
				window.draw(sprite1);
			}

			//EIGHT
			for (int i = 0; i < (17 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 7))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 17; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 7))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (17 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 7))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (19 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 7)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 19; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 7)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (19 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 7)) * size);
				window.draw(sprite1);
			}

			//NINE
			for (int i = 0; i < (15 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 8))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 15; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 8))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (15 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 8))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (13 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 8)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 13; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 8)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (13 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 8)) * size);
				window.draw(sprite1);
			}

			//TEN
			for (int i = 0; i < (18 - 3); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (90 + 7 * (10 * j + 9))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 18; i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (91 + 7 * (10 * j + 9))) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (18 - 2); i++)
			{
				sprite1.setPosition((cave.x + i) * size, (cave.y + (92 + 7 * (10 * j + 9))) * size);
				window.draw(sprite1);
			}

			for (int i = 0; i < (19 - 2); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 93 + 7 * (10 * j + 9)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < 19; i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 94 + 7 * (10 * j + 9)) * size);
				window.draw(sprite1);
			}
			for (int i = 0; i < (19 - 3); i++)
			{
				sprite1.setPosition((num_horzBox - cave.x - i) * size, (cave.y + 95 + 7 * (10 * j + 9)) * size);
				window.draw(sprite1);
			}
		}

		//draw miner
		sprite2.setPosition((miner.x + 22) * size, (miner.y + 45) * size);
		window.draw(sprite2);

		//update score as miner dives deeper into cave
		sf::Font font;
		sf::Text minerScore;
		std::stringstream ss;
		ss << score;

		minerScore.setFont(font);

		minerScore.setString(ss.str().c_str());
		minerScore.setCharacterSize(27);

		minerScore.setPosition(22, 90);
		window.draw(minerScore);

		window.display();
	}

	return 0;
}