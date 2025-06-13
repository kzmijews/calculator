# Build
Using Visual Studio Code:
```bash
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Configure [<Type of build>]
Ctrl + Shift + P
> Type: "Run Task"
> Select: "CMake Build [<Type of build>]
```
By default "Debug" type of build is set, key sequence: `Ctrl + Shift + B` will rebuild "Debug" version.

Using CMake directly:
```
cmake -S . -B ./build/debug -DCMAKE_BUILD_TYPE=Debug"
cmake --build ./build/debug" --config "Debug"
```

# Run
```bash
./build/release/bin/calculator
```