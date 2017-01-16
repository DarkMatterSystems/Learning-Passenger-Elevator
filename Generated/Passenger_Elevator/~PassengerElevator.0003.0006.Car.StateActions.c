
#include "~PassengerElevator.0000.0000.Header.h"


/* Car State Actions */

void adm_state_action_car_stationary(
    adm_ent_car_typ * ent_car)
{
    /* Entity Objects */
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_floor_typ * ent_floor_0000000003;

    /* Relationship Relations */
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000001;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000003;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_stationary");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 479, 45);

    traverse_not_found_0000000002 = TRUE;

    rel_car_scheduled_to_move_up_to_floor_0000000001 = ent_car->rel_scheduled_to_move_up_to_floor_head;

    while (rel_car_scheduled_to_move_up_to_floor_0000000001 != NULL) {

        ent_floor_0000000001 = rel_car_scheduled_to_move_up_to_floor_0000000001->ent_floor;

        traverse_not_found_0000000002 = FALSE;

        /* SelectionHead */

        adm_object_existent_car(
            ent_car,
            1, 479, 45);

        if (rel_car_scheduled_to_move_up_to_floor_0000000001 == ent_car->rel_scheduled_to_move_up_to_floor_head) {

            /* GenerateEvent */

            adm_send_event_car_service_requested(
                ent_car,
                ent_car,
                1, 483, 53);
        }

        rel_car_scheduled_to_move_up_to_floor_0000000001 = rel_car_scheduled_to_move_up_to_floor_0000000001->next;
    }

    /* Traverse - Null Traverse Selection */

    if (traverse_not_found_0000000002) {

        /* Traverse - TraverseSelection */

        adm_object_existent_car(
            ent_car,
            1, 487, 53);

        rel_car_scheduled_to_move_down_to_floor_0000000003 = ent_car->rel_scheduled_to_move_down_to_floor_head;

        while (rel_car_scheduled_to_move_down_to_floor_0000000003 != NULL) {

            ent_floor_0000000003 = rel_car_scheduled_to_move_down_to_floor_0000000003->ent_floor;

            /* SelectionHead */

            adm_object_existent_car(
                ent_car,
                1, 487, 53);

            if (rel_car_scheduled_to_move_down_to_floor_0000000003 == ent_car->rel_scheduled_to_move_down_to_floor_head) {

                /* GenerateEvent */

                adm_send_event_car_service_requested(
                    ent_car,
                    ent_car,
                    1, 491, 61);
            }

            rel_car_scheduled_to_move_down_to_floor_0000000003 = rel_car_scheduled_to_move_down_to_floor_0000000003->next;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_stationary");
    #endif
}

void adm_state_action_car_selecting_schedule(
    adm_ent_car_typ * ent_car)
{
    /* Process Data */
    adm_bln_flag_typ pdt_stop_not_found;

    /* Entity Objects */
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_floor_typ * ent_floor_0000000002;
    adm_ent_floor_typ * ent_floor_0000000004;
    adm_ent_floor_typ * ent_floor_0000000005;
    adm_ent_floor_typ * ent_floor_0000000007;

    /* Relationship Relations */
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000001;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000002;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000004;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000005;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000007;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000003;
    adm_base_boolean_typ traverse_not_found_0000000006;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_selecting_schedule");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 523, 45);

    rel_car_currently_at_floor_0000000001 = ent_car->rel_currently_at_floor_head;

    ent_floor_0000000001 = rel_car_currently_at_floor_0000000001->ent_floor;

    /* Assignment - Set */

    pdt_stop_not_found = TRUE;

    /* CaseSelection */

    if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_UP
            )
        )) {

        /* Traverse - TraverseSelection */

        adm_object_existent_car(
            ent_car,
            1, 543, 65);

        traverse_not_found_0000000003 = TRUE;

        rel_car_scheduled_to_move_up_to_floor_0000000002 = ent_car->rel_scheduled_to_move_up_to_floor_head;

        while (rel_car_scheduled_to_move_up_to_floor_0000000002 != NULL) {

            ent_floor_0000000002 = rel_car_scheduled_to_move_up_to_floor_0000000002->ent_floor;

            traverse_not_found_0000000003 = FALSE;

            /* CaseSelection */

            if (
                (
                    (
                        pdt_stop_not_found
                    )
                    &&
                    (
                        ent_floor_0000000002 == ent_floor_0000000001
                    )
                )) {

                /* GenerateEvent */

                adm_send_event_car_service_current_floor(
                    ent_car,
                    ent_car,
                    1, 555, 81);

                /* Assignment - Set */

                pdt_stop_not_found = FALSE;
            }

            /* SelectionLast */

            adm_object_existent_car(
                ent_car,
                1, 543, 65);

            if (rel_car_scheduled_to_move_up_to_floor_0000000002 == ent_car->rel_scheduled_to_move_up_to_floor_tail) {

                /* CaseSelection */

                if (
                    (
                        (
                            pdt_stop_not_found
                        )
                    )) {

                    /* GenerateEvent */

                    adm_send_event_car_service_schedule(
                        ent_car,
                        ent_car,
                        1, 568, 85);
                }
            }

            rel_car_scheduled_to_move_up_to_floor_0000000002 = rel_car_scheduled_to_move_up_to_floor_0000000002->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000003) {

            /* Traverse - TraverseSelection */

            adm_object_existent_car(
                ent_car,
                1, 573, 73);

            rel_car_scheduled_to_move_down_to_floor_0000000004 = ent_car->rel_scheduled_to_move_down_to_floor_head;

            while (rel_car_scheduled_to_move_down_to_floor_0000000004 != NULL) {

                ent_floor_0000000004 = rel_car_scheduled_to_move_down_to_floor_0000000004->ent_floor;

                /* Assignment - Set */

                if (
                    ADM_LITERAL_DIRECTION_DOWN < ADM_TYPE_MINIMUM_DIRECTION ||
                    ADM_LITERAL_DIRECTION_DOWN > ADM_TYPE_MAXIMUM_DIRECTION) {

                    adm_error_report(
                        ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                        1, 578, 81,
                        "Car",
                        ent_car->identity,
                        "Direction",
                        adm_enumeration_direction[ADM_LITERAL_DIRECTION_DOWN]);
                }

                ent_car->atb_direction = ADM_LITERAL_DIRECTION_DOWN;

                /* CaseSelection */

                if (
                    (
                        (
                            pdt_stop_not_found
                        )
                        &&
                        (
                            ent_floor_0000000004 == ent_floor_0000000001
                        )
                    )) {

                    /* GenerateEvent */

                    adm_send_event_car_service_current_floor(
                        ent_car,
                        ent_car,
                        1, 589, 89);

                    /* Assignment - Set */

                    pdt_stop_not_found = FALSE;
                }

                /* SelectionLast */

                adm_object_existent_car(
                    ent_car,
                    1, 573, 73);

                if (rel_car_scheduled_to_move_down_to_floor_0000000004 == ent_car->rel_scheduled_to_move_down_to_floor_tail) {

                    /* CaseSelection */

                    if (
                        (
                            (
                                pdt_stop_not_found
                            )
                        )) {

                        /* GenerateEvent */

                        adm_send_event_car_service_schedule(
                            ent_car,
                            ent_car,
                            1, 602, 93);
                    }
                }

                rel_car_scheduled_to_move_down_to_floor_0000000004 = rel_car_scheduled_to_move_down_to_floor_0000000004->next;
            }
        }

    } else if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_DOWN
            )
        )) {

        /* Traverse - TraverseSelection */

        adm_object_existent_car(
            ent_car,
            1, 615, 65);

        traverse_not_found_0000000006 = TRUE;

        rel_car_scheduled_to_move_down_to_floor_0000000005 = ent_car->rel_scheduled_to_move_down_to_floor_head;

        while (rel_car_scheduled_to_move_down_to_floor_0000000005 != NULL) {

            ent_floor_0000000005 = rel_car_scheduled_to_move_down_to_floor_0000000005->ent_floor;

            traverse_not_found_0000000006 = FALSE;

            /* CaseSelection */

            if (
                (
                    (
                        pdt_stop_not_found
                    )
                    &&
                    (
                        ent_floor_0000000005 == ent_floor_0000000001
                    )
                )) {

                /* GenerateEvent */

                adm_send_event_car_service_current_floor(
                    ent_car,
                    ent_car,
                    1, 626, 81);

                /* Assignment - Set */

                pdt_stop_not_found = FALSE;
            }

            /* SelectionLast */

            adm_object_existent_car(
                ent_car,
                1, 615, 65);

            if (rel_car_scheduled_to_move_down_to_floor_0000000005 == ent_car->rel_scheduled_to_move_down_to_floor_tail) {

                /* CaseSelection */

                if (
                    (
                        (
                            pdt_stop_not_found
                        )
                    )) {

                    /* GenerateEvent */

                    adm_send_event_car_service_schedule(
                        ent_car,
                        ent_car,
                        1, 638, 85);
                }
            }

            rel_car_scheduled_to_move_down_to_floor_0000000005 = rel_car_scheduled_to_move_down_to_floor_0000000005->next;
        }

        /* Traverse - Null Traverse Selection */

        if (traverse_not_found_0000000006) {

            /* Traverse - TraverseSelection */

            adm_object_existent_car(
                ent_car,
                1, 644, 73);

            rel_car_scheduled_to_move_up_to_floor_0000000007 = ent_car->rel_scheduled_to_move_up_to_floor_head;

            while (rel_car_scheduled_to_move_up_to_floor_0000000007 != NULL) {

                ent_floor_0000000007 = rel_car_scheduled_to_move_up_to_floor_0000000007->ent_floor;

                /* Assignment - Set */

                if (
                    ADM_LITERAL_DIRECTION_UP < ADM_TYPE_MINIMUM_DIRECTION ||
                    ADM_LITERAL_DIRECTION_UP > ADM_TYPE_MAXIMUM_DIRECTION) {

                    adm_error_report(
                        ADM_ERROR_VALUE_OUTSIDE_RANGE_FOR_TYPE,
                        1, 649, 81,
                        "Car",
                        ent_car->identity,
                        "Direction",
                        adm_enumeration_direction[ADM_LITERAL_DIRECTION_UP]);
                }

                ent_car->atb_direction = ADM_LITERAL_DIRECTION_UP;

                /* CaseSelection */

                if (
                    (
                        (
                            pdt_stop_not_found
                        )
                        &&
                        (
                            ent_floor_0000000007 == ent_floor_0000000001
                        )
                    )) {

                    /* GenerateEvent */

                    adm_send_event_car_service_current_floor(
                        ent_car,
                        ent_car,
                        1, 660, 89);

                    /* Assignment - Set */

                    pdt_stop_not_found = FALSE;
                }

                /* SelectionLast */

                adm_object_existent_car(
                    ent_car,
                    1, 644, 73);

                if (rel_car_scheduled_to_move_up_to_floor_0000000007 == ent_car->rel_scheduled_to_move_up_to_floor_tail) {

                    /* CaseSelection */

                    if (
                        (
                            (
                                pdt_stop_not_found
                            )
                        )) {

                        /* GenerateEvent */

                        adm_send_event_car_service_schedule(
                            ent_car,
                            ent_car,
                            1, 673, 93);
                    }
                }

                rel_car_scheduled_to_move_up_to_floor_0000000007 = rel_car_scheduled_to_move_up_to_floor_0000000007->next;
            }
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_selecting_schedule");
    #endif
}

void adm_state_action_car_servicing_schedule(
    adm_ent_car_typ * ent_car)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_servicing_schedule");
    #endif

    /* CaseSelection */

    if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_UP
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("EVENT -> Machinery::Moving (Direction:UP)");
        adm_write_newline();

    } else if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_DOWN
            )
        )) {

        /* Template */

        adm_write_newline();
        adm_write_str("EVENT -> Machinery::Moving (Direction:DOWN)");
        adm_write_newline();
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_servicing_schedule");
    #endif
}

void adm_state_action_car_checking_schedule(
    adm_ent_car_typ * ent_car,
    adm_dst_car_travel_typ * dst_travel)
{
    /* Process Data */
    adm_bln_flag_typ pdt_stop_not_found;

    /* Entity Objects */
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_car_service_typ * ent_car_service_0000000002;
    adm_ent_floor_typ * ent_floor_0000000002;
    adm_ent_floor_typ * ent_floor_0000000003;
    adm_ent_floor_typ * ent_floor_0000000004;

    /* Relationship Relations */
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000001;
    adm_rel_car_services_car_service_typ * rel_car_services_car_service_0000000002;
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor_0000000002;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000003;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000004;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_checking_schedule");
    #endif

    /* Assignment - Set */

    pdt_stop_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 772, 45);

    rel_car_currently_at_floor_0000000001 = ent_car->rel_currently_at_floor_head;

    ent_floor_0000000001 = rel_car_currently_at_floor_0000000001->ent_floor;

    /* Unrelate */

    adm_kill_relation_car_currently_at_floor(
        ent_car,
        rel_car_currently_at_floor_0000000001,
        1, 775, 49);

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 780, 45);

    rel_car_services_car_service_0000000002 = ent_car->rel_services_car_service_head;

    while (rel_car_services_car_service_0000000002 != NULL) {

        ent_car_service_0000000002 = rel_car_services_car_service_0000000002->ent_car_service;

        rel_car_service_services_floor_0000000002 = ent_car_service_0000000002->rel_services_floor_head;

        ent_floor_0000000002 = rel_car_service_services_floor_0000000002->ent_floor;

        /* CaseSelection */

        if (
            (
                (
                    ent_floor_0000000002->atb_number == dst_travel->next_floor_number
                )
            )) {

            /* Relate */

            adm_link_relation_car_currently_at_floor(
                ent_car,
                ent_floor_0000000002,
                1, 792, 61);

            /* CaseSelection */

            if (
                (
                    (
                        ent_car->atb_direction == ADM_LITERAL_DIRECTION_UP
                    )
                )) {

                /* Traverse - TraverseSelection */

                adm_object_existent_car(
                    ent_car,
                    1, 806, 77);

                rel_car_scheduled_to_move_up_to_floor_0000000003 = ent_car->rel_scheduled_to_move_up_to_floor_head;

                while (rel_car_scheduled_to_move_up_to_floor_0000000003 != NULL) {

                    ent_floor_0000000003 = rel_car_scheduled_to_move_up_to_floor_0000000003->ent_floor;

                    /* CaseSelection */

                    if (
                        (
                            (
                                pdt_stop_not_found
                            )
                            &&
                            (
                                ent_floor_0000000003->atb_number == dst_travel->next_floor_number
                            )
                        )) {

                        /* GenerateEvent */

                        adm_send_event_car_stop_at_next_floor(
                            ent_car,
                            ent_car,
                            1, 819, 93);

                        /* Assignment - Set */

                        pdt_stop_not_found = FALSE;
                    }

                    /* SelectionLast */

                    adm_object_existent_car(
                        ent_car,
                        1, 806, 77);

                    if (rel_car_scheduled_to_move_up_to_floor_0000000003 == ent_car->rel_scheduled_to_move_up_to_floor_tail) {

                        /* CaseSelection */

                        if (
                            (
                                (
                                    pdt_stop_not_found
                                )
                            )) {

                            /* GenerateEvent */

                            adm_send_event_car_continue(
                                ent_car,
                                ent_car,
                                1, 833, 97);
                        }
                    }

                    rel_car_scheduled_to_move_up_to_floor_0000000003 = rel_car_scheduled_to_move_up_to_floor_0000000003->next;
                }

            } else if (
                (
                    (
                        ent_car->atb_direction == ADM_LITERAL_DIRECTION_DOWN
                    )
                )) {

                /* Traverse - TraverseSelection */

                adm_object_existent_car(
                    ent_car,
                    1, 844, 77);

                rel_car_scheduled_to_move_down_to_floor_0000000004 = ent_car->rel_scheduled_to_move_down_to_floor_head;

                while (rel_car_scheduled_to_move_down_to_floor_0000000004 != NULL) {

                    ent_floor_0000000004 = rel_car_scheduled_to_move_down_to_floor_0000000004->ent_floor;

                    /* CaseSelection */

                    if (
                        (
                            (
                                pdt_stop_not_found
                            )
                            &&
                            (
                                ent_floor_0000000004->atb_number == dst_travel->next_floor_number
                            )
                        )) {

                        /* GenerateEvent */

                        adm_send_event_car_stop_at_next_floor(
                            ent_car,
                            ent_car,
                            1, 857, 93);

                        /* Assignment - Set */

                        pdt_stop_not_found = FALSE;
                    }

                    /* SelectionLast */

                    adm_object_existent_car(
                        ent_car,
                        1, 844, 77);

                    if (rel_car_scheduled_to_move_down_to_floor_0000000004 == ent_car->rel_scheduled_to_move_down_to_floor_tail) {

                        /* CaseSelection */

                        if (
                            (
                                (
                                    pdt_stop_not_found
                                )
                            )) {

                            /* GenerateEvent */

                            adm_send_event_car_continue(
                                ent_car,
                                ent_car,
                                1, 871, 97);
                        }
                    }

                    rel_car_scheduled_to_move_down_to_floor_0000000004 = rel_car_scheduled_to_move_down_to_floor_0000000004->next;
                }
            }
        }

        rel_car_services_car_service_0000000002 = rel_car_services_car_service_0000000002->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_checking_schedule");
    #endif
}

void adm_state_action_car_slowing(
    adm_ent_car_typ * ent_car)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_slowing");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("EVENT -> Machinery::Car.Slowing ()");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_slowing");
    #endif
}

void adm_state_action_car_opening(
    adm_ent_car_typ * ent_car)
{
    /* Entity Objects */
    adm_ent_door_typ * ent_door_0000000001;

    /* Relationship Relations */
    adm_rel_car_accessed_through_door_typ * rel_car_accessed_through_door_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_opening");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 920, 45);

    rel_car_accessed_through_door_0000000001 = ent_car->rel_accessed_through_door_head;

    ent_door_0000000001 = rel_car_accessed_through_door_0000000001->ent_door;

    /* GenerateEvent */

    adm_send_event_door_open(
        ent_car,
        ent_door_0000000001,
        1, 923, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_opening");
    #endif
}

void adm_state_action_car_accessible(
    adm_ent_car_typ * ent_car)
{
    /* Entity Objects */
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_floor_typ * ent_floor_0000000002;
    adm_ent_floor_typ * ent_floor_0000000003;

    /* Relationship Relations */
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000001;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000002;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * nxt_car_scheduled_to_move_up_to_floor_0000000002;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000003;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * nxt_car_scheduled_to_move_down_to_floor_0000000003;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_accessible");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 952, 45);

    rel_car_currently_at_floor_0000000001 = ent_car->rel_currently_at_floor_head;

    ent_floor_0000000001 = rel_car_currently_at_floor_0000000001->ent_floor;

    /* CaseSelection */

    if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_UP
            )
        )) {

        /* Traverse - TraverseSelection */

        adm_object_existent_car(
            ent_car,
            1, 966, 65);

        rel_car_scheduled_to_move_up_to_floor_0000000002 = ent_car->rel_scheduled_to_move_up_to_floor_head;

        while (rel_car_scheduled_to_move_up_to_floor_0000000002 != NULL) {

            nxt_car_scheduled_to_move_up_to_floor_0000000002 = rel_car_scheduled_to_move_up_to_floor_0000000002->next;

            ent_floor_0000000002 = rel_car_scheduled_to_move_up_to_floor_0000000002->ent_floor;

            /* CaseSelection */

            if (
                (
                    (
                        ent_floor_0000000002 == ent_floor_0000000001
                    )
                )) {

                /* Unrelate */

                adm_kill_relation_car_scheduled_to_move_up_to_floor(
                    ent_car,
                    rel_car_scheduled_to_move_up_to_floor_0000000002,
                    1, 975, 81);
            }

            rel_car_scheduled_to_move_up_to_floor_0000000002 = nxt_car_scheduled_to_move_up_to_floor_0000000002;
        }

    } else if (
        (
            (
                ent_car->atb_direction == ADM_LITERAL_DIRECTION_DOWN
            )
        )) {

        /* Traverse - TraverseSelection */

        adm_object_existent_car(
            ent_car,
            1, 987, 65);

        rel_car_scheduled_to_move_down_to_floor_0000000003 = ent_car->rel_scheduled_to_move_down_to_floor_head;

        while (rel_car_scheduled_to_move_down_to_floor_0000000003 != NULL) {

            nxt_car_scheduled_to_move_down_to_floor_0000000003 = rel_car_scheduled_to_move_down_to_floor_0000000003->next;

            ent_floor_0000000003 = rel_car_scheduled_to_move_down_to_floor_0000000003->ent_floor;

            /* CaseSelection */

            if (
                (
                    (
                        ent_floor_0000000003 == ent_floor_0000000001
                    )
                )) {

                /* Unrelate */

                adm_kill_relation_car_scheduled_to_move_down_to_floor(
                    ent_car,
                    rel_car_scheduled_to_move_down_to_floor_0000000003,
                    1, 996, 81);
            }

            rel_car_scheduled_to_move_down_to_floor_0000000003 = nxt_car_scheduled_to_move_down_to_floor_0000000003;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_accessible");
    #endif
}

void adm_state_action_car_closing(
    adm_ent_car_typ * ent_car)
{
    /* Entity Objects */
    adm_ent_door_typ * ent_door_0000000001;

    /* Relationship Relations */
    adm_rel_car_accessed_through_door_typ * rel_car_accessed_through_door_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_closing");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_car(
        ent_car,
        1, 1021, 45);

    rel_car_accessed_through_door_0000000001 = ent_car->rel_accessed_through_door_head;

    ent_door_0000000001 = rel_car_accessed_through_door_0000000001->ent_door;

    /* GenerateEvent */

    adm_send_event_door_close(
        ent_car,
        ent_door_0000000001,
        1, 1024, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_car_closing");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */