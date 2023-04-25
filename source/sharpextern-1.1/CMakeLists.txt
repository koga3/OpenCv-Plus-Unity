cmake_minimum_required(VERSION 3.0)

# aux function to match regext case-insenitive (cmake doesn't support (i)')
function(TestLibraryPath path name)
	# local changes
	string(TOLOWER ${path} lopath)
	string(TOLOWER ${CMAKE_PREFIX_PATH} lochecker)

	IF (NOT "${lopath}" MATCHES "^${lochecker}")
		MESSAGE (FATAL_ERROR "*** '${name}' invalid install path = '${path}', should match '${CMAKE_PREFIX_PATH}'")
	ELSE()
		MESSAGE ("*** '${name}' install path = '${path}'")
	ENDIF ()
endfunction(TestLibraryPath)

IF(!EMSCRIPTEN)
	link_directories(${OpenCV_LIBRARY_DIR} ${OpenCV_LIBRARIES})
ENDIF()
IF(APPLE)
    # Fix linking on 10.14+. See https://stackoverflow.com/questions/54068035
    link_directories(/usr/local/lib)
ENDIF()

# define project
project(OpenCvSharpExtern)

# force static C++ runtime
if (BUILD_WITH_STATIC_CRT)
	include ("ucm.cmake")
	ucm_set_runtime("STATIC")
endif()


message("${CMAKE_PREFIX_PATH}")
set(OpenCV_DIR "${CMAKE_PREFIX_PATH}/sdk/native/jni")

# OpenCV is a bit specific: it has different output folders for Windows, Android and iOS/Mac, so we have to "hint" all three
find_package(OpenCV REQUIRED PATHS "${CMAKE_PREFIX_PATH}" "${CMAKE_PREFIX_PATH}/*/Shared/OpenCV" "${CMAKE_PREFIX_PATH}/*/sdk/native/jni" NO_DEFAULT_PATH )
TestLibraryPath(${OpenCV_INSTALL_PATH} "OpenCV")

# SOURCE FILES
set(OPENCVSHARP_FILES 
	core.cpp
	imgproc.cpp
	std_vector.cpp
	utils.cpp
)

if(OpenCV_FOUND)
	include_directories(${OpenCV_INCLUDE_DIRS})
	#set(LIBS ${LIBS} ${OpenCV_LIBRARIES})

	if(CMAKE_GENERATOR MATCHES "Visual Studio")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
		set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
		
		set(CMAKE_CXX_STANDARD_LIBRARIES "${CMAKE_CXX_STANDARD_LIBRARIES} kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib")
	endif()


	# iOS - Unity expects static library
	if (IPHONEOS)
		add_library(OpenCvSharpExtern STATIC ${OPENCVSHARP_FILES})
	# Windows, Android - just regular dynamic library for the target
	# macOS - shared library will became .bundle
	else()
		add_library(OpenCvSharpExtern SHARED ${OPENCVSHARP_FILES})
	endif()


	# OUTPUT FOLDER(s)
	install(TARGETS OpenCvSharpExtern
			RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
			LIBRARY DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
			ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib"
	)
	target_link_libraries(OpenCvSharpExtern ${OpenCV_LIBS})

	if (CMAKE_WRAPPER_TRIAL_VERSION)
		target_compile_definitions(OpenCvSharpExtern PRIVATE OPENCV_SHARP_TRIAL)
	endif()
endif(OpenCV_FOUND)
