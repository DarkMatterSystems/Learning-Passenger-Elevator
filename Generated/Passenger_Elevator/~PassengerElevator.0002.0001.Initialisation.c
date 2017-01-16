
#include "~PassengerElevator.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_elevator_management(
    void)
{
    /* Declare Objects */

    /* Floor */
    adm_ent_floor_typ * ent_floor_0000000001;
    adm_ent_floor_typ * ent_floor_0000000002;
    adm_ent_floor_typ * ent_floor_0000000003;
    adm_ent_floor_typ * ent_floor_0000000004;
    adm_ent_floor_typ * ent_floor_0000000005;
    adm_ent_floor_typ * ent_floor_0000000006;
    adm_ent_floor_typ * ent_floor_0000000007;

    /* Door */
    adm_ent_door_typ * ent_door_0000000008;
    adm_ent_door_typ * ent_door_0000000009;
    adm_ent_door_typ * ent_door_0000000010;

    /* Car Service */
    adm_ent_car_service_typ * ent_car_service_0000000011;
    adm_ent_car_service_typ * ent_car_service_0000000012;
    adm_ent_car_service_typ * ent_car_service_0000000013;
    adm_ent_car_service_typ * ent_car_service_0000000014;
    adm_ent_car_service_typ * ent_car_service_0000000015;
    adm_ent_car_service_typ * ent_car_service_0000000016;
    adm_ent_car_service_typ * ent_car_service_0000000017;
    adm_ent_car_service_typ * ent_car_service_0000000018;
    adm_ent_car_service_typ * ent_car_service_0000000019;
    adm_ent_car_service_typ * ent_car_service_0000000020;
    adm_ent_car_service_typ * ent_car_service_0000000021;
    adm_ent_car_service_typ * ent_car_service_0000000022;
    adm_ent_car_service_typ * ent_car_service_0000000023;
    adm_ent_car_service_typ * ent_car_service_0000000024;
    adm_ent_car_service_typ * ent_car_service_0000000025;
    adm_ent_car_service_typ * ent_car_service_0000000026;
    adm_ent_car_service_typ * ent_car_service_0000000027;
    adm_ent_car_service_typ * ent_car_service_0000000028;
    adm_ent_car_service_typ * ent_car_service_0000000029;
    adm_ent_car_service_typ * ent_car_service_0000000030;
    adm_ent_car_service_typ * ent_car_service_0000000031;

    /* Car Stop */
    adm_ent_car_stop_typ * ent_car_stop_0000000032;
    adm_ent_car_stop_typ * ent_car_stop_0000000033;
    adm_ent_car_stop_typ * ent_car_stop_0000000034;

    /* Service Assigner */
    adm_ent_service_assigner_typ * ent_service_assigner_0000000035;

    /* Car */
    adm_ent_car_typ * ent_car_0000000036;
    adm_ent_car_typ * ent_car_0000000037;
    adm_ent_car_typ * ent_car_0000000038;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_elevator_management");
    #endif

    /* Entity System */

    adm_entity_system.ent_floor.tote = 0;
    adm_entity_system.ent_door.tote = 0;
    adm_entity_system.ent_car_service.tote = 0;
    adm_entity_system.ent_car_stop.tote = 0;
    adm_entity_system.ent_service_assigner.tote = 0;
    adm_entity_system.ent_car.tote = 0;

    adm_entity_system.ent_floor.live_list_head = NULL;
    adm_entity_system.ent_door.live_list_head = NULL;
    adm_entity_system.ent_car_service.live_list_head = NULL;
    adm_entity_system.ent_car_stop.live_list_head = NULL;
    adm_entity_system.ent_service_assigner.live_list_head = NULL;
    adm_entity_system.ent_car.live_list_head = NULL;

    adm_entity_system.ent_floor.live_list_tail = NULL;
    adm_entity_system.ent_door.live_list_tail = NULL;
    adm_entity_system.ent_car_service.live_list_tail = NULL;
    adm_entity_system.ent_car_stop.live_list_tail = NULL;
    adm_entity_system.ent_service_assigner.live_list_tail = NULL;
    adm_entity_system.ent_car.live_list_tail = NULL;

    adm_entity_system.ent_floor.dead_list_head = NULL;
    adm_entity_system.ent_door.dead_list_head = NULL;
    adm_entity_system.ent_car_service.dead_list_head = NULL;
    adm_entity_system.ent_car_stop.dead_list_head = NULL;
    adm_entity_system.ent_service_assigner.dead_list_head = NULL;
    adm_entity_system.ent_car.dead_list_head = NULL;

    adm_entity_system.ent_floor.dead_list_tail = NULL;
    adm_entity_system.ent_door.dead_list_tail = NULL;
    adm_entity_system.ent_car_service.dead_list_tail = NULL;
    adm_entity_system.ent_car_stop.dead_list_tail = NULL;
    adm_entity_system.ent_service_assigner.dead_list_tail = NULL;
    adm_entity_system.ent_car.dead_list_tail = NULL;

    adm_entity_system.ent_floor.home_pool_head = NULL;
    adm_entity_system.ent_door.home_pool_head = NULL;
    adm_entity_system.ent_car_stop.home_pool_head = NULL;
    adm_entity_system.ent_service_assigner.home_pool_head = NULL;
    adm_entity_system.ent_car.home_pool_head = NULL;

    adm_entity_system.ent_floor.home_pool_tail = NULL;
    adm_entity_system.ent_door.home_pool_tail = NULL;
    adm_entity_system.ent_car_stop.home_pool_tail = NULL;
    adm_entity_system.ent_service_assigner.home_pool_tail = NULL;
    adm_entity_system.ent_car.home_pool_tail = NULL;

    adm_entity_system.ent_floor.away_pool_head = NULL;
    adm_entity_system.ent_door.away_pool_head = NULL;
    adm_entity_system.ent_car_stop.away_pool_head = NULL;
    adm_entity_system.ent_service_assigner.away_pool_head = NULL;
    adm_entity_system.ent_car.away_pool_head = NULL;

    adm_entity_system.ent_floor.away_pool_tail = NULL;
    adm_entity_system.ent_door.away_pool_tail = NULL;
    adm_entity_system.ent_car_stop.away_pool_tail = NULL;
    adm_entity_system.ent_service_assigner.away_pool_tail = NULL;
    adm_entity_system.ent_car.away_pool_tail = NULL;


    /* Make Objects */

    /* Floor */
    ent_floor_0000000001 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000002 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000003 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000004 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000005 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000006 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);
    ent_floor_0000000007 = adm_make_object_floor(ADM_STATUS_FLOOR_IDLE);

    /* Door */
    ent_door_0000000008 = adm_make_object_door(ADM_STATUS_DOOR_CLOSED);
    ent_door_0000000009 = adm_make_object_door(ADM_STATUS_DOOR_CLOSED);
    ent_door_0000000010 = adm_make_object_door(ADM_STATUS_DOOR_CLOSED);

    /* Car Service */
    ent_car_service_0000000011 = adm_make_object_car_service();
    ent_car_service_0000000012 = adm_make_object_car_service();
    ent_car_service_0000000013 = adm_make_object_car_service();
    ent_car_service_0000000014 = adm_make_object_car_service();
    ent_car_service_0000000015 = adm_make_object_car_service();
    ent_car_service_0000000016 = adm_make_object_car_service();
    ent_car_service_0000000017 = adm_make_object_car_service();
    ent_car_service_0000000018 = adm_make_object_car_service();
    ent_car_service_0000000019 = adm_make_object_car_service();
    ent_car_service_0000000020 = adm_make_object_car_service();
    ent_car_service_0000000021 = adm_make_object_car_service();
    ent_car_service_0000000022 = adm_make_object_car_service();
    ent_car_service_0000000023 = adm_make_object_car_service();
    ent_car_service_0000000024 = adm_make_object_car_service();
    ent_car_service_0000000025 = adm_make_object_car_service();
    ent_car_service_0000000026 = adm_make_object_car_service();
    ent_car_service_0000000027 = adm_make_object_car_service();
    ent_car_service_0000000028 = adm_make_object_car_service();
    ent_car_service_0000000029 = adm_make_object_car_service();
    ent_car_service_0000000030 = adm_make_object_car_service();
    ent_car_service_0000000031 = adm_make_object_car_service();

    /* Car Stop */
    ent_car_stop_0000000032 = adm_make_object_car_stop(ADM_STATUS_CAR_STOP_AWAITING_FLOOR);
    ent_car_stop_0000000033 = adm_make_object_car_stop(ADM_STATUS_CAR_STOP_AWAITING_FLOOR);
    ent_car_stop_0000000034 = adm_make_object_car_stop(ADM_STATUS_CAR_STOP_AWAITING_FLOOR);

    /* Service Assigner */
    ent_service_assigner_0000000035 = adm_make_object_service_assigner(ADM_STATUS_SERVICE_ASSIGNER_IDLE);

    /* Car */
    ent_car_0000000036 = adm_make_object_car(ADM_STATUS_CAR_STATIONARY);
    ent_car_0000000037 = adm_make_object_car(ADM_STATUS_CAR_STATIONARY);
    ent_car_0000000038 = adm_make_object_car(ADM_STATUS_CAR_STATIONARY);


    /* Object Fact Assignments */

    /* Floor */

    ent_floor_0000000001->atb_number = 1;

    ent_floor_0000000002->atb_number = 2;

    ent_floor_0000000003->atb_number = 3;

    ent_floor_0000000004->atb_number = 4;

    ent_floor_0000000005->atb_number = 5;

    ent_floor_0000000006->atb_number = 6;

    ent_floor_0000000007->atb_number = 7;

    /* Car */

    ent_car_0000000036->atb_direction = ADM_LITERAL_DIRECTION_UP;

    ent_car_0000000037->atb_direction = ADM_LITERAL_DIRECTION_UP;

    ent_car_0000000038->atb_direction = ADM_LITERAL_DIRECTION_UP;


    /* Bind Objects */

    /* Floor */
    adm_bind_object_floor(
        ent_floor_0000000001,
        1, 1051, 29);
    adm_bind_object_floor(
        ent_floor_0000000002,
        1, 1052, 29);
    adm_bind_object_floor(
        ent_floor_0000000003,
        1, 1053, 29);
    adm_bind_object_floor(
        ent_floor_0000000004,
        1, 1054, 29);
    adm_bind_object_floor(
        ent_floor_0000000005,
        1, 1055, 29);
    adm_bind_object_floor(
        ent_floor_0000000006,
        1, 1056, 29);
    adm_bind_object_floor(
        ent_floor_0000000007,
        1, 1057, 29);

    /* Door */
    adm_bind_object_door(
        ent_door_0000000008,
        1, 1084, 29);
    adm_bind_object_door(
        ent_door_0000000009,
        1, 1085, 29);
    adm_bind_object_door(
        ent_door_0000000010,
        1, 1086, 29);

    /* Car Service */
    adm_bind_object_car_service(
        ent_car_service_0000000011,
        1, 1095, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000012,
        1, 1096, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000013,
        1, 1097, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000014,
        1, 1098, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000015,
        1, 1099, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000016,
        1, 1100, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000017,
        1, 1101, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000018,
        1, 1102, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000019,
        1, 1103, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000020,
        1, 1104, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000021,
        1, 1105, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000022,
        1, 1106, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000023,
        1, 1107, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000024,
        1, 1108, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000025,
        1, 1109, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000026,
        1, 1110, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000027,
        1, 1111, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000028,
        1, 1112, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000029,
        1, 1113, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000030,
        1, 1114, 29);
    adm_bind_object_car_service(
        ent_car_service_0000000031,
        1, 1115, 29);

    /* Car Stop */
    adm_bind_object_car_stop(
        ent_car_stop_0000000032,
        1, 1186, 29);
    adm_bind_object_car_stop(
        ent_car_stop_0000000033,
        1, 1187, 29);
    adm_bind_object_car_stop(
        ent_car_stop_0000000034,
        1, 1188, 29);

    /* Service Assigner */
    adm_bind_object_service_assigner(
        ent_service_assigner_0000000035,
        1, 1197, 29);

    /* Car */
    adm_bind_object_car(
        ent_car_0000000036,
        1, 1224, 29);
    adm_bind_object_car(
        ent_car_0000000037,
        1, 1225, 29);
    adm_bind_object_car(
        ent_car_0000000038,
        1, 1226, 29);


    /* Link Relations */

    /* Floor */

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000001,
        ent_car_service_0000000011,
        1, 1059, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000001,
        ent_car_service_0000000018,
        1, 1060, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000001,
        ent_car_service_0000000025,
        1, 1061, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000002,
        ent_car_service_0000000012,
        1, 1062, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000002,
        ent_car_service_0000000019,
        1, 1063, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000002,
        ent_car_service_0000000026,
        1, 1064, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000003,
        ent_car_service_0000000013,
        1, 1065, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000003,
        ent_car_service_0000000020,
        1, 1066, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000003,
        ent_car_service_0000000027,
        1, 1067, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000004,
        ent_car_service_0000000014,
        1, 1068, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000004,
        ent_car_service_0000000021,
        1, 1069, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000004,
        ent_car_service_0000000028,
        1, 1070, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000005,
        ent_car_service_0000000015,
        1, 1071, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000005,
        ent_car_service_0000000022,
        1, 1072, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000005,
        ent_car_service_0000000029,
        1, 1073, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000006,
        ent_car_service_0000000016,
        1, 1074, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000006,
        ent_car_service_0000000023,
        1, 1075, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000006,
        ent_car_service_0000000030,
        1, 1076, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000007,
        ent_car_service_0000000017,
        1, 1077, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000007,
        ent_car_service_0000000024,
        1, 1078, 29);

    adm_link_relation_floor_serviced_by_car_service(
        ent_floor_0000000007,
        ent_car_service_0000000031,
        1, 1079, 29);

    /* Door */

    adm_link_relation_door_provides_passenger_access_to_car(
        ent_door_0000000008,
        ent_car_0000000036,
        1, 1088, 29);

    adm_link_relation_door_provides_passenger_access_to_car(
        ent_door_0000000009,
        ent_car_0000000037,
        1, 1089, 29);

    adm_link_relation_door_provides_passenger_access_to_car(
        ent_door_0000000010,
        ent_car_0000000038,
        1, 1090, 29);

    /* Car Service */

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000011,
        ent_floor_0000000001,
        1, 1139, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000012,
        ent_floor_0000000002,
        1, 1140, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000013,
        ent_floor_0000000003,
        1, 1141, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000014,
        ent_floor_0000000004,
        1, 1142, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000015,
        ent_floor_0000000005,
        1, 1143, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000016,
        ent_floor_0000000006,
        1, 1144, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000017,
        ent_floor_0000000007,
        1, 1145, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000018,
        ent_floor_0000000001,
        1, 1146, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000019,
        ent_floor_0000000002,
        1, 1147, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000020,
        ent_floor_0000000003,
        1, 1148, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000021,
        ent_floor_0000000004,
        1, 1149, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000022,
        ent_floor_0000000005,
        1, 1150, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000023,
        ent_floor_0000000006,
        1, 1151, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000024,
        ent_floor_0000000007,
        1, 1152, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000025,
        ent_floor_0000000001,
        1, 1153, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000026,
        ent_floor_0000000002,
        1, 1154, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000027,
        ent_floor_0000000003,
        1, 1155, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000028,
        ent_floor_0000000004,
        1, 1156, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000029,
        ent_floor_0000000005,
        1, 1157, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000030,
        ent_floor_0000000006,
        1, 1158, 29);

    adm_link_relation_car_service_services_floor(
        ent_car_service_0000000031,
        ent_floor_0000000007,
        1, 1159, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000011,
        ent_car_0000000036,
        1, 1117, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000012,
        ent_car_0000000036,
        1, 1118, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000013,
        ent_car_0000000036,
        1, 1119, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000014,
        ent_car_0000000036,
        1, 1120, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000015,
        ent_car_0000000036,
        1, 1121, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000016,
        ent_car_0000000036,
        1, 1122, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000017,
        ent_car_0000000036,
        1, 1123, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000018,
        ent_car_0000000037,
        1, 1124, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000019,
        ent_car_0000000037,
        1, 1125, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000020,
        ent_car_0000000037,
        1, 1126, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000021,
        ent_car_0000000037,
        1, 1127, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000022,
        ent_car_0000000037,
        1, 1128, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000023,
        ent_car_0000000037,
        1, 1129, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000024,
        ent_car_0000000037,
        1, 1130, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000025,
        ent_car_0000000038,
        1, 1131, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000026,
        ent_car_0000000038,
        1, 1132, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000027,
        ent_car_0000000038,
        1, 1133, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000028,
        ent_car_0000000038,
        1, 1134, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000029,
        ent_car_0000000038,
        1, 1135, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000030,
        ent_car_0000000038,
        1, 1136, 29);

    adm_link_relation_car_service_serviced_by_car(
        ent_car_service_0000000031,
        ent_car_0000000038,
        1, 1137, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000011,
        ent_service_assigner_0000000035,
        1, 1161, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000012,
        ent_service_assigner_0000000035,
        1, 1162, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000013,
        ent_service_assigner_0000000035,
        1, 1163, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000014,
        ent_service_assigner_0000000035,
        1, 1164, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000015,
        ent_service_assigner_0000000035,
        1, 1165, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000016,
        ent_service_assigner_0000000035,
        1, 1166, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000017,
        ent_service_assigner_0000000035,
        1, 1167, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000018,
        ent_service_assigner_0000000035,
        1, 1168, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000019,
        ent_service_assigner_0000000035,
        1, 1169, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000020,
        ent_service_assigner_0000000035,
        1, 1170, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000021,
        ent_service_assigner_0000000035,
        1, 1171, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000022,
        ent_service_assigner_0000000035,
        1, 1172, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000023,
        ent_service_assigner_0000000035,
        1, 1173, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000024,
        ent_service_assigner_0000000035,
        1, 1174, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000025,
        ent_service_assigner_0000000035,
        1, 1175, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000026,
        ent_service_assigner_0000000035,
        1, 1176, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000027,
        ent_service_assigner_0000000035,
        1, 1177, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000028,
        ent_service_assigner_0000000035,
        1, 1178, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000029,
        ent_service_assigner_0000000035,
        1, 1179, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000030,
        ent_service_assigner_0000000035,
        1, 1180, 29);

    adm_link_relation_car_service_assigned_by_service_assigner(
        ent_car_service_0000000031,
        ent_service_assigner_0000000035,
        1, 1181, 29);

    /* Car Stop */

    adm_link_relation_car_stop_directs_car(
        ent_car_stop_0000000032,
        ent_car_0000000036,
        1, 1190, 29);

    adm_link_relation_car_stop_directs_car(
        ent_car_stop_0000000033,
        ent_car_0000000037,
        1, 1191, 29);

    adm_link_relation_car_stop_directs_car(
        ent_car_stop_0000000034,
        ent_car_0000000038,
        1, 1192, 29);

    /* Service Assigner */

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000011,
        1, 1199, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000012,
        1, 1200, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000013,
        1, 1201, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000014,
        1, 1202, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000015,
        1, 1203, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000016,
        1, 1204, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000017,
        1, 1205, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000018,
        1, 1206, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000019,
        1, 1207, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000020,
        1, 1208, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000021,
        1, 1209, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000022,
        1, 1210, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000023,
        1, 1211, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000024,
        1, 1212, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000025,
        1, 1213, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000026,
        1, 1214, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000027,
        1, 1215, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000028,
        1, 1216, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000029,
        1, 1217, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000030,
        1, 1218, 29);

    adm_link_relation_service_assigner_assigns_car_service(
        ent_service_assigner_0000000035,
        ent_car_service_0000000031,
        1, 1219, 29);

    /* Car */

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000011,
        1, 1228, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000012,
        1, 1229, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000013,
        1, 1230, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000014,
        1, 1231, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000015,
        1, 1232, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000016,
        1, 1233, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000036,
        ent_car_service_0000000017,
        1, 1234, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000018,
        1, 1235, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000019,
        1, 1236, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000020,
        1, 1237, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000021,
        1, 1238, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000022,
        1, 1239, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000023,
        1, 1240, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000037,
        ent_car_service_0000000024,
        1, 1241, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000025,
        1, 1242, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000026,
        1, 1243, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000027,
        1, 1244, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000028,
        1, 1245, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000029,
        1, 1246, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000030,
        1, 1247, 29);

    adm_link_relation_car_services_car_service(
        ent_car_0000000038,
        ent_car_service_0000000031,
        1, 1248, 29);

    adm_link_relation_car_currently_at_floor(
        ent_car_0000000036,
        ent_floor_0000000001,
        1, 1250, 29);

    adm_link_relation_car_currently_at_floor(
        ent_car_0000000037,
        ent_floor_0000000001,
        1, 1251, 29);

    adm_link_relation_car_currently_at_floor(
        ent_car_0000000038,
        ent_floor_0000000001,
        1, 1252, 29);

    adm_link_relation_car_accessed_through_door(
        ent_car_0000000036,
        ent_door_0000000008,
        1, 1254, 29);

    adm_link_relation_car_accessed_through_door(
        ent_car_0000000037,
        ent_door_0000000009,
        1, 1255, 29);

    adm_link_relation_car_accessed_through_door(
        ent_car_0000000038,
        ent_door_0000000010,
        1, 1256, 29);


    /* Integrity Check */
    adm_integrity_check();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_elevator_management");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */