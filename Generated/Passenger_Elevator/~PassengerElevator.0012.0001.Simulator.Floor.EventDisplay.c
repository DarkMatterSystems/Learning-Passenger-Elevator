
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator Floor Display Event */

void adm_sim_display_event_floor_request_service(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_floor_request_service");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Floor[");
        printf("%d", ent_floor->identity);
        printf("] Request_service (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_floor_request_service");
    #endif
}

void adm_sim_display_event_floor_service_called(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_floor_service_called");
    #endif

    if (
        adm_sim_trace.all &&
        adm_sim_trace.events) {

        printf(NEWLINE);
        printf("EVENT (");
        printf("%d:%d:%d)", error_file, error_line, error_rank);
        printf(" - Floor[");
        printf("%d", ent_floor->identity);
        printf("] Service_called (");
        printf(")");
        printf(NEWLINE);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_display_event_floor_service_called");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */