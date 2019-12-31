#include "WindowManager.h"

void WindowManager::mainWindow(){
	std::srand(time(NULL));
	Map map(100, 100);

	Actor enemyActor("Ruslan",map);
	enemyActor.setPlayerID(2);
	////////////////////////////CREATING UNITS
	std::vector<int> enemiesID;
	enemiesID.push_back(2);
	//enemy units
	//std::vector<Unit> EnemyUnitVector;
	Legion *legionEnemy=new Legion;
	Militia *militiaEnemy=new Militia;
	militiaEnemy->setPlayerID(2);
	militiaEnemy->spawn(128, 128, map);
	//EnemyUnitVector.push_back(militiaEnemy);
	enemyActor.__PUSH_UNIT_DEBUG(militiaEnemy);
	legionEnemy->setPlayerID(2);
	legionEnemy->spawn(96, 96, map);
	//EnemyUnitVector.push_back(legionEnemy);
	enemyActor.__PUSH_UNIT_DEBUG(legionEnemy);

	Actor actor("Kolya",map);




	int what_unit = 0;
	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE"/*,Style::Fullscreen*/);
		//w.setVerticalSyncEnabled(1);

		while (w.isOpen()) {
#pragma region events
			Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();

				actor.takeControl(event,map,w,enemyActor.getUnits());

			}
#pragma endregion
			//WINDOW-FILL-COLOR
			w.clear(Color::Black);

			//MAP-DRAW
			map.draw(w);

			actor.draw(w);
			enemyActor.draw(w);
			//DISPLAY
			w.display();
		}
	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}
}
