
#include "~PassengerElevator.0000.0000.Header.h"


/* Door State Actions */

void adm_state_action_door_closed(
    adm_ent_door_typ * ent_door)
{
    /* Entity Objects */
    adm_ent_car_typ * ent_car_0000000001;

    /* Relationship Relations */
    adm_rel_door_provides_passenger_access_to_car_typ * rel_door_provides_passenger_access_to_car_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_closed");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_door(
        ent_door,
        1, 111, 45);

    rel_door_provides_passenger_access_to_car_0000000001 = ent_door->rel_provides_passenger_access_to_car_head;

    ent_car_0000000001 = rel_door_provides_passenger_access_to_car_0000000001->ent_car;

    /* GenerateEvent */

    adm_send_event_car_door_closed(
        ent_door,
        ent_car_0000000001,
        1, 114, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_closed");
    #endif
}

void adm_state_action_door_opening(
    adm_ent_door_typ * ent_door)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_opening");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("EVENT -> Machinery::Door_Opening");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_opening");
    #endif
}

void adm_state_action_door_open(
    adm_ent_door_typ * ent_door)
{
    /* Entity Objects */
    adm_ent_car_typ * ent_car_0000000001;

    /* Relationship Relations */
    adm_rel_door_provides_passenger_access_to_car_typ * rel_door_provides_passenger_access_to_car_0000000001;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_open");
    #endif

    /* Traverse - TraverseSelection */

    adm_object_existent_door(
        ent_door,
        1, 150, 45);

    rel_door_provides_passenger_access_to_car_0000000001 = ent_door->rel_provides_passenger_access_to_car_head;

    ent_car_0000000001 = rel_door_provides_passenger_access_to_car_0000000001->ent_car;

    /* GenerateEvent */

    adm_send_event_car_door_open(
        ent_door,
        ent_car_0000000001,
        1, 153, 49);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_open");
    #endif
}

void adm_state_action_door_closing(
    adm_ent_door_typ * ent_door)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_closing");
    #endif

    /* Template */

    adm_write_newline();
    adm_write_str("EVENT -> Machinery::Door_Closing");
    adm_write_newline();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_STATE_ACTION, "adm_state_action_door_closing");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */