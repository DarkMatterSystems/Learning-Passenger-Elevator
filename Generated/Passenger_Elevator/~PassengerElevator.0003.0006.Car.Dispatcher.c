
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Dispatcher */

/* Dispatcher */

void adm_dispatcher_car(
    void)
{
    adm_pool_target_car_typ * pool_target_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_car");
    #endif

    pool_target_car = adm_find_away_target_event_car();

    adm_dispatch_state_action_car(pool_target_car);

    adm_dispatch_home_pool_car();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_car");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_car(
    void)
{
    adm_pool_target_car_typ * pool_target_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_car");
    #endif

    while (adm_entity_system.ent_car.home_pool_head != NULL) {

        pool_target_car = adm_find_home_target_event_car();

        adm_dispatch_state_action_car(pool_target_car);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_car");
    #endif
}


/* Find Home Target Event */

adm_pool_target_car_typ * adm_find_home_target_event_car(
    void)
{
    adm_pool_target_car_typ * pool_target_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_car");
    #endif

    pool_target_car = adm_entity_system.ent_car.home_pool_head;

    adm_entity_system.ent_car.home_pool_head = pool_target_car->next;

    if (adm_entity_system.ent_car.home_pool_head == NULL) {

        adm_entity_system.ent_car.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_car");
    #endif

    return (pool_target_car);
}


/* Find Away Target Event */

adm_pool_target_car_typ * adm_find_away_target_event_car(
    void)
{
    adm_pool_target_car_typ * pool_target_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_car");
    #endif

    pool_target_car = adm_entity_system.ent_car.away_pool_head;

    adm_entity_system.ent_car.away_pool_head = pool_target_car->next;

    if (adm_entity_system.ent_car.away_pool_head == NULL) {

        adm_entity_system.ent_car.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_car");
    #endif

    return (pool_target_car);
}


/* Dispatch State Action */

void adm_dispatch_state_action_car(
    adm_pool_target_car_typ * pool_target)
{
    adm_dst_car_travel_typ * dst_travel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_car");
    #endif

    if (pool_target->ent_car != NULL) {

        adm_object_existent_car(
            pool_target->ent_car,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_CAR_SERVICE_REQUESTED :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_sim_display_state_car_selecting_schedule(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_SELECTING_SCHEDULE;

                    adm_state_action_car_selecting_schedule(
                        pool_target->ent_car);

                break;
            }

        break;

        case ADM_EVENT_CAR_OPEN_DOOR :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_sim_display_state_car_opening(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_OPENING;

                    adm_state_action_car_opening(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_sim_display_state_car_opening(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_OPENING;

                    adm_state_action_car_opening(
                        pool_target->ent_car);

                break;
            }

        break;

        case ADM_EVENT_CAR_CLOSE_DOOR :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_sim_display_state_car_closing(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_CLOSING;

                    adm_state_action_car_closing(
                        pool_target->ent_car);

                break;
            }

        break;

        case ADM_EVENT_CAR_SERVICE_SCHEDULE :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_sim_display_state_car_servicing_schedule(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_SERVICING_SCHEDULE;

                    adm_state_action_car_servicing_schedule(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_schedule",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_SERVICE_CURRENT_FLOOR :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_sim_display_state_car_opening(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_OPENING;

                    adm_state_action_car_opening(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Service_current_floor",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_MOVING :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_sim_display_state_car_moving(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_MOVING;

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Moving",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_FLOOR_APPROACHING :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    dst_travel = (adm_dst_car_travel_typ*)pool_target->dataset.travel;

                    adm_sim_display_state_car_checking_schedule(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_CHECKING_SCHEDULE;

                    adm_state_action_car_checking_schedule(
                        pool_target->ent_car,
                        dst_travel);

                    adm_deallocate_memory(pool_target->dataset.travel);

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Floor_approaching",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_CONTINUE :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_sim_display_state_car_moving(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_MOVING;

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Continue",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_STOP_AT_NEXT_FLOOR :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_sim_display_state_car_slowing(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_SLOWING;

                    adm_state_action_car_slowing(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Stop_at_next_floor",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_CAR_STOPPED :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_sim_display_state_car_opening(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_OPENING;

                    adm_state_action_car_opening(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Car_stopped",
                        "State:Closing");

                break;
            }

        break;

        case ADM_EVENT_CAR_DOOR_OPEN :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_sim_display_state_car_accessible(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_ACCESSIBLE;

                    adm_state_action_car_accessible(
                        pool_target->ent_car);

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_open",
                        "State:Accessible");

                break;
            }

        break;

        case ADM_EVENT_CAR_DOOR_CLOSED :

            switch ((pool_target->ent_car)->status) {

                case ADM_STATUS_CAR_STATIONARY :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Stationary");

                break;

                case ADM_STATUS_CAR_SELECTING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Selecting_Schedule");

                break;

                case ADM_STATUS_CAR_SERVICING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Servicing_Schedule");

                break;

                case ADM_STATUS_CAR_MOVING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Moving");

                break;

                case ADM_STATUS_CAR_CHECKING_SCHEDULE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Checking_Schedule");

                break;

                case ADM_STATUS_CAR_SLOWING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Slowing");

                break;

                case ADM_STATUS_CAR_OPENING :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Opening");

                break;

                case ADM_STATUS_CAR_ACCESSIBLE :

                    adm_error_report(
                        ADM_ERROR_TRANSITION_CANNOT_HAPPEN,
                        pool_target->error_location.file,
                        pool_target->error_location.line,
                        pool_target->error_location.rank,
                        "Entity:Car",
                        (pool_target->ent_car)->identity,
                        "Event:Door_closed",
                        "State:Accessible");

                break;

                case ADM_STATUS_CAR_CLOSING :

                    adm_sim_display_state_car_stationary(pool_target);

                    (pool_target->ent_car)->status = ADM_STATUS_CAR_STATIONARY;

                    adm_state_action_car_stationary(
                        pool_target->ent_car);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_car");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */