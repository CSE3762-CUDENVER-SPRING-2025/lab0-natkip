#Compiler
CC = gcc

#Flags
CFLAGS = -Wall -g

#Executables
CLIENT_EXEC = udp_client
SERVER_EXEC = udp_server

#Source files
CLIENT_SRC = udp_client.c
SERVER_SRC = udp_server.c

# Default target: build both client and server
all: $(CLIENT_EXEC) $(SERVER_EXEC)

# Rule to build the client
$(CLIENT_EXEC): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_EXEC) $(CLIENT_SRC)

# Rule to build the server
$(SERVER_EXEC): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_EXEC) $(SERVER_SRC)

# Clean target to remove executables and temporary files
clean:
	rm -f $(CLIENT_EXEC) $(SERVER_EXEC) *.o

# Phony targets
.PHONY: all clean

