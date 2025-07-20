# MINI SHELL

## introduction

```text
 ----------------
< Shell we begin >
 ----------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

## architecture

```
mini_shell/
├-- include/
│  ├-- init.h
│  ├-- utils.h
│  ├-- parser.h
│  ├-- builtin.h
│  └-- executor.h
├-- src/
│  ├-- init.c
│  ├-- utils.c
│  ├-- parser.c
│  ├-- builtin.c
│  ├-- executor.c
│  └-- main.c
├-- test/
│  ├-- ut_utils.cpp
├-- .gitignore
├-- CMakeLists.txt
└-- README.md
```

## log

### [2025-07-20]
#### Changed
- support execute command with pipe "|" 

### [2025-07-09]
#### Changed
- support parse command with pipe "|" 

### [2025-07-08]
#### Changed
- change struct **commandStru** from single command to linked list for pipe extension

### [2025-06-23]
#### Added
- built-in command: export

### [2025-06-22]
#### Added
- built-in command: pwd and echo

### [2025-06-05]
#### Added
- built-in command: cd
#### Fixed
- item search out from built-in commands hash table should not be freed

### [2025-05-22]
#### Changed
- use hash table to refactor built-in commands

### [2025-05-20]
#### Added
- built-in command: exit

### [2025-05-19]
#### Added
- seach for built-in commands 
 
### [2025-05-18]
#### Added
- utils and related unit test
- built-in functions
#### Fixed
- some details

### [2025-05-11]
#### Added
- basic functions
