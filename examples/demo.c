#include <stdio.h>
#include <forza.h>

// Optional callback for new telemetry data
void on_new_telemetry(ForzaTelemetry *telemetry)
{
    printf("Callback received new telemetry!\nGear is %d\n", telemetry->gear);
}

int main(void)
{
    // Initialize sockets for each game (required)
    forza_init();

    // Optionally register the callback
    notify_on_new_telemetry(on_new_telemetry);

    puts("Initialization Complete\n");

    // Continuously poll, consider moving to another thread
    while (1)
    {
        // Poll for new data (should be around 60hz)
        forza_poll();

        // If there is new telemetry, callback will be notified

        // Latest telemetry can be retrieved on demand
        ForzaTelemetry *telemetry = get_latest_telemetry();

        printf("Retrieved new telemetry!\nNumber of Cylinders is %d\n",
               telemetry->num_cylinders);
    }

    forza_cleanup();

    return 0;
}