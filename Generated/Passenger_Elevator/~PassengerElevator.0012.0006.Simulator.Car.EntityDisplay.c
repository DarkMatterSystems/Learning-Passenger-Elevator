
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Simulator Display Entity */

void adm_sim_display_entity_car(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_car_typ * ent_car;

    adm_sim_width_car_typ width_car;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car");
    #endif

    width_car.identity = strlen("Identity");
    width_car.status = strlen("Status");
    width_car.atb_direction = strlen("Direction");

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (ent_car != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_car->identity);
        if (width > width_car.identity) width_car.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_car[ent_car->status]);
        if (width > width_car.status) width_car.status = width;

        if (ent_car->atb_direction >= ADM_TYPE_MINIMUM_DIRECTION && ent_car->atb_direction <= ADM_TYPE_MAXIMUM_DIRECTION) {
            width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_enumeration_direction[ent_car->atb_direction]);
            if (width > width_car.atb_direction) width_car.atb_direction = width;}

        ent_car = ent_car->next;
    }

    printf(NEWLINE);
    printf("Car:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_car.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_car.status, "Status");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_car.atb_direction, "Direction");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_car.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_car.status);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_car.atb_direction);

    ent_car = adm_entity_system.ent_car.live_list_head;

    while (ent_car != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_car.identity, ent_car->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_car->status) {
            case ADM_STATUS_CAR_STATIONARY :
                printf("%-*s", width_car.status, "Stationary");
            break;
            case ADM_STATUS_CAR_SELECTING_SCHEDULE :
                printf("%-*s", width_car.status, "Selecting_Schedule");
            break;
            case ADM_STATUS_CAR_SERVICING_SCHEDULE :
                printf("%-*s", width_car.status, "Servicing_Schedule");
            break;
            case ADM_STATUS_CAR_MOVING :
                printf("%-*s", width_car.status, "Moving");
            break;
            case ADM_STATUS_CAR_CHECKING_SCHEDULE :
                printf("%-*s", width_car.status, "Checking_Schedule");
            break;
            case ADM_STATUS_CAR_SLOWING :
                printf("%-*s", width_car.status, "Slowing");
            break;
            case ADM_STATUS_CAR_OPENING :
                printf("%-*s", width_car.status, "Opening");
            break;
            case ADM_STATUS_CAR_ACCESSIBLE :
                printf("%-*s", width_car.status, "Accessible");
            break;
            case ADM_STATUS_CAR_CLOSING :
                printf("%-*s", width_car.status, "Closing");
            break;
            default :
                printf("%-*s", width_car.status, "ERROR");
            break;
        }

        printf(ADM_SIM_COLUMN_GAP);
        if (ent_car->atb_direction >= ADM_TYPE_MINIMUM_DIRECTION && ent_car->atb_direction <= ADM_TYPE_MAXIMUM_DIRECTION)
            printf("%-*s", width_car.atb_direction, adm_enumeration_direction[ent_car->atb_direction]);
        else
            adm_sim_display_row('*', width_car.atb_direction);

        ent_car = ent_car->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */