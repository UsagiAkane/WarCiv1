#include "WindowManager.h"
#include "GameManager.h"

WindowManager::WindowManager()
{
	this->w.create(sf::VideoMode(1000, 600), "WC"/*, sf::Style::Fullscreen*/);
	this->w.setFramerateLimit(60);

}

void WindowManager::mainWindow() {

	try {
		GameManager game;
		//sf::RenderWindow w(sf::VideoMode(1000, 600), "TITLE"/*, sf::Style::Fullscreen*/);

		sf::View view(w.getView());



		while (w.isOpen()) {
			sf::Event event;

			//CAMERA CONTROL
			if (isMouseInWindow(w))
				cameraControl(view, w);

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				if (event.type == sf::Event::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						if (isMenu)isMenu = 0;
						else isMenu = 1;
					}
				}

				if (!isMenu)
				{
					//Check is mouse in window
					if (isMouseInWindow(w))
					{
						//all other control
						game.getActors().at(0).takeControl(event, game.getMap(), w);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//If you want to attack or move unit
						{
							if (event.MouseButtonReleased)
								game.getActors().at(0).takeControlUnit(event, game.getMap(), w, game.findActorUnit(getPosMouseByWindowX(w), getPosMouseByWindowY(w)));
						}

					}
				}




			}


			w.setView(view);
			//WINDOW-FILL-COLOR
			w.clear(sf::Color::Green);
			//draw all in game
			game.draw(w);

			if (isMenu)
				mainMenu(w);
			//DISPLAY
			w.display();

		}
	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}
}

void WindowManager::cameraControl(sf::View& view, sf::Window& w)
{
	if (sf::Mouse::getPosition(w).x >= w.getSize().x - BORDER_PIXEL_32)
		view.move(BORDER_PIXEL_32 / 6, 0);
	if (sf::Mouse::getPosition(w).x <= BORDER_PIXEL_32)
		view.move(-BORDER_PIXEL_32 / 6, 0);
	if (sf::Mouse::getPosition(w).y <= BORDER_PIXEL_32)
		view.move(0, -BORDER_PIXEL_32 / 6);
	if (sf::Mouse::getPosition(w).y >= w.getSize().y - BORDER_PIXEL_32)
		view.move(0, BORDER_PIXEL_32 / 6);
}

bool WindowManager::isMouseInWindow(sf::RenderWindow& w)
{
	return (sf::Mouse::getPosition(w).x >= 0 && sf::Mouse::getPosition(w).x < w.getSize().x) && ((sf::Mouse::getPosition(w).y >= 0 && sf::Mouse::getPosition(w).y < w.getSize().y)) ? true : false;
}

int WindowManager::getPosMouseByWindowX(sf::RenderWindow& w)
{
	return sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2);
}

int WindowManager::getPosMouseByWindowY(sf::RenderWindow& w)
{
	return  sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2);
}


