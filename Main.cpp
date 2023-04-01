//Main thoughts on this project. This project is supposed to build into a complete gambling platform. For now I focus on the backend and create the
//user base and a couple of games, think roulette, slotmachines and 1 or 2 other random influenced gamemechanics. Each player will have 
//an individual balance and login to the platform, all will be handled in this backend engine. The games will import these credentials so every player
//needs to login to the platform and can then increase their balance so they are able to interact with the gameplatforms. 
//The end goal is to have a running platform with 3-4 games, a login with credentials and balance on the backend and a complete frontend-base to go with 
//this platform. Nothing will be without fault... or secure... but it should run without any mayor bugs. Code-time should be around a week or two. 

//Time spent: 5h

#include <iostream>
#include "Player.h"


int main() {

	//*TESTING Should be moved to a separete PlayerTest-class
	Player player("Jacob", "Winthwood", "jwinth", "jwinth@gmail.com", "superSecurePassw0rd");
	Player player2("Jenna", "Berg", "jberg", "jberg@gmail.com", "anotherSecurePassw0rd");

	player.setFirstName("James");

	std::cout << player.getFirstName() << std::endl;
	std::cout << player2.getEmail() << std::endl;
	
	std::cout << player.getBalance() << std::endl;
	//*TESTING
	return 0;
}