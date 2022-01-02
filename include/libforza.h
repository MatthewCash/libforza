#pragma once

#include "ForzaTelemetry.h"

ForzaTelemetry *get_latest_telemetry(void);

void notify_on_latest(void (*provided_func)(ForzaTelemetry *));

void start_all_sockets(void);

void wait_all_sockets(void);