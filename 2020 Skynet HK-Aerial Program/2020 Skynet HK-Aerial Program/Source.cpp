/* By: Naszir Merritt
*  In this project we create a 8 by 8 grid that is searched.
* Using a given algorithim code.
* This project uses random number generating,
* Two new files, <cstdlib> and <ctime>, booleans,
* and do while loops.
*/


// files for the program to pull from
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0))); // Seeds the random number givien the current time

	int EnemyLocation = rand() % 64 + 1; // number between 1 and 64 for EnemyLocation

	int BoxMax = 64; // Max guess place holder

	int BoxMin = 1; // Min guess place holder

	int Predictions = 0; // number of predictions place holder 

	int GuessLocation = rand() % 64 + 1; // number between 1 and 64 for BinarySkyNetGuess


	bool EnemyFound = false; // boolean for if enemy is found 

	// Welcoming the user to the program
	cout << "\n\t\t\t\t\t Welcome to Skynet, This is just a test.\n\n";
	cout << "Together we will witness our first model of Skynet search, Binary Skynet.\n\n";
	cout << "Binary Skynet program Initalizing...\n\n";
	cout << "User, this program will precisely find anything in the 8x8 sector.\n";
	cout << "Binary SKynet, hunts down and tracks sectors of the program in order to find the target.\n";

	// do loop for the BinarySkynet 
	do
	{
		cout << "'Binary Skynet' Sending out ping #" << Predictions << "\n";


		if (GuessLocation > EnemyLocation) // gives condition for if guessed location is too high
		{
			cout << "\nThe enemy location is not in the box #" << GuessLocation << ", the number is too high.\n"; // Tells the user that the guess is too high
			
			BoxMax = GuessLocation; // changes the max to last guessed

			GuessLocation = ((BoxMax - BoxMin) / 2) + BoxMin; // next guessed location 

			Predictions++; // increments the prediction counter
		}
		else if (GuessLocation < EnemyLocation) // gives condition if guessed location is too low 
		{
			cout << "\nThe enemy location is not in box #" << GuessLocation << ", the number is too low.\n"; // tells user that guess is too low 

			BoxMin = GuessLocation; // changes the min to last guessed location

			GuessLocation = ((BoxMax - BoxMin) / 2) + BoxMin; 

			Predictions++;
		}
		if (GuessLocation == EnemyLocation) // gives condition if the enemylocation is equal to guessed location
		{
			cout << "\nThe enemy was located in box #" << EnemyLocation << "\n"; // tells user where enemy was found 
			
			cout << "\nEnemy Location spotted. Only took 'Binary Skynet' " << Predictions << " search attempts.\n"; // tells user number of attempts

			EnemyFound = true; // sets  enemy found  boolean to true 

		}
	} while (EnemyLocation != GuessLocation); // gives condition of until enemy is found, run the program

	system("pause"); // pauses program 
	return (0);






}