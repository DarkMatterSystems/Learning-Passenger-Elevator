
#include "~PassengerElevator.0000.0000.Header.h"


/* Door Simulator Display Entity */

void adm_sim_display_entity_door(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_door_typ * ent_door;

    adm_sim_width_door_typ width_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_door");
    #endif

    width_door.identity = strlen("Identity");
    width_door.status = strlen("Status");

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (ent_door != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_door->identity);
        if (width > width_door.identity) width_door.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_door[ent_door->status]);
        if (width > width_door.status) width_door.status = width;

        ent_door = ent_door->next;
    }

    printf(NEWLINE);
    printf("Door:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_door.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_door.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_door.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_door.status);

    ent_door = adm_entity_system.ent_door.live_list_head;

    while (ent_door != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_door.identity, ent_door->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_door->status) {
            case ADM_STATUS_DOOR_CLOSED :
                printf("%-*s", width_door.status, "Closed");
            break;
            case ADM_STATUS_DOOR_OPENING :
                printf("%-*s", width_door.status, "Opening");
            break;
            case ADM_STATUS_DOOR_OPEN :
                printf("%-*s", width_door.status, "Open");
            break;
            case ADM_STATUS_DOOR_CLOSING :
                printf("%-*s", width_door.status, "Closing");
            break;
            case ADM_STATUS_DOOR_AVOIDING_OBSTRUCTION :
                printf("%-*s", width_door.status, "Avoiding_Obstruction");
            break;
            default :
                printf("%-*s", width_door.status, "ERROR");
            break;
        }


        ent_door = ent_door->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */