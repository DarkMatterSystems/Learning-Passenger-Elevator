
#include "~PassengerElevator.0000.0000.Header.h"


/* Floor Data Access */

/* Make Entity Object */

adm_ent_floor_typ * adm_make_object_floor(
    adm_sta_floor_typ status)
{
    adm_ent_floor_typ * ent_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_floor");
    #endif

    if (adm_entity_system.ent_floor.dead_list_head != NULL) {

        ent_floor = adm_entity_system.ent_floor.dead_list_head;

        if (adm_entity_system.ent_floor.dead_list_head == ent_floor) {

            adm_entity_system.ent_floor.dead_list_head = ent_floor->next;

        } else {

            (ent_floor->back)->next = ent_floor->next;
        }

        if (adm_entity_system.ent_floor.dead_list_tail == ent_floor) {

            adm_entity_system.ent_floor.dead_list_tail = ent_floor->back;

        } else {

            (ent_floor->next)->back = ent_floor->back;
        }

    } else {

        ent_floor = (adm_ent_floor_typ*)adm_allocate_memory(sizeof(adm_ent_floor_typ));
    }

    ent_floor->identity = ++adm_entity_system.ent_floor.tote;

    ent_floor->unique  = FALSE;
    ent_floor->deleted = FALSE;
    ent_floor->marked  = FALSE;
    ent_floor->status  = status;

    ent_floor->rel_serviced_by_car_service_head = NULL;
    ent_floor->rel_serviced_by_car_service_tail = NULL;

    ent_floor->back = NULL;
    ent_floor->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_floor");
    #endif

    return (ent_floor);
}


/* Bind Entity Object */

void adm_bind_object_floor(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_floor");
    #endif

    adm_object_existent_floor(
        ent_floor,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_floor.live_list_head == NULL) {

        ent_floor->back = NULL;

        adm_entity_system.ent_floor.live_list_head = ent_floor;

    } else {

        ent_floor->back = adm_entity_system.ent_floor.live_list_tail;

        (adm_entity_system.ent_floor.live_list_tail)->next = ent_floor;
    }

    ent_floor->next = NULL;

    adm_entity_system.ent_floor.live_list_tail = ent_floor;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_floor");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_floor(
    void * source_object,
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_floor");
    #endif

    adm_object_existent_floor(
        ent_floor,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_floor) {

        if (ent_floor->rel_serviced_by_car_service_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Floor",
                ent_floor->identity,
                "Serviced_by",
                "Car_Service");
        }

        if (adm_entity_system.ent_floor.live_list_head == ent_floor) {

            adm_entity_system.ent_floor.live_list_head = ent_floor->next;

        } else {

            (ent_floor->back)->next = ent_floor->next;
        }

        if (adm_entity_system.ent_floor.live_list_tail == ent_floor) {

            adm_entity_system.ent_floor.live_list_tail = ent_floor->back;

        } else {

            (ent_floor->next)->back = ent_floor->back;
        }

        ent_floor->deleted = TRUE;

        if (adm_entity_system.ent_floor.dead_list_head == NULL) {

            ent_floor->back = NULL;

            adm_entity_system.ent_floor.dead_list_head = ent_floor;

        } else {

            ent_floor->back = adm_entity_system.ent_floor.dead_list_tail;

            (adm_entity_system.ent_floor.dead_list_tail)->next = ent_floor;
        }

        ent_floor->next = NULL;

        adm_entity_system.ent_floor.dead_list_tail = ent_floor;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Floor",
            ent_floor->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_floor");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_floor_serviced_by_car_service(
    adm_ent_floor_typ * ent_source_floor,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service;

    adm_base_boolean_typ car_service_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_floor_serviced_by_car_service");
    #endif

    adm_object_existent_floor(
        ent_source_floor,
        error_file,
        error_line,
        error_rank);

    car_service_not_found = TRUE;

    rel_floor_serviced_by_car_service = ent_source_floor->rel_serviced_by_car_service_head;

    while (
        car_service_not_found &&
        rel_floor_serviced_by_car_service != NULL) {

        if (rel_floor_serviced_by_car_service->ent_car_service == ent_target_car_service) {

            car_service_not_found = FALSE;
        }

        rel_floor_serviced_by_car_service = rel_floor_serviced_by_car_service->next;
    }

    if (car_service_not_found) {

        rel_floor_serviced_by_car_service = (adm_rel_floor_serviced_by_car_service_typ*)
            adm_allocate_memory(sizeof(adm_rel_floor_serviced_by_car_service_typ));

        rel_floor_serviced_by_car_service->ent_car_service = ent_target_car_service;

        if (ent_source_floor->rel_serviced_by_car_service_head == NULL) {

            rel_floor_serviced_by_car_service->back = NULL;

            ent_source_floor->rel_serviced_by_car_service_head = rel_floor_serviced_by_car_service;

        } else {

            rel_floor_serviced_by_car_service->back = ent_source_floor->rel_serviced_by_car_service_tail;

            (ent_source_floor->rel_serviced_by_car_service_tail)->next = rel_floor_serviced_by_car_service;
        }

        rel_floor_serviced_by_car_service->next = NULL;

        ent_source_floor->rel_serviced_by_car_service_tail = rel_floor_serviced_by_car_service;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Floor",
            ent_source_floor->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_floor_serviced_by_car_service");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_floor_serviced_by_car_service(
    adm_ent_floor_typ * ent_floor,
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_floor_serviced_by_car_service");
    #endif

    adm_object_existent_floor(
        ent_floor,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_floor_serviced_by_car_service->next !=
        (adm_base_integer_typ)rel_floor_serviced_by_car_service->ent_car_service) {

        if (ent_floor->rel_serviced_by_car_service_head != NULL) {

            if (ent_floor->rel_serviced_by_car_service_head == rel_floor_serviced_by_car_service) {

                ent_floor->rel_serviced_by_car_service_head = rel_floor_serviced_by_car_service->next;

            } else {

                (rel_floor_serviced_by_car_service->back)->next = rel_floor_serviced_by_car_service->next;
            }

            if (ent_floor->rel_serviced_by_car_service_tail == rel_floor_serviced_by_car_service) {

                ent_floor->rel_serviced_by_car_service_tail = rel_floor_serviced_by_car_service->back;

            } else {

                (rel_floor_serviced_by_car_service->next)->back = rel_floor_serviced_by_car_service->back;
            }

            adm_deallocate_memory(rel_floor_serviced_by_car_service);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Floor",
                ent_floor->identity,
                "Serviced_by",
                "Car_Service");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Floor",
            ent_floor->identity,
            "Serviced_by",
            "Car_Service");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_floor_serviced_by_car_service");
    #endif
}


/* Object Existent */

void adm_object_existent_floor(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_floor");
    #endif

    if (ent_floor->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Floor",
            ent_floor->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */