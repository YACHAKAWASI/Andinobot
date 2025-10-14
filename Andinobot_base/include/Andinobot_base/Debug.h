#pragma once
#include <rclcpp/rclcpp.hpp>

// Compila el cuerpo sólo si quieres forzar silencios en release
#ifndef USE_DEBUG
  #define USE_DEBUG 1
#endif

// Saca el logger por nodo o por nombre genérico si no tienes "this"
#define GET_LOGGER() (rclcpp::get_logger("Andinobot_base"))

#if USE_DEBUG
  // Macros con nivel ROS 2
  #define LOG_DEBUG(...)   RCLCPP_DEBUG(GET_LOGGER(), __VA_ARGS__)
  #define LOG_INFO(...)    RCLCPP_INFO(GET_LOGGER(), __VA_ARGS__)
  #define LOG_WARN(...)    RCLCPP_WARN(GET_LOGGER(), __VA_ARGS__)
  #define LOG_ERROR(...)   RCLCPP_ERROR(GET_LOGGER(), __VA_ARGS__)
  #define LOG_FATAL(...)   RCLCPP_FATAL(GET_LOGGER(), __VA_ARGS__)
#else
  // En release, elimínalas del binario
  #define LOG_DEBUG(...)   do {} while (0)
  #define LOG_INFO(...)    do {} while (0)
  #define LOG_WARN(...)    do {} while (0)
  #define LOG_ERROR(...)   do {} while (0)
  #define LOG_FATAL(...)   do {} while (0)
#endif
