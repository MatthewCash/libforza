#include <stdio.h>
#include <pthread.h>

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
    int success = 0;

    pthread_t threads[3];

    pthread_create(threads, NULL, start_fh5_socket, (void *)NULL);

    // if (start_fh5_socket() == 1)
    // {
    //     fprintf(stderr, "Unable to create FH5 socket");
    //     success++;
    // }

    pthread_join(threads[i], NULL);

    return failures;
}