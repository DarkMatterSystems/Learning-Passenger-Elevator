
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Stop Event Senders */

void adm_send_event_car_stop_go_to_floor(
    void * source_object,
    adm_ent_car_stop_typ * ent_car_stop,
    adm_int_floor_typ evd_desired_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_stop_typ * pool_target;
    adm_pool_target_car_stop_typ * home_pool_target;

    adm_dst_car_stop_await_typ * dst_await;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_stop_go_to_floor");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_stop_go_to_floor(
            ent_car_stop,
            evd_desired_floor_number,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car_stop(
            ent_car_stop,
            error_file,
            error_line,
            error_rank);

        if (
            evd_desired_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
            evd_desired_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Car_Stop",
                ent_car_stop->identity,
                "desired_floor_number",
                adm_sim_lib_itoa(evd_desired_floor_number));
        }

        dst_await = (adm_dst_car_stop_await_typ*)
            adm_allocate_memory(sizeof(adm_dst_car_stop_await_typ));

        dst_await->desired_floor_number = evd_desired_floor_number;

        pool_target = (adm_pool_target_car_stop_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_stop_typ));

        pool_target->evente = ADM_EVENT_CAR_STOP_GO_TO_FLOOR;
        pool_target->ent_car_stop = ent_car_stop;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.await = dst_await;

        if (source_object == ent_car_stop) {

            if (adm_entity_system.ent_car_stop.home_pool_head == NULL) {

                adm_entity_system.ent_car_stop.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car_stop.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car_stop == ent_car_stop) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car_Stop",
                            ent_car_stop->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car_stop.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car_stop.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car_stop.away_pool_head == NULL) {

                adm_entity_system.ent_car_stop.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car_stop.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car_stop.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_stop_go_to_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */