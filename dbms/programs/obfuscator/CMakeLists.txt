add_library (clickhouse-obfuscator-lib ${LINK_MODE} Obfuscator.cpp)
target_link_libraries (clickhouse-obfuscator-lib PRIVATE dbms ${Boost_PROGRAM_OPTIONS_LIBRARY})

if (CLICKHOUSE_SPLIT_BINARY)
    add_executable (clickhouse-obfuscator clickhouse-obfuscator.cpp)
    set_target_properties(clickhouse-obfuscator PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
    target_link_libraries (clickhouse-obfuscator PRIVATE clickhouse-obfuscator-lib)
    install (TARGETS clickhouse-obfuscator ${CLICKHOUSE_ALL_TARGETS} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT clickhouse)
endif ()
