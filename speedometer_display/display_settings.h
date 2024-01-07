#ifndef SETTINGS_H
#define SETTINGS_H

// The next constants are use for the demo example and later
// may be substituted by real values from settings.

constexpr int maxSpeed{240};
constexpr int speedStep{20};
constexpr int numSteps{maxSpeed / speedStep};
constexpr int degreeStep{180 / numSteps};

constexpr int windowWidth{640};
constexpr int windowHeight{320};

#endif // SETTINGS_H
