add_compile_definitions(${PRESET_DEFINE_MACRO})

cmake_minimum_required(VERSION 3.10)
project("LetoAPI")

file(
	GLOB C_SOURCES 
	"src/*/*/*.c" 
	"src/*/*.c" 
	"src/*.c"
)
include_directories("include")

if (${PRESET_DEFINE_MACRO} STREQUAL "__STM32__")
	project("LetoAPI" C CXX ASM)

	add_library(${PROJECT_NAME} STATIC ${C_SOURCES})

	target_compile_definitions(${PROJECT_NAME} PRIVATE
		USE_HAL_DRIVER
		${MCU_CHIP}
	)
	
	# ------------------------------------------------------------------------------
	# Настройки архитектуры из .cproject (STM32F401CCUx)
	# ------------------------------------------------------------------------------
	set(OBJECT_GEN_FLAGS "-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb")
	set(COMPILER_FLAGS "-Os -ffunction-sections -fdata-sections -Wall -fstack-usage")
	# -fcyclomatic-complexity - Используется только в STM32CubeIDE

	# Флаги компиляции для C / C++ / ASM
	set(CMAKE_C_FLAGS   "${OBJECT_GEN_FLAGS} ${COMPILER_FLAGS}" CACHE INTERNAL "C Compiler Flags")
	set(CMAKE_CXX_FLAGS "${OBJECT_GEN_FLAGS} ${COMPILER_FLAGS} -fno-exceptions -fno-rtti -fno-use-cxa-atexit" CACHE INTERNAL "C++ Compiler Flags")
	set(CMAKE_ASM_FLAGS "${OBJECT_GEN_FLAGS} -x assembler-with-cpp" CACHE INTERNAL "ASM Compiler Flags")

	#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections --specs=nano.specs --specs=nosys.specs -mthumb -mabi=aapcs -Wl,-Map=${CMAKE_PROJECT_NAME}.map" CACHE INTERNAL "Linker options")

elseif (${PRESET_DEFINE_MACRO} STREQUAL "__WIN__")

	add_library(${PROJECT_NAME} SHARED ${C_SOURCES})

	# Включаем предупреждения только для вашей цели
	target_compile_options(${PROJECT_NAME} PRIVATE
		$<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wunused>
		$<$<CXX_COMPILER_ID:MSVC>:/W4 /wd4251>
	)

elseif (${PRESET_DEFINE_MACRO} STREQUAL "__LINUX__")

	# find_package(Qt6 COMPONENTS Widgets REQUIRED Core)
	# qt_standard_project_setup()
	# add_executable (${PROJECT_NAME} "Main/App.cpp" ${C_SOURCES})
	# target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

elseif (${PRESET_DEFINE_MACRO} STREQUAL "__TERMUX__")

	# add_library(${PROJECT_NAME} SHARED ${C_SOURCES})
	# set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)
# 
	# target_link_libraries(${PROJECT_NAME} PRIVATE httplib::httplib)
	# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

endif ()

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin     # Для исполняемых файлов
    ARCHIVE DESTINATION lib     # Для статических библиотек
    LIBRARY DESTINATION lib     # Для динамических библиотек
)

target_compile_definitions(${PROJECT_NAME} PRIVATE LETOAPI_EXPORT_LIBRARY)
