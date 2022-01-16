#pragma once

#include "ForzaTelemetry.h"

#define IP_ADDRESS "0.0.0.0"
#define PORT 9924

ForzaTelemetry *get_latest_telemetry(void);