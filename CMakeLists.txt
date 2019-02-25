cmake_minimum_required(VERSION 3.5)

project(timeSynchronization VERSION 0.0.1.0 LANGUAGES CXX)

#[[ Only include Ctest if user set BUILD_TESTING:BOOL=ON. ]]
if(BUILD_TESTING)
    include(CTest)
endif (BUILD_TESTING)

#[[ Create inteface library. ]]
add_library(timeSynchronization INTERFACE)

target_include_directories(timeSynchronization INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

install(DIRECTORY include/timeSynchronization
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

install(TARGETS timeSynchronization EXPORT ${PROJECT_NAME}Targets COMPONENT development
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        INCLUDES DESTINATION include)

if(BUILD_TESTING)
    add_subdirectory(test)
endif (BUILD_TESTING)

#[[ Include cmake-default tools to help create export files. Every thing below this line is usually unchanged
    across projects except for the namespace in the install(EXPORT ...) command. ]]
include(CMakePackageConfigHelpers)

#[[ Install ${CMAKE_INSTALL_PREFIX}/lib/cmake/<project>/<project>Targets.cmake for other
    projects to include the installation tree. ]]
install(EXPORT ${PROJECT_NAME}Targets NAMESPACE TimeSynchronization::
        FILE ${PROJECT_NAME}Targets.cmake
        DESTINATION lib/cmake/${PROJECT_NAME})

#[[ Generate a configuration and install it. ]]
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake
        COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/cmake/${PROJECT_NAME})

#[[ Configure and install <project>Config.cmake.in to enable other projects find this project from
    the install tree. Even though the function configure_package_config_file takes the INSTALL_DESTINATION, it
    doesn't actually create a installation step. So, to install the generated config file, we
    are required to manually create a install step. ]]
configure_package_config_file(
        cmake/${PROJECT_NAME}Config.cmake.in cmake/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION lib/cmake/${PROJECT_NAME})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}Config.cmake
        DESTINATION lib/cmake/${PROJECT_NAME})