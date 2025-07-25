// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from roomie_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

#include "roomie_msgs/msg/detail/robot_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_roomie_msgs
const rosidl_type_hash_t *
roomie_msgs__msg__RobotState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xaf, 0xd5, 0xf5, 0x46, 0xc8, 0xfb, 0xa1, 0x04,
      0x0a, 0xd1, 0x5a, 0xe5, 0xbc, 0xef, 0x09, 0x0a,
      0xa0, 0x3a, 0x22, 0x6e, 0x2c, 0x77, 0xb4, 0xe2,
      0x84, 0xa0, 0x27, 0x0f, 0xa7, 0x69, 0x9f, 0xee,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char roomie_msgs__msg__RobotState__TYPE_NAME[] = "roomie_msgs/msg/RobotState";

// Define type names, field names, and default values
static char roomie_msgs__msg__RobotState__FIELD_NAME__robot_id[] = "robot_id";
static char roomie_msgs__msg__RobotState__FIELD_NAME__robot_state_id[] = "robot_state_id";

static rosidl_runtime_c__type_description__Field roomie_msgs__msg__RobotState__FIELDS[] = {
  {
    {roomie_msgs__msg__RobotState__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {roomie_msgs__msg__RobotState__FIELD_NAME__robot_state_id, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
roomie_msgs__msg__RobotState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {roomie_msgs__msg__RobotState__TYPE_NAME, 26, 26},
      {roomie_msgs__msg__RobotState__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# RobotState.msg\n"
  "int32 robot_id\n"
  "int32 robot_state_id\n"
  "# int32 task_id\n"
  "\n"
  "# robot_state_id values:\n"
  "# 0: \\xec\\x9e\\x91\\xec\\x97\\x85 \\xeb\\xb6\\x88\\xea\\xb0\\x80\\xeb\\x8a\\xa5\n"
  "# 1: \\xec\\x9e\\x91\\xec\\x97\\x85 \\xea\\xb0\\x80\\xeb\\x8a\\xa5\n"
  "# 2: \\xec\\x9e\\x91\\xec\\x97\\x85 \\xec\\x9e\\x85\\xeb\\xa0\\xa5 \\xec\\xa4\\x91\n"
  "# 3: \\xec\\x9e\\x91\\xec\\x97\\x85 \\xec\\x88\\x98\\xed\\x96\\x89 \\xec\\xa4\\x91\n"
  "# 4: \\xeb\\xb3\\xb5\\xea\\xb7\\x80 \\xeb\\x8c\\x80\\xea\\xb8\\xb0 \\xec\\xa4\\x91\n"
  "# 5: \\xeb\\xb3\\xb5\\xea\\xb7\\x80 \\xec\\xa4\\x91\n"
  "# 6: \\xec\\x9e\\x91\\xec\\x97\\x85 \\xec\\x8b\\xa4\\xed\\x8c\\xa8\n"
  "# 7: \\xec\\x8b\\x9c\\xec\\x8a\\xa4\\xed\\x85\\x9c \\xec\\x98\\xa4\\xeb\\xa5\\x98 ";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
roomie_msgs__msg__RobotState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {roomie_msgs__msg__RobotState__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 190, 190},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
roomie_msgs__msg__RobotState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *roomie_msgs__msg__RobotState__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
