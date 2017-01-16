
#include "~PassengerElevator.0000.0000.Header.h"


/* Service Assigner Data Access */

/* Make Entity Object */

adm_ent_service_assigner_typ * adm_make_object_service_assigner(
    adm_sta_service_assigner_typ status)
{
    adm_ent_service_assigner_typ * ent_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_service_assigner");
    #endif

    if (adm_entity_system.ent_service_assigner.dead_list_head != NULL) {

        ent_service_assigner = adm_entity_system.ent_service_assigner.dead_list_head;

        if (adm_entity_system.ent_service_assigner.dead_list_head == ent_service_assigner) {

            adm_entity_system.ent_service_assigner.dead_list_head = ent_service_assigner->next;

        } else {

            (ent_service_assigner->back)->next = ent_service_assigner->next;
        }

        if (adm_entity_system.ent_service_assigner.dead_list_tail == ent_service_assigner) {

            adm_entity_system.ent_service_assigner.dead_list_tail = ent_service_assigner->back;

        } else {

            (ent_service_assigner->next)->back = ent_service_assigner->back;
        }

    } else {

        ent_service_assigner = (adm_ent_service_assigner_typ*)adm_allocate_memory(sizeof(adm_ent_service_assigner_typ));
    }

    ent_service_assigner->identity = ++adm_entity_system.ent_service_assigner.tote;

    ent_service_assigner->unique  = FALSE;
    ent_service_assigner->deleted = FALSE;
    ent_service_assigner->marked  = FALSE;
    ent_service_assigner->status  = status;

    ent_service_assigner->rel_assigns_car_service_head = NULL;
    ent_service_assigner->rel_assigns_car_service_tail = NULL;

    ent_service_assigner->back = NULL;
    ent_service_assigner->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_service_assigner");
    #endif

    return (ent_service_assigner);
}


/* Bind Entity Object */

void adm_bind_object_service_assigner(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_service_assigner");
    #endif

    adm_object_existent_service_assigner(
        ent_service_assigner,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_service_assigner.live_list_head == NULL) {

        ent_service_assigner->back = NULL;

        adm_entity_system.ent_service_assigner.live_list_head = ent_service_assigner;

    } else {

        ent_service_assigner->back = adm_entity_system.ent_service_assigner.live_list_tail;

        (adm_entity_system.ent_service_assigner.live_list_tail)->next = ent_service_assigner;
    }

    ent_service_assigner->next = NULL;

    adm_entity_system.ent_service_assigner.live_list_tail = ent_service_assigner;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_service_assigner");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_service_assigner(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_service_assigner");
    #endif

    adm_object_existent_service_assigner(
        ent_service_assigner,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_service_assigner) {

        if (ent_service_assigner->rel_assigns_car_service_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Service_Assigner",
                ent_service_assigner->identity,
                "Assigns",
                "Car_Service");
        }

        if (adm_entity_system.ent_service_assigner.live_list_head == ent_service_assigner) {

            adm_entity_system.ent_service_assigner.live_list_head = ent_service_assigner->next;

        } else {

            (ent_service_assigner->back)->next = ent_service_assigner->next;
        }

        if (adm_entity_system.ent_service_assigner.live_list_tail == ent_service_assigner) {

            adm_entity_system.ent_service_assigner.live_list_tail = ent_service_assigner->back;

        } else {

            (ent_service_assigner->next)->back = ent_service_assigner->back;
        }

        ent_service_assigner->deleted = TRUE;

        if (adm_entity_system.ent_service_assigner.dead_list_head == NULL) {

            ent_service_assigner->back = NULL;

            adm_entity_system.ent_service_assigner.dead_list_head = ent_service_assigner;

        } else {

            ent_service_assigner->back = adm_entity_system.ent_service_assigner.dead_list_tail;

            (adm_entity_system.ent_service_assigner.dead_list_tail)->next = ent_service_assigner;
        }

        ent_service_assigner->next = NULL;

        adm_entity_system.ent_service_assigner.dead_list_tail = ent_service_assigner;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Service_Assigner",
            ent_service_assigner->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_service_assigner");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_service_assigner_assigns_car_service(
    adm_ent_service_assigner_typ * ent_source_service_assigner,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_service_assigner_assigns_car_service_typ * rel_service_assigner_assigns_car_service;

    adm_base_boolean_typ car_service_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_service_assigner_assigns_car_service");
    #endif

    adm_object_existent_service_assigner(
        ent_source_service_assigner,
        error_file,
        error_line,
        error_rank);

    car_service_not_found = TRUE;

    rel_service_assigner_assigns_car_service = ent_source_service_assigner->rel_assigns_car_service_head;

    while (
        car_service_not_found &&
        rel_service_assigner_assigns_car_service != NULL) {

        if (rel_service_assigner_assigns_car_service->ent_car_service == ent_target_car_service) {

            car_service_not_found = FALSE;
        }

        rel_service_assigner_assigns_car_service = rel_service_assigner_assigns_car_service->next;
    }

    if (car_service_not_found) {

        rel_service_assigner_assigns_car_service = (adm_rel_service_assigner_assigns_car_service_typ*)
            adm_allocate_memory(sizeof(adm_rel_service_assigner_assigns_car_service_typ));

        rel_service_assigner_assigns_car_service->ent_car_service = ent_target_car_service;

        if (ent_source_service_assigner->rel_assigns_car_service_head == NULL) {

            rel_service_assigner_assigns_car_service->back = NULL;

            ent_source_service_assigner->rel_assigns_car_service_head = rel_service_assigner_assigns_car_service;

        } else {

            rel_service_assigner_assigns_car_service->back = ent_source_service_assigner->rel_assigns_car_service_tail;

            (ent_source_service_assigner->rel_assigns_car_service_tail)->next = rel_service_assigner_assigns_car_service;
        }

        rel_service_assigner_assigns_car_service->next = NULL;

        ent_source_service_assigner->rel_assigns_car_service_tail = rel_service_assigner_assigns_car_service;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Service_Assigner",
            ent_source_service_assigner->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_service_assigner_assigns_car_service");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_service_assigner_assigns_car_service(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_rel_service_assigner_assigns_car_service_typ * rel_service_assigner_assigns_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_service_assigner_assigns_car_service");
    #endif

    adm_object_existent_service_assigner(
        ent_service_assigner,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_service_assigner_assigns_car_service->next !=
        (adm_base_integer_typ)rel_service_assigner_assigns_car_service->ent_car_service) {

        if (ent_service_assigner->rel_assigns_car_service_head != NULL) {

            if (ent_service_assigner->rel_assigns_car_service_head == rel_service_assigner_assigns_car_service) {

                ent_service_assigner->rel_assigns_car_service_head = rel_service_assigner_assigns_car_service->next;

            } else {

                (rel_service_assigner_assigns_car_service->back)->next = rel_service_assigner_assigns_car_service->next;
            }

            if (ent_service_assigner->rel_assigns_car_service_tail == rel_service_assigner_assigns_car_service) {

                ent_service_assigner->rel_assigns_car_service_tail = rel_service_assigner_assigns_car_service->back;

            } else {

                (rel_service_assigner_assigns_car_service->next)->back = rel_service_assigner_assigns_car_service->back;
            }

            adm_deallocate_memory(rel_service_assigner_assigns_car_service);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Service_Assigner",
                ent_service_assigner->identity,
                "Assigns",
                "Car_Service");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Service_Assigner",
            ent_service_assigner->identity,
            "Assigns",
            "Car_Service");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_service_assigner_assigns_car_service");
    #endif
}


/* Object Existent */

void adm_object_existent_service_assigner(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_service_assigner");
    #endif

    if (ent_service_assigner->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Service_Assigner",
            ent_service_assigner->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_service_assigner");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */