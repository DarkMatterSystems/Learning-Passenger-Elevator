
#include "~PassengerElevator.0000.0000.Header.h"


/* System Stimulate */

void adm_sim_simulate(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif

    if (adm_sim_err_success) {

        while (
            adm_entity_system.ent_floor.away_pool_head != NULL ||
            adm_entity_system.ent_door.away_pool_head != NULL ||
            adm_entity_system.ent_car_stop.away_pool_head != NULL ||
            adm_entity_system.ent_service_assigner.away_pool_head != NULL ||
            adm_entity_system.ent_car.away_pool_head != NULL) {

            adm_scheduler_dom_elevator_management();
        }

        adm_integrity_check();
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_simulate");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */