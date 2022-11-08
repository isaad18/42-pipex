# 42-pipex
<h1 align="center">
	📖 Pipex
</h1>

<p align="center">
	<b><i>Implementing Shell Pipes</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/isaad18/42-pipex?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/isaad18/42-pipex?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/isaad18/42-pipex?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/isaad18/42-pipex?color=green" />
</p>

## Description

#### Implemented shell pipes and executing simple relative path commands with two types of redirection which is reading a file for the first command and then putting the output in the other file, by forking for every command so they can execute at the same time and the second command will wait for the output from the first one. Using the functions pipe, dup2, fork, and execve implemeting pipes was possible as I used pipe to take the input of the first command and pass it to the second command, dup2 to redirect the output of the commands to another file and be able to take another file as an input, fork to create child processes to be able to execute the commands correctly at the same time, and execve to be abe to execute the commands and take their output.

## QuickStart

#### Makefile is provided so you can execute all files using the following command
```
make all
```

#### then execute with the suitable arguements

- [file1] => the file to read from.
- [cmd1] => the command to execute before the pipe.
- [cmd2] => the command to execute after the pipe.
- [file2] => the file to put the output of the command inside.

```
./pipex [file1] [cmd1] [cmd2] [file2]
```
