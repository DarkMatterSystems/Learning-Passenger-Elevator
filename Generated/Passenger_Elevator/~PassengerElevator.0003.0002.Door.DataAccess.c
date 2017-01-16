
#include "~PassengerElevator.0000.0000.Header.h"


/* Door Data Access */

/* Make Entity Object */

adm_ent_door_typ * adm_make_object_door(
    adm_sta_door_typ status)
{
    adm_ent_door_typ * ent_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_door");
    #endif

    if (adm_entity_system.ent_door.dead_list_head != NULL) {

        ent_door = adm_entity_system.ent_door.dead_list_head;

        if (adm_entity_system.ent_door.dead_list_head == ent_door) {

            adm_entity_system.ent_door.dead_list_head = ent_door->next;

        } else {

            (ent_door->back)->next = ent_door->next;
        }

        if (adm_entity_system.ent_door.dead_list_tail == ent_door) {

            adm_entity_system.ent_door.dead_list_tail = ent_door->back;

        } else {

            (ent_door->next)->back = ent_door->back;
        }

    } else {

        ent_door = (adm_ent_door_typ*)adm_allocate_memory(sizeof(adm_ent_door_typ));
    }

    ent_door->identity = ++adm_entity_system.ent_door.tote;

    ent_door->unique  = FALSE;
    ent_door->deleted = FALSE;
    ent_door->marked  = FALSE;
    ent_door->status  = status;

    ent_door->rel_provides_passenger_access_to_car_head = NULL;
    ent_door->rel_provides_passenger_access_to_car_tail = NULL;

    ent_door->back = NULL;
    ent_door->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_door");
    #endif

    return (ent_door);
}


/* Bind Entity Object */

void adm_bind_object_door(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_door");
    #endif

    adm_object_existent_door(
        ent_door,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_door.live_list_head == NULL) {

        ent_door->back = NULL;

        adm_entity_system.ent_door.live_list_head = ent_door;

    } else {

        ent_door->back = adm_entity_system.ent_door.live_list_tail;

        (adm_entity_system.ent_door.live_list_tail)->next = ent_door;
    }

    ent_door->next = NULL;

    adm_entity_system.ent_door.live_list_tail = ent_door;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_door");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_door(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_door");
    #endif

    adm_object_existent_door(
        ent_door,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_door) {

        if (ent_door->rel_provides_passenger_access_to_car_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Door",
                ent_door->identity,
                "Provides_passenger_access_to",
                "Car");
        }

        if (adm_entity_system.ent_door.live_list_head == ent_door) {

            adm_entity_system.ent_door.live_list_head = ent_door->next;

        } else {

            (ent_door->back)->next = ent_door->next;
        }

        if (adm_entity_system.ent_door.live_list_tail == ent_door) {

            adm_entity_system.ent_door.live_list_tail = ent_door->back;

        } else {

            (ent_door->next)->back = ent_door->back;
        }

        ent_door->deleted = TRUE;

        if (adm_entity_system.ent_door.dead_list_head == NULL) {

            ent_door->back = NULL;

            adm_entity_system.ent_door.dead_list_head = ent_door;

        } else {

            ent_door->back = adm_entity_system.ent_door.dead_list_tail;

            (adm_entity_system.ent_door.dead_list_tail)->next = ent_door;
        }

        ent_door->next = NULL;

        adm_entity_system.ent_door.dead_list_tail = ent_door;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Door",
            ent_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_door");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_door_provides_passenger_access_to_car(
    adm_ent_door_typ * ent_source_door,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_door_provides_passenger_access_to_car_typ * rel_door_provides_passenger_access_to_car;

    adm_base_boolean_typ car_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_door_provides_passenger_access_to_car");
    #endif

    adm_object_existent_door(
        ent_source_door,
        error_file,
        error_line,
        error_rank);

    car_not_found = TRUE;

    rel_door_provides_passenger_access_to_car = ent_source_door->rel_provides_passenger_access_to_car_head;

    while (
        car_not_found &&
        rel_door_provides_passenger_access_to_car != NULL) {

        if (rel_door_provides_passenger_access_to_car->ent_car == ent_target_car) {

            car_not_found = FALSE;
        }

        rel_door_provides_passenger_access_to_car = rel_door_provides_passenger_access_to_car->next;
    }

    if (car_not_found) {

        rel_door_provides_passenger_access_to_car = (adm_rel_door_provides_passenger_access_to_car_typ*)
            adm_allocate_memory(sizeof(adm_rel_door_provides_passenger_access_to_car_typ));

        rel_door_provides_passenger_access_to_car->ent_car = ent_target_car;

        if (ent_source_door->rel_provides_passenger_access_to_car_head == NULL) {

            rel_door_provides_passenger_access_to_car->back = NULL;

            ent_source_door->rel_provides_passenger_access_to_car_head = rel_door_provides_passenger_access_to_car;

        } else {

            rel_door_provides_passenger_access_to_car->back = ent_source_door->rel_provides_passenger_access_to_car_tail;

            (ent_source_door->rel_provides_passenger_access_to_car_tail)->next = rel_door_provides_passenger_access_to_car;
        }

        rel_door_provides_passenger_access_to_car->next = NULL;

        ent_source_door->rel_provides_passenger_access_to_car_tail = rel_door_provides_passenger_access_to_car;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Door",
            ent_source_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_door_provides_passenger_access_to_car");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_door_provides_passenger_access_to_car(
    adm_ent_door_typ * ent_door,
    adm_rel_door_provides_passenger_access_to_car_typ * rel_door_provides_passenger_access_to_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_door_provides_passenger_access_to_car");
    #endif

    adm_object_existent_door(
        ent_door,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_door_provides_passenger_access_to_car->next !=
        (adm_base_integer_typ)rel_door_provides_passenger_access_to_car->ent_car) {

        if (ent_door->rel_provides_passenger_access_to_car_head != NULL) {

            if (ent_door->rel_provides_passenger_access_to_car_head == rel_door_provides_passenger_access_to_car) {

                ent_door->rel_provides_passenger_access_to_car_head = rel_door_provides_passenger_access_to_car->next;

            } else {

                (rel_door_provides_passenger_access_to_car->back)->next = rel_door_provides_passenger_access_to_car->next;
            }

            if (ent_door->rel_provides_passenger_access_to_car_tail == rel_door_provides_passenger_access_to_car) {

                ent_door->rel_provides_passenger_access_to_car_tail = rel_door_provides_passenger_access_to_car->back;

            } else {

                (rel_door_provides_passenger_access_to_car->next)->back = rel_door_provides_passenger_access_to_car->back;
            }

            adm_deallocate_memory(rel_door_provides_passenger_access_to_car);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Door",
                ent_door->identity,
                "Provides_passenger_access_to",
                "Car");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Door",
            ent_door->identity,
            "Provides_passenger_access_to",
            "Car");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_door_provides_passenger_access_to_car");
    #endif
}


/* Object Existent */

void adm_object_existent_door(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_door");
    #endif

    if (ent_door->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Door",
            ent_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */