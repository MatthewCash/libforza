#pragma once

#include "../ForzaTelemetry.h"

void fh5_parse_telemetry(ForzaTelemetry *telemetry, void *buffer);

void *start_fh5_socket(void);