
#include "~PassengerElevator.0000.0000.Header.h"


/* Domain Scheduler */

void adm_scheduler_dom_elevator_management(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_elevator_management");
    #endif

    if (adm_entity_system.ent_floor.away_pool_head != NULL) adm_dispatcher_floor();
    if (adm_entity_system.ent_door.away_pool_head != NULL) adm_dispatcher_door();
    if (adm_entity_system.ent_car_stop.away_pool_head != NULL) adm_dispatcher_car_stop();
    if (adm_entity_system.ent_service_assigner.away_pool_head != NULL) adm_dispatcher_service_assigner();
    if (adm_entity_system.ent_car.away_pool_head != NULL) adm_dispatcher_car();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_dom_elevator_management");
    #endif
}

adm_base_boolean_typ adm_scheduler_determine_termination_dom_elevator_management(
    void)
{
    adm_base_boolean_typ event_pending;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_elevator_management");
    #endif

    event_pending =
        (adm_entity_system.ent_floor.away_pool_head != NULL) ||
        (adm_entity_system.ent_door.away_pool_head != NULL) ||
        (adm_entity_system.ent_car_stop.away_pool_head != NULL) ||
        (adm_entity_system.ent_service_assigner.away_pool_head != NULL) ||
        (adm_entity_system.ent_car.away_pool_head != NULL);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SCHEDULER, "adm_scheduler_determine_termination_dom_elevator_management");
    #endif

    return (event_pending);
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */