COMPILING THE PROJECT : 
#	type 'make' into the terminal to build the executable from current code
#	type 'make clean' into the terminal to clean up files generated from 'make'

NOTES ON THE MAKEFILE :
#	Current makefile version is 1

NOTES ON CODE STRUCTURE :
#	The code for this project will have the following structure

#	SOURCE
#	main.cpp : minimalistic code to simply execute the game
#	game.cpp : includes all code relating to the actual gameplay (such as user input, prompts, scores, etc.)

#	CLASSES
#	c_airc.cpp : includes the abstract class for an aircraft and other aircraft types (spitfire, me 109 etc..)
#	(IN FUTURE) c_pilot.cpp : this will be an amalgamation of the functionality between enemy and player
#			(This function won't differentiate between a player and an enemy, they're both pilots and the enemy behaviour can be coded into the game.cpp)

NOTES ON CODE COMPLETEION : (code must be completed roughly in this order to maximise our work efficiency)
#	1. Aircraft class (c_airc.cpp)	- aircraft attributes
#	2. Pilot class (c_pilot.cpp)	- actions that a pilot can make (for example a function climb() will affect the position of an aircraft)

#	3. Basic game loop (game.cpp)	- simply show that we can manipulate an aircraft using the actions coded into the pilot class
#	4. Enemy behaviour (game.cpp)	- allow a proto-AI to "take control" and manipulate an aircraft using the actions coded into the pilot class

DELEGATION (CURRENT):
#	HAMOUN - 4. Enemy behaviour
#	THARANE - 3. Basic game loop
#	IZAK - 1. Aircraft class, makefile
