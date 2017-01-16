
#include "~PassengerElevator.0000.0000.Header.h"


/* Simulator System Literal Strings */

/* Status Literal Strings */

adm_base_string_typ * adm_sim_status_floor[] = {
    "Idle",
    "Calling_Service"
};

adm_base_string_typ * adm_sim_status_door[] = {
    "Closed",
    "Opening",
    "Open",
    "Closing",
    "Avoiding_Obstruction"
};

adm_base_string_typ * adm_sim_status_car_stop[] = {
    "Awaiting_Floor"
};

adm_base_string_typ * adm_sim_status_service_assigner[] = {
    "Idle",
    "Allocating_Car"
};

adm_base_string_typ * adm_sim_status_car[] = {
    "Stationary",
    "Selecting_Schedule",
    "Servicing_Schedule",
    "Moving",
    "Checking_Schedule",
    "Slowing",
    "Opening",
    "Accessible",
    "Closing"
};

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */