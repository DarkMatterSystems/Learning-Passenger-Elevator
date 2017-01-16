
#include "~PassengerElevator.0000.0000.Header.h"


/* Service Assigner Event Senders */

void adm_send_event_service_assigner_assign_car(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_int_floor_typ evd_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_service_assigner_typ * pool_target;
    adm_pool_target_service_assigner_typ * home_pool_target;

    adm_dst_service_assigner_allocate_typ * dst_allocate;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_service_assigner_assign_car");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_service_assigner_assign_car(
            ent_service_assigner,
            evd_floor_number,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_service_assigner(
            ent_service_assigner,
            error_file,
            error_line,
            error_rank);

        if (
            evd_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
            evd_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Service_Assigner",
                ent_service_assigner->identity,
                "floor_number",
                adm_sim_lib_itoa(evd_floor_number));
        }

        dst_allocate = (adm_dst_service_assigner_allocate_typ*)
            adm_allocate_memory(sizeof(adm_dst_service_assigner_allocate_typ));

        dst_allocate->floor_number = evd_floor_number;

        pool_target = (adm_pool_target_service_assigner_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_service_assigner_typ));

        pool_target->evente = ADM_EVENT_SERVICE_ASSIGNER_ASSIGN_CAR;
        pool_target->ent_service_assigner = ent_service_assigner;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.allocate = dst_allocate;

        if (source_object == ent_service_assigner) {

            if (adm_entity_system.ent_service_assigner.home_pool_head == NULL) {

                adm_entity_system.ent_service_assigner.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_service_assigner.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_service_assigner == ent_service_assigner) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Service_Assigner",
                            ent_service_assigner->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_service_assigner.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_service_assigner.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_service_assigner.away_pool_head == NULL) {

                adm_entity_system.ent_service_assigner.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_service_assigner.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_service_assigner.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_service_assigner_assign_car");
    #endif
}

void adm_send_event_service_assigner_car_assigned(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_service_assigner_typ * pool_target;
    adm_pool_target_service_assigner_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_service_assigner_car_assigned");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_service_assigner_car_assigned(
            ent_service_assigner,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_service_assigner(
            ent_service_assigner,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_service_assigner_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_service_assigner_typ));

        pool_target->evente = ADM_EVENT_SERVICE_ASSIGNER_CAR_ASSIGNED;
        pool_target->ent_service_assigner = ent_service_assigner;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_service_assigner) {

            if (adm_entity_system.ent_service_assigner.home_pool_head == NULL) {

                adm_entity_system.ent_service_assigner.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_service_assigner.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_service_assigner == ent_service_assigner) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Service_Assigner",
                            ent_service_assigner->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_service_assigner.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_service_assigner.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_service_assigner.away_pool_head == NULL) {

                adm_entity_system.ent_service_assigner.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_service_assigner.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_service_assigner.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_service_assigner_car_assigned");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */