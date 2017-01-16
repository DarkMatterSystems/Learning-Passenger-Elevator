
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_FLOOR,
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR_SERVICE,
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR_STOP,
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER,
    ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_FLOOR_REQUEST_SERVICE,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_FLOOR_SERVICE_CALLED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_OPEN,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_CLOSE,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_OBSTRUCTION,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_OPEN_COMPLETED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_CLOSE_COMPLETED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_DOOR_CLEAR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_STOP_GO_TO_FLOOR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER_ASSIGN_CAR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER_CAR_ASSIGNED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_SERVICE_REQUESTED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_OPEN_DOOR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_CLOSE_DOOR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_SERVICE_SCHEDULE,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_SERVICE_CURRENT_FLOOR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_MOVING,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_FLOOR_APPROACHING,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_CONTINUE,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_STOP_AT_NEXT_FLOOR,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_CAR_STOPPED,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_DOOR_OPEN,
    ADM_SIM_INDEX_EVENT_ELEVATOR_MANAGEMENT_CAR_DOOR_CLOSED
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_number;
} adm_sim_width_floor_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_door_typ;

typedef struct {
    adm_base_integer_typ identity;
} adm_sim_width_car_service_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_car_stop_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_service_assigner_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_direction;
} adm_sim_width_car_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */