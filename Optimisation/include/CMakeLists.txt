set(FILES "")
set(RELATIVE_PATH "include")

#Add all subdirectories 
add_subdirectory("ProblemeOptimisation")
add_subdirectory("Probleme14")
add_subdirectory("Probleme23")
add_subdirectory("Enregistre")

if(FILES)
	#Add source files to target
	target_sources("${PROJECT_NAME}" PRIVATE ${FILES})
	
	#Install our source files
	install(FILES ${FILES} DESTINATION ${RELATIVE_PATH})
endif()