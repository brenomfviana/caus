# CAUS

## Description

CAUS is a cellular automata simulator (its name is an acronym of Cellular
AUtomata Simulator). Cellular Automata is a

### B/S notation.

TODO

## Build and Run

Dependencies:

- C++17;
- CMake 3.13.

To build the project, go to the root and, through terminal, run the following
commands:

```
mkdir build
cd build
cmake ..
```

Then, type the following command to run CAUS (see the [samples](samples)):

```
./caus <cellular-automata-file>.yml
```

Or generate a random world and set the rulestring manually by using the follow
command:

```
./caus -rand <width> <height> <string_rule> <max_number_of_generations>
```

## Sample

Add a gif.

## License

This project is licensed under MIT license - see the [LICENSE](LICENSE) file for
details.