void WindowManager::mainMenu(sf::RenderWindow& w)
{
	sf::Texture texture;
	texture.loadFromFile("Icons\\menuBG.png");
	texture.setSmooth(1);
	sf::Sprite backGroundImage(texture);

	backGroundImage.scale(3, 3);

	sf::Texture menuTexture1;
	menuTexture1.loadFromFile("Icons\\menu.png");
	sf::Sprite bNewGame(menuTexture1), bContinue(menuTexture1), bExit(menuTexture1), bLoadGame(menuTexture1);
	sf::Font font;
	font.loadFromFile("18536.ttf");
	sf::Text tNewGame, tContinue, tExit, tLoadGame;

	//inicializate----------------------------------
	tNewGame.setFont(font);
	tNewGame.setString("New game");
	tContinue.setFont(font);
	tContinue.setString("Continue");
	tLoadGame.setFont(font);
	tLoadGame.setString("Load game");
	tExit.setFont(font);
	tExit.setString("Exit");

	bNewGame.setScale(1.5, 1.5);
	bContinue.setScale(1.5, 1.5);
	bLoadGame.setScale(1.5, 1.5);
	bExit.setScale(1.5, 1.5);

	sf::FloatRect localBounds = tNewGame.getLocalBounds();
	tNewGame.setOrigin(localBounds.left + localBounds.width / 2.0f, localBounds.top + localBounds.height / 2.0f);

	localBounds = tNewGame.getLocalBounds();
	tContinue.setOrigin(localBounds.left + localBounds.width / 2.0f, localBounds.top + localBounds.height / 2.0f);

	localBounds = tLoadGame.getLocalBounds();
	tLoadGame.setOrigin(localBounds.left + localBounds.width / 2.0f, localBounds.top + localBounds.height / 2.0f);

	localBounds = tExit.getLocalBounds();
	tExit.setOrigin(localBounds.left + localBounds.width / 2.0f, localBounds.top + localBounds.height / 2.0f);


	//BAR---------------------------------------POS
	bNewGame.setPosition(static_cast<float>(w.getView().getCenter().x - 100 * bNewGame.getScale().x), static_cast<float>(w.getView().getCenter().y - 45 * bNewGame.getScale().y));
	bContinue.setPosition(static_cast<float>(w.getView().getCenter().x - 100 * bContinue.getScale().x), static_cast<float>(w.getView().getCenter().y - 15 * bContinue.getScale().x));
	bLoadGame.setPosition(static_cast<float>(w.getView().getCenter().x - 100 * bLoadGame.getScale().x), static_cast<float>(w.getView().getCenter().y + 15 * bLoadGame.getScale().x));
	bExit.setPosition(static_cast<float>(w.getView().getCenter().x - 100 * bExit.getScale().x), static_cast<float>(w.getView().getCenter().y + 45 * bExit.getScale().x));

	//TEXT-----------------------------------------POS
	tNewGame.setPosition(static_cast<float>(bNewGame.getPosition().x + 100 * bNewGame.getScale().x), static_cast<float>(bNewGame.getPosition().y + 15));
	tContinue.setPosition(static_cast<float>(bContinue.getPosition().x + 100 * bContinue.getScale().x), static_cast<float>(bContinue.getPosition().y + 15));
	tLoadGame.setPosition(static_cast<float>(bLoadGame.getPosition().x + 100 * bLoadGame.getScale().x), static_cast<float>(bLoadGame.getPosition().y + 15));
	tExit.setPosition(static_cast<float>(bExit.getPosition().x + 100 * bExit.getScale().x), static_cast<float>(bExit.getPosition().y + 15));



	while (isMenu)
	{
		sf::Event ev;
		while (w.pollEvent(ev)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				isMenu = false;
			if (ev.type == sf::Event::Closed)
				w.close();
	/*		if (ev.type == sf::Event::MouseWheelScrolled)
			{
				if (ev.mouseWheelScroll.delta > 0)
				{
					w.getView().zoom(0.99f);
				}
				else if (event.mouseWheelScroll.delta < 0)
				{
					view.zoom(1.01f);
				}
			}*/
		}
		w.clear(sf::Color(0, 0, 0));

		w.draw(backGroundImage);
		//bar
		w.draw(bNewGame);
		w.draw(bContinue);
		w.draw(bLoadGame);
		w.draw(bExit);
		//text
		w.draw(tNewGame);
		w.draw(tContinue);
		w.draw(tLoadGame);
		w.draw(tExit);

		w.display();
	}



}

sf::RenderWindow& WindowManager::getWindow()
{
	return this->w;
}



//////////////////////////////////DON'T USE THIS////////////////////////////
		/*	if (event.type ==sf::Event::MouseWheelScrolled)
			{
				if (event.mouseWheelScroll.delta > 0)
				{
					view.zoom(0.99f);
				}
				else if (event.mouseWheelScroll.delta < 0)
				{
					view.zoom(1.01f);
				}
			}*/