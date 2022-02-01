#include <stdio.h>
#include <stdlib.h>
#include <poll.h>

#include "ForzaTelemetry.h"
#include "games/fm7.h"
#include "games/fh4.h"
#include "games/fh5.h"

#define GAME_COUNT (int)(sizeof(game_socket_inits) / sizeof(game_socket_inits[0]))

// Games sorted by release
int (*game_socket_inits[])(void) = {start_fm7_socket, start_fh4_socket, start_fh5_socket};
int (*game_socket_destructors[])(const int) = {destruct_fm7, destruct_fh4, destruct_fh5};
int (*game_socket_handlers[])(const int) = {handle_fm7_socket_data, handle_fh4_socket_data, handle_fh5_socket_data};

static ForzaTelemetry *latest_telemetry = NULL;
void (*notify_func)(ForzaTelemetry *);

struct pollfd pollfds[GAME_COUNT];

ForzaTelemetry *get_latest_telemetry(void)
{
    return latest_telemetry;
}

void notify_on_new_telemetry(void (*provided_func)(ForzaTelemetry *))
{
    if (latest_telemetry == NULL)
        latest_telemetry = malloc(sizeof(ForzaTelemetry));

    notify_func = provided_func;
}

int start_all_sockets(void)
{
    if (latest_telemetry == NULL)
        latest_telemetry = malloc(sizeof(ForzaTelemetry));

    int failures = 0;

    for (int i = 0; i < GAME_COUNT; i++)
    {
        const int sockfd = game_socket_inits[i]();
        if (sockfd < 1) failures++;

        pollfds[i] =
            (struct pollfd){.fd = sockfd, .events = POLLIN};
    }

    return failures;
}

int stop_all_sockets(void)
{
    int failures = 0;

    for (int i = 0; i < GAME_COUNT; i++)
    {
        const int sockfd = pollfds[i].fd;

        if (game_socket_destructors[i](sockfd) != 0)
            failures++;
    }

    return failures;
}

int poll_all_sockets(void)
{
    const int ready = poll(pollfds, GAME_COUNT, -1);

    if (!ready)
        return 0;

    int telemetry_count = 0;

    for (int i = 0; i < GAME_COUNT; i++)
    {
        struct pollfd pfd = pollfds[i];

        if (!pfd.revents)
            continue;

        if (!(pfd.revents & POLLIN))
            continue;

        if (game_socket_handlers[i](pfd.fd))
        {
            telemetry_count++;
            notify_func(latest_telemetry);
            
        }
    }

    return telemetry_count;
}
