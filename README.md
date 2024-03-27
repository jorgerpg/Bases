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
The code is written in C++ and utilizes the [HAL (Hardware Abstraction Layer)](https://en.wikipedia.org/wiki/Hardware_abstraction) library for obtaining the system tick. It is assumed that the `HAL_GetTick()` function is available in the environment, just change it and the respective lib for your micro.

### Explanation of Functions

#### `Base::Base()`
- **Description**: Constructor for the `Base` class.
- **Functionality**: Initializes member variables `intervalMs_`, `startTime_`, and `elapsedTime_`. Sets the start time using the `getTick()` function.

#### `void Base::start(uint32_t interval)`
- **Description**: Sets the interval for the timer.
- **Parameters**: `interval`: The time interval in milliseconds.

#### `bool Base::get() const`
- **Description**: Checks whether the timer interval has elapsed.
- **Returns**: `true` if the interval has elapsed, `false` otherwise.

#### `void Base::restart()`
- **Description**: Restarts the timer, resetting the start time to the current time.

#### `uint32_t Base::getTick() const`
- **Description**: Retrieves the current system tick.
- **Returns**: The current system tick obtained using the `HAL_GetTick()` function or its equivalent. This function may need to be overridden by subclasses to provide the system tick implementation specific to the platform.


## Setup
To incorporate the `Base` class into your project, follow these steps:

### Adapting for Different Microcontrollers
If you intend to use this code with a different microcontroller, you may need to make the following changes:

1. **Replace HAL Library**: If you are using a microcontroller from a different manufacturer, you'll likely need to replace the `HAL_GetTick()` function with an equivalent function provided by the new microcontroller's hardware abstraction layer (HAL) library.

2. **Include Correct Headers**: Ensure that you include the appropriate headers for the new microcontroller platform. For example, if you switch to a microcontroller from a different family or manufacturer, you may need to include a different header file.

3. **Adjust Hardware-specific Code**: Any hardware-specific code, such as initialization routines or register access, may need to be modified to work with the new microcontroller.

By making these adjustments, you can adapt the `Base` class to work seamlessly with a different microcontroller platform.

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