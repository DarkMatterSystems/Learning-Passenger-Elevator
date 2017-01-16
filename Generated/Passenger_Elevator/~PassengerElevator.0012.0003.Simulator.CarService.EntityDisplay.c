
#include "~PassengerElevator.0000.0000.Header.h"


/* Car Service Simulator Display Entity */

void adm_sim_display_entity_car_service(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_car_service_typ * ent_car_service;

    adm_sim_width_car_service_typ width_car_service;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car_service");
    #endif

    width_car_service.identity = strlen("Identity");

    ent_car_service = adm_entity_system.ent_car_service.live_list_head;

    while (ent_car_service != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_car_service->identity);
        if (width > width_car_service.identity) width_car_service.identity = width;

        ent_car_service = ent_car_service->next;
    }

    printf(NEWLINE);
    printf("Car_Service:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_car_service.identity, "Identity");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_car_service.identity);

    ent_car_service = adm_entity_system.ent_car_service.live_list_head;

    while (ent_car_service != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_car_service.identity, ent_car_service->identity);

        ent_car_service = ent_car_service->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_car_service");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */