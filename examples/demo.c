#include <stdlib.h>
#include <stdio.h>
#include <forza.h>

// Optional callback for new telemetry data
void on_new_telemetry(ForzaTelemetry *telemetry)
{
    printf("\nCallback received new telemetry!\nGear is %d\n", telemetry->gear);
}

int main(void)
{
    // Initialize sockets for each game (required)
    const int init_error = forza_init();

    // Check for initialization error
    if (init_error != 0)
    {
        perror("An error occurred during initialization!");
        exit(1);
    }

    // Optionally register the callback
    notify_on_new_telemetry(on_new_telemetry);

    puts("Initialization Complete");

    // Continuously poll, consider moving to another thread
    while (1)
    {
        // Poll for new data (should be around 60hz)
        const int telemetry_ready = forza_poll();

        // If there is new telemetry, callback will be notified
        
        // Check for poll error
        if (telemetry_ready == -1)
        {
            perror("An error occurred while polling for new telemetry!");
        }
        
        // Check if new telemetry is ready
        if (telemetry_ready)
        {
            // Latest telemetry can be retrieved on demand
            ForzaTelemetry *telemetry = get_latest_telemetry();

            puts("\nRetrieved new telemetry!");
            printf("Number of Cylinders is %d\n", telemetry->num_cylinders);
        }
    }

    const int cleanup_error = forza_cleanup();

    // Check for cleanup error
    if (cleanup_error != 0)
    {
        perror("An error occurred during cleanup!");
    }

    return 0;
}
