
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Stop Dispatcher */

/* Dispatcher */

void adm_dispatcher_car_stop(
    void)
{
    adm_pool_target_car_stop_typ * pool_target_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_car_stop");
    #endif

    pool_target_car_stop = adm_find_away_target_event_car_stop();

    adm_dispatch_state_action_car_stop(pool_target_car_stop);

    adm_dispatch_home_pool_car_stop();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_car_stop");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_car_stop(
    void)
{
    adm_pool_target_car_stop_typ * pool_target_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_car_stop");
    #endif

    while (adm_entity_system.ent_car_stop.home_pool_head != NULL) {

        pool_target_car_stop = adm_find_home_target_event_car_stop();

        adm_dispatch_state_action_car_stop(pool_target_car_stop);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_car_stop");
    #endif
}


/* Find Home Target Event */

adm_pool_target_car_stop_typ * adm_find_home_target_event_car_stop(
    void)
{
    adm_pool_target_car_stop_typ * pool_target_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_car_stop");
    #endif

    pool_target_car_stop = adm_entity_system.ent_car_stop.home_pool_head;

    adm_entity_system.ent_car_stop.home_pool_head = pool_target_car_stop->next;

    if (adm_entity_system.ent_car_stop.home_pool_head == NULL) {

        adm_entity_system.ent_car_stop.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_car_stop");
    #endif

    return (pool_target_car_stop);
}


/* Find Away Target Event */

adm_pool_target_car_stop_typ * adm_find_away_target_event_car_stop(
    void)
{
    adm_pool_target_car_stop_typ * pool_target_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_car_stop");
    #endif

    pool_target_car_stop = adm_entity_system.ent_car_stop.away_pool_head;

    adm_entity_system.ent_car_stop.away_pool_head = pool_target_car_stop->next;

    if (adm_entity_system.ent_car_stop.away_pool_head == NULL) {

        adm_entity_system.ent_car_stop.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_car_stop");
    #endif

    return (pool_target_car_stop);
}


/* Dispatch State Action */

void adm_dispatch_state_action_car_stop(
    adm_pool_target_car_stop_typ * pool_target)
{
    adm_dst_car_stop_await_typ * dst_await;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_car_stop");
    #endif

    if (pool_target->ent_car_stop != NULL) {

        adm_object_existent_car_stop(
            pool_target->ent_car_stop,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_CAR_STOP_GO_TO_FLOOR :

            switch ((pool_target->ent_car_stop)->status) {

                case ADM_STATUS_CAR_STOP_AWAITING_FLOOR :

                    dst_await = (adm_dst_car_stop_await_typ*)pool_target->dataset.await;

                    adm_sim_display_state_car_stop_awaiting_floor(pool_target);

                    (pool_target->ent_car_stop)->status = ADM_STATUS_CAR_STOP_AWAITING_FLOOR;

                    adm_state_action_car_stop_awaiting_floor(
                        pool_target->ent_car_stop,
                        dst_await);

                    adm_deallocate_memory(pool_target->dataset.await);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_car_stop");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */