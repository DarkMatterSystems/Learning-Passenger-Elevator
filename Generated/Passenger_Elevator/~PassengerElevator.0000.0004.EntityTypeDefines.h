
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_FLOOR_IDLE,
    ADM_STATUS_FLOOR_CALLING_SERVICE
} adm_sta_floor_typ;

typedef enum {
    ADM_STATUS_DOOR_CLOSED,
    ADM_STATUS_DOOR_OPENING,
    ADM_STATUS_DOOR_OPEN,
    ADM_STATUS_DOOR_CLOSING,
    ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION
} adm_sta_door_typ;

typedef enum {
    ADM_STATUS_CAR_STOP_AWAITING_FLOOR
} adm_sta_car_stop_typ;

typedef enum {
    ADM_STATUS_SERVICE_ASSIGNER_IDLE,
    ADM_STATUS_SERVICE_ASSIGNER_ALLOCATING_CAR
} adm_sta_service_assigner_typ;

typedef enum {
    ADM_STATUS_CAR_STATIONARY,
    ADM_STATUS_CAR_SELECTING_SCHEDULE,
    ADM_STATUS_CAR_SERVICING_SCHEDULE,
    ADM_STATUS_CAR_MOVING,
    ADM_STATUS_CAR_CHECKING_SCHEDULE,
    ADM_STATUS_CAR_SLOWING,
    ADM_STATUS_CAR_OPENING,
    ADM_STATUS_CAR_ACCESSIBLE,
    ADM_STATUS_CAR_CLOSING
} adm_sta_car_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_FLOOR_REQUEST_SERVICE,
    ADM_EVENT_FLOOR_SERVICE_CALLED
} adm_evt_floor_typ;

typedef enum {
    ADM_EVENT_DOOR_OPEN,
    ADM_EVENT_DOOR_CLOSE,
    ADM_EVENT_DOOR_OBSTRUCTION,
    ADM_EVENT_DOOR_OPEN_COMPLETED,
    ADM_EVENT_DOOR_CLOSE_COMPLETED,
    ADM_EVENT_DOOR_CLEAR
} adm_evt_door_typ;

typedef enum {
    ADM_EVENT_CAR_STOP_GO_TO_FLOOR
} adm_evt_car_stop_typ;

typedef enum {
    ADM_EVENT_SERVICE_ASSIGNER_ASSIGN_CAR,
    ADM_EVENT_SERVICE_ASSIGNER_CAR_ASSIGNED
} adm_evt_service_assigner_typ;

typedef enum {
    ADM_EVENT_CAR_SERVICE_REQUESTED,
    ADM_EVENT_CAR_OPEN_DOOR,
    ADM_EVENT_CAR_CLOSE_DOOR,
    ADM_EVENT_CAR_SERVICE_SCHEDULE,
    ADM_EVENT_CAR_SERVICE_CURRENT_FLOOR,
    ADM_EVENT_CAR_MOVING,
    ADM_EVENT_CAR_FLOOR_APPROACHING,
    ADM_EVENT_CAR_CONTINUE,
    ADM_EVENT_CAR_STOP_AT_NEXT_FLOOR,
    ADM_EVENT_CAR_CAR_STOPPED,
    ADM_EVENT_CAR_DOOR_OPEN,
    ADM_EVENT_CAR_DOOR_CLOSED
} adm_evt_car_typ;


/* Entity Type Defines */

/* Floor */

typedef struct adm_ent_floor {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_floor_typ status;
    adm_int_floor_typ atb_number;
    struct adm_rel_floor_serviced_by_car_service * rel_serviced_by_car_service_head;
    struct adm_rel_floor_serviced_by_car_service * rel_serviced_by_car_service_tail;
    struct adm_ent_floor * back;
    struct adm_ent_floor * next;
} adm_ent_floor_typ;

/* Door */

typedef struct adm_ent_door {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_door_typ status;
    struct adm_rel_door_provides_passenger_access_to_car * rel_provides_passenger_access_to_car_head;
    struct adm_rel_door_provides_passenger_access_to_car * rel_provides_passenger_access_to_car_tail;
    struct adm_ent_door * back;
    struct adm_ent_door * next;
} adm_ent_door_typ;

/* Car Service */

typedef struct adm_ent_car_service {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    struct adm_rel_car_service_services_floor * rel_services_floor_head;
    struct adm_rel_car_service_services_floor * rel_services_floor_tail;
    struct adm_rel_car_service_serviced_by_car * rel_serviced_by_car_head;
    struct adm_rel_car_service_serviced_by_car * rel_serviced_by_car_tail;
    struct adm_rel_car_service_assigned_by_service_assigner * rel_assigned_by_service_assigner_head;
    struct adm_rel_car_service_assigned_by_service_assigner * rel_assigned_by_service_assigner_tail;
    struct adm_ent_car_service * back;
    struct adm_ent_car_service * next;
} adm_ent_car_service_typ;

/* Car Stop */

typedef struct adm_ent_car_stop {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_car_stop_typ status;
    struct adm_rel_car_stop_directs_car * rel_directs_car_head;
    struct adm_rel_car_stop_directs_car * rel_directs_car_tail;
    struct adm_ent_car_stop * back;
    struct adm_ent_car_stop * next;
} adm_ent_car_stop_typ;

/* Service Assigner */

typedef struct adm_ent_service_assigner {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_service_assigner_typ status;
    struct adm_rel_service_assigner_assigns_car_service * rel_assigns_car_service_head;
    struct adm_rel_service_assigner_assigns_car_service * rel_assigns_car_service_tail;
    struct adm_ent_service_assigner * back;
    struct adm_ent_service_assigner * next;
} adm_ent_service_assigner_typ;

/* Car */

typedef struct adm_ent_car {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_car_typ status;
    adm_enm_direction_typ atb_direction;
    struct adm_rel_car_services_car_service * rel_services_car_service_head;
    struct adm_rel_car_services_car_service * rel_services_car_service_tail;
    struct adm_rel_car_currently_at_floor * rel_currently_at_floor_head;
    struct adm_rel_car_currently_at_floor * rel_currently_at_floor_tail;
    struct adm_rel_car_accessed_through_door * rel_accessed_through_door_head;
    struct adm_rel_car_accessed_through_door * rel_accessed_through_door_tail;
    struct adm_rel_car_scheduled_to_move_up_to_floor * rel_scheduled_to_move_up_to_floor_head;
    struct adm_rel_car_scheduled_to_move_up_to_floor * rel_scheduled_to_move_up_to_floor_tail;
    struct adm_rel_car_scheduled_to_move_down_to_floor * rel_scheduled_to_move_down_to_floor_head;
    struct adm_rel_car_scheduled_to_move_down_to_floor * rel_scheduled_to_move_down_to_floor_tail;
    struct adm_ent_car * back;
    struct adm_ent_car * next;
} adm_ent_car_typ;


/* Relationship Type Defines */

typedef struct adm_rel_floor_serviced_by_car_service {
    adm_ent_car_service_typ * ent_car_service;
    struct adm_rel_floor_serviced_by_car_service * back;
    struct adm_rel_floor_serviced_by_car_service * next;
} adm_rel_floor_serviced_by_car_service_typ;

typedef struct adm_rel_door_provides_passenger_access_to_car {
    adm_ent_car_typ * ent_car;
    struct adm_rel_door_provides_passenger_access_to_car * back;
    struct adm_rel_door_provides_passenger_access_to_car * next;
} adm_rel_door_provides_passenger_access_to_car_typ;

typedef struct adm_rel_car_service_services_floor {
    adm_ent_floor_typ * ent_floor;
    struct adm_rel_car_service_services_floor * back;
    struct adm_rel_car_service_services_floor * next;
} adm_rel_car_service_services_floor_typ;

typedef struct adm_rel_car_service_serviced_by_car {
    adm_ent_car_typ * ent_car;
    struct adm_rel_car_service_serviced_by_car * back;
    struct adm_rel_car_service_serviced_by_car * next;
} adm_rel_car_service_serviced_by_car_typ;

typedef struct adm_rel_car_service_assigned_by_service_assigner {
    adm_ent_service_assigner_typ * ent_service_assigner;
    struct adm_rel_car_service_assigned_by_service_assigner * back;
    struct adm_rel_car_service_assigned_by_service_assigner * next;
} adm_rel_car_service_assigned_by_service_assigner_typ;

typedef struct adm_rel_car_stop_directs_car {
    adm_ent_car_typ * ent_car;
    struct adm_rel_car_stop_directs_car * back;
    struct adm_rel_car_stop_directs_car * next;
} adm_rel_car_stop_directs_car_typ;

typedef struct adm_rel_service_assigner_assigns_car_service {
    adm_ent_car_service_typ * ent_car_service;
    struct adm_rel_service_assigner_assigns_car_service * back;
    struct adm_rel_service_assigner_assigns_car_service * next;
} adm_rel_service_assigner_assigns_car_service_typ;

typedef struct adm_rel_car_services_car_service {
    adm_ent_car_service_typ * ent_car_service;
    struct adm_rel_car_services_car_service * back;
    struct adm_rel_car_services_car_service * next;
} adm_rel_car_services_car_service_typ;

typedef struct adm_rel_car_currently_at_floor {
    adm_ent_floor_typ * ent_floor;
    struct adm_rel_car_currently_at_floor * back;
    struct adm_rel_car_currently_at_floor * next;
} adm_rel_car_currently_at_floor_typ;

typedef struct adm_rel_car_accessed_through_door {
    adm_ent_door_typ * ent_door;
    struct adm_rel_car_accessed_through_door * back;
    struct adm_rel_car_accessed_through_door * next;
} adm_rel_car_accessed_through_door_typ;

typedef struct adm_rel_car_scheduled_to_move_up_to_floor {
    adm_ent_floor_typ * ent_floor;
    struct adm_rel_car_scheduled_to_move_up_to_floor * back;
    struct adm_rel_car_scheduled_to_move_up_to_floor * next;
} adm_rel_car_scheduled_to_move_up_to_floor_typ;

typedef struct adm_rel_car_scheduled_to_move_down_to_floor {
    adm_ent_floor_typ * ent_floor;
    struct adm_rel_car_scheduled_to_move_down_to_floor * back;
    struct adm_rel_car_scheduled_to_move_down_to_floor * next;
} adm_rel_car_scheduled_to_move_down_to_floor_typ;


/* Entity Dataset Type Defines */

typedef struct {
    adm_int_floor_typ desired_floor_number;
} adm_dst_car_stop_await_typ;

typedef struct {
    adm_int_floor_typ floor_number;
} adm_dst_service_assigner_allocate_typ;

typedef struct {
    adm_int_floor_typ next_floor_number;
} adm_dst_car_travel_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_floor {
    adm_evt_floor_typ evente;
    adm_ent_floor_typ * ent_floor;
    adm_error_location_typ error_location;
    struct adm_pool_target_floor * next;
} adm_pool_target_floor_typ;

typedef struct adm_pool_target_door {
    adm_evt_door_typ evente;
    adm_ent_door_typ * ent_door;
    adm_error_location_typ error_location;
    struct adm_pool_target_door * next;
} adm_pool_target_door_typ;

typedef struct adm_pool_target_car_stop {
    adm_evt_car_stop_typ evente;
    adm_ent_car_stop_typ * ent_car_stop;
    adm_error_location_typ error_location;
    struct adm_pool_target_car_stop * next;
    union {
        adm_dst_car_stop_await_typ * await;
    } dataset;
} adm_pool_target_car_stop_typ;

typedef struct adm_pool_target_service_assigner {
    adm_evt_service_assigner_typ evente;
    adm_ent_service_assigner_typ * ent_service_assigner;
    adm_error_location_typ error_location;
    struct adm_pool_target_service_assigner * next;
    union {
        adm_dst_service_assigner_allocate_typ * allocate;
    } dataset;
} adm_pool_target_service_assigner_typ;

typedef struct adm_pool_target_car {
    adm_evt_car_typ evente;
    adm_ent_car_typ * ent_car;
    adm_error_location_typ error_location;
    struct adm_pool_target_car * next;
    union {
        adm_dst_car_travel_typ * travel;
    } dataset;
} adm_pool_target_car_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_floor_typ * live_list_head;
    adm_ent_floor_typ * live_list_tail;
    adm_ent_floor_typ * dead_list_head;
    adm_ent_floor_typ * dead_list_tail;
    adm_pool_target_floor_typ * home_pool_head;
    adm_pool_target_floor_typ * home_pool_tail;
    adm_pool_target_floor_typ * away_pool_head;
    adm_pool_target_floor_typ * away_pool_tail;
} adm_entity_system_floor_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_door_typ * live_list_head;
    adm_ent_door_typ * live_list_tail;
    adm_ent_door_typ * dead_list_head;
    adm_ent_door_typ * dead_list_tail;
    adm_pool_target_door_typ * home_pool_head;
    adm_pool_target_door_typ * home_pool_tail;
    adm_pool_target_door_typ * away_pool_head;
    adm_pool_target_door_typ * away_pool_tail;
} adm_entity_system_door_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_car_service_typ * live_list_head;
    adm_ent_car_service_typ * live_list_tail;
    adm_ent_car_service_typ * dead_list_head;
    adm_ent_car_service_typ * dead_list_tail;
} adm_entity_system_car_service_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_car_stop_typ * live_list_head;
    adm_ent_car_stop_typ * live_list_tail;
    adm_ent_car_stop_typ * dead_list_head;
    adm_ent_car_stop_typ * dead_list_tail;
    adm_pool_target_car_stop_typ * home_pool_head;
    adm_pool_target_car_stop_typ * home_pool_tail;
    adm_pool_target_car_stop_typ * away_pool_head;
    adm_pool_target_car_stop_typ * away_pool_tail;
} adm_entity_system_car_stop_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_service_assigner_typ * live_list_head;
    adm_ent_service_assigner_typ * live_list_tail;
    adm_ent_service_assigner_typ * dead_list_head;
    adm_ent_service_assigner_typ * dead_list_tail;
    adm_pool_target_service_assigner_typ * home_pool_head;
    adm_pool_target_service_assigner_typ * home_pool_tail;
    adm_pool_target_service_assigner_typ * away_pool_head;
    adm_pool_target_service_assigner_typ * away_pool_tail;
} adm_entity_system_service_assigner_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_car_typ * live_list_head;
    adm_ent_car_typ * live_list_tail;
    adm_ent_car_typ * dead_list_head;
    adm_ent_car_typ * dead_list_tail;
    adm_pool_target_car_typ * home_pool_head;
    adm_pool_target_car_typ * home_pool_tail;
    adm_pool_target_car_typ * away_pool_head;
    adm_pool_target_car_typ * away_pool_tail;
} adm_entity_system_car_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_floor_typ ent_floor;
    adm_entity_system_door_typ ent_door;
    adm_entity_system_car_service_typ ent_car_service;
    adm_entity_system_car_stop_typ ent_car_stop;
    adm_entity_system_service_assigner_typ ent_service_assigner;
    adm_entity_system_car_typ ent_car;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */