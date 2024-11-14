CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I lib.h
SRCS = main.c vote.c role_attribution.c president_turn.c chancelor_turn.c print_board.c computer_turn.c progress_bar.c
OBJS = $(SRCS:.c=.o)
TARGET = prog

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

run: all
	rm -f $(OBJS) && ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all
