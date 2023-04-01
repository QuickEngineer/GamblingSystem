//The player credential logic
#include "Player.h"

Player::Player(string firstName, string lastName, string username, string email, string password) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->username = username;
	this->email = email;
	this->password = password;
	this->balance = 0.0f;
}

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

float Player::getBalance() {
	return this->balance;
}