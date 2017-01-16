
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Car Stop Display Event */

void adm_sim_display_event_car_stop_go_to_floor(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_int_floor_typ evd_desired_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_car_stop_go_to_floor");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Car_Stop[");
        printf("%d", ent_car_stop->identity);
        printf("] Go_to_floor (");
        printf("Desired_floor_number:%d", evd_desired_floor_number);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_car_stop_go_to_floor");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */