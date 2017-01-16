
#include "~PassengerElevator.0000.0000.Header.h"


/* Floor Simulator Display Entity */

void adm_sim_display_entity_floor(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_floor_typ * ent_floor;

    adm_sim_width_floor_typ width_floor;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_floor");
    #endif

    width_floor.identity = strlen("Identity");
    width_floor.status = strlen("Status");
    width_floor.atb_number = strlen("Number");

    ent_floor = adm_entity_system.ent_floor.live_list_head;

    while (ent_floor != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_floor->identity);
        if (width > width_floor.identity) width_floor.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_floor[ent_floor->status]);
        if (width > width_floor.status) width_floor.status = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_floor->atb_number);
        if (width > width_floor.atb_number) width_floor.atb_number = width;

        ent_floor = ent_floor->next;
    }

    printf(NEWLINE);
    printf("Floor:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_floor.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_floor.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_floor.atb_number, "Number");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_floor.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_floor.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_floor.atb_number);

    ent_floor = adm_entity_system.ent_floor.live_list_head;

    while (ent_floor != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_floor.identity, ent_floor->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_floor->status) {
            case ADM_STATUS_FLOOR_IDLE :
                printf("%-*s", width_floor.status, "Idle");
            break;
            case ADM_STATUS_FLOOR_CALLING_SERVICE :
                printf("%-*s", width_floor.status, "Calling_Service");
            break;
            default :
                printf("%-*s", width_floor.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        printf("%*d", width_floor.atb_number, ent_floor->atb_number);

        ent_floor = ent_floor->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */