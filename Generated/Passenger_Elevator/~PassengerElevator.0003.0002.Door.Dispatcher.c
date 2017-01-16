
#include "~PassengerElevator.0000.0000.Header.h"


/* Door Dispatcher */

/* Dispatcher */

void adm_dispatcher_door(
    void)
{
    adm_pool_target_door_typ * pool_target_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_door");
    #endif

    pool_target_door = adm_find_away_target_event_door();

    adm_dispatch_state_action_door(pool_target_door);

    adm_dispatch_home_pool_door();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_door");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_door(
    void)
{
    adm_pool_target_door_typ * pool_target_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_door");
    #endif

    while (adm_entity_system.ent_door.home_pool_head != NULL) {

        pool_target_door = adm_find_home_target_event_door();

        adm_dispatch_state_action_door(pool_target_door);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_door");
    #endif
}


/* Find Home Target Event */

adm_pool_target_door_typ * adm_find_home_target_event_door(
    void)
{
    adm_pool_target_door_typ * pool_target_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_door");
    #endif

    pool_target_door = adm_entity_system.ent_door.home_pool_head;

    adm_entity_system.ent_door.home_pool_head = pool_target_door->next;

    if (adm_entity_system.ent_door.home_pool_head == NULL) {

        adm_entity_system.ent_door.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_door");
    #endif

    return (pool_target_door);
}


/* Find Away Target Event */

adm_pool_target_door_typ * adm_find_away_target_event_door(
    void)
{
    adm_pool_target_door_typ * pool_target_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_door");
    #endif

    pool_target_door = adm_entity_system.ent_door.away_pool_head;

    adm_entity_system.ent_door.away_pool_head = pool_target_door->next;

    if (adm_entity_system.ent_door.away_pool_head == NULL) {

        adm_entity_system.ent_door.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_door");
    #endif

    return (pool_target_door);
}


/* Dispatch State Action */

void adm_dispatch_state_action_door(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_door");
    #endif

    if (pool_target->ent_door != NULL) {

        adm_object_existent_door(
            pool_target->ent_door,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_DOOR_OPEN :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_CLOSED :

                    adm_sim_display_state_door_opening(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_OPENING;

                    adm_state_action_door_opening(
                        pool_target->ent_door);

                break;
            }

        break;

        case ADM_EVENT_DOOR_CLOSE :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_OPEN :

                    adm_sim_display_state_door_closing(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_CLOSING;

                    adm_state_action_door_closing(
                        pool_target->ent_door);

                break;
            }

        break;

        case ADM_EVENT_DOOR_OBSTRUCTION :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Obstruction",
                        "State:Closed");

                break;

                case ADM_STATUS_DOOR_CLOSING :

                    adm_sim_display_state_door_avoiding_obstruction(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION;

                break;
            }

        break;

        case ADM_EVENT_DOOR_OPEN_COMPLETED :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Open_completed",
                        "State:Closed");

                break;

                case ADM_STATUS_DOOR_OPENING :

                    adm_sim_display_state_door_open(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_OPEN;

                    adm_state_action_door_open(
                        pool_target->ent_door);

                break;

                case ADM_STATUS_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Open_completed",
                        "State:Open");

                break;

                case ADM_STATUS_DOOR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Open_completed",
                        "State:Closing");

                break;

                case ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Open_completed",
                        "State:Avoiding_Obstruction");

                break;
            }

        break;

        case ADM_EVENT_DOOR_CLOSE_COMPLETED :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Close_completed",
                        "State:Closed");

                break;

                case ADM_STATUS_DOOR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Close_completed",
                        "State:Opening");

                break;

                case ADM_STATUS_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Close_completed",
                        "State:Open");

                break;

                case ADM_STATUS_DOOR_CLOSING :

                    adm_sim_display_state_door_closed(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_CLOSED;

                    adm_state_action_door_closed(
                        pool_target->ent_door);

                break;

                case ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Close_completed",
                        "State:Avoiding_Obstruction");

                break;
            }

        break;

        case ADM_EVENT_DOOR_CLEAR :

            switch ((pool_target->ent_door)->status) {

                case ADM_STATUS_DOOR_CLOSED :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Clear",
                        "State:Closed");

                break;

                case ADM_STATUS_DOOR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Clear",
                        "State:Opening");

                break;

                case ADM_STATUS_DOOR_OPEN :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Clear",
                        "State:Open");

                break;

                case ADM_STATUS_DOOR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Door",
                        (pool_target->ent_door)->identity,
                        "Event:Clear",
                        "State:Closing");

                break;

                case ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION :

                    adm_sim_display_state_door_closing(pool_target);

                    (pool_target->ent_door)->status = ADM_STATUS_DOOR_CLOSING;

                    adm_state_action_door_closing(
                        pool_target->ent_door);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */