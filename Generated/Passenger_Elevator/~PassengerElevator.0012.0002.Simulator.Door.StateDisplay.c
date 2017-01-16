
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Door Display State */

void adm_sim_display_state_door_closed(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_closed");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:107:42) - Door[");
        printf("%d", (pool_target->ent_door)->identity);
        printf("] ");
        printf("Closed");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_door[(pool_target->ent_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_closed");
    #endif
}

void adm_sim_display_state_door_opening(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_opening");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:128:42) - Door[");
        printf("%d", (pool_target->ent_door)->identity);
        printf("] ");
        printf("Opening");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_door[(pool_target->ent_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_opening");
    #endif
}

void adm_sim_display_state_door_open(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_open");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:146:42) - Door[");
        printf("%d", (pool_target->ent_door)->identity);
        printf("] ");
        printf("Open");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_door[(pool_target->ent_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_open");
    #endif
}

void adm_sim_display_state_door_closing(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_closing");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:167:42) - Door[");
        printf("%d", (pool_target->ent_door)->identity);
        printf("] ");
        printf("Closing");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_door[(pool_target->ent_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_closing");
    #endif
}

void adm_sim_display_state_door_avoiding_obstruction(
    adm_pool_target_door_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_avoiding_obstruction");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:185:42) - Door[");
        printf("%d", (pool_target->ent_door)->identity);
        printf("] ");
        printf("Avoiding_Obstruction");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_DOOR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_door[(pool_target->ent_door)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_door_avoiding_obstruction");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */