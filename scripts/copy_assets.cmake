# Found on stackoverflow: https://stackoverflow.com/a/65133324

file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(COPY ${CMAKE_CURRENT_LIST_DIR}/../assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
