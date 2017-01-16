
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Stop State Actions */

void adm_state_action_car_stop_awaiting_floor(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_dst_car_stop_await_typ * dst_await)
{
    /* Entity Objects */
    adm_ent_car_typ * ent_car_0000000001;
    adm_ent_car_service_typ * ent_car_service_0000000001;
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_car_typ * ent_car_0000000002;
    adm_ent_floor_typ * ent_floor_0000000002;

    /* Relationship Relations */
    adm_rel_car_stop_directs_car_typ * rel_car_stop_directs_car_0000000001;
    adm_rel_car_services_car_service_typ * rel_car_services_car_service_0000000001;
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor_0000000001;
    adm_rel_car_stop_directs_car_typ * rel_car_stop_directs_car_0000000002;
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_stop_awaiting_floor");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car_stop(
        ent_car_stop,
        1, 227, 45);

    rel_car_stop_directs_car_0000000001 = ent_car_stop->rel_directs_car_head;

    ent_car_0000000001 = rel_car_stop_directs_car_0000000001->ent_car;

    rel_car_services_car_service_0000000001 = ent_car_0000000001->rel_services_car_service_head;

    while (rel_car_services_car_service_0000000001 != NULL) {

        ent_car_service_0000000001 = rel_car_services_car_service_0000000001->ent_car_service;

        rel_car_service_services_floor_0000000001 = ent_car_service_0000000001->rel_services_floor_head;

        ent_floor_0000000001 = rel_car_service_services_floor_0000000001->ent_floor;

        /* CaseSelection */

        if (
            (
                (
                    ent_floor_0000000001->atb_number == dst_await->desired_floor_number
                )
            )) {

            /* Traverse - TraverseSelection */

            adm_object_existent_car_stop(
                ent_car_stop,
                1, 241, 65);

            rel_car_stop_directs_car_0000000002 = ent_car_stop->rel_directs_car_head;

            ent_car_0000000002 = rel_car_stop_directs_car_0000000002->ent_car;

            rel_car_currently_at_floor_0000000002 = ent_car_0000000002->rel_currently_at_floor_head;

            ent_floor_0000000002 = rel_car_currently_at_floor_0000000002->ent_floor;

            /* CaseSelection */

            if (
                (
                    (
                        ent_floor_0000000002->atb_number <= ent_floor_0000000001->atb_number
                    )
                )) {

                /* Relate */

                adm_link_relation_car_scheduled_to_move_up_to_floor(
                    ent_car_0000000002,
                    ent_floor_0000000001,
                    1, 257, 81);

            } else if (
                (
                    (
                        ent_floor_0000000002->atb_number > ent_floor_0000000001->atb_number
                    )
                )) {

                /* Relate */

                adm_link_relation_car_scheduled_to_move_down_to_floor(
                    ent_car_0000000002,
                    ent_floor_0000000001,
                    1, 267, 81);
            }

            /* GenerateEvent */

            adm_send_event_car_service_requested(
                ent_car_stop,
                ent_car_0000000002,
                1, 270, 69);
        }

        rel_car_services_car_service_0000000001 = rel_car_services_car_service_0000000001->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_stop_awaiting_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */