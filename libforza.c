#include <stdio.h>

#include "games/fh5.h"

static ForzaTelemetry *latest_telemetry;

void store_latest_telemetry(ForzaTelemetry *new_telemetry)
{
    latest_telemetry = new_telemetry;
}

ForzaTelemetry *get_latest_telemetry(void)
{
    return latest_telemetry;
}

int start_all_sockets()
{
    if (start_fh5_socket() == 1)
    {
        perror("Unable to create FH5 socket");
    }
}