
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Event Senders */

void adm_send_event_car_service_requested(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_requested");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_service_requested(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_SERVICE_REQUESTED;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_requested");
    #endif
}

void adm_send_event_car_open_door(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_open_door");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_open_door(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_OPEN_DOOR;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_open_door");
    #endif
}

void adm_send_event_car_close_door(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_close_door");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_close_door(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_CLOSE_DOOR;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_close_door");
    #endif
}

void adm_send_event_car_service_schedule(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_schedule");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_service_schedule(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_SERVICE_SCHEDULE;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_schedule");
    #endif
}

void adm_send_event_car_service_current_floor(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_current_floor");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_service_current_floor(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_SERVICE_CURRENT_FLOOR;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_service_current_floor");
    #endif
}

void adm_send_event_car_moving(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_moving");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_moving(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_MOVING;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_moving");
    #endif
}

void adm_send_event_car_floor_approaching(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_int_floor_typ evd_next_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    adm_dst_car_travel_typ * dst_travel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_floor_approaching");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_floor_approaching(
            ent_car,
            evd_next_floor_number,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        if (
            evd_next_floor_number < ADM_TYPE_MINIMUM_FLOOR ||
            evd_next_floor_number > ADM_TYPE_MAXIMUM_FLOOR) {

            adm_error_report(
                ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                error_file, error_line, error_rank,
                "Car",
                ent_car->identity,
                "next_floor_number",
                adm_sim_lib_itoa(evd_next_floor_number));
        }

        dst_travel = (adm_dst_car_travel_typ*)
            adm_allocate_memory(sizeof(adm_dst_car_travel_typ));

        dst_travel->next_floor_number = evd_next_floor_number;

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_FLOOR_APPROACHING;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;
        pool_target->dataset.travel = dst_travel;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_floor_approaching");
    #endif
}

void adm_send_event_car_continue(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_continue");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_continue(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_CONTINUE;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_continue");
    #endif
}

void adm_send_event_car_stop_at_next_floor(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_stop_at_next_floor");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_stop_at_next_floor(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_STOP_AT_NEXT_FLOOR;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_stop_at_next_floor");
    #endif
}

void adm_send_event_car_car_stopped(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_car_stopped");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_car_stopped(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_CAR_STOPPED;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_car_stopped");
    #endif
}

void adm_send_event_car_door_open(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_door_open");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_door_open(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_DOOR_OPEN;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_door_open");
    #endif
}

void adm_send_event_car_door_closed(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_pool_target_car_typ * pool_target;
    adm_pool_target_car_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_door_closed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_car_door_closed(
            ent_car,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_car(
            ent_car,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_car_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_car_typ));

        pool_target->evente = ADM_EVENT_CAR_DOOR_CLOSED;
        pool_target->ent_car = ent_car;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_car) {

            if (adm_entity_system.ent_car.home_pool_head == NULL) {

                adm_entity_system.ent_car.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_car.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_car == ent_car) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Car",
                            ent_car->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_car.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_car.away_pool_head == NULL) {

                adm_entity_system.ent_car.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_car.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_car.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_car_door_closed");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */