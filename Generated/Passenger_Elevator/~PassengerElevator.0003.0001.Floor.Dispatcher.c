
#include "~PassengerElevator.0000.0000.Header.h"


/* Floor Dispatcher */

/* Dispatcher */

void adm_dispatcher_floor(
    void)
{
    adm_pool_target_floor_typ * pool_target_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_floor");
    #endif

    pool_target_floor = adm_find_away_target_event_floor();

    adm_dispatch_state_action_floor(pool_target_floor);

    adm_dispatch_home_pool_floor();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_floor");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_floor(
    void)
{
    adm_pool_target_floor_typ * pool_target_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_floor");
    #endif

    while (adm_entity_system.ent_floor.home_pool_head != NULL) {

        pool_target_floor = adm_find_home_target_event_floor();

        adm_dispatch_state_action_floor(pool_target_floor);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_floor");
    #endif
}


/* Find Home Target Event */

adm_pool_target_floor_typ * adm_find_home_target_event_floor(
    void)
{
    adm_pool_target_floor_typ * pool_target_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_floor");
    #endif

    pool_target_floor = adm_entity_system.ent_floor.home_pool_head;

    adm_entity_system.ent_floor.home_pool_head = pool_target_floor->next;

    if (adm_entity_system.ent_floor.home_pool_head == NULL) {

        adm_entity_system.ent_floor.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_floor");
    #endif

    return (pool_target_floor);
}


/* Find Away Target Event */

adm_pool_target_floor_typ * adm_find_away_target_event_floor(
    void)
{
    adm_pool_target_floor_typ * pool_target_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_floor");
    #endif

    pool_target_floor = adm_entity_system.ent_floor.away_pool_head;

    adm_entity_system.ent_floor.away_pool_head = pool_target_floor->next;

    if (adm_entity_system.ent_floor.away_pool_head == NULL) {

        adm_entity_system.ent_floor.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_floor");
    #endif

    return (pool_target_floor);
}


/* Dispatch State Action */

void adm_dispatch_state_action_floor(
    adm_pool_target_floor_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_floor");
    #endif

    if (pool_target->ent_floor != NULL) {

        adm_object_existent_floor(
            pool_target->ent_floor,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_FLOOR_REQUEST_SERVICE :

            switch ((pool_target->ent_floor)->status) {

                case ADM_STATUS_FLOOR_IDLE :

                    adm_sim_display_state_floor_calling_service(pool_target);

                    (pool_target->ent_floor)->status = ADM_STATUS_FLOOR_CALLING_SERVICE;

                    adm_state_action_floor_calling_service(
                        pool_target->ent_floor);

                break;

                case ADM_STATUS_FLOOR_CALLING_SERVICE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Floor",
                        (pool_target->ent_floor)->identity,
                        "Event:Request_service",
                        "State:Calling_Service");

                break;
            }

        break;

        case ADM_EVENT_FLOOR_SERVICE_CALLED :

            switch ((pool_target->ent_floor)->status) {

                case ADM_STATUS_FLOOR_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Floor",
                        (pool_target->ent_floor)->identity,
                        "Event:Service_called",
                        "State:Idle");

                break;

                case ADM_STATUS_FLOOR_CALLING_SERVICE :

                    adm_sim_display_state_floor_idle(pool_target);

                    (pool_target->ent_floor)->status = ADM_STATUS_FLOOR_IDLE;

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */