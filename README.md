# libforza

A simple C library for receiving Forza telemetry
Compatible with Forza Motorsport 7, Forza Horizon 4 and 5

## Installation

1. Clone the repository
2. Build with `make`
3. Enable "Data Out" in Forza Settings
    - This is usually near the bottom of `HUD AND GAMEPLAY`
    - Set IP adress to `127.0.0.1` and port to
        - Forza Motorsport 7 `9917`
        - Forza Horizon 4 `9924`
        - Forza Horizon 5 `9925`
4. If you are using Forza from the Windows Store follow the instructions in [Network Isolation](#network-isolation)

## OS Support

Only compatible with Linux
WSL can be used on Windows, set Forza Data Out IP Address to WSL IP Address found with `ip a`

## Network Isolation

Windows store apps prevent localhost connections by default for "security"
This will need to be disabled for this program to work

Thankfully it can be done on a per-app basis

Steam/Linux players will not have to do this

Run this corresponding powershell command for your game

### Forza Motorsport 7:

```
CheckNetIsolation.exe LoopbackExempt -a -n="microsoft.apollobasegame_1.174.4791.2_x64__8wekyb3d8bbwe"
```

### Forza Horizon 4:

```
CheckNetIsolation.exe LoopbackExempt -a -n="microsoft.sunrisebasegame_8wekyb3d8bbwe"
```

### Forza Horizon 5:

```
CheckNetIsolation.exe LoopbackExempt -a -n="microsoft.624F8B84B80_8wekyb3d8bbwe"
```
