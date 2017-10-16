FUNCTION(GroupSources mainDirectory currentDirectory)
	
	FILE(GLOB children RELATIVE ${mainDirectory}/${currentDirectory} ${mainDirectory}/${currentDirectory}/*)
	
	FOREACH(child ${children})

		IF(IS_DIRECTORY ${mainDirectory}/${currentDirectory}/${child})
			
			GroupSources(${mainDirectory} ${currentDirectory}/${child})
			
		ELSE(IS_DIRECTORY ${mainDirectory}/${currentDirectory}/${child})
			
			STRING(REPLACE "/" "\\" groupname ${currentDirectory})
			
			# src root folder in a different name, only visual studio (not mandatory)
			#STRING(REPLACE "src" "MarlinSource" groupname ${groupname})
			
			SOURCE_GROUP(${groupname} FILES ${mainDirectory}/${currentDirectory}/${child})
						
		ENDIF(IS_DIRECTORY ${mainDirectory}/${currentDirectory}/${child})
	
	ENDFOREACH(child)

ENDFUNCTION(GroupSources)


FUNCTION(GroupTests currentDirectory)
	
	SET(ROOT_DIRECTORY ${MARLIN_MAIN_DIRECTORY}/test/ut)
	
	IF(${currentDirectory} MATCHES "Stream")
		SET (ROOT_DIRECTORY ${ROOT_DIRECTORY}/Util/Stream)
	ENDIF( ${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	
	FILE(GLOB children RELATIVE ${ROOT_DIRECTORY}/${currentDirectory} ${ROOT_DIRECTORY}/${currentDirectory}/*)
	
	FOREACH(child ${children})

		IF(IS_DIRECTORY ${ROOT_DIRECTORY}/${currentDirectory}/${child})
			
			GroupTests(${currentDirectory}/${child})
			
		ELSE(IS_DIRECTORY ${ROOT_DIRECTORY}/${currentDirectory}/${child})
			
			STRING(REPLACE "/" "\\" groupname ${currentDirectory})

			SOURCE_GROUP(${groupname} FILES ${ROOT_DIRECTORY}/${currentDirectory}/${child})
						
		ENDIF(IS_DIRECTORY ${ROOT_DIRECTORY}/${currentDirectory}/${child})
	
	ENDFOREACH(child)

ENDFUNCTION(GroupTests)


