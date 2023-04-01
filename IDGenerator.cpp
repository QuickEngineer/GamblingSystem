#include <fstream>
#include <iostream>
#include "IDGenerator.h"

bool isEmpty(std::ifstream& file)
{
	return file.peek() == std::ifstream::traits_type::eof();
}

int generateID()
{
	const std::string IDFILENAME = "ID.txt";
	int id = 0;
	//Open the ID-File
	std::ofstream writeFile;
	std::ifstream readFile;
	readFile.open(IDFILENAME);
	//Read the last ID
	if (readFile.is_open()) 
	{
		if (isEmpty(readFile))
		{
			readFile.close();
			writeFile.open(IDFILENAME);
			if(writeFile.is_open())
			{
				writeFile << 1;
				id = 1;
				writeFile.close();
			}
			else
			{
				std::cout << "ERROR: Could not write to empty ID-file" << std::endl;
				return -1;
			}
		}
		else
		{
			readFile >> id;
			readFile.close();
		}
	}
	else
	{
		std::cout << "ERROR: Something went wrong when trying to open ID-File in readmode" << std::endl;
		return -1;
	}
	
	//Generate next ID
	id++;
	//Save the new ID
	writeFile.open(IDFILENAME);
	if (writeFile.is_open())
	{
		writeFile << id;
	}
	else
	{
		std::cout << "ERROR: Could not open ID-File in writemode" << std::endl;
		return -1;
	}
	//Return new ID
	
	//Testing
	std::cout << "ID:" << id << std::endl;

	return id;
}
