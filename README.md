# libforza

A simple C library for receiving Forza telemetry
Compatible with Forza Motorsport 7, Forza Horizon 4 and 5

## OS Support

Only compatible with Linux

WSL can be used on Windows, set Forza Data Out IP Address to WSL IP Address found with `ip a`

## Installation

1. Clone the repository
2. Build with `make`
2. Install with `sudo make install`
3. Enable "Data Out" in Forza Settings
    - This is usually near the bottom of `HUD AND GAMEPLAY`
    - Set IP adress to `127.0.0.1` (or WSL IP) and port to
        | Game               | Port |
        | ------------------ | ---- |
        | Forza Motorsport 7 | 9917 |
        | Forza Horizon 4    | 9924 |
        | Forza Horizon 5    | 9925 |

## Usage

View [demo.c](examples/demo.c) for an example implemenation of the library

View [forza.h](include/forza.h) to see avaiable functions as well as the `ForzaTelemetry` data structure


## Network Isolation

Bypassing UWP network isolation is unnecessary because either WSL will be the host, not requiring isolation, or the game will be launched with Steam, which does not use UWP.