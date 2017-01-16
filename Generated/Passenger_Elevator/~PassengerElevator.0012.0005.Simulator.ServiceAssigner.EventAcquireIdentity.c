
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Service Assigner Acquire Identity Event */

void adm_sim_acquire_identity_event_service_assigner_assign_car(
    void)
{
    adm_ent_service_assigner_typ * ent_service_assigner;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ evd_num_floor_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_service_assigner_assign_car");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    evd_num_floor_number = adm_sim_int_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
        evd_num_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_floor_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_service_assigner = adm_entity_system.ent_service_assigner.live_list_head;

    while (
        entity_not_found &&
        ent_service_assigner != NULL) {

        if (ent_service_assigner->identity == identity) {

            adm_send_event_service_assigner_assign_car(
                NULL,
                ent_service_assigner,
                evd_num_floor_number,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_service_assigner = ent_service_assigner->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_service_assigner_assign_car");
    #endif
}

void adm_sim_acquire_identity_event_service_assigner_car_assigned(
    void)
{
    adm_ent_service_assigner_typ * ent_service_assigner;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_service_assigner_car_assigned");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_service_assigner = adm_entity_system.ent_service_assigner.live_list_head;

    while (
        entity_not_found &&
        ent_service_assigner != NULL) {

        if (ent_service_assigner->identity == identity) {

            adm_send_event_service_assigner_car_assigned(
                NULL,
                ent_service_assigner,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_service_assigner = ent_service_assigner->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_service_assigner_car_assigned");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */