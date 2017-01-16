
#include "~PassengerElevator.0000.0000.Header.h"


/* Service Assigner Dispatcher */

/* Dispatcher */

void adm_dispatcher_service_assigner(
    void)
{
    adm_pool_target_service_assigner_typ * pool_target_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_service_assigner");
    #endif

    pool_target_service_assigner = adm_find_away_target_event_service_assigner();

    adm_dispatch_state_action_service_assigner(pool_target_service_assigner);

    adm_dispatch_home_pool_service_assigner();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_service_assigner");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_service_assigner(
    void)
{
    adm_pool_target_service_assigner_typ * pool_target_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_service_assigner");
    #endif

    while (adm_entity_system.ent_service_assigner.home_pool_head != NULL) {

        pool_target_service_assigner = adm_find_home_target_event_service_assigner();

        adm_dispatch_state_action_service_assigner(pool_target_service_assigner);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_service_assigner");
    #endif
}


/* Find Home Target Event */

adm_pool_target_service_assigner_typ * adm_find_home_target_event_service_assigner(
    void)
{
    adm_pool_target_service_assigner_typ * pool_target_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_service_assigner");
    #endif

    pool_target_service_assigner = adm_entity_system.ent_service_assigner.home_pool_head;

    adm_entity_system.ent_service_assigner.home_pool_head = pool_target_service_assigner->next;

    if (adm_entity_system.ent_service_assigner.home_pool_head == NULL) {

        adm_entity_system.ent_service_assigner.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_service_assigner");
    #endif

    return (pool_target_service_assigner);
}


/* Find Away Target Event */

adm_pool_target_service_assigner_typ * adm_find_away_target_event_service_assigner(
    void)
{
    adm_pool_target_service_assigner_typ * pool_target_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_service_assigner");
    #endif

    pool_target_service_assigner = adm_entity_system.ent_service_assigner.away_pool_head;

    adm_entity_system.ent_service_assigner.away_pool_head = pool_target_service_assigner->next;

    if (adm_entity_system.ent_service_assigner.away_pool_head == NULL) {

        adm_entity_system.ent_service_assigner.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_service_assigner");
    #endif

    return (pool_target_service_assigner);
}


/* Dispatch State Action */

void adm_dispatch_state_action_service_assigner(
    adm_pool_target_service_assigner_typ * pool_target)
{
    adm_dst_service_assigner_allocate_typ * dst_allocate;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_service_assigner");
    #endif

    if (pool_target->ent_service_assigner != NULL) {

        adm_object_existent_service_assigner(
            pool_target->ent_service_assigner,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_SERVICE_ASSIGNER_ASSIGN_CAR :

            switch ((pool_target->ent_service_assigner)->status) {

                case ADM_STATUS_SERVICE_ASSIGNER_IDLE :

                    dst_allocate = (adm_dst_service_assigner_allocate_typ*)pool_target->dataset.allocate;

                    adm_sim_display_state_service_assigner_allocating_car(pool_target);

                    (pool_target->ent_service_assigner)->status = ADM_STATUS_SERVICE_ASSIGNER_ALLOCATING_CAR;

                    adm_state_action_service_assigner_allocating_car(
                        pool_target->ent_service_assigner,
                        dst_allocate);

                    adm_deallocate_memory(pool_target->dataset.allocate);

                break;

                case ADM_STATUS_SERVICE_ASSIGNER_ALLOCATING_CAR :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Service_Assigner",
                        (pool_target->ent_service_assigner)->identity,
                        "Event:Assign_car",
                        "State:Allocating_Car");

                break;
            }

        break;

        case ADM_EVENT_SERVICE_ASSIGNER_CAR_ASSIGNED :

            switch ((pool_target->ent_service_assigner)->status) {

                case ADM_STATUS_SERVICE_ASSIGNER_IDLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Service_Assigner",
                        (pool_target->ent_service_assigner)->identity,
                        "Event:Car_assigned",
                        "State:Idle");

                break;

                case ADM_STATUS_SERVICE_ASSIGNER_ALLOCATING_CAR :

                    adm_sim_display_state_service_assigner_idle(pool_target);

                    (pool_target->ent_service_assigner)->status = ADM_STATUS_SERVICE_ASSIGNER_IDLE;

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_service_assigner");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */