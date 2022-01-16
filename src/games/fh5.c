#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "../forza.h"
#include "../ForzaTelemetry.h"

#define FH5_PORT 9925
#define FH5_BUFFER_SIZE 324

static void fh5_parse_telemetry(ForzaTelemetry *telemetry, void *buffer)
{
    unsigned int offset = 0;
    size_t datum_size;

    datum_size = sizeof(telemetry->is_race_on);
    memcpy(&telemetry->is_race_on, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->timestamp_ms);
    memcpy(&telemetry->timestamp_ms, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->engine_max_rpm);
    memcpy(&telemetry->engine_max_rpm, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->engine_idle_rpm);
    memcpy(&telemetry->engine_idle_rpm, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->current_engine_rpm);
    memcpy(&telemetry->current_engine_rpm, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->acceleration_x);
    memcpy(&telemetry->acceleration_x, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->acceleration_y);
    memcpy(&telemetry->acceleration_y, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->acceleration_z);
    memcpy(&telemetry->acceleration_z, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->velocity_x);
    memcpy(&telemetry->velocity_x, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->velocity_y);
    memcpy(&telemetry->velocity_y, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->velocity_z);
    memcpy(&telemetry->velocity_z, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->angular_velocity_x);
    memcpy(&telemetry->angular_velocity_x, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->angular_velocity_y);
    memcpy(&telemetry->angular_velocity_y, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->angular_velocity_z);
    memcpy(&telemetry->angular_velocity_z, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->yaw);
    memcpy(&telemetry->yaw, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->pitch);
    memcpy(&telemetry->pitch, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->roll);
    memcpy(&telemetry->roll, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_suspension_travel_front_left);
    memcpy(&telemetry->normalized_suspension_travel_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_suspension_travel_front_right);
    memcpy(&telemetry->normalized_suspension_travel_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_suspension_travel_rear_left);
    memcpy(&telemetry->normalized_suspension_travel_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_suspension_travel_rear_right);
    memcpy(&telemetry->normalized_suspension_travel_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_ratio_front_left);
    memcpy(&telemetry->tire_slip_ratio_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_ratio_front_right);
    memcpy(&telemetry->tire_slip_ratio_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_ratio_rear_left);
    memcpy(&telemetry->tire_slip_ratio_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_ratio_rear_right);
    memcpy(&telemetry->tire_slip_ratio_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_rotation_speed_front_left);
    memcpy(&telemetry->wheel_rotation_speed_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_rotation_speed_front_right);
    memcpy(&telemetry->wheel_rotation_speed_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_rotation_speed_rear_left);
    memcpy(&telemetry->wheel_rotation_speed_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_rotation_speed_rear_right);
    memcpy(&telemetry->wheel_rotation_speed_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_on_rumble_strip_front_left);
    memcpy(&telemetry->wheel_on_rumble_strip_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_on_rumble_strip_front_right);
    memcpy(&telemetry->wheel_on_rumble_strip_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_on_rumble_strip_rear_left);
    memcpy(&telemetry->wheel_on_rumble_strip_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_on_rumble_strip_rear_right);
    memcpy(&telemetry->wheel_on_rumble_strip_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_in_puddle_depth_front_left);
    memcpy(&telemetry->wheel_in_puddle_depth_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_in_puddle_depth_front_right);
    memcpy(&telemetry->wheel_in_puddle_depth_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_in_puddle_depth_rear_left);
    memcpy(&telemetry->wheel_in_puddle_depth_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->wheel_in_puddle_depth_rear_right);
    memcpy(&telemetry->wheel_in_puddle_depth_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->surface_rumble_front_left);
    memcpy(&telemetry->surface_rumble_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->surface_rumble_front_right);
    memcpy(&telemetry->surface_rumble_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->surface_rumble_rear_left);
    memcpy(&telemetry->surface_rumble_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->surface_rumble_rear_right);
    memcpy(&telemetry->surface_rumble_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_angle_front_left);
    memcpy(&telemetry->tire_slip_angle_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_angle_front_right);
    memcpy(&telemetry->tire_slip_angle_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_angle_rear_left);
    memcpy(&telemetry->tire_slip_angle_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_slip_angle_rear_right);
    memcpy(&telemetry->tire_slip_angle_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_combined_slip_front_left);
    memcpy(&telemetry->tire_combined_slip_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_combined_slip_front_right);
    memcpy(&telemetry->tire_combined_slip_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_combined_slip_rear_left);
    memcpy(&telemetry->tire_combined_slip_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_combined_slip_rear_right);
    memcpy(&telemetry->tire_combined_slip_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->suspension_travel_meters_front_left);
    memcpy(&telemetry->suspension_travel_meters_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->suspension_travel_meters_front_right);
    memcpy(&telemetry->suspension_travel_meters_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->suspension_travel_meters_rear_left);
    memcpy(&telemetry->suspension_travel_meters_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->suspension_travel_meters_rear_right);
    memcpy(&telemetry->suspension_travel_meters_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->car_ordinal);
    memcpy(&telemetry->car_ordinal, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->car_class);
    memcpy(&telemetry->car_class, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->car_performance_index);
    memcpy(&telemetry->car_performance_index, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->drivetrain_type);
    memcpy(&telemetry->drivetrain_type, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->num_cylinders);
    memcpy(&telemetry->num_cylinders, buffer + offset, datum_size);
    offset += datum_size;

    // Skip 12 bytes
    offset += 12;

    datum_size = sizeof(telemetry->position_x);
    memcpy(&telemetry->position_x, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->position_y);
    memcpy(&telemetry->position_y, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->position_z);
    memcpy(&telemetry->position_z, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->speed);
    memcpy(&telemetry->speed, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->power);
    memcpy(&telemetry->power, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->torque);
    memcpy(&telemetry->torque, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_temp_front_left);
    memcpy(&telemetry->tire_temp_front_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_temp_front_right);
    memcpy(&telemetry->tire_temp_front_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_temp_rear_left);
    memcpy(&telemetry->tire_temp_rear_left, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->tire_temp_rear_right);
    memcpy(&telemetry->tire_temp_rear_right, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->boost);
    memcpy(&telemetry->boost, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->fuel);
    memcpy(&telemetry->fuel, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->distance_travelled);
    memcpy(&telemetry->distance_travelled, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->best_lap);
    memcpy(&telemetry->best_lap, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->last_lap);
    memcpy(&telemetry->last_lap, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->current_lap);
    memcpy(&telemetry->current_lap, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->current_race_time);
    memcpy(&telemetry->current_race_time, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->lap_number);
    memcpy(&telemetry->lap_number, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->race_position);
    memcpy(&telemetry->race_position, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->accel);
    memcpy(&telemetry->accel, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->brake);
    memcpy(&telemetry->brake, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->clutch);
    memcpy(&telemetry->clutch, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->hand_brake);
    memcpy(&telemetry->hand_brake, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->gear);
    memcpy(&telemetry->gear, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->steer);
    memcpy(&telemetry->steer, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_driving_line);
    memcpy(&telemetry->normalized_driving_line, buffer + offset, datum_size);
    offset += datum_size;

    datum_size = sizeof(telemetry->normalized_ai_brake_difference);
    memcpy(&telemetry->normalized_ai_brake_difference, buffer + offset, datum_size);
    offset += datum_size;
}

int start_fh5_socket(void)
{
    struct sockaddr_in servaddr, cliaddr;

    const int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("An error occurred creating FH5 socket");
        return 0;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FH5_PORT);
    servaddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("An error occurred binding FH5 socket");
        return 0;
    }

    return sockfd;
}

int handle_fh5_socket_data(const int sockfd)
{
    socklen_t len;
    struct sockaddr cliaddr;

    void *buffer = alloca(FH5_BUFFER_SIZE);

    ForzaTelemetry *telemetry = get_latest_telemetry();

    const ssize_t msg_len = recvfrom(sockfd, buffer, FH5_BUFFER_SIZE, MSG_WAITALL, &cliaddr, &len);

    if (msg_len != FH5_BUFFER_SIZE)
        return 0;

    fh5_parse_telemetry(telemetry, buffer);

    return 1;
}