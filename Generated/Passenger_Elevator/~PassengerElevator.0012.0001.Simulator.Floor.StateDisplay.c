
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Floor Display State */

void adm_sim_display_state_floor_idle(
    adm_pool_target_floor_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_floor_idle");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:64:42) - Floor[");
        printf("%d", (pool_target->ent_floor)->identity);
        printf("] ");
        printf("Idle");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_FLOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_floor[(pool_target->ent_floor)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_floor_idle");
    #endif
}

void adm_sim_display_state_floor_calling_service(
    adm_pool_target_floor_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_floor_calling_service");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:73:42) - Floor[");
        printf("%d", (pool_target->ent_floor)->identity);
        printf("] ");
        printf("Calling_Service");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_FLOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_floor[(pool_target->ent_floor)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_floor_calling_service");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */