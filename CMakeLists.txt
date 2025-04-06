cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("CMakeProjectRacingSimulator")


#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
#add_library(Transport SHARED )

add_executable(CMakeProjectRacingSimulator 
    "Transport.h" 
    "Transport.cpp" 
    "GameRules.h" 
    "GameRules.cpp" 
    "Air.h" 
    "Lend.h"    
    "Lend.cpp" 
    "Air.cpp" 
    "TypeGame.h" 
    "StringInt.h" 
    "IntInt.h" 
    "CMakeProjectRacingSimulator.cpp"
    "MacroInput.h"
    "Print.h"
    "Print.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProjectRacingSimulator PROPERTY CXX_STANDARD 20)
endif()

#target_link_libraries(CMakeProjectRacingSimulatorAndDll PRIVATE Transport)