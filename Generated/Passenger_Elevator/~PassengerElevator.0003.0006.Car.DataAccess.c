
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Data Access */

/* Make Entity Object */

adm_ent_car_typ * adm_make_object_car(
    adm_sta_car_typ status)
{
    adm_ent_car_typ * ent_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car");
    #endif

    if (adm_entity_system.ent_car.dead_list_head != NULL) {

        ent_car = adm_entity_system.ent_car.dead_list_head;

        if (adm_entity_system.ent_car.dead_list_head == ent_car) {

            adm_entity_system.ent_car.dead_list_head = ent_car->next;

        } else {

            (ent_car->back)->next = ent_car->next;
        }

        if (adm_entity_system.ent_car.dead_list_tail == ent_car) {

            adm_entity_system.ent_car.dead_list_tail = ent_car->back;

        } else {

            (ent_car->next)->back = ent_car->back;
        }

    } else {

        ent_car = (adm_ent_car_typ*)adm_allocate_memory(sizeof(adm_ent_car_typ));
    }

    ent_car->identity = ++adm_entity_system.ent_car.tote;

    ent_car->unique  = FALSE;
    ent_car->deleted = FALSE;
    ent_car->marked  = FALSE;
    ent_car->status  = status;

    ent_car->rel_services_car_service_head = NULL;
    ent_car->rel_services_car_service_tail = NULL;

    ent_car->rel_currently_at_floor_head = NULL;
    ent_car->rel_currently_at_floor_tail = NULL;

    ent_car->rel_accessed_through_door_head = NULL;
    ent_car->rel_accessed_through_door_tail = NULL;

    ent_car->rel_scheduled_to_move_up_to_floor_head = NULL;
    ent_car->rel_scheduled_to_move_up_to_floor_tail = NULL;

    ent_car->rel_scheduled_to_move_down_to_floor_head = NULL;
    ent_car->rel_scheduled_to_move_down_to_floor_tail = NULL;

    ent_car->back = NULL;
    ent_car->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_car");
    #endif

    return (ent_car);
}


/* Bind Entity Object */

void adm_bind_object_car(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_car.live_list_head == NULL) {

        ent_car->back = NULL;

        adm_entity_system.ent_car.live_list_head = ent_car;

    } else {

        ent_car->back = adm_entity_system.ent_car.live_list_tail;

        (adm_entity_system.ent_car.live_list_tail)->next = ent_car;
    }

    ent_car->next = NULL;

    adm_entity_system.ent_car.live_list_tail = ent_car;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_car");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_car(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_car) {

        if (ent_car->rel_services_car_service_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Services",
                "Car_Service");
        }

        if (ent_car->rel_currently_at_floor_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Currently_at",
                "Floor");
        }

        if (ent_car->rel_accessed_through_door_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Accessed_through",
                "Door");
        }

        if (ent_car->rel_scheduled_to_move_up_to_floor_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Scheduled_to_move_up_to",
                "Floor");
        }

        if (ent_car->rel_scheduled_to_move_down_to_floor_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Scheduled_to_move_down_to",
                "Floor");
        }

        if (adm_entity_system.ent_car.live_list_head == ent_car) {

            adm_entity_system.ent_car.live_list_head = ent_car->next;

        } else {

            (ent_car->back)->next = ent_car->next;
        }

        if (adm_entity_system.ent_car.live_list_tail == ent_car) {

            adm_entity_system.ent_car.live_list_tail = ent_car->back;

        } else {

            (ent_car->next)->back = ent_car->back;
        }

        ent_car->deleted = TRUE;

        if (adm_entity_system.ent_car.dead_list_head == NULL) {

            ent_car->back = NULL;

            adm_entity_system.ent_car.dead_list_head = ent_car;

        } else {

            ent_car->back = adm_entity_system.ent_car.dead_list_tail;

            (adm_entity_system.ent_car.dead_list_tail)->next = ent_car;
        }

        ent_car->next = NULL;

        adm_entity_system.ent_car.dead_list_tail = ent_car;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_car");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_car_services_car_service(
    adm_ent_car_typ * ent_source_car,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_services_car_service_typ * rel_car_services_car_service;

    adm_base_boolean_typ car_service_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_services_car_service");
    #endif

    adm_object_existent_car(
        ent_source_car,
        error_file,
        error_line,
        error_rank);

    car_service_not_found = TRUE;

    rel_car_services_car_service = ent_source_car->rel_services_car_service_head;

    while (
        car_service_not_found &&
        rel_car_services_car_service != NULL) {

        if (rel_car_services_car_service->ent_car_service == ent_target_car_service) {

            car_service_not_found = FALSE;
        }

        rel_car_services_car_service = rel_car_services_car_service->next;
    }

    if (car_service_not_found) {

        rel_car_services_car_service = (adm_rel_car_services_car_service_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_services_car_service_typ));

        rel_car_services_car_service->ent_car_service = ent_target_car_service;

        if (ent_source_car->rel_services_car_service_head == NULL) {

            rel_car_services_car_service->back = NULL;

            ent_source_car->rel_services_car_service_head = rel_car_services_car_service;

        } else {

            rel_car_services_car_service->back = ent_source_car->rel_services_car_service_tail;

            (ent_source_car->rel_services_car_service_tail)->next = rel_car_services_car_service;
        }

        rel_car_services_car_service->next = NULL;

        ent_source_car->rel_services_car_service_tail = rel_car_services_car_service;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_source_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_services_car_service");
    #endif
}

