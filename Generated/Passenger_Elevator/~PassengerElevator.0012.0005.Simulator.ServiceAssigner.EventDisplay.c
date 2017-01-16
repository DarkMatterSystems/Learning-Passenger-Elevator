
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Service Assigner Display Event */

void adm_sim_display_event_service_assigner_assign_car(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_int_floor_typ evd_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_service_assigner_assign_car");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Service_Assigner[");
        printf("%d", ent_service_assigner->identity);
        printf("] Assign_car (");
        printf("Floor_number:%d", evd_floor_number);
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_service_assigner_assign_car");
    #endif
}

void adm_sim_display_event_service_assigner_car_assigned(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_service_assigner_car_assigned");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Service_Assigner[");
        printf("%d", ent_service_assigner->identity);
        printf("] Car_assigned (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_service_assigner_car_assigned");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */