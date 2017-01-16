
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Service Assigner Display State */

void adm_sim_display_state_service_assigner_idle(
    adm_pool_target_service_assigner_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_service_assigner_idle");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:288:42) - Service_Assigner[");
        printf("%d", (pool_target->ent_service_assigner)->identity);
        printf("] ");
        printf("Idle");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_service_assigner[(pool_target->ent_service_assigner)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_service_assigner_idle");
    #endif
}

void adm_sim_display_state_service_assigner_allocating_car(
    adm_pool_target_service_assigner_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_service_assigner_allocating_car");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:297:46) - Service_Assigner[");
        printf("%d", (pool_target->ent_service_assigner)->identity);
        printf("] ");
        printf("Allocating_Car");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_SERVICE_ASSIGNER, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_service_assigner[(pool_target->ent_service_assigner)->status]);
        printf("} (");
        printf("Floor_number:");
        printf("%d", (pool_target->dataset.allocate)->floor_number);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_service_assigner_allocating_car");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */