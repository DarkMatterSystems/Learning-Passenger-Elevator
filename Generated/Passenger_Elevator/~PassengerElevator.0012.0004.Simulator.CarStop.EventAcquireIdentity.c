
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Car Stop Acquire Identity Event */

void adm_sim_acquire_identity_event_car_stop_go_to_floor(
    void)
{
    adm_ent_car_stop_typ * ent_car_stop;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ evd_num_desired_floor_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_stop_go_to_floor");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    evd_num_desired_floor_number = adm_sim_int_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_desired_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
        evd_num_desired_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_desired_floor_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car_stop = adm_entity_system.ent_car_stop.live_list_head;

    while (
        entity_not_found &&
        ent_car_stop != NULL) {

        if (ent_car_stop->identity == identity) {

            adm_send_event_car_stop_go_to_floor(
                NULL,
                ent_car_stop,
                evd_num_desired_floor_number,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car_stop = ent_car_stop->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_stop_go_to_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */