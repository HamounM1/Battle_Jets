#MAKEFILE V3
#(Thanks to www3.ntu.edu.sg and softwarecarpentry [youtube] for information)

#VARIABLES
CC = g++
CC_FLAGS = -Wall -Werror

#TARGETS
all: obj main						#DEFAULT TARGET : requires relocatables folder (obj) and an executable (main)
obj:							#OBJ DIRECTORY TARGET : creates a directory to store .o files
	mkdir -p obj
main: obj/main.o obj/game.o obj/c_airc.o obj/c_pilot.o obj/c_board.o	#MAIN TARGET : links relocatables (.o) to generate executable (main) | main.o + game.o + (*.o) --> main |
	$(CC) $(CC_FLAGS) -o $@ $^
obj/main.o: src/main.cpp				#MAIN.O TARGET : compiles source (main.cpp) to relocatable (main.o) | main.cpp --> obj/main.o |
	$(CC) -c -o $@ $^
obj/game.o: src/game.cpp				#GAME.O TARGET : compiles source (game.cpp) to relocatable (game.o) | game.cpp --> obj/game.o |
	$(CC) -c -o $@ $^
obj/c_airc.o: src/class/c_airc.cpp			#C_AIRC.O TARGET : compiles source (c_airc.cpp) to relocatable (c_airc.o) | c_airc.cpp --> obj/c_airc.o |
	$(CC) -c -o $@ $^
obj/c_board.o: src/class/c_board.cpp			#C_BOARD.o TARGET : compiles source (c_board.cpp) to relocatable (c_board.o) | c_board.cpp --> obj/c_board.o |
	$(CC) -c -o $@ $^
obj/c_pilot.o: src/class/c_pilot.cpp			#C_PILOT.O TARGET : compiles source (c_pilot.cpp) to relocatable (c_pilot.o) | c_pilot.cpp --> obj/c_pilot.o |
	$(CC) -c -o $@ $^
clean:							#CLEAN TARGET : removes executable (main) and relocatables (obj recursive)
	rm -r -f main test_c_airc test_c_board test_c_pilot obj

#C_AIRC TEST
test_c_airc: obj/test_c_airc.o obj/c_airc.o
	$(CC) $(CC_FLAGS) -o $@ $^
obj/test_c_airc.o: obj src/test/test_c_airc.cpp src/class/c_airc.cpp
	$(CC) $(CC_FLAGS) -c -o $@ src/test/test_c_airc.cpp

#C_BOARD TEST
test_c_board: obj/test_c_board.o obj/c_board.o
	$(CC) $(CC_FLAGS) -o $@ $^
obj/test_c_board.o: obj src/test/test_c_board.cpp src/class/c_board.cpp
	$(CC) $(CC_FLAGS) -c -o $@ src/test/test_c_board.cpp

#C_PILOT TEST
test_c_pilot: obj/test_c_pilot.o obj/c_pilot.o
	$(CC) $(CC_FLAGS) -o $@ $^
obj/test_c_pilot.o: obj src/test/test_c_pilot.cpp src/class/c_pilot.cpp
	$(CC) $(CC_FLAGS) -c -o $@ src/test/test_c_pilot.cpp
