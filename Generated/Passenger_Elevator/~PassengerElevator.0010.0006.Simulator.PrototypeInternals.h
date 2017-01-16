
/* Simulator System Prototype Internals Header */

/* Display Entity Prototypes */

void adm_sim_display_entity_floor(
    void);

void adm_sim_display_entity_door(
    void);

void adm_sim_display_entity_car_service(
    void);

void adm_sim_display_entity_car_stop(
    void);

void adm_sim_display_entity_service_assigner(
    void);

void adm_sim_display_entity_car(
    void);


/* Acquire Identity Event Prototypes */

void adm_sim_acquire_identity_event_floor_request_service(
    void);

void adm_sim_acquire_identity_event_floor_service_called(
    void);

void adm_sim_acquire_identity_event_door_open(
    void);

void adm_sim_acquire_identity_event_door_close(
    void);

void adm_sim_acquire_identity_event_door_obstruction(
    void);

void adm_sim_acquire_identity_event_door_open_completed(
    void);

void adm_sim_acquire_identity_event_door_close_completed(
    void);

void adm_sim_acquire_identity_event_door_clear(
    void);

void adm_sim_acquire_identity_event_car_stop_go_to_floor(
    void);

void adm_sim_acquire_identity_event_service_assigner_assign_car(
    void);

void adm_sim_acquire_identity_event_service_assigner_car_assigned(
    void);

void adm_sim_acquire_identity_event_car_service_requested(
    void);

void adm_sim_acquire_identity_event_car_open_door(
    void);

void adm_sim_acquire_identity_event_car_close_door(
    void);

void adm_sim_acquire_identity_event_car_service_schedule(
    void);

void adm_sim_acquire_identity_event_car_service_current_floor(
    void);

void adm_sim_acquire_identity_event_car_moving(
    void);

void adm_sim_acquire_identity_event_car_floor_approaching(
    void);

void adm_sim_acquire_identity_event_car_continue(
    void);

void adm_sim_acquire_identity_event_car_stop_at_next_floor(
    void);

void adm_sim_acquire_identity_event_car_car_stopped(
    void);

void adm_sim_acquire_identity_event_car_door_open(
    void);

void adm_sim_acquire_identity_event_car_door_closed(
    void);


/* Acquire Identifier Event Prototypes */


/* Display Event Prototypes */

void adm_sim_display_event_floor_request_service(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_floor_service_called(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_open(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_close(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_obstruction(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_open_completed(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_close_completed(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_door_clear(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_stop_go_to_floor(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_int_floor_typ evd_desired_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_service_assigner_assign_car(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_int_floor_typ evd_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_service_assigner_car_assigned(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_service_requested(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_open_door(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_close_door(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_service_schedule(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_service_current_floor(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_moving(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_floor_approaching(
    adm_ent_car_typ * ent_car,
    adm_int_floor_typ evd_next_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_continue(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_stop_at_next_floor(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_car_stopped(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_door_open(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_sim_display_event_car_door_closed(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Display State Prototypes */

void adm_sim_display_state_floor_idle(
    adm_pool_target_floor_typ * pool_target);

void adm_sim_display_state_floor_calling_service(
    adm_pool_target_floor_typ * pool_target);

void adm_sim_display_state_door_closed(
    adm_pool_target_door_typ * pool_target);

void adm_sim_display_state_door_opening(
    adm_pool_target_door_typ * pool_target);

void adm_sim_display_state_door_open(
    adm_pool_target_door_typ * pool_target);

void adm_sim_display_state_door_closing(
    adm_pool_target_door_typ * pool_target);

void adm_sim_display_state_door_avoiding_obstruction(
    adm_pool_target_door_typ * pool_target);

void adm_sim_display_state_car_stop_awaiting_floor(
    adm_pool_target_car_stop_typ * pool_target);

void adm_sim_display_state_service_assigner_idle(
    adm_pool_target_service_assigner_typ * pool_target);

void adm_sim_display_state_service_assigner_allocating_car(
    adm_pool_target_service_assigner_typ * pool_target);

void adm_sim_display_state_car_stationary(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_selecting_schedule(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_servicing_schedule(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_moving(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_checking_schedule(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_slowing(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_opening(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_accessible(
    adm_pool_target_car_typ * pool_target);

void adm_sim_display_state_car_closing(
    adm_pool_target_car_typ * pool_target);


/* Find Event Name Prototype */

adm_base_string_typ * adm_sim_find_event_name(
    adm_base_integer_typ entity_index,
    adm_base_integer_typ entity_event_index);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */