
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Door Acquire Identity Event */

void adm_sim_acquire_identity_event_door_open(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_open");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_open(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_open");
    #endif
}

void adm_sim_acquire_identity_event_door_close(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_close");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_close(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_close");
    #endif
}

void adm_sim_acquire_identity_event_door_obstruction(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_obstruction");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_obstruction(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_obstruction");
    #endif
}

void adm_sim_acquire_identity_event_door_open_completed(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_open_completed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_open_completed(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_open_completed");
    #endif
}

void adm_sim_acquire_identity_event_door_close_completed(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_close_completed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_close_completed(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_close_completed");
    #endif
}

void adm_sim_acquire_identity_event_door_clear(
    void)
{
    adm_ent_door_typ * ent_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_clear");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (
        entity_not_found &&
        ent_door != NULL) {

        if (ent_door->identity == identity) {

            adm_send_event_door_clear(
                NULL,
                ent_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_door = ent_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_door_clear");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */