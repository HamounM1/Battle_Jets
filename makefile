#MAKEFILE V1
#(Thanks to www3.ntu.edu.sg and softwarecarpentry [youtube] for information)

#VARIABLES
CC = g++
CC_FLAGS = -Wall -Werror

#TARGETS
all: obj main					#DEFAULT TARGET : requires relocatables folder (obj) and an executable (main)
obj:						#OBJ DIRECTORY TARGET : creates a directory to store .o files
	mkdir -p obj
main: obj/main.o obj/game.o obj/c_airc.o	#MAIN TARGET : links relocatables (.o) to generate executable (main) | main.o + game.o + (*.o) --> main |
	$(CC) $(CC_FLAGS) -o $@ $^
obj/main.o: src/main.cpp			#MAIN.O TARGET : compiles source (main.cpp) to relocatable (main.o) | main.cpp --> obj/main.o |
	$(CC) -c -o $@ $^
obj/game.o: src/game.cpp			#GAME.O TARGET : compiles source (game.cpp) to relocatable (game.o) | game.cpp --> obj/game.o |
	$(CC) -c -o $@ $^
obj/c_airc.o: src/class/c_airc.cpp		#C_AIRC.O TARGET : compiles source (c_airc.cpp) to relocatable (c_airc.o) | c_airc.cpp --> obj/c_airc.o |
	$(CC) -c -o $@ $^
clean:						#CLEAN TARGET : removes executable (main) and relocatables (obj recursive)
	rm -r -f main obj