void adm_link_relation_car_currently_at_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor;

    adm_base_boolean_typ floor_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_currently_at_floor");
    #endif

    adm_object_existent_car(
        ent_source_car,
        error_file,
        error_line,
        error_rank);

    floor_not_found = TRUE;

    rel_car_currently_at_floor = ent_source_car->rel_currently_at_floor_head;

    while (
        floor_not_found &&
        rel_car_currently_at_floor != NULL) {

        if (rel_car_currently_at_floor->ent_floor == ent_target_floor) {

            floor_not_found = FALSE;
        }

        rel_car_currently_at_floor = rel_car_currently_at_floor->next;
    }

    if (floor_not_found) {

        rel_car_currently_at_floor = (adm_rel_car_currently_at_floor_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_currently_at_floor_typ));

        rel_car_currently_at_floor->ent_floor = ent_target_floor;

        if (ent_source_car->rel_currently_at_floor_head == NULL) {

            rel_car_currently_at_floor->back = NULL;

            ent_source_car->rel_currently_at_floor_head = rel_car_currently_at_floor;

        } else {

            rel_car_currently_at_floor->back = ent_source_car->rel_currently_at_floor_tail;

            (ent_source_car->rel_currently_at_floor_tail)->next = rel_car_currently_at_floor;
        }

        rel_car_currently_at_floor->next = NULL;

        ent_source_car->rel_currently_at_floor_tail = rel_car_currently_at_floor;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_source_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_currently_at_floor");
    #endif
}

void adm_link_relation_car_accessed_through_door(
    adm_ent_car_typ * ent_source_car,
    adm_ent_door_typ * ent_target_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_accessed_through_door_typ * rel_car_accessed_through_door;

    adm_base_boolean_typ door_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_accessed_through_door");
    #endif

    adm_object_existent_car(
        ent_source_car,
        error_file,
        error_line,
        error_rank);

    door_not_found = TRUE;

    rel_car_accessed_through_door = ent_source_car->rel_accessed_through_door_head;

    while (
        door_not_found &&
        rel_car_accessed_through_door != NULL) {

        if (rel_car_accessed_through_door->ent_door == ent_target_door) {

            door_not_found = FALSE;
        }

        rel_car_accessed_through_door = rel_car_accessed_through_door->next;
    }

    if (door_not_found) {

        rel_car_accessed_through_door = (adm_rel_car_accessed_through_door_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_accessed_through_door_typ));

        rel_car_accessed_through_door->ent_door = ent_target_door;

        if (ent_source_car->rel_accessed_through_door_head == NULL) {

            rel_car_accessed_through_door->back = NULL;

            ent_source_car->rel_accessed_through_door_head = rel_car_accessed_through_door;

        } else {

            rel_car_accessed_through_door->back = ent_source_car->rel_accessed_through_door_tail;

            (ent_source_car->rel_accessed_through_door_tail)->next = rel_car_accessed_through_door;
        }

        rel_car_accessed_through_door->next = NULL;

        ent_source_car->rel_accessed_through_door_tail = rel_car_accessed_through_door;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_source_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_accessed_through_door");
    #endif
}

void adm_link_relation_car_scheduled_to_move_up_to_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor;

    adm_base_boolean_typ floor_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_scheduled_to_move_up_to_floor");
    #endif

    adm_object_existent_car(
        ent_source_car,
        error_file,
        error_line,
        error_rank);

    floor_not_found = TRUE;

    rel_car_scheduled_to_move_up_to_floor = ent_source_car->rel_scheduled_to_move_up_to_floor_head;

    while (
        floor_not_found &&
        rel_car_scheduled_to_move_up_to_floor != NULL) {

        if (rel_car_scheduled_to_move_up_to_floor->ent_floor == ent_target_floor) {

            floor_not_found = FALSE;
        }

        rel_car_scheduled_to_move_up_to_floor = rel_car_scheduled_to_move_up_to_floor->next;
    }

    if (floor_not_found) {

        rel_car_scheduled_to_move_up_to_floor = (adm_rel_car_scheduled_to_move_up_to_floor_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_scheduled_to_move_up_to_floor_typ));

        rel_car_scheduled_to_move_up_to_floor->ent_floor = ent_target_floor;

        if (ent_source_car->rel_scheduled_to_move_up_to_floor_head == NULL) {

            rel_car_scheduled_to_move_up_to_floor->back = NULL;

            ent_source_car->rel_scheduled_to_move_up_to_floor_head = rel_car_scheduled_to_move_up_to_floor;

        } else {

            rel_car_scheduled_to_move_up_to_floor->back = ent_source_car->rel_scheduled_to_move_up_to_floor_tail;

            (ent_source_car->rel_scheduled_to_move_up_to_floor_tail)->next = rel_car_scheduled_to_move_up_to_floor;
        }

        rel_car_scheduled_to_move_up_to_floor->next = NULL;

        ent_source_car->rel_scheduled_to_move_up_to_floor_tail = rel_car_scheduled_to_move_up_to_floor;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_source_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_scheduled_to_move_up_to_floor");
    #endif
}

void adm_link_relation_car_scheduled_to_move_down_to_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor;

    adm_base_boolean_typ floor_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_scheduled_to_move_down_to_floor");
    #endif

    adm_object_existent_car(
        ent_source_car,
        error_file,
        error_line,
        error_rank);

    floor_not_found = TRUE;

    rel_car_scheduled_to_move_down_to_floor = ent_source_car->rel_scheduled_to_move_down_to_floor_head;

    while (
        floor_not_found &&
        rel_car_scheduled_to_move_down_to_floor != NULL) {

        if (rel_car_scheduled_to_move_down_to_floor->ent_floor == ent_target_floor) {

            floor_not_found = FALSE;
        }

        rel_car_scheduled_to_move_down_to_floor = rel_car_scheduled_to_move_down_to_floor->next;
    }

    if (floor_not_found) {

        rel_car_scheduled_to_move_down_to_floor = (adm_rel_car_scheduled_to_move_down_to_floor_typ*)
            adm_allocate_memory(sizeof(adm_rel_car_scheduled_to_move_down_to_floor_typ));

        rel_car_scheduled_to_move_down_to_floor->ent_floor = ent_target_floor;

        if (ent_source_car->rel_scheduled_to_move_down_to_floor_head == NULL) {

            rel_car_scheduled_to_move_down_to_floor->back = NULL;

            ent_source_car->rel_scheduled_to_move_down_to_floor_head = rel_car_scheduled_to_move_down_to_floor;

        } else {

            rel_car_scheduled_to_move_down_to_floor->back = ent_source_car->rel_scheduled_to_move_down_to_floor_tail;

            (ent_source_car->rel_scheduled_to_move_down_to_floor_tail)->next = rel_car_scheduled_to_move_down_to_floor;
        }

        rel_car_scheduled_to_move_down_to_floor->next = NULL;

        ent_source_car->rel_scheduled_to_move_down_to_floor_tail = rel_car_scheduled_to_move_down_to_floor;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_source_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_car_scheduled_to_move_down_to_floor");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_car_services_car_service(
    adm_ent_car_typ * ent_car,
    adm_rel_car_services_car_service_typ * rel_car_services_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_services_car_service");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_services_car_service->next !=
        (adm_base_integer_typ)rel_car_services_car_service->ent_car_service) {

        if (ent_car->rel_services_car_service_head != NULL) {

            if (ent_car->rel_services_car_service_head == rel_car_services_car_service) {

                ent_car->rel_services_car_service_head = rel_car_services_car_service->next;

            } else {

                (rel_car_services_car_service->back)->next = rel_car_services_car_service->next;
            }

            if (ent_car->rel_services_car_service_tail == rel_car_services_car_service) {

                ent_car->rel_services_car_service_tail = rel_car_services_car_service->back;

            } else {

                (rel_car_services_car_service->next)->back = rel_car_services_car_service->back;
            }

            adm_deallocate_memory(rel_car_services_car_service);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Services",
                "Car_Service");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            "Services",
            "Car_Service");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_services_car_service");
    #endif
}

void adm_kill_relation_car_currently_at_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_currently_at_floor");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_currently_at_floor->next !=
        (adm_base_integer_typ)rel_car_currently_at_floor->ent_floor) {

        if (ent_car->rel_currently_at_floor_head != NULL) {

            if (ent_car->rel_currently_at_floor_head == rel_car_currently_at_floor) {

                ent_car->rel_currently_at_floor_head = rel_car_currently_at_floor->next;

            } else {

                (rel_car_currently_at_floor->back)->next = rel_car_currently_at_floor->next;
            }

            if (ent_car->rel_currently_at_floor_tail == rel_car_currently_at_floor) {

                ent_car->rel_currently_at_floor_tail = rel_car_currently_at_floor->back;

            } else {

                (rel_car_currently_at_floor->next)->back = rel_car_currently_at_floor->back;
            }

            adm_deallocate_memory(rel_car_currently_at_floor);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Currently_at",
                "Floor");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            "Currently_at",
            "Floor");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_currently_at_floor");
    #endif
}

void adm_kill_relation_car_accessed_through_door(
    adm_ent_car_typ * ent_car,
    adm_rel_car_accessed_through_door_typ * rel_car_accessed_through_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_accessed_through_door");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_accessed_through_door->next !=
        (adm_base_integer_typ)rel_car_accessed_through_door->ent_door) {

        if (ent_car->rel_accessed_through_door_head != NULL) {

            if (ent_car->rel_accessed_through_door_head == rel_car_accessed_through_door) {

                ent_car->rel_accessed_through_door_head = rel_car_accessed_through_door->next;

            } else {

                (rel_car_accessed_through_door->back)->next = rel_car_accessed_through_door->next;
            }

            if (ent_car->rel_accessed_through_door_tail == rel_car_accessed_through_door) {

                ent_car->rel_accessed_through_door_tail = rel_car_accessed_through_door->back;

            } else {

                (rel_car_accessed_through_door->next)->back = rel_car_accessed_through_door->back;
            }

            adm_deallocate_memory(rel_car_accessed_through_door);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Accessed_through",
                "Door");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            "Accessed_through",
            "Door");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_accessed_through_door");
    #endif
}

void adm_kill_relation_car_scheduled_to_move_up_to_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_scheduled_to_move_up_to_floor");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_scheduled_to_move_up_to_floor->next !=
        (adm_base_integer_typ)rel_car_scheduled_to_move_up_to_floor->ent_floor) {

        if (ent_car->rel_scheduled_to_move_up_to_floor_head != NULL) {

            if (ent_car->rel_scheduled_to_move_up_to_floor_head == rel_car_scheduled_to_move_up_to_floor) {

                ent_car->rel_scheduled_to_move_up_to_floor_head = rel_car_scheduled_to_move_up_to_floor->next;

            } else {

                (rel_car_scheduled_to_move_up_to_floor->back)->next = rel_car_scheduled_to_move_up_to_floor->next;
            }

            if (ent_car->rel_scheduled_to_move_up_to_floor_tail == rel_car_scheduled_to_move_up_to_floor) {

                ent_car->rel_scheduled_to_move_up_to_floor_tail = rel_car_scheduled_to_move_up_to_floor->back;

            } else {

                (rel_car_scheduled_to_move_up_to_floor->next)->back = rel_car_scheduled_to_move_up_to_floor->back;
            }

            adm_deallocate_memory(rel_car_scheduled_to_move_up_to_floor);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Scheduled_to_move_up_to",
                "Floor");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            "Scheduled_to_move_up_to",
            "Floor");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_scheduled_to_move_up_to_floor");
    #endif
}

void adm_kill_relation_car_scheduled_to_move_down_to_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_scheduled_to_move_down_to_floor");
    #endif

    adm_object_existent_car(
        ent_car,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_car_scheduled_to_move_down_to_floor->next !=
        (adm_base_integer_typ)rel_car_scheduled_to_move_down_to_floor->ent_floor) {

        if (ent_car->rel_scheduled_to_move_down_to_floor_head != NULL) {

            if (ent_car->rel_scheduled_to_move_down_to_floor_head == rel_car_scheduled_to_move_down_to_floor) {

                ent_car->rel_scheduled_to_move_down_to_floor_head = rel_car_scheduled_to_move_down_to_floor->next;

            } else {

                (rel_car_scheduled_to_move_down_to_floor->back)->next = rel_car_scheduled_to_move_down_to_floor->next;
            }

            if (ent_car->rel_scheduled_to_move_down_to_floor_tail == rel_car_scheduled_to_move_down_to_floor) {

                ent_car->rel_scheduled_to_move_down_to_floor_tail = rel_car_scheduled_to_move_down_to_floor->back;

            } else {

                (rel_car_scheduled_to_move_down_to_floor->next)->back = rel_car_scheduled_to_move_down_to_floor->back;
            }

            adm_deallocate_memory(rel_car_scheduled_to_move_down_to_floor);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "Scheduled_to_move_down_to",
                "Floor");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            "Scheduled_to_move_down_to",
            "Floor");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_car_scheduled_to_move_down_to_floor");
    #endif
}


/* Object Existent */

void adm_object_existent_car(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car");
    #endif

    if (ent_car->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Car",
            ent_car->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_car");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */