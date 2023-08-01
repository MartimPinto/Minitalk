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
git@github.com:MartimPinto/ft_printf.git ft_printf
```
#### 2nd - Enter the library folder and run Make
``` bash
cd ft_printf/src
make
```
#### 3rd - Include the header in your .c file
``` c
#include "ft_printf.h"
```
## Norme

All 42 projects must be written following the **Norme**.

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
 	- Each line must be at most 80 columns wide, comments included
	- A function can take 4 named parameters maximum
	- No more than 5 variables in 1 function
