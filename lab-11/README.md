# UDP Client-Server Project

This project demonstrates a basic UDP client-server communication using C++. The server listens for incoming messages, and the client sends messages to the server and receives replies.

## Files

- `MainClient.cpp`: Contains the client code for sending and receiving messages over UDP.
- `MainServer.cpp`: Contains the server code for receiving and responding to messages.
- `UDPSocket.h`/`UDPSocket.cpp`: Defines and implements the `UDPSocket` class for handling UDP communication.
- `UDPServer.h`/`UDPServer.cpp`: Defines and implements the `UDPServer` class that extends `UDPSocket` to handle server-specific functionality.

## Requirements

- C++11 or higher
- CMake (for building the project)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/UDPClientServerProject.git