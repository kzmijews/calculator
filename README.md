# Overview

> ⚠️ **Warning**: This project is not fully functional yet. Stay tuned for updates!

This implementation of the Calculator App uses a **Context-Free Grammar (CFG)** to define
the structure of valid expressions and instructions. **CFG** is a formal set of production
rules that describe how expressions in a language can be formed.

The grammar is based on **BNF (Backus-Naur Form)** — a notation used to formally specify
the syntax of programming languages and other structured formats. **BNF** is considered
a meta-syntax, meaning it provides a systematic way to describe the rules that govern the
structure of a language. It is commonly used for defining document formats, instruction
sets, and communication protocols.

There are several variations of **BNF**, including:
- **EBNF (Extended Backus-Naur Form)** – introduces additional syntactic sugar for readability.
- **ABNF (Augmented Backus-Naur Form)** – often used in internet protocol specifications.

BNF-based grammars consist of three fundamental components:
- **Non-terminal symbols** – These represent abstract language constructs and are typically
enclosed in angle brackets (e.g., <expression>, <term>). They can be replaced by other
non-terminals or terminals according to the grammar rules.
- **Terminal symbols** – These are the actual symbols or keywords used in the language
(e.g., +, -, numbers, parentheses).
- **Production rules (derivations)** – These define how non-terminal symbols can be rewritten
as a combination of terminals and/or non-terminals.

Simplified BNF Grammar of the Calculator:

```
<expression> ::= <term>
              | <expression> + <term>
              | <expression> - <term>

<term>       ::= <primary>
              | <primary> * <term>
              | <primary> / <term>

<primary>    ::= <number>
              | ( <expression> )
              | - <primary>
```

This grammar allows for arithmetic expressions using addition, subtraction, multiplication,
division, parentheses, and unary negation. Parsing is done recursively, reflecting the
hierarchical structure defined by these grammar rules.

# Build
To build this project, a few prerequisites are required:
- Qt 6.9.1 (used for the GUI)
- g++ compiler
- CMake build tools

To simplify the build process and ensure consistency, the entire build environment is isolated
within a Docker container. The Dockerfile is structured into multiple stages to enable layer
caching. This means that only the first build may take a while; subsequent builds will be much
faster — as long as there are no changes to the build environment.

> **Note:** Building the project requires access to the Qt Essentials libraries, which are available
> to registered Qt users.

To obtain access, please create a free Qt account at:

👉 https://login.qt.io/register

You will need to provide your Qt credentials as build arguments.

## Steps to Build
1. Install Docker following the official instructions.
Example for Ubuntu: [Docker Installation Guide for Ubuntu](https://docs.docker.com/engine/install/ubuntu/)
2. Run the following command, replacing the placeholder values with your Qt account credentials:
```bash
sudo docker build \
    -f Dockerfile.build \
    --build-arg QT_USERNAME=<email-used-for-qt-registration> \
    --build-arg QT_PASSWORD=<password-used-for-qt-registration> \
    --output type=local,dest=./ .
```

The build output will be available in the `./artifacts` directory.

# Run
To run the application, essential OpenGL-related libraries are required. These libraries
will be installed automatically during the installation of the Calculator `.deb` package:
```bash
apt install -y ./artifacts/calculator_*.deb
```
Once installed, you can launch the application by running:
```bash
cd /opt/calculator/usr/bin/
./calculator -u
```
Alternatively, the application can be containerized with Docker:
```bash
docker build -t calculator .
```
To run the application from within the Docker container:
```bash
xhost +local:docker
docker run \
    --rm -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    calculator
```
The application supports multiple run modes, as described in the sections below.
For usage details and available options, execute the binary with the `--help` flag:
```bash
./calculator --help
```
To pass arguments to the application when running in Docker, use the `APP_ARGS`
environment variable:
```bash
-e APP_ARGS="--help"
```

## GUI mode
To launch the graphical user interface, run:
```bash
./calculator -u
```
This will display the GUI:

<div>
    <p align="center" width="100%" height="100%">
        <img src="./imgs/calculator_gui.png" width="300px" height="400px"/>
    </p>
</div>

## execution mode
To directly evaluate an expression, use the `-e` flag:
```bash
./calculator -e <expression>;
```
Example:
```bash
./calculator -e "(1+2)*3;"
```
> **Note:** Don’t forget the semicolon (;) at the end of the expression.
> It is required to signal the end of the input. If omitted, the calculator will
> continue to wait for additional tokens.

## interactive mode
To enter interactive mode, run:
```bash
./calculator -i
```
This mode displays a prompt and allows you to enter expressions one at a time,
confirming each with the `<ENTER>` key:
```bash
Launching calculator in interactive mode.
Enter expression (or q to quit):
> (1+2)*3;
= 9
> q
Exiting calculator.
```

# Development
If you prefer to set up the development environment directly on your host machine for greater
control during development, follow the tips below.

## Visual Studio Code
Recommended configuration files are provided in the `./.vscode` directory. These allow you to:
- Configure the project (this generates the appropriate Makefile):
```bash
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Configure [<Type of build>]
```
- Build the project (this compiles the executable binary):
```bash
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Build [<Type of build>]
```
By default, the build type is set to Debug, so pressing `Ctrl + Shift + B` will rebuild the project
in Debug mode.

## CMake
Alternatively, you can configure and build the project directly using the CMake command-line tools:
```bash
cmake -S . -B "./build/Debug" -DCMAKE_BUILD_TYPE="Debug"
cmake --build "./build/Debug" --config "Debug"
```
To create `.deb` package:
```bash
cpack -G DEB -B "./build/deb" --config "./build/Debug/CPackConfig.cmake"
```

# Release
To release a new version of the Calculator application, first tag the source code you wish to use
for the release using [semantic versioning](https://semver.org). Then, push the tag to the repository.
For example:
```bash
git tag v1.0.0
git push origin v1.0.0
```