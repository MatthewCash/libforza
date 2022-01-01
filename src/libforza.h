#pragma once

#include "ForzaTelemetry.h"

#define IP_ADDRESS "0.0.0.0"
#define PORT 9924

void store_latest_telemetry(ForzaTelemetry *new_telemetry);

ForzaTelemetry *get_latest_telemetry(void);

int start_all_sockets();