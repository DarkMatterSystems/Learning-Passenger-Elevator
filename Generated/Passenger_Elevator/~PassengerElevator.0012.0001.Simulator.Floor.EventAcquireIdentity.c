
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Floor Acquire Identity Event */

void adm_sim_acquire_identity_event_floor_request_service(
    void)
{
    adm_ent_floor_typ * ent_floor;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_floor_request_service");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_floor = adm_entity_system.ent_floor.live_list_head;

    while (
        entity_not_found &&
        ent_floor != NULL) {

        if (ent_floor->identity == identity) {

            adm_send_event_floor_request_service(
                NULL,
                ent_floor,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_floor = ent_floor->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_floor_request_service");
    #endif
}

void adm_sim_acquire_identity_event_floor_service_called(
    void)
{
    adm_ent_floor_typ * ent_floor;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_floor_service_called");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_floor = adm_entity_system.ent_floor.live_list_head;

    while (
        entity_not_found &&
        ent_floor != NULL) {

        if (ent_floor->identity == identity) {

            adm_send_event_floor_service_called(
                NULL,
                ent_floor,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_floor = ent_floor->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_floor_service_called");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */