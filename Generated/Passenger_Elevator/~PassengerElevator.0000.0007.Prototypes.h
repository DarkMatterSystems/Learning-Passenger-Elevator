
/* System Prototypes Header */

/* Main Prototype */

int main(
    int,
    char * []);


/* System Library */

void * adm_allocate_memory(
    adm_base_integer_typ amount);

void adm_deallocate_memory(
    void * memory);

void adm_open_test_result_file  (void);
void adm_close_test_result_file (void);

void adm_open_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_close_stream_file(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_write_int(
    adm_base_integer_typ number);

void adm_write_bln(
    adm_base_boolean_typ value);

void adm_write_enm_direction(
    adm_enm_direction_typ value);

void adm_write_fxd(
    adm_base_fixed_typ number);

void adm_write_flt(
    adm_base_float_typ number);

void adm_write_str(
    adm_base_string_typ * string);

void adm_write_newline(void);

void adm_template_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_template_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_in(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_display_tab_out(
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_convert_string_upper_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_lower_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_sentence_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_capital_case(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_remove_spaces(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_convert_string_convert_underlines(
    adm_base_string_typ * source_string,
    adm_base_string_typ * target_string);

void adm_integrity_check(void);


#if ADM_PROBE

void adm_probe_enter(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_probe_leave(
    adm_probe_group_typ   group,
    adm_base_string_typ * procedure_name);

void adm_add_spaces(
    adm_base_string_typ  * space_string,
    adm_base_integer_typ   space_number);

#endif


/* System Error Handler */

void adm_error_report(
    adm_err_number_typ     error,
    adm_err_file_typ       file,
    adm_err_line_typ       line,
    adm_err_rank_typ       rank,
    adm_err_problem_typ  * source,
    adm_base_integer_typ   identity,
    adm_err_problem_typ  * relation,
    adm_err_problem_typ  * target);


/* Initialisation Prototype */

void adm_initialisation(void);


/* Domain Initialisation Prototypes */

void adm_initialisation_elevator_management(void);


/* Enumeration Prototypes */

adm_enm_direction_typ adm_increment_enumeration_direction(
    adm_enm_direction_typ source_direction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

adm_enm_direction_typ adm_decrement_enumeration_direction(
    adm_enm_direction_typ source_direction,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* System Scheduler Prototypes */

void adm_scheduler(void);

void adm_scheduler_dom_elevator_management(void);


/* System Initialisation Scheduler Prototypes */

void adm_scheduler_initialisation(void);

void adm_scheduler_initialisation_elevator_management(void);


/* System Determine Termination Scheduler Prototypes */

adm_base_boolean_typ adm_scheduler_determine_termination(void);

adm_base_boolean_typ adm_scheduler_determine_termination_dom_elevator_management(void);


/* Data Access Prototypes */

adm_ent_floor_typ * adm_make_object_floor(
    adm_sta_floor_typ status);

adm_ent_door_typ * adm_make_object_door(
    adm_sta_door_typ status);

adm_ent_car_service_typ * adm_make_object_car_service(void);

adm_ent_car_stop_typ * adm_make_object_car_stop(
    adm_sta_car_stop_typ status);

adm_ent_service_assigner_typ * adm_make_object_service_assigner(
    adm_sta_service_assigner_typ status);

adm_ent_car_typ * adm_make_object_car(
    adm_sta_car_typ status);

void adm_bind_object_floor(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_door(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_car_service(
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_car_stop(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_service_assigner(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_bind_object_car(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_floor(
    void * source_object,
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_door(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_car_service(
    void * source_object,
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_car_stop(
    void * source_object,
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_service_assigner(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_object_car(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_floor_serviced_by_car_service(
    adm_ent_floor_typ * ent_source_floor,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_door_provides_passenger_access_to_car(
    adm_ent_door_typ * ent_source_door,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_service_services_floor(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_service_serviced_by_car(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_service_assigned_by_service_assigner(
    adm_ent_car_service_typ * ent_source_car_service,
    adm_ent_service_assigner_typ * ent_target_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_stop_directs_car(
    adm_ent_car_stop_typ * ent_source_car_stop,
    adm_ent_car_typ * ent_target_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_service_assigner_assigns_car_service(
    adm_ent_service_assigner_typ * ent_source_service_assigner,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_services_car_service(
    adm_ent_car_typ * ent_source_car,
    adm_ent_car_service_typ * ent_target_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_currently_at_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_accessed_through_door(
    adm_ent_car_typ * ent_source_car,
    adm_ent_door_typ * ent_target_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_scheduled_to_move_up_to_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_link_relation_car_scheduled_to_move_down_to_floor(
    adm_ent_car_typ * ent_source_car,
    adm_ent_floor_typ * ent_target_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_floor_serviced_by_car_service(
    adm_ent_floor_typ * ent_floor,
    adm_rel_floor_serviced_by_car_service_typ * rel_floor_serviced_by_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_door_provides_passenger_access_to_car(
    adm_ent_door_typ * ent_door,
    adm_rel_door_provides_passenger_access_to_car_typ * rel_door_provides_passenger_access_to_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_service_services_floor(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_services_floor_typ * rel_car_service_services_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_service_serviced_by_car(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_serviced_by_car_typ * rel_car_service_serviced_by_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_service_assigned_by_service_assigner(
    adm_ent_car_service_typ * ent_car_service,
    adm_rel_car_service_assigned_by_service_assigner_typ * rel_car_service_assigned_by_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_stop_directs_car(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_rel_car_stop_directs_car_typ * rel_car_stop_directs_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_service_assigner_assigns_car_service(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_rel_service_assigner_assigns_car_service_typ * rel_service_assigner_assigns_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_services_car_service(
    adm_ent_car_typ * ent_car,
    adm_rel_car_services_car_service_typ * rel_car_services_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_currently_at_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_currently_at_floor_typ * rel_car_currently_at_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_accessed_through_door(
    adm_ent_car_typ * ent_car,
    adm_rel_car_accessed_through_door_typ * rel_car_accessed_through_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_scheduled_to_move_up_to_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_scheduled_to_move_up_to_floor_typ * rel_car_scheduled_to_move_up_to_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_kill_relation_car_scheduled_to_move_down_to_floor(
    adm_ent_car_typ * ent_car,
    adm_rel_car_scheduled_to_move_down_to_floor_typ * rel_car_scheduled_to_move_down_to_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_floor(
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_door(
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_car_service(
    adm_ent_car_service_typ * ent_car_service,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_car_stop(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_service_assigner(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_object_existent_car(
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Event Sender Prototypes */

void adm_send_event_floor_request_service(
    void * source_object,
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_floor_service_called(
    void * source_object,
    adm_ent_floor_typ * ent_floor,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_open(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_close(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_obstruction(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_open_completed(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_close_completed(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_door_clear(
    void * source_object,
    adm_ent_door_typ * ent_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_stop_go_to_floor(
    void * source_object,
    adm_ent_car_stop_typ * ent_car_stop,
    adm_int_floor_typ evd_desired_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_service_assigner_assign_car(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_int_floor_typ evd_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_service_assigner_car_assigned(
    void * source_object,
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_service_requested(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_open_door(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_close_door(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_service_schedule(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_service_current_floor(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_moving(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_floor_approaching(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_int_floor_typ evd_next_floor_number,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_continue(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_stop_at_next_floor(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_car_stopped(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_door_open(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);

void adm_send_event_car_door_closed(
    void * source_object,
    adm_ent_car_typ * ent_car,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank);


/* Dispatcher Prototypes */

void adm_dispatcher_floor         (void);
void adm_dispatch_home_pool_floor (void);

adm_pool_target_floor_typ * adm_find_home_target_event_floor (void);
adm_pool_target_floor_typ * adm_find_away_target_event_floor (void);

void adm_dispatch_state_action_floor(
    adm_pool_target_floor_typ * pool_target_floor);

void adm_dispatcher_door         (void);
void adm_dispatch_home_pool_door (void);

adm_pool_target_door_typ * adm_find_home_target_event_door (void);
adm_pool_target_door_typ * adm_find_away_target_event_door (void);

void adm_dispatch_state_action_door(
    adm_pool_target_door_typ * pool_target_door);

void adm_dispatcher_car_stop         (void);
void adm_dispatch_home_pool_car_stop (void);

adm_pool_target_car_stop_typ * adm_find_home_target_event_car_stop (void);
adm_pool_target_car_stop_typ * adm_find_away_target_event_car_stop (void);

void adm_dispatch_state_action_car_stop(
    adm_pool_target_car_stop_typ * pool_target_car_stop);

void adm_dispatcher_service_assigner         (void);
void adm_dispatch_home_pool_service_assigner (void);

adm_pool_target_service_assigner_typ * adm_find_home_target_event_service_assigner (void);
adm_pool_target_service_assigner_typ * adm_find_away_target_event_service_assigner (void);

void adm_dispatch_state_action_service_assigner(
    adm_pool_target_service_assigner_typ * pool_target_service_assigner);

void adm_dispatcher_car         (void);
void adm_dispatch_home_pool_car (void);

adm_pool_target_car_typ * adm_find_home_target_event_car (void);
adm_pool_target_car_typ * adm_find_away_target_event_car (void);

void adm_dispatch_state_action_car(
    adm_pool_target_car_typ * pool_target_car);


/* State Action Prototypes */

void adm_state_action_floor_calling_service(
    adm_ent_floor_typ * ent_floor);

void adm_state_action_door_closed(
    adm_ent_door_typ * ent_door);

void adm_state_action_door_opening(
    adm_ent_door_typ * ent_door);

void adm_state_action_door_open(
    adm_ent_door_typ * ent_door);

void adm_state_action_door_closing(
    adm_ent_door_typ * ent_door);

void adm_state_action_car_stop_awaiting_floor(
    adm_ent_car_stop_typ * ent_car_stop,
    adm_dst_car_stop_await_typ * dst_await);

void adm_state_action_service_assigner_allocating_car(
    adm_ent_service_assigner_typ * ent_service_assigner,
    adm_dst_service_assigner_allocate_typ * dst_allocate);

void adm_state_action_car_stationary(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_selecting_schedule(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_servicing_schedule(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_checking_schedule(
    adm_ent_car_typ * ent_car,
    adm_dst_car_travel_typ * dst_travel);

void adm_state_action_car_slowing(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_opening(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_accessible(
    adm_ent_car_typ * ent_car);

void adm_state_action_car_closing(
    adm_ent_car_typ * ent_car);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */