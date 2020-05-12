if(ANDROID)
    include(${CMAKE_CURRENT_LIST_DIR}/../tools/qt-android-cmake/AddQtAndroidApk.cmake)
endif()

function(add_imgui_app)
    set(args ${ARGN})
    list(GET args 0 app_name)
    list(SUBLIST args 1 -1 app_sources)
    message("add_imgui_app app_name=${app_name} sources=${app_sources}")

    if (ANDROID)
        add_library(${app_name} SHARED ${app_sources})
    else()
        add_executable(${app_name} ${app_sources})
    endif()

    if(ANDROID)
        add_qt_android_apk(${app_name}_apk ${app_name})
    endif()

    target_link_libraries(${app_name} PRIVATE qt_imgui_quick)
endfunction()
