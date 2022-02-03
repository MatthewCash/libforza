#include "forza.h"

// These functions have been renamed and are only here for compatibility

int start_all_sockets(void)
{
    return forza_init();
}

int poll_all_sockets(void)
{
    return forza_poll();
}
