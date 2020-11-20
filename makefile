CC=g++
SRCS=text_game.cpp Controller.cpp Menu.cpp Role.cpp Weapon.cpp
OBJS=$(SRCS:.cpp=.o)
EXEC=game
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
.cpp.o:
	$(CC) -o $@ -c $< -DMYLINUX

clean:
	rm -rf $(OBJS)
	rm -rf game
	rm -rf user_database
