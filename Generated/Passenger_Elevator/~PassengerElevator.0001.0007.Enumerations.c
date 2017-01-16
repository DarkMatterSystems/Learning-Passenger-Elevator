
#include "~PassengerElevator.0000.0000.Header.h"


/* System - Enumerations */

/* System Enumerations */

/* Increment Direction Enumeration */

adm_enm_direction_typ adm_increment_enumeration_direction(
    adm_enm_direction_typ source_direction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_enm_direction_typ target_direction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_ENUMERATION, "adm_increment_enumeration_direction");
    #endif

    if (source_direction != ADM_TYPE_MAXIMUM_DIRECTION) {

        target_direction = (adm_enm_direction_typ)((int)source_direction+1);

    } else {

        adm_error_report(
            ADM_ERROR_ENUMERATION_INCREMENTED_OUT_OF_BOUNDS,
            error_file, error_line, error_rank,
            "Direction",
            null, NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_ENUMERATION, "adm_increment_enumeration_direction");
    #endif

    return (target_direction);
}

/* Decrement Direction Enumeration */

adm_enm_direction_typ adm_decrement_enumeration_direction(
    adm_enm_direction_typ source_direction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_enm_direction_typ target_direction;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_ENUMERATION, "adm_decrement_enumeration_direction");
    #endif

    if (source_direction != ADM_TYPE_MINIMUM_DIRECTION) {

        target_direction = (adm_enm_direction_typ)((int)source_direction-1);

    } else {

        adm_error_report(
            ADM_ERROR_ENUMERATION_DECREMENTED_OUT_OF_BOUNDS,
            error_file, error_line, error_rank,
            "Direction",
            null, NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_ENUMERATION, "adm_decrement_enumeration_direction");
    #endif

    return (target_direction);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */