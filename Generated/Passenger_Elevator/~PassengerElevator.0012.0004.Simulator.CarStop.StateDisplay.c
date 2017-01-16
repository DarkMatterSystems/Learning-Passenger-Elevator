
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Car Stop Display State */

void adm_sim_display_state_car_stop_awaiting_floor(
    adm_pool_target_car_stop_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_stop_awaiting_floor");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:218:46) - Car_Stop[");
        printf("%d", (pool_target->ent_car_stop)->identity);
        printf("] ");
        printf("Awaiting_Floor");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR_STOP, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car_stop[(pool_target->ent_car_stop)->status]);
        printf("} (");
        printf("Desired_floor_number:");
        printf("%d", (pool_target->dataset.await)->desired_floor_number);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_stop_awaiting_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */