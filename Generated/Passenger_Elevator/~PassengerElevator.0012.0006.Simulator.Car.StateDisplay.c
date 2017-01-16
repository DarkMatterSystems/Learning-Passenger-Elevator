
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Car Display State */

void adm_sim_display_state_car_stationary(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_stationary");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:471:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Stationary");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_stationary");
    #endif
}

void adm_sim_display_state_car_selecting_schedule(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_selecting_schedule");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:511:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Selecting_Schedule");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_selecting_schedule");
    #endif
}

void adm_sim_display_state_car_servicing_schedule(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_servicing_schedule");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:694:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Servicing_Schedule");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_servicing_schedule");
    #endif
}

void adm_sim_display_state_car_moving(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_moving");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:734:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Moving");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_moving");
    #endif
}

void adm_sim_display_state_car_checking_schedule(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_checking_schedule");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:754:46) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Checking_Schedule");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf("Next_floor_number:");
        printf("%d", (pool_target->dataset.travel)->next_floor_number);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_checking_schedule");
    #endif
}

void adm_sim_display_state_car_slowing(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_slowing");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:892:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Slowing");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_slowing");
    #endif
}

void adm_sim_display_state_car_opening(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_opening");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:916:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Opening");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_opening");
    #endif
}

void adm_sim_display_state_car_accessible(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_accessible");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:943:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Accessible");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_accessible");
    #endif
}

void adm_sim_display_state_car_closing(
    adm_pool_target_car_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_closing");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.states) {

        printf(NEWLINE);
        printf("STATE (1:1017:42) - Car[");
        printf("%d", (pool_target->ent_car)->identity);
        printf("] ");
        printf("Closing");
        printf(" {");
        printf("%s", adm_sim_find_event_name(ADM_SIM_INDEX_ENTITY_ELEVATOR_MANAGEMENT_CAR, pool_target->evente));
        printf(" -> ");
        printf("%s", adm_sim_status_car[(pool_target->ent_car)->status]);
        printf("} (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_state_car_closing");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */