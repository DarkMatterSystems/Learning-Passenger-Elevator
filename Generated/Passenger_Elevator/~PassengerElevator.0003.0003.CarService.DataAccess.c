
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Service Data Access */

/* Make Entity Object */

adm_ent_car_service_typ * adm_make_object_car_service(
    void)
{
    adm_ent_car_service_typ * ent_car_service;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car_service");
    #endif

    if (adm_entity_system.ent_car_service.dead_list_head != NULL) {

        ent_car_service = adm_entity_system.ent_car_service.dead_list_head;

        if (adm_entity_system.ent_car_service.dead_list_head == ent_car_service) {

            adm_entity_system.ent_car_service.dead_list_head = ent_car_service->next;

        } else {

            (ent_car_service->back)->next = ent_car_service->next;
        }

        if (adm_entity_system.ent_car_service.dead_list_tail == ent_car_service) {

            adm_entity_system.ent_car_service.dead_list_tail = ent_car_service->back;

        } else {

            (ent_car_service->next)->back = ent_car_service->back;
        }

    } else {

        ent_car_service = (adm_ent_car_service_typ*)adm_allocate_memory(sizeof(adm_ent_car_service_typ));
    }

    ent_car_service->identity = ++adm_entity_system.ent_car_service.tote;

    ent_car_service->unique  = FALSE;
    ent_car_service->deleted = FALSE;
    ent_car_service->marked  = FALSE;
    ent_car_service->ignore  = null;

    ent_car_service->rel_services_floor_head = NULL;
    ent_car_service->rel_services_floor_tail = NULL;

    ent_car_service->rel_serviced_by_car_head = NULL;
    ent_car_service->rel_serviced_by_car_tail = NULL;

    ent_car_service->rel_assigned_by_service_assigner_head = NULL;
    ent_car_service->rel_assigned_by_service_assigner_tail = NULL;

    ent_car_service->back = NULL;
    ent_car_service->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car_service");
    #endif

    return (ent_car_service);
}


/* Bind Entity Object */

void adm_bind_object_car_service(
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car_service");
    #endif

    adm_object_existent_car_service(
        ent_car_service,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_car_service.live_list_head == NULL) {

        ent_car_service->back = NULL;

        adm_entity_system.ent_car_service.live_list_head = ent_car_service;

    } else {

        ent_car_service->back = adm_entity_system.ent_car_service.live_list_tail;

        (adm_entity_system.ent_car_service.live_list_tail)->next = ent_car_service;
    }

    ent_car_service->next = NULL;

    adm_entity_system.ent_car_service.live_list_tail = ent_car_service;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car_service");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_car_service(
    void * source_object,
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car_service");
    #endif

    adm_object_existent_car_service(
        ent_car_service,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_car_service) {

        if (ent_car_service->rel_services_floor_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Services",
                "Floor");
        }

        if (ent_car_service->rel_serviced_by_car_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Serviced_by",
                "Car");
        }

        if (ent_car_service->rel_assigned_by_service_assigner_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Assigned_by",
                "Service_Assigner");
        }

        if (adm_entity_system.ent_car_service.live_list_head == ent_car_service) {

            adm_entity_system.ent_car_service.live_list_head = ent_car_service->next;

        } else {

            (ent_car_service->back)->next = ent_car_service->next;
        }

        if (adm_entity_system.ent_car_service.live_list_tail == ent_car_service) {

            adm_entity_system.ent_car_service.live_list_tail = ent_car_service->back;

        } else {

            (ent_car_service->next)->back = ent_car_service->back;
        }

        ent_car_service->deleted = TRUE;

        if (adm_entity_system.ent_car_service.dead_list_head == NULL) {

            ent_car_service->back = NULL;

            adm_entity_system.ent_car_service.dead_list_head = ent_car_service;

        } else {

            ent_car_service->back = adm_entity_system.ent_car_service.dead_list_tail;

            (adm_entity_system.ent_car_service.dead_list_tail)->next = ent_car_service;
        }

        ent_car_service->next = NULL;

        adm_entity_system.ent_car_service.dead_list_tail = ent_car_service;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_car_service->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car_service");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_car_service_services_floor(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor;

    adm_base_boolean_typ floor_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_services_floor");
    #endif

    adm_object_existent_car_service(
        ent_source_car_service,
        error_file,
        error_line,
        error_rank);

    floor_not_found = TRUE;

    rel_car_service_services_floor = ent_source_car_service->rel_services_floor_head;

    while (
        floor_not_found &&
        rel_car_service_services_floor != NULL) {

        if (rel_car_service_services_floor->ent_floor == ent_target_floor) {

            floor_not_found = FALSE;
        }

        rel_car_service_services_floor = rel_car_service_services_floor->next;
    }

    if (floor_not_found) {

        rel_car_service_services_floor = (adm_rel_car_service_services_floor_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_service_services_floor_typ));

        rel_car_service_services_floor->ent_floor = ent_target_floor;

        if (ent_source_car_service->rel_services_floor_head == NULL) {

            rel_car_service_services_floor->back = NULL;

            ent_source_car_service->rel_services_floor_head = rel_car_service_services_floor;

        } else {

            rel_car_service_services_floor->back = ent_source_car_service->rel_services_floor_tail;

            (ent_source_car_service->rel_services_floor_tail)->next = rel_car_service_services_floor;
        }

        rel_car_service_services_floor->next = NULL;

        ent_source_car_service->rel_services_floor_tail = rel_car_service_services_floor;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_source_car_service->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_services_floor");
    #endif
}

