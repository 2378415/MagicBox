cmake_minimum_required(VERSION 3.22.1)
project(mbpre CXX)

add_library(mbpre SHARED letterbox.cpp postprocess.cpp)

# The app builds the Debug variant, where AGP's default is -O0. The letterbox loop is the
# hottest CPU code in the pipeline, so force optimisation regardless of the variant.
target_compile_options(mbpre PRIVATE -O3 -ffast-math -funroll-loops -fno-exceptions -fno-rtti)

find_library(log-lib log)
target_link_libraries(mbpre ${log-lib})

set_target_properties(mbpre PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)
