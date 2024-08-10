# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SYN_CLIENT_SRC = syn_client.c
SYN_SERVER_SRC = syn_server.c
ACCEPT_CLIENT_SRC = accept_client.c
ACCEPT_SERVER_SRC = accept_server.c

# Header files
SYN_HEADERS = syn_client.h syn_server.h
ACCEPT_HEADERS = accept_client.h accept_server.h

# Executables
SYN_CLIENT = syn_client
SYN_SERVER = syn_server
ACCEPT_CLIENT = accept_client
ACCEPT_SERVER = accept_server

.PHONY: all clean syn accept

# Default target
all: syn accept

# Build syn_client and syn_server
syn: $(SYN_CLIENT) $(SYN_SERVER)

$(SYN_CLIENT): $(SYN_CLIENT_SRC) $(SYN_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SYN_CLIENT_SRC)

$(SYN_SERVER): $(SYN_SERVER_SRC) $(SYN_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SYN_SERVER_SRC)

# Build accept_client and accept_server
accept: $(ACCEPT_CLIENT) $(ACCEPT_SERVER)

$(ACCEPT_CLIENT): $(ACCEPT_CLIENT_SRC) $(ACCEPT_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(ACCEPT_CLIENT_SRC)

$(ACCEPT_SERVER): $(ACCEPT_SERVER_SRC) $(ACCEPT_HEADERS)
	$(CC) $(CFLAGS) -o $@ $(ACCEPT_SERVER_SRC)

# Clean up generated files
clean:
	rm -f $(SYN_CLIENT) $(SYN_SERVER) $(ACCEPT_CLIENT) $(ACCEPT_SERVER)

