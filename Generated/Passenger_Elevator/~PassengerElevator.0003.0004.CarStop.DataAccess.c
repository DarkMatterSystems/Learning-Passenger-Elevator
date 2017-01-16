
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Stop Data Access */

/* Make Entity Object */

adm_ent_car_stop_typ * adm_make_object_car_stop(
    adm_sta_car_stop_typ status)
{
    adm_ent_car_stop_typ * ent_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car_stop");
    #endif

    if (adm_entity_system.ent_car_stop.dead_list_head != NULL) {

        ent_car_stop = adm_entity_system.ent_car_stop.dead_list_head;

        if (adm_entity_system.ent_car_stop.dead_list_head == ent_car_stop) {

            adm_entity_system.ent_car_stop.dead_list_head = ent_car_stop->next;

        } else {

            (ent_car_stop->back)->next = ent_car_stop->next;
        }

        if (adm_entity_system.ent_car_stop.dead_list_tail == ent_car_stop) {

            adm_entity_system.ent_car_stop.dead_list_tail = ent_car_stop->back;

        } else {

            (ent_car_stop->next)->back = ent_car_stop->back;
        }

    } else {

        ent_car_stop = (adm_ent_car_stop_typ*)adm_allocate_memory(sizeof(adm_ent_car_stop_typ));
    }

    ent_car_stop->identity = ++adm_entity_system.ent_car_stop.tote;

    ent_car_stop->unique  = FALSE;
    ent_car_stop->deleted = FALSE;
    ent_car_stop->marked  = FALSE;
    ent_car_stop->status  = status;

    ent_car_stop->rel_directs_car_head = NULL;
    ent_car_stop->rel_directs_car_tail = NULL;

    ent_car_stop->back = NULL;
    ent_car_stop->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car_stop");
    #endif

    return (ent_car_stop);
}


/* Bind Entity Object */

void adm_bind_object_car_stop(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car_stop");
    #endif

    adm_object_existent_car_stop(
        ent_car_stop,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_car_stop.live_list_head == NULL) {

        ent_car_stop->back = NULL;

        adm_entity_system.ent_car_stop.live_list_head = ent_car_stop;

    } else {

        ent_car_stop->back = adm_entity_system.ent_car_stop.live_list_tail;

        (adm_entity_system.ent_car_stop.live_list_tail)->next = ent_car_stop;
    }

    ent_car_stop->next = NULL;

    adm_entity_system.ent_car_stop.live_list_tail = ent_car_stop;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car_stop");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_car_stop(
    void * source_object,
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car_stop");
    #endif

    adm_object_existent_car_stop(
        ent_car_stop,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_car_stop) {

        if (ent_car_stop->rel_directs_car_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car_Stop",
                ent_car_stop->identity,
                "Directs",
                "Car");
        }

        if (adm_entity_system.ent_car_stop.live_list_head == ent_car_stop) {

            adm_entity_system.ent_car_stop.live_list_head = ent_car_stop->next;

        } else {

            (ent_car_stop->back)->next = ent_car_stop->next;
        }

        if (adm_entity_system.ent_car_stop.live_list_tail == ent_car_stop) {

            adm_entity_system.ent_car_stop.live_list_tail = ent_car_stop->back;

        } else {

            (ent_car_stop->next)->back = ent_car_stop->back;
        }

        ent_car_stop->deleted = TRUE;

        if (adm_entity_system.ent_car_stop.dead_list_head == NULL) {

            ent_car_stop->back = NULL;

            adm_entity_system.ent_car_stop.dead_list_head = ent_car_stop;

        } else {

            ent_car_stop->back = adm_entity_system.ent_car_stop.dead_list_tail;

            (adm_entity_system.ent_car_stop.dead_list_tail)->next = ent_car_stop;
        }

        ent_car_stop->next = NULL;

        adm_entity_system.ent_car_stop.dead_list_tail = ent_car_stop;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Car_Stop",
            ent_car_stop->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car_stop");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_car_stop_directs_car(
    adm_ent_car_stop_typ * ent_source_car_stop,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_stop_directs_car_typ * rel_car_stop_directs_car;

    adm_base_boolean_typ car_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_stop_directs_car");
    #endif

    adm_object_existent_car_stop(
        ent_source_car_stop,
        error_file,
        error_line,
        error_rank);

    car_not_found = TRUE;

    rel_car_stop_directs_car = ent_source_car_stop->rel_directs_car_head;

    while (
        car_not_found &&
        rel_car_stop_directs_car != NULL) {

        if (rel_car_stop_directs_car->ent_car == ent_target_car) {

            car_not_found = FALSE;
        }

        rel_car_stop_directs_car = rel_car_stop_directs_car->next;
    }

    if (car_not_found) {

        rel_car_stop_directs_car = (adm_rel_car_stop_directs_car_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_stop_directs_car_typ));

        rel_car_stop_directs_car->ent_car = ent_target_car;

        if (ent_source_car_stop->rel_directs_car_head == NULL) {

            rel_car_stop_directs_car->back = NULL;

            ent_source_car_stop->rel_directs_car_head = rel_car_stop_directs_car;

        } else {

            rel_car_stop_directs_car->back = ent_source_car_stop->rel_directs_car_tail;

            (ent_source_car_stop->rel_directs_car_tail)->next = rel_car_stop_directs_car;
        }

        rel_car_stop_directs_car->next = NULL;

        ent_source_car_stop->rel_directs_car_tail = rel_car_stop_directs_car;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car_Stop",
            ent_source_car_stop->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_stop_directs_car");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_car_stop_directs_car(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_rel_car_stop_directs_car_typ * rel_car_stop_directs_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_stop_directs_car");
    #endif

    adm_object_existent_car_stop(
        ent_car_stop,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_stop_directs_car->next !=
        (adm_base_integer_typ)rel_car_stop_directs_car->ent_car) {

        if (ent_car_stop->rel_directs_car_head != NULL) {

            if (ent_car_stop->rel_directs_car_head == rel_car_stop_directs_car) {

                ent_car_stop->rel_directs_car_head = rel_car_stop_directs_car->next;

            } else {

                (rel_car_stop_directs_car->back)->next = rel_car_stop_directs_car->next;
            }

            if (ent_car_stop->rel_directs_car_tail == rel_car_stop_directs_car) {

                ent_car_stop->rel_directs_car_tail = rel_car_stop_directs_car->back;

            } else {

                (rel_car_stop_directs_car->next)->back = rel_car_stop_directs_car->back;
            }

            adm_deallocate_memory(rel_car_stop_directs_car);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car_Stop",
                ent_car_stop->identity,
                "Directs",
                "Car");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car_Stop",
            ent_car_stop->identity,
            "Directs",
            "Car");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_stop_directs_car");
    #endif
}


/* Object Existent */

void adm_object_existent_car_stop(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car_stop");
    #endif

    if (ent_car_stop->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Car_Stop",
            ent_car_stop->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car_stop");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */