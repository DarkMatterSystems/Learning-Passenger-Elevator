
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Car Acquire Identity Event */

void adm_sim_acquire_identity_event_car_service_requested(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_requested");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_service_requested(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_requested");
    #endif
}

void adm_sim_acquire_identity_event_car_open_door(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_open_door");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_open_door(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_open_door");
    #endif
}

void adm_sim_acquire_identity_event_car_close_door(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_close_door");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_close_door(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_close_door");
    #endif
}

void adm_sim_acquire_identity_event_car_service_schedule(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_schedule");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_service_schedule(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_schedule");
    #endif
}

void adm_sim_acquire_identity_event_car_service_current_floor(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_current_floor");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_service_current_floor(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_service_current_floor");
    #endif
}

void adm_sim_acquire_identity_event_car_moving(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_moving");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_moving(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_moving");
    #endif
}

void adm_sim_acquire_identity_event_car_floor_approaching(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;
    adm_base_integer_typ evd_num_next_floor_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_floor_approaching");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Fetch Event Data */

    evd_num_next_floor_number = adm_sim_int_fetch();

    /* Check Event Data Type Ranges */

    if (
        evd_num_next_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
        evd_num_next_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(evd_num_next_floor_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_floor_approaching(
                NULL,
                ent_car,
                evd_num_next_floor_number,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_floor_approaching");
    #endif
}

void adm_sim_acquire_identity_event_car_continue(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_continue");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_continue(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_continue");
    #endif
}

void adm_sim_acquire_identity_event_car_stop_at_next_floor(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_stop_at_next_floor");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_stop_at_next_floor(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_stop_at_next_floor");
    #endif
}

void adm_sim_acquire_identity_event_car_car_stopped(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_car_stopped");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_car_stopped(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_car_stopped");
    #endif
}

void adm_sim_acquire_identity_event_car_door_open(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_door_open");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_door_open(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_door_open");
    #endif
}

void adm_sim_acquire_identity_event_car_door_closed(
    void)
{
    adm_ent_car_typ * ent_car;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_door_closed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (
        entity_not_found &&
        ent_car != NULL) {

        if (ent_car->identity == identity) {

            adm_send_event_car_door_closed(
                NULL,
                ent_car,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_car = ent_car->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_car_door_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */