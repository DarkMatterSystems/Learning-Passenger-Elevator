
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator System Configuration */

/* Domain Map */

adm_sim_domain_typ adm_sim_domain[] = {
    {"Elevator_Management"},
    {SNULL}
};

/* Entity Map */

adm_sim_entity_typ adm_sim_entity[] = {
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Floor", TRUE, adm_sim_display_entity_floor},
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Door", TRUE, adm_sim_display_entity_door},
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Car_Service", FALSE, adm_sim_display_entity_car_service},
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Car_Stop", TRUE, adm_sim_display_entity_car_stop},
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Service_Assigner", TRUE, adm_sim_display_entity_service_assigner},
    {ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT, "Car", TRUE, adm_sim_display_entity_car},
    {null, SNULL, null, NULL}
};

/* Event Map */

adm_sim_event_typ adm_sim_event[] = {
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_FLOOR,
        "Request_service",
        FALSE,
        adm_sim_acquire_identity_event_floor_request_service
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_FLOOR,
        "Service_called",
        FALSE,
        adm_sim_acquire_identity_event_floor_service_called
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Open",
        FALSE,
        adm_sim_acquire_identity_event_door_open
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Close",
        FALSE,
        adm_sim_acquire_identity_event_door_close
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Obstruction",
        FALSE,
        adm_sim_acquire_identity_event_door_obstruction
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Open_completed",
        FALSE,
        adm_sim_acquire_identity_event_door_open_completed
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Close_completed",
        FALSE,
        adm_sim_acquire_identity_event_door_close_completed
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR,
        "Clear",
        FALSE,
        adm_sim_acquire_identity_event_door_clear
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR_STOP,
        "Go_to_floor",
        FALSE,
        adm_sim_acquire_identity_event_car_stop_go_to_floor
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER,
        "Assign_car",
        FALSE,
        adm_sim_acquire_identity_event_service_assigner_assign_car
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER,
        "Car_assigned",
        FALSE,
        adm_sim_acquire_identity_event_service_assigner_car_assigned
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Service_requested",
        FALSE,
        adm_sim_acquire_identity_event_car_service_requested
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Open_door",
        FALSE,
        adm_sim_acquire_identity_event_car_open_door
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Close_door",
        FALSE,
        adm_sim_acquire_identity_event_car_close_door
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Service_schedule",
        FALSE,
        adm_sim_acquire_identity_event_car_service_schedule
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Service_current_floor",
        FALSE,
        adm_sim_acquire_identity_event_car_service_current_floor
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Moving",
        FALSE,
        adm_sim_acquire_identity_event_car_moving
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Floor_approaching",
        FALSE,
        adm_sim_acquire_identity_event_car_floor_approaching
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Continue",
        FALSE,
        adm_sim_acquire_identity_event_car_continue
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Stop_at_next_floor",
        FALSE,
        adm_sim_acquire_identity_event_car_stop_at_next_floor
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Car_stopped",
        FALSE,
        adm_sim_acquire_identity_event_car_car_stopped
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Door_open",
        FALSE,
        adm_sim_acquire_identity_event_car_door_open
    },
    {
        ADM_SIM_INDEX_DOMAIN_ELEVATOR_MANAGEMENT,
        ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR,
        "Door_closed",
        FALSE,
        adm_sim_acquire_identity_event_car_door_closed
    },
    {
        null,
        null,
        SNULL,
        null,
        NULL
    }
};

/* Identifier Map */

adm_sim_identifier_typ adm_sim_identifier[] = {
    {
        null,
        null,
        null,
        SNULL,
        NULL
    }
};


/* Find Event Name From Event Index */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index)
{
    adm_base_integer_typ index;

    adm_base_boolean_typ event_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    index = 0;

    event_not_found = TRUE;

    while (event_not_found) {

        if (adm_sim_event[index].entity == entity_index) {

            index += entity_event_index;

            event_not_found = FALSE;

        } else {

            ++index;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_find_event_name");
    #endif

    return (adm_sim_event[index].name);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */