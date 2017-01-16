
#include "~PassengerElevator.0000.0000.Header.h"


/* Service Assigner State Actions */

void adm_state_action_service_assigner_allocating_car(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_dst_service_assigner_allocate_typ * dst_allocate)
{
    /* Process Data */
    adm_bln_flag_typ pdt_car_not_found;

    /* Entity Objects */
    adm_ent_car_service_typ * ent_car_service_0000000001;
    adm_ent_car_typ * ent_car_0000000002;
    adm_ent_car_service_typ * ent_car_service_0000000002;
    adm_ent_floor_typ * ent_floor_0000000002;
    adm_ent_car_service_typ * ent_car_service_0000000003;
    adm_ent_car_typ * ent_car_0000000003;
    adm_ent_floor_typ * ent_floor_0000000004;
    adm_ent_floor_typ * ent_floor_0000000005;
    adm_ent_floor_typ * ent_floor_0000000006;
    adm_ent_car_service_typ * ent_car_service_0000000007;
    adm_ent_car_typ * ent_car_0000000007;
    adm_ent_floor_typ * ent_floor_0000000008;

    /* Relationship Relations */
    adm_rel_service_assigner_assigns_car_service_typ * rel_service_assigner_assigns_car_service_0000000001;
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car_0000000002;
    adm_rel_car_services_car_service_typ * rel_car_services_car_service_0000000002;
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor_0000000002;
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service_0000000003;
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car_0000000003;
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor_0000000004;
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor_0000000005;
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000006;
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service_0000000007;
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car_0000000007;
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor_0000000008;

    /* Traverse Null Selection Flags */
    adm_base_boolean_typ traverse_not_found_0000000004;
    adm_base_boolean_typ traverse_not_found_0000000005;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_service_assigner_allocating_car");
    #endif

    /* Assignment - Set */

    pdt_car_not_found = TRUE;

    /* Traverse - TraverseSelection */

    adm_object_existent_service_assigner(
        ent_service_assigner,
        1, 313, 45);

    rel_service_assigner_assigns_car_service_0000000001 = ent_service_assigner->rel_assigns_car_service_head;

    while (rel_service_assigner_assigns_car_service_0000000001 != NULL) {

        ent_car_service_0000000001 = rel_service_assigner_assigns_car_service_0000000001->ent_car_service;

        /* SelectionHead */

        adm_object_existent_service_assigner(
            ent_service_assigner,
            1, 313, 45);

        if (rel_service_assigner_assigns_car_service_0000000001 == ent_service_assigner->rel_assigns_car_service_head) {

            /* Traverse - TraverseSelection */

            adm_object_existent_car_service(
                ent_car_service_0000000001,
                1, 318, 57);

            rel_car_service_serviced_by_car_0000000002 = ent_car_service_0000000001->rel_serviced_by_car_head;

            ent_car_0000000002 = rel_car_service_serviced_by_car_0000000002->ent_car;

            rel_car_services_car_service_0000000002 = ent_car_0000000002->rel_services_car_service_head;

            while (rel_car_services_car_service_0000000002 != NULL) {

                ent_car_service_0000000002 = rel_car_services_car_service_0000000002->ent_car_service;

                rel_car_service_services_floor_0000000002 = ent_car_service_0000000002->rel_services_floor_head;

                ent_floor_0000000002 = rel_car_service_services_floor_0000000002->ent_floor;

                /* CaseSelection */

                if (
                    (
                        (
                            ent_floor_0000000002->atb_number == dst_allocate->floor_number
                        )
                    )) {

                    /* Traverse - TraverseSelection */

                    adm_object_existent_floor(
                        ent_floor_0000000002,
                        1, 335, 77);

                    rel_floor_serviced_by_car_service_0000000003 = ent_floor_0000000002->rel_serviced_by_car_service_head;

                    while (rel_floor_serviced_by_car_service_0000000003 != NULL) {

                        ent_car_service_0000000003 = rel_floor_serviced_by_car_service_0000000003->ent_car_service;

                        rel_car_service_serviced_by_car_0000000003 = ent_car_service_0000000003->rel_serviced_by_car_head;

                        ent_car_0000000003 = rel_car_service_serviced_by_car_0000000003->ent_car;

                        /* CaseSelection */

                        if (
                            (
                                (
                                    pdt_car_not_found
                                )
                            )) {

                            /* Traverse - TraverseSelection */

                            adm_object_existent_car(
                                ent_car_0000000003,
                                1, 349, 97);

                            traverse_not_found_0000000004 = TRUE;

                            rel_car_scheduled_to_move_up_to_floor_0000000004 = ent_car_0000000003->rel_scheduled_to_move_up_to_floor_head;

                            while (rel_car_scheduled_to_move_up_to_floor_0000000004 != NULL) {

                                ent_floor_0000000004 = rel_car_scheduled_to_move_up_to_floor_0000000004->ent_floor;

                                traverse_not_found_0000000004 = FALSE;

                                rel_car_scheduled_to_move_up_to_floor_0000000004 = rel_car_scheduled_to_move_up_to_floor_0000000004->next;
                            }

                            /* Traverse - Null Traverse Selection */

                            if (traverse_not_found_0000000004) {

                                /* Traverse - TraverseSelection */

                                adm_object_existent_car(
                                    ent_car_0000000003,
                                    1, 355, 105);

                                traverse_not_found_0000000005 = TRUE;

                                rel_car_scheduled_to_move_down_to_floor_0000000005 = ent_car_0000000003->rel_scheduled_to_move_down_to_floor_head;

                                while (rel_car_scheduled_to_move_down_to_floor_0000000005 != NULL) {

                                    ent_floor_0000000005 = rel_car_scheduled_to_move_down_to_floor_0000000005->ent_floor;

                                    traverse_not_found_0000000005 = FALSE;

                                    rel_car_scheduled_to_move_down_to_floor_0000000005 = rel_car_scheduled_to_move_down_to_floor_0000000005->next;
                                }

                                /* Traverse - Null Traverse Selection */

                                if (traverse_not_found_0000000005) {

                                    /* Traverse - TraverseSelection */

                                    adm_object_existent_car(
                                        ent_car_0000000003,
                                        1, 361, 113);

                                    rel_car_currently_at_floor_0000000006 = ent_car_0000000003->rel_currently_at_floor_head;

                                    ent_floor_0000000006 = rel_car_currently_at_floor_0000000006->ent_floor;

                                    /* CaseSelection */

                                    if (
                                        (
                                            (
                                                ent_floor_0000000006->atb_number <= dst_allocate->floor_number
                                            )
                                        )) {

                                        /* Relate */

                                        adm_link_relation_car_scheduled_to_move_up_to_floor(
                                            ent_car_0000000003,
                                            ent_floor_0000000002,
                                            1, 374, 129);

                                    } else if (
                                        (
                                            (
                                                ent_floor_0000000006->atb_number > dst_allocate->floor_number
                                            )
                                        )) {

                                        /* Relate */

                                        adm_link_relation_car_scheduled_to_move_down_to_floor(
                                            ent_car_0000000003,
                                            ent_floor_0000000002,
                                            1, 383, 129);
                                    }

                                    /* Assignment - Set */

                                    pdt_car_not_found = FALSE;

                                    /* GenerateEvent */

                                    adm_send_event_car_service_requested(
                                        ent_service_assigner,
                                        ent_car_0000000003,
                                        1, 389, 117);
                                }
                            }
                        }

                        rel_floor_serviced_by_car_service_0000000003 = rel_floor_serviced_by_car_service_0000000003->next;
                    }

                    /* CaseSelection */

                    if (
                        (
                            (
                                pdt_car_not_found
                            )
                        )) {

                        /* Traverse - TraverseSelection */

                        adm_object_existent_floor(
                            ent_floor_0000000002,
                            1, 403, 89);

                        rel_floor_serviced_by_car_service_0000000007 = ent_floor_0000000002->rel_serviced_by_car_service_head;

                        while (rel_floor_serviced_by_car_service_0000000007 != NULL) {

                            ent_car_service_0000000007 = rel_floor_serviced_by_car_service_0000000007->ent_car_service;

                            rel_car_service_serviced_by_car_0000000007 = ent_car_service_0000000007->rel_serviced_by_car_head;

                            ent_car_0000000007 = rel_car_service_serviced_by_car_0000000007->ent_car;

                            /* SelectionHead */

                            adm_object_existent_floor(
                                ent_floor_0000000002,
                                1, 403, 89);

                            if (
                                rel_floor_serviced_by_car_service_0000000007 == ent_floor_0000000002->rel_serviced_by_car_service_head &&
                                rel_car_service_serviced_by_car_0000000007 == ent_car_service_0000000007->rel_serviced_by_car_head) {

                                /* Traverse - TraverseSelection */

                                adm_object_existent_car(
                                    ent_car_0000000007,
                                    1, 413, 101);

                                rel_car_currently_at_floor_0000000008 = ent_car_0000000007->rel_currently_at_floor_head;

                                ent_floor_0000000008 = rel_car_currently_at_floor_0000000008->ent_floor;

                                /* CaseSelection */

                                if (
                                    (
                                        (
                                            ent_floor_0000000008->atb_number <= dst_allocate->floor_number
                                        )
                                    )) {

                                    /* Relate */

                                    adm_link_relation_car_scheduled_to_move_up_to_floor(
                                        ent_car_0000000007,
                                        ent_floor_0000000002,
                                        1, 426, 117);

                                } else if (
                                    (
                                        (
                                            ent_floor_0000000008->atb_number > dst_allocate->floor_number
                                        )
                                    )) {

                                    /* Relate */

                                    adm_link_relation_car_scheduled_to_move_down_to_floor(
                                        ent_car_0000000007,
                                        ent_floor_0000000002,
                                        1, 435, 117);
                                }

                                /* Assignment - Set */

                                pdt_car_not_found = FALSE;

                                /* GenerateEvent */

                                adm_send_event_car_service_requested(
                                    ent_service_assigner,
                                    ent_car_0000000007,
                                    1, 441, 105);
                            }

                            rel_floor_serviced_by_car_service_0000000007 = rel_floor_serviced_by_car_service_0000000007->next;
                        }
                    }
                }

                rel_car_services_car_service_0000000002 = rel_car_services_car_service_0000000002->next;
            }
        }

        rel_service_assigner_assigns_car_service_0000000001 = rel_service_assigner_assigns_car_service_0000000001->next;
    }

    /* GenerateEvent */

    adm_send_event_service_assigner_car_assigned(
        ent_service_assigner,
        ent_service_assigner,
        1, 444, 41);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_service_assigner_allocating_car");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */