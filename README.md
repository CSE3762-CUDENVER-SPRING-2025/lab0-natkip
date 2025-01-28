
# Lab 0 Networking Class

## Description
This project demonstrates a **UDP-based client-server communication** system. The server listens on a specified port, receives a message from the client, and responds with "Welcome to CSE5462". The client sends a "Hello, World!" message to the server and waits for the server's response.

This project is implemented in C and can run across multiple nodes.
---

## Features
- **UDP Client**: Sends a "Hello, World!" message to the server and displays the server's response.
- **UDP Server**: Listens for incoming messages, logs client details, and sends "Welcome to CSE5462".
- **Configurable and Lightweight**: Easily modifiable constants like port and buffer sizes for flexibility.

---

## Requirements
- GCC or any C compiler
- Unix-based system (Linux/MacOS)
- Basic knowledge of networking and C programming

---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone [repository-url]
   cd [repository-folder]
   ```

2. **Build the Project** using the provided `Makefile`:
   ```bash
   make
   ```
   This will generate the executables `udp_client` and `udp_server`.

---

## Usage

### 1. Start the Server
Run the server on the desired node:
```bash
./udp_server
```
The server will listen on the default port `2132` and wait for client messages. The user can replace the port number with the specified port of their choosing.

### 2. Start the Client
Run the client on another node or the same node (replace the server IP in the client code if necessary):
```bash
./udp_client
```
The client will send a "Hello, World!" message to the server and display the server's response.

The response displayed should be "Welcome to CSE5462".

---

## Project Structure

- **udp_server.c**: Implements the UDP server.
- **udp_client.c**: Implements the UDP client.
- **Makefile**: Automates the compilation of the client and server.

---

## Configuration

You can adjust the following constants in the code:
- `SERVERIP`: The server's IP address (in `udp_client.c`).
- `SERVERPORT`: The port number used for communication (in both `udp_client.c` and `udp_server.c`).
- `BUFFERSIZE`: Size of the message buffer.

---

## License
This project is open-source and distributed under the [MIT License](LICENSE).
