
#include "~PassengerElevator.0000.0000.Header.h"


/* Door Event Senders */

void adm_send_event_door_open(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_open");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_open(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_OPEN;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_open");
    #endif
}

void adm_send_event_door_close(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_close");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_close(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_CLOSE;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_close");
    #endif
}

void adm_send_event_door_obstruction(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_obstruction");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_obstruction(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_OBSTRUCTION;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_obstruction");
    #endif
}

void adm_send_event_door_open_completed(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_open_completed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_open_completed(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_OPEN_COMPLETED;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_open_completed");
    #endif
}

void adm_send_event_door_close_completed(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_close_completed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_close_completed(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_CLOSE_COMPLETED;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_close_completed");
    #endif
}

void adm_send_event_door_clear(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_door_typ * pool_target;
    adm_pool_target_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_clear");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_door_clear(
            ent_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_door(
            ent_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_door_typ));

        pool_target->evente = ADM_EVENT_DOOR_CLEAR;
        pool_target->ent_door = ent_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_door) {

            if (adm_entity_system.ent_door.home_pool_head == NULL) {

                adm_entity_system.ent_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_door == ent_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Door",
                            ent_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_door.away_pool_head == NULL) {

                adm_entity_system.ent_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_door_clear");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */