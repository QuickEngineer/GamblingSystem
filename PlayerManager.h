#include <iostream>
#include "Player.h"
using std::string;

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
class PlayerManager
{
	PlayerManager();

	void registerPlayer(Player);

	void loginPlayer(Player);

	void writeToDB(Player);

	void readFromDB();

	void searchInDB();

};
#endif

