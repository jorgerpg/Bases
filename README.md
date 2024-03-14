## Table of Contents
* [General Info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Usage](#usage)
* [Contributing](#contributing)
* [Contact](#contact)

## General Info
This repository contains a C++ code implementation for a software timer management class named `Base`. The `Base` class provides functionalities to start, check, and restart timers, making it useful for time-related tasks in embedded systems or other applications.

## Technologies
The code is written in C++ and utilizes the [HAL (Hardware Abstraction Layer)](https://en.wikipedia.org/wiki/Hardware_abstraction) library for obtaining the system tick. It is assumed that the `HAL_GetTick()` function is available in the environment.

## Setup
To incorporate the `Base` class into your project, follow these steps:

1. Copy the `Base` class implementation (from `Base.hpp`) into your project.
2. Include the necessary headers, such as `main.h` and any required system headers.
3. Ensure that the `HAL_GetTick()` function or an equivalent is available in your environment.

## Usage
To use the `Base` class for software timer management, follow the example below:

```cpp
#include "Base.hpp"

int main() {
    Base timer;

    // Setting the interval to 1000 milliseconds (1 second)
    timer.start(1000);

    // Waiting until the interval is reached
    if (timer.get()) {
        // Perform tasks
        led.toggle(0);
        // Restart the timer for the next cycle
        timer.restart();
    }

    return 0;
}
```

## Contributing
Feel free to contribute to the project by opening issues or submitting pull requests. Your input is highly appreciated!

## Contact
For any questions or suggestions, please contact the project maintainer:
* Jorge Ricarte Passos Gonçalves [[Jorgerpg](https://github.com/jorgerpg)]