void adm_link_relation_car_service_serviced_by_car(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car;

    adm_base_boolean_typ car_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_serviced_by_car");
    #endif

    adm_object_existent_car_service(
        ent_source_car_service,
        error_file,
        error_line,
        error_rank);

    car_not_found = TRUE;

    rel_car_service_serviced_by_car = ent_source_car_service->rel_serviced_by_car_head;

    while (
        car_not_found &&
        rel_car_service_serviced_by_car != NULL) {

        if (rel_car_service_serviced_by_car->ent_car == ent_target_car) {

            car_not_found = FALSE;
        }

        rel_car_service_serviced_by_car = rel_car_service_serviced_by_car->next;
    }

    if (car_not_found) {

        rel_car_service_serviced_by_car = (adm_rel_car_service_serviced_by_car_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_service_serviced_by_car_typ));

        rel_car_service_serviced_by_car->ent_car = ent_target_car;

        if (ent_source_car_service->rel_serviced_by_car_head == NULL) {

            rel_car_service_serviced_by_car->back = NULL;

            ent_source_car_service->rel_serviced_by_car_head = rel_car_service_serviced_by_car;

        } else {

            rel_car_service_serviced_by_car->back = ent_source_car_service->rel_serviced_by_car_tail;

            (ent_source_car_service->rel_serviced_by_car_tail)->next = rel_car_service_serviced_by_car;
        }

        rel_car_service_serviced_by_car->next = NULL;

        ent_source_car_service->rel_serviced_by_car_tail = rel_car_service_serviced_by_car;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_source_car_service->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_serviced_by_car");
    #endif
}

void adm_link_relation_car_service_assigned_by_service_assigner(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_service_assigner_typ * ent_target_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_service_assigned_by_service_assigner_typ * rel_car_service_assigned_by_service_assigner;

    adm_base_boolean_typ service_assigner_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_assigned_by_service_assigner");
    #endif

    adm_object_existent_car_service(
        ent_source_car_service,
        error_file,
        error_line,
        error_rank);

    service_assigner_not_found = TRUE;

    rel_car_service_assigned_by_service_assigner = ent_source_car_service->rel_assigned_by_service_assigner_head;

    while (
        service_assigner_not_found &&
        rel_car_service_assigned_by_service_assigner != NULL) {

        if (rel_car_service_assigned_by_service_assigner->ent_service_assigner == ent_target_service_assigner) {

            service_assigner_not_found = FALSE;
        }

        rel_car_service_assigned_by_service_assigner = rel_car_service_assigned_by_service_assigner->next;
    }

    if (service_assigner_not_found) {

        rel_car_service_assigned_by_service_assigner = (adm_rel_car_service_assigned_by_service_assigner_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_service_assigned_by_service_assigner_typ));

        rel_car_service_assigned_by_service_assigner->ent_service_assigner = ent_target_service_assigner;

        if (ent_source_car_service->rel_assigned_by_service_assigner_head == NULL) {

            rel_car_service_assigned_by_service_assigner->back = NULL;

            ent_source_car_service->rel_assigned_by_service_assigner_head = rel_car_service_assigned_by_service_assigner;

        } else {

            rel_car_service_assigned_by_service_assigner->back = ent_source_car_service->rel_assigned_by_service_assigner_tail;

            (ent_source_car_service->rel_assigned_by_service_assigner_tail)->next = rel_car_service_assigned_by_service_assigner;
        }

        rel_car_service_assigned_by_service_assigner->next = NULL;

        ent_source_car_service->rel_assigned_by_service_assigner_tail = rel_car_service_assigned_by_service_assigner;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_source_car_service->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_service_assigned_by_service_assigner");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_car_service_services_floor(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_services_floor");
    #endif

    adm_object_existent_car_service(
        ent_car_service,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_service_services_floor->next !=
        (adm_base_integer_typ)rel_car_service_services_floor->ent_floor) {

        if (ent_car_service->rel_services_floor_head != NULL) {

            if (ent_car_service->rel_services_floor_head == rel_car_service_services_floor) {

                ent_car_service->rel_services_floor_head = rel_car_service_services_floor->next;

            } else {

                (rel_car_service_services_floor->back)->next = rel_car_service_services_floor->next;
            }

            if (ent_car_service->rel_services_floor_tail == rel_car_service_services_floor) {

                ent_car_service->rel_services_floor_tail = rel_car_service_services_floor->back;

            } else {

                (rel_car_service_services_floor->next)->back = rel_car_service_services_floor->back;
            }

            adm_deallocate_memory(rel_car_service_services_floor);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Services",
                "Floor");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_car_service->identity,
            "Services",
            "Floor");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_services_floor");
    #endif
}

void adm_kill_relation_car_service_serviced_by_car(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_serviced_by_car");
    #endif

    adm_object_existent_car_service(
        ent_car_service,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_service_serviced_by_car->next !=
        (adm_base_integer_typ)rel_car_service_serviced_by_car->ent_car) {

        if (ent_car_service->rel_serviced_by_car_head != NULL) {

            if (ent_car_service->rel_serviced_by_car_head == rel_car_service_serviced_by_car) {

                ent_car_service->rel_serviced_by_car_head = rel_car_service_serviced_by_car->next;

            } else {

                (rel_car_service_serviced_by_car->back)->next = rel_car_service_serviced_by_car->next;
            }

            if (ent_car_service->rel_serviced_by_car_tail == rel_car_service_serviced_by_car) {

                ent_car_service->rel_serviced_by_car_tail = rel_car_service_serviced_by_car->back;

            } else {

                (rel_car_service_serviced_by_car->next)->back = rel_car_service_serviced_by_car->back;
            }

            adm_deallocate_memory(rel_car_service_serviced_by_car);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Serviced_by",
                "Car");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_car_service->identity,
            "Serviced_by",
            "Car");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_serviced_by_car");
    #endif
}

void adm_kill_relation_car_service_assigned_by_service_assigner(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_assigned_by_service_assigner_typ * rel_car_service_assigned_by_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_assigned_by_service_assigner");
    #endif

    adm_object_existent_car_service(
        ent_car_service,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_service_assigned_by_service_assigner->next !=
        (adm_base_integer_typ)rel_car_service_assigned_by_service_assigner->ent_service_assigner) {

        if (ent_car_service->rel_assigned_by_service_assigner_head != NULL) {

            if (ent_car_service->rel_assigned_by_service_assigner_head == rel_car_service_assigned_by_service_assigner) {

                ent_car_service->rel_assigned_by_service_assigner_head = rel_car_service_assigned_by_service_assigner->next;

            } else {

                (rel_car_service_assigned_by_service_assigner->back)->next = rel_car_service_assigned_by_service_assigner->next;
            }

            if (ent_car_service->rel_assigned_by_service_assigner_tail == rel_car_service_assigned_by_service_assigner) {

                ent_car_service->rel_assigned_by_service_assigner_tail = rel_car_service_assigned_by_service_assigner->back;

            } else {

                (rel_car_service_assigned_by_service_assigner->next)->back = rel_car_service_assigned_by_service_assigner->back;
            }

            adm_deallocate_memory(rel_car_service_assigned_by_service_assigner);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car_Service",
                ent_car_service->identity,
                "Assigned_by",
                "Service_Assigner");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_car_service->identity,
            "Assigned_by",
            "Service_Assigner");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_service_assigned_by_service_assigner");
    #endif
}


/* Object Existent */

void adm_object_existent_car_service(
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car_service");
    #endif

    if (ent_car_service->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Car_Service",
            ent_car_service->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car_service");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */