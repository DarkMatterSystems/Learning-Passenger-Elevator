
#include "~PassengerElevator.0000.0000.Header.h"


/* Floor State Actions */

void adm_state_action_floor_calling_service(
    adm_ent_floor_typ * ent_floor)
{
    /* Entity Objects */
    adm_ent_car_service_typ * ent_car_service_0000000001;
    adm_ent_service_assigner_typ * ent_service_assigner_0000000002;

    /* Relationship Relations */
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service_0000000001;
    adm_rel_car_service_assigned_by_service_assigner_typ * rel_car_service_assigned_by_service_assigner_0000000002;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_floor_calling_service");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_floor(
        ent_floor,
        1, 79, 45);

    rel_floor_serviced_by_car_service_0000000001 = ent_floor->rel_serviced_by_car_service_head;

    while (rel_floor_serviced_by_car_service_0000000001 != NULL) {

        ent_car_service_0000000001 = rel_floor_serviced_by_car_service_0000000001->ent_car_service;

        /* SelectionHead */

        adm_object_existent_floor(
            ent_floor,
            1, 79, 45);

        if (rel_floor_serviced_by_car_service_0000000001 == ent_floor->rel_serviced_by_car_service_head) {

            /* Traverse - TraverseSelection */

            adm_object_existent_car_service(
                ent_car_service_0000000001,
                1, 84, 57);

            rel_car_service_assigned_by_service_assigner_0000000002 = ent_car_service_0000000001->rel_assigned_by_service_assigner_head;

            ent_service_assigner_0000000002 = rel_car_service_assigned_by_service_assigner_0000000002->ent_service_assigner;

            /* GenerateEvent */

            adm_send_event_floor_service_called(
                ent_floor,
                ent_floor,
                1, 87, 61);

            /* GenerateEvent */

            adm_send_event_service_assigner_assign_car(
                ent_floor,
                ent_service_assigner_0000000002,
                ent_floor->atb_number,
                1, 88, 75);
        }

        rel_floor_serviced_by_car_service_0000000001 = rel_floor_serviced_by_car_service_0000000001->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_floor_calling_service");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */