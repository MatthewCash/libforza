#include <stdio.h>

#include "games/fh5.h"
#include "ForzaTelemetry.h"

ForzaTelemetry *last_telemetry;

void store_telemetry(ForzaTelemetry *telemetry)
{
    last_telemetry = telemetry;

    printf("is race on: %d\n", last_telemetry->is_race_on);
    printf("timestamp: %u\n", last_telemetry->timestamp_ms);
    printf("max rpm: %f\n", last_telemetry->engine_max_rpm);
    printf("idle rpm: %f\n", last_telemetry->engine_idle_rpm);
    printf("current rpm: %f\n", last_telemetry->current_engine_rpm);
    printf("gear: %d\n", last_telemetry->gear);
}

int main()
{
    start_fh5_socket();

    return 0;
}