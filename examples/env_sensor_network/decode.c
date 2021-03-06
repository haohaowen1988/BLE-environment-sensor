#include <stdio.h>

#include "pb_common.h"
#include "pb_decode.h"

#include "proto_compiled/DataRequest.pb.h"
#include "proto_compiled/FeatureResponse.pb.h"

//Todo: Use macros to generate debug code.
#define DEBUG_DECODE true

//Logging
extern void log_int(char *level, char *func_name, char *key, int value);

extern void log_string(char *level, char *func_name, char *key, char *value);

extern void log_hex(char *level, char *func_name, char *key, uint8_t value);

extern void log_hex_array(char *level, char *func_name, char *key, uint8_t *value, size_t length);

void log_env_sensor_data_request(char *level, char *func_name, bool decode_status,
                                 environmentSensors_DataRequest *message_ptr) {
    log_int(level, func_name, "decode_status", decode_status);
    log_int(level, func_name, "message_ptr->atmosphericPressure", message_ptr->atmosphericPressure);
    log_int(level, func_name, "message_ptr->humanity", message_ptr->humanity);
}

int env_sensor_data_request_decode(
        environmentSensors_DataRequest *message_ptr,
        uint8_t *encoded_msg_ptr, size_t decoded_msg_size) {
    if (DEBUG_DECODE) {
        log_hex_array("DEBUG", "env_sensor_data_request_decode", "encoded_message", encoded_msg_ptr, decoded_msg_size);
    }

    pb_istream_t stream = pb_istream_from_buffer(encoded_msg_ptr, decoded_msg_size);

    bool decode_status = pb_decode(&stream, environmentSensors_DataRequest_fields, message_ptr);

    if (DEBUG_DECODE) {
        log_env_sensor_data_request("DEBUG", "env_sensor_data_request_decode", decode_status, message_ptr);
    }
    if (!decode_status) {
        printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        return 1;
    }

    return 0;
}
