# DELEGATION (CURRENT):
	HAMOUN - 4. Preventing the planes from leaving the board ( bug fixing )
	THARANE - 3. Aircraft types (in c_airc.h/c_airc.cpp)
			note: when creating aircraft types
			lets say you want to add the spitfire in, please do it like
			
	name the classes ---->	struct supermarine_spitfire : public c_airc
	in the format:		{
	manufacturer_name		supermarine_spitfire(); <----- in c_airc.cpp you define all the stats
				}
	IZAK - 1. Implementing the attack action (ACTION_ATTACK and ACTION_ATTACKSEC)
# COMPILING THE PROJECT : 
	type 'make' into the terminal to build the executable from current code
	type 'make clean' into the terminal to clean up files generated from 'make'
# TESTING :
	to test any of our classes that we are working on:
	type 'make test_<classname>' where obviously <classname> could be c_airc or c_pilot or c_board
# NOTES ON CODE STRUCTURE :
	The code for this project will have the following structure

	SOURCE
	main.cpp : minimalistic code to simply execute the game
	game.cpp : includes all code relating to the actual gameplay (such as user input, prompts, scores, etc.)

	CLASSES
	c_airc.cpp : includes the abstract class for an aircraft and other aircraft types (spitfire, me 109 etc..)
	c_pilot.cpp : this will be an amalgamation of the functionality between enemy and player
			(This function won't differentiate between a player and an enemy, they're both pilots and the enemy behaviour can be coded into the game.cpp)
	c_board.cpp : this is a simple class which holds information about the board which holds the aircraft
# NOTES ON CODE COMPLETEION : (code must be completed roughly in this order to maximise our work efficiency)
	1. Board class (c_board.cpp)	- the board which shows the aircrafts
	2. Aircraft class (c_airc.cpp)	- aircraft attributes
	3. Pilot class (c_pilot.cpp)	- actions that a pilot can make (for example a function climb() will affect the position of an aircraft)
	
	4. Basic game loop (game.cpp)	- simply show that we can manipulate an aircraft using the actions coded into the pilot class
	5. Enemy behaviour (game.cpp)	- allow a proto-AI to "take control" and manipulate an aircraft using the actions coded into the pilot class
