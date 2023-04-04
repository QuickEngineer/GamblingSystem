//The player credential logic
#include "Player.h"
#include "IDGenerator.h"

Player::Player(string firstName, string lastName, string username, string email, string password) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->username = username;
	this->email = email;
	this->password = password;
	this->balance = 0.0f;
}

//Setters
void Player::setFirstName(string firstName)
{
	this->firstName = firstName;
}
void Player::setLastName(string lastName)
{
	this->lastName = lastName;
}
void Player::setUsername(string username)
{
	this->username = username;
}
void Player::setEmail(string email)
{
	this->email = email;
}
void Player::setPassword(string password)
{
	this->password = password;
}

void Player::setBalance(float newBalance)
{
	this->balance = newBalance;
}


//Getters
string Player::getFirstName()
{
	return this->firstName;
}
string Player::getLastName()
{
	return this->lastName;
}
string Player::getUsername()
{
	return this->username;
}
string Player::getEmail()
{
	return this->email;
}
string Player::getPassword()
{
	return this->password;
}

float Player::getBalance() 
{
	return this->balance;
}


//Balance specific functions

void Player::increaseBalance(float amount) 
{
	this->balance += amount;
}

void Player::decreaseBalance(float amount)
{
	this->balance += amount;
}


int Player::registerPlayer(string firstName, string lastName, string username, string email, string password)
{
	const string PLAYERFILENAME = "PlayerFile.txt";

	Player newPlayer(firstName, lastName, username, email, password);

	newPlayer.balance = 0.0f;

	//Open the Players-File
	std::ofstream writeFile;
	std::ifstream readFile;

	// Check for duplicate email or username in DB. 
	readFile.open(PLAYERFILENAME);
	if (readFile.is_open())
	{
		int id;
		string fName, lName, usrname, mail, pwd;
		float blnc;
		while (readFile >> id >> fName >> lName >> usrname >> mail >> pwd >> blnc)
		{
			if (usrname == username || mail == email)
			{
				std::cout << "User is already registered" << std::endl;
				readFile.close();
				return -1;
			}
		}
		//No duplicate in DB
		readFile.close();
		writeFile.open(PLAYERFILENAME, std::ios_base::app);
		if (writeFile.is_open())
		{
			newPlayer.id = generateID();
			writeFile << newPlayer.id << " " << newPlayer.firstName << " " << newPlayer.lastName << " " << newPlayer.username << " " << newPlayer.email << " " << newPlayer.password << " " << newPlayer.balance << std::endl;
			std::cout << "New Player Registered!" << std::endl;
			writeFile.close();
		}
		else
		{
			std::cout << "Could not open " << PLAYERFILENAME << " in writemode." << std::endl;
			return -1;
		}
	}
	else
	{
		std::cout << "Could not open " << PLAYERFILENAME << " in readmode." << std::endl;
		return -1;
	}

	return 0;

}