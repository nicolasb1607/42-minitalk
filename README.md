# Minitalk Project

## Introduction

Welcome to the **Minitalk** project! In this project, you will create a communication program consisting of a client and a server. The server will be responsible for receiving and displaying messages sent by clients. The communication between the client and server will be done exclusively using UNIX signals.

## Common Instructions

Before we delve into the project specifics, let's review some common instructions that apply to this project:

- **Language**: Your project must be written in C.

- **Norm Compliance**: Your project must adhere to the Norm. Norm errors, including those in bonus files/functions, will result in a score of 0.

- **Stability**: Your functions should not quit unexpectedly (e.g., segmentation fault, bus error, double free) except for undefined behaviors. Unexpected crashes will lead to a non-functional evaluation.

- **Memory Management**: Properly free all heap allocated memory space. No memory leaks will be tolerated.

- **Makefile**: If required by the subject, include a Makefile to compile your source files with the flags -Wall, -Wextra, and -Werror using cc. Ensure your Makefile does not relink and includes the rules $(NAME), all, clean, fclean, and re.

- **Bonuses**: If applicable, create a bonus rule in your Makefile to include headers, libraries, or functions forbidden in the main part of the project. Store bonus code in separate _bonus.{c/h} files.

- **Libft Integration**: If permitted, integrate your libft by copying its sources and associated Makefile into a libft folder with its own Makefile. Your project’s Makefile should compile the library via its Makefile and then compile the project.

- **Testing**: Develop test programs for your project, although they won't be submitted or graded. These tests will assist in verifying your work and evaluating your peers' work during the defense.

- **Submission**: Submit your work to your assigned git repository. Deepthought may grade your work after peer evaluations, and any errors during Deepthought’s grading will halt the evaluation.

## Project Instructions

You must create a communication program with both a client and a server component. Here are the main requirements:

- Start the server first, which will print its PID.

- The client accepts two parameters:
  - The server PID.
  - The string to send.

- The client sends the specified string to the server.

- Upon receiving the string, the server must promptly display it.

- The server should display the string quickly; any delay is considered excessive.

- The server must handle messages from multiple clients without requiring a restart.

- Communication between the client and server must exclusively use UNIX signals, particularly SIGUSR1 and SIGUSR2.

Bonus features you can consider adding:

- Implement acknowledgment: The server acknowledges every received message by sending a signal back to the client.

- Unicode characters support: Enhance your program to support Unicode characters in messages.
