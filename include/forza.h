#pragma once

#include <stdint.h>

typedef struct ForzaTelemetry ForzaTelemetry;

struct ForzaTelemetry
{
    int32_t is_race_on;
    uint32_t timestamp_ms;
    float engine_max_rpm;
    float engine_idle_rpm;
    float current_engine_rpm;
    float acceleration_x;
    float acceleration_y;
    float acceleration_z;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angular_velocity_x;
    float angular_velocity_y;
    float angular_velocity_z;
    float yaw;
    float pitch;
    float roll;
    float normalized_suspension_travel_front_left;
    float normalized_suspension_travel_front_right;
    float normalized_suspension_travel_rear_left;
    float normalized_suspension_travel_rear_right;
    float tire_slip_ratio_front_left;
    float tire_slip_ratio_front_right;
    float tire_slip_ratio_rear_left;
    float tire_slip_ratio_rear_right;
    float wheel_rotation_speed_front_left;
    float wheel_rotation_speed_front_right;
    float wheel_rotation_speed_rear_left;
    float wheel_rotation_speed_rear_right;
    int32_t wheel_on_rumble_strip_front_left;
    int32_t wheel_on_rumble_strip_front_right;
    int32_t wheel_on_rumble_strip_rear_left;
    int32_t wheel_on_rumble_strip_rear_right;
    float wheel_in_puddle_depth_front_left;
    float wheel_in_puddle_depth_front_right;
    float wheel_in_puddle_depth_rear_left;
    float wheel_in_puddle_depth_rear_right;
    float surface_rumble_front_left;
    float surface_rumble_front_right;
    float surface_rumble_rear_left;
    float surface_rumble_rear_right;
    float tire_slip_angle_front_left;
    float tire_slip_angle_front_right;
    float tire_slip_angle_rear_left;
    float tire_slip_angle_rear_right;
    float tire_combined_slip_front_left;
    float tire_combined_slip_front_right;
    float tire_combined_slip_rear_left;
    float tire_combined_slip_rear_right;
    float suspension_travel_meters_front_left;
    float suspension_travel_meters_front_right;
    float suspension_travel_meters_rear_left;
    float suspension_travel_meters_rear_right;
    int32_t car_ordinal;
    int32_t car_class;
    int32_t car_performance_index;
    int32_t drivetrain_type;
    int32_t num_cylinders;
    float position_x;
    float position_y;
    float position_z;
    float speed;
    float power;
    float torque;
    float tire_temp_front_left;
    float tire_temp_front_right;
    float tire_temp_rear_left;
    float tire_temp_rear_right;
    float boost;
    float fuel;
    float distance_travelled;
    float best_lap;
    float last_lap;
    float current_lap;
    float current_race_time;
    uint16_t lap_number;
    uint8_t race_position;
    uint8_t accel;
    uint8_t brake;
    uint8_t clutch;
    uint8_t hand_brake;
    uint8_t gear;
    int8_t steer;
    int8_t normalized_driving_line;
    int8_t normalized_ai_brake_difference;
};

ForzaTelemetry *get_latest_telemetry(void);

void notify_on_new_telemetry(void (*provided_func)(ForzaTelemetry *));

// Creates and binds sockets, allocates buffers
int forza_init(void);
int start_all_sockets(void); // Deprecated

// Poll sockets for data and parses
int forza_poll(void);
int poll_all_sockets(void); // Deprecated

// Close sockets and free buffers
int forza_cleanup(void);