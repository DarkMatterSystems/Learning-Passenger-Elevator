
#include "~PassengerElevator.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_elevator_management(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_elevator_management");
    #endif

    adm_dispatch_home_pool_floor();
    adm_dispatch_home_pool_door();
    adm_dispatch_home_pool_car_stop();
    adm_dispatch_home_pool_service_assigner();
    adm_dispatch_home_pool_car();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_elevator_management");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */