# Demo: Applications and Library for QNX Platform

## Problem

- Application 1: Receives data and displays a speedometer (presented as a circular scale with an arrow). Implementation details are not emphasized.
- Application 2: Generates data for Application 1. It's a console application in C++, employing continuous periodic generation based on time (e.g., sum of sines with different periods and coefficients).

The library facilitates asynchronous data exchange between Apps 1 and 2 using IPC. Other implementation details are omitted.

The application aims for a consistent output of 60 frames per second (fps).

## Solution

- **Application 1 (speedometer_display):**
  - Utilizes QT for displaying the speedometer and receiving speed data via IPC.
- **Application 2 (speedometer_sensor):**
  - A console application responsible for generating speed data and transmitting it to speedometer_display via IPC.
- Both applications utilize the **speedometer_ipc** library, which operates with POSIX queues.

### What Was Not Done

- **Platform Limitation:** Originally intended for QNX platform, but also intended for Linux due to the absence of QNX OS. Hence, POSIX queues were used instead of the QNX message API.
- **Namespaces:** Not implemented to condense code and enhance readability.
- **Unit Tests:** Not implemented.
- **Settings:** Not implemented.
- **Logging:** Not implemented.
