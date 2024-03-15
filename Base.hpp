/**
 * @file bases.hpp
 * @author Jorge Ricarte Passos Gonçalves (jorgericartepg@gmail.com)
 * @brief Implementation file for software timers management.
 * @version 0.1
 * @date 2024-03-08
 *
 * @copyright Copyright (c) 2024
 *
 * This file provides functions to manage software timers.
 */

#ifndef BASE_H
#define BASE_H

#include "stm32f0xx_hal.h"

class Base {
public:
    Base() : intervalMs_(0), startTime_(0), elapsedTime_(0) {}

    void start(uint32_t interval) {
        intervalMs_ = interval;
    }

    bool get() const {
        auto currentTime = getTick(); // Get the current time

        // Handle overflow
        if (currentTime < startTime_) {
            // Overflow occurred, adjust the difference
            elapsedTime_ = UINT32_MAX - startTime_ + currentTime;
        } else {
            elapsedTime_ = currentTime - startTime_;
        }

        return elapsedTime_ >= intervalMs_;
    }

    void restart() {
        startTime_ = getTick(); // Using getTick() to get the initial time
    }

protected:
    uint32_t getTick() const override {
            return HAL_GetTick();
        }
        
private:
    uint32_t intervalMs_; // Interval in milliseconds
    uint32_t startTime_;   // Timer start time
    mutable uint32_t elapsedTime_; // Time elapsed since start
};

#endif // BASE_H