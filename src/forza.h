#pragma once

#include "ForzaTelemetry.h"

#define IP_ADDRESS "0.0.0.0"
#define PORT 9924

ForzaTelemetry *get_latest_telemetry(void);

void notify_on_new_telemetry(void (*provided_func)(ForzaTelemetry *));

int forza_init(void);

int forza_poll(void);

int forza_cleanup(void);