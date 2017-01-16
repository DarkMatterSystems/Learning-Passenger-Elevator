
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Stop Simulator Display Entity */

void adm_sim_display_entity_car_stop(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_car_stop_typ * ent_car_stop;

    adm_sim_width_car_stop_typ width_car_stop;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car_stop");
    #endif

    width_car_stop.identity = strlen("Identity");
    width_car_stop.status = strlen("Status");

    ent_car_stop = adm_entity_system.ent_car_stop.live_list_head;

    while (ent_car_stop != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_car_stop->identity);
        if (width > width_car_stop.identity) width_car_stop.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_car_stop[ent_car_stop->status]);
        if (width > width_car_stop.status) width_car_stop.status = width;

        ent_car_stop = ent_car_stop->next;
    }

    printf(NEWLINE);
    printf("Car_Stop:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_car_stop.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_car_stop.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_car_stop.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_car_stop.status);

    ent_car_stop = adm_entity_system.ent_car_stop.live_list_head;

    while (ent_car_stop != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_car_stop.identity, ent_car_stop->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_car_stop->status) {
            case ADM_STATUS_CAR_STOP_AWAITING_FLOOR :
                printf("%-*s", width_car_stop.status, "Awaiting_Floor");
            break;
            default :
                printf("%-*s", width_car_stop.status, "ERROR");
            break;
        }


        ent_car_stop = ent_car_stop->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car_stop");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */