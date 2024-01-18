# simple_shell
This is repository contains my implementation of a simple Linux shell in C. This project is designed to:

- **Learn**: Gain practical experience with operating system concepts and system programming.
- **Challenge**: Implement core functionalities of a shell, including parsing commands, handling input/output, and executing programs.
- **Grow**: Develop problem-solving and coding skills through a hands-on project.

## Features:
- **Interactive Prompt**: Accept users command and displays input
- **Non-Interactive mode**: Works in non-intractive mode also like the linux shell
- **Command execution**: Runs all linux commands that can be executed by the linux simple shell except some built-ins command like `alias`

## Building and Running:
1. Clone the repository: 
```bash
git clone https://github.com/Hullaah/simple_shell
```
2. Install required dependencies:
```bash
sudo apt install build-essential
```
3. Build the Project:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
4. Run the executable:
```bash
./hsh
```

## Testing:
You can test the shell by running various Linux commands and checking the output. You can also write your own test script to ensure functionality.

## Contributing:
I welcome contributions to this project. Please feel free to open pull requests with bug fixes, improvements, or new features.

## Disclaimer:
This project is for educational purposes only and is not intended to be a fully functional shell replacement. It may not support all features of a real shell and may have limitations.

## Further resources
- The Linux Programming Interface: https://man7.org/tlpi/
- Bash documentation: https://www.gnu.org/software/bash/
