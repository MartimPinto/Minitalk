# Minitalk
>Server/client system that uses UNIX signals for communication

</p>
<p align="center">
	<a href="#about">About</a> •
	<a href="#usage">Usage</a> •
	<a href="#norme">Norme</a>
</p>

## About
The Minitalk project consists of creating a client-server program that allows two processes (one acting as the server and the other as the client) to communicate with each other using UNIX signals. In the mandatory part of this assignment, the Client must communicate a string passed as a parameter to the server (referenced by its process ID) and display it and in the bonus part the Server must send a message of acknowledgment back to the Client. This project introduces concepts such as Signal Handling, Bitwise Operations, and Low-Level Networking.

## Usage
#### 1st - Clone the repository
``` bash
git@github.com:MartimPinto/Minitalk.git Minitalk
```
#### 2nd - Enter the project folder and run Make or Make bonus
``` bash
cd Minitalk

make

or

make bonus
```
#### 3rd - Run server or server_bonus and copy its PID
```bash
./server
./server_bonus
```

#### 4th - Open another terminal, run client or client_bonus, paste the PID and write a message
```bash
./client [SERVER PID] [MESSAGE]
./client_bonus [SERVER PID] [MESSAGE] [EMOTE]
```
## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function
