cmake_minimum_required(VERSION 3.5)
project(Nerve)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(Include)

add_library(Nerve
            Source/al/Nerve/NerveExecutor.cpp
            Source/al/Nerve/NerveKeeper.cpp
            Source/al/Nerve/NerveStateBase.cpp
            Source/al/Nerve/NerveStateCtrl.cpp
            Source/al/Nerve/NerveUtil.cpp
            )
