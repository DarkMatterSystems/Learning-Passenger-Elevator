
#include "~PassengerElevator.0000.0000.Header.h"


/* Service Assigner Simulator Display Entity */

void adm_sim_display_entity_service_assigner(
    void)
{
    adm_base_string_typ buffer [ADM_SIM_BUFFER_SIZE];

    adm_base_integer_typ width;

    adm_ent_service_assigner_typ * ent_service_assigner;

    adm_sim_width_service_assigner_typ width_service_assigner;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_service_assigner");
    #endif

    width_service_assigner.identity = strlen("Identity");
    width_service_assigner.status = strlen("Status");

    ent_service_assigner = adm_entity_system.ent_service_assigner.live_list_head;

    while (ent_service_assigner != NULL) {

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%d", ent_service_assigner->identity);
        if (width > width_service_assigner.identity) width_service_assigner.identity = width;

        width = sprintf_s(buffer, ADM_SIM_BUFFER_SIZE, "%s", adm_sim_status_service_assigner[ent_service_assigner->status]);
        if (width > width_service_assigner.status) width_service_assigner.status = width;

        ent_service_assigner = ent_service_assigner->next;
    }

    printf(NEWLINE);
    printf("Service_Assigner:");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    printf("%-*s", width_service_assigner.identity, "Identity");
    printf(ADM_SIM_COLUMN_GAP);
    printf("%-*s", width_service_assigner.status, "Status");

    printf(NEWLINE);
    printf(ADM_SIM_INDENT);
    adm_sim_display_underline(width_service_assigner.identity);
    printf(ADM_SIM_COLUMN_GAP);
    adm_sim_display_underline(width_service_assigner.status);

    ent_service_assigner = adm_entity_system.ent_service_assigner.live_list_head;

    while (ent_service_assigner != NULL) {

        printf(NEWLINE);
        printf(ADM_SIM_INDENT);
        printf("%*d", width_service_assigner.identity, ent_service_assigner->identity);
        printf(ADM_SIM_COLUMN_GAP);

        switch (ent_service_assigner->status) {
            case ADM_STATUS_SERVICE_ASSIGNER_IDLE :
                printf("%-*s", width_service_assigner.status, "Idle");
            break;
            case ADM_STATUS_SERVICE_ASSIGNER_ALLOCATING_CAR :
                printf("%-*s", width_service_assigner.status, "Allocating_Car");
            break;
            default :
                printf("%-*s", width_service_assigner.status, "ERROR");
            break;
        }


        ent_service_assigner = ent_service_assigner->next;
    }

    printf(NEWLINE);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_entity_service_assigner");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */