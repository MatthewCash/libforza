#include <stdio.h>
#include <pthread.h>

#include "ForzaTelemetry.h"
#include "games/fm7.h"
#include "games/fh4.h"
#include "games/fh5.h"

#define GAME_COUNT sizeof(games) / sizeof(games[0])
void *(*games[])(void *) = {start_fm7_socket, start_fh4_socket, start_fh5_socket};

static ForzaTelemetry *latest_telemetry;
void (*notify_func)(ForzaTelemetry *);

void store_latest_telemetry(ForzaTelemetry *new_telemetry)
{
    latest_telemetry = new_telemetry;
    notify_func(new_telemetry);
}

ForzaTelemetry *get_latest_telemetry(void)
{
    return latest_telemetry;
}

void notify_on_latest(void (*provided_func)(ForzaTelemetry *))
{
    notify_func = provided_func;
}

pthread_t threads[GAME_COUNT];

void start_all_sockets(void)
{

    for (size_t i = 0; i < GAME_COUNT; i++)
    {
        pthread_create(threads + i, NULL, games[i], (void *)NULL);
    }
}

void wait_all_sockets(void)
{
    for (size_t i = 0; i < GAME_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
}