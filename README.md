# Build

## Visual Studio Code:
- Configure (will generate proper Makefile):
```bash
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Configure [<Type of build>]
```
- Build (will create execution binary):
```bash
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Build [<Type of build>]
```
By default "Debug" type of build is set, key sequence: `Ctrl + Shift + B` will rebuild "Debug" version.

## CMake:
To configure and build try following commands:
```
cmake -S . -B ./build/debug -DCMAKE_BUILD_TYPE=Debug"
cmake --build ./build/debug" --config "Debug"
```

# Run
Build artifacts are available in following directory:
```bash
./build/<build_type>/bin/
```
where `<build_type>` could be `debug` or `release`.
All information needed to properly execute calculator app can be displayed on `--help` / `-h` command

## execution mode
To run and execute expression type:
```bash
./calculator -e <expression>;
```
for example:
```bash
./calculator -e "(1+2)*3;"
```
Don't forget about the last sign `;`, it's needed to mark the end of expression, if the sign won't be provided
calcualtor will still wait for more tokens to process as a part of provided expression.

## interactive mode
To run:
```bash
./calculator -i
```
This will display the prompt and wait until user provide expression to evaluate, and confirm it with
<ENTER> key, for instance:
```bash
Launching calculator in interactive mode.
Enter expression (or q to quit):
> (1+2)*3;
= 9
> q
Exiting calculator.
```

## GUI mode
To run:
```bash
./calculator -u
```
This will display GUI:

<div>
    <p align="center" width="100%">
        <img src="./imgs/calculator_gui.png" width="60%" height="60%"/>
    </p>
</div>