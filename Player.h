#include <iostream>

using std::string;

#ifndef PLAYER_H
#define PLAYER_H
//A class to store and manage all player credentials. For now it stores the balance too but im thinking about changeing that to a sub-class. 
class Player
{
public:
	int id;
	string firstName;
	string lastName;
	string username;
	string email;

	Player(string, string, string, string, string);

	void setFirstName(string);
	void setLastName(string);
	void setUsername(string);
	void setEmail(string);

	string getFirstName();
	string getLastName();
	string getUsername();
	string getEmail();

	string password;
	float balance;

	void setPassword(string);
	string getPassword();

	//Change to a separate class? Might be better to inherit this class.. 
	void setBalance(float);
	void increaseBalance(float);
	void decreaseBalance(float);
	float getBalance();

	//Player Management
	int registerPlayer(string, string, string, string, string);

	int loginPlayer(string, string);
	
private:
	const string PLAYERFILENAME = "PlayerFile.txt";

};
#endif