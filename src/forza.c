#include <stdio.h>
#include <stdlib.h>
#include <poll.h>

#include "ForzaTelemetry.h"
#include "games/fm7.h"
#include "games/fh4.h"
#include "games/fh5.h"

#define GAME_COUNT (int)(sizeof(game_constructors) / sizeof(game_constructors[0]))

// Games sorted by release
int (*game_constructors[])(struct pollfd *pollfd) = {init_fm7, init_fh4, init_fh5};
int (*game_destructors[])(void) = {destruct_fm7, destruct_fh4, destruct_fh5};
int (*game_socket_handlers[])(void) = {handle_fm7_socket_data, handle_fh4_socket_data, handle_fh5_socket_data};

static ForzaTelemetry *latest_telemetry = NULL;
void (*notify_callback)(ForzaTelemetry *);

struct pollfd pollfds[GAME_COUNT];

ForzaTelemetry *get_latest_telemetry(void)
{
    return latest_telemetry;
}

void notify_on_new_telemetry(void (*provided_func)(ForzaTelemetry *))
{
    if (latest_telemetry == NULL)
        latest_telemetry = malloc(sizeof(ForzaTelemetry));

    notify_callback = provided_func;
}

int forza_init(void)
{
    if (latest_telemetry == NULL)
        latest_telemetry = malloc(sizeof(ForzaTelemetry));

    int failures = 0;

    for (int i = 0; i < GAME_COUNT; i++)
    {
        struct pollfd pollfd =
            {
                .fd = -1,
                .events = POLLIN,
            };

        if (game_constructors[i](&pollfd) != 0)
            failures++;

        pollfds[i] = pollfd;
    }

    return failures;
}

int forza_cleanup(void)
{
    int failures = 0;

    for (int i = 0; i < GAME_COUNT; i++)
    {
        if (game_destructors[i]() != 0)
            failures++;
    }

    return failures;
}

int forza_poll(void)
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

        // Verify no errors befor continuing
        if (game_socket_handlers[i]() != 0)
            return -1;
        
        telemetry_count++;
        notify_callback(latest_telemetry);
        
    }

    return telemetry_count;
}
