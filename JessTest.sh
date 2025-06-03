#!/bin/bash
# Path to the directory containing the map files
MAP="./maps/error"
# MAP="./maps/passing"
# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
RESET='\033[0m' # No color
# Function to run valgrind and check output
run_test() {
    local map=$1
    local test_type=$2
    local map_color=$3
    echo -e "${CYAN}Running ${test_type} maps:${RESET} ${map_color}$map${RESET}"
    # Run the program and capture both stdout and stderr
    ./cub3D "$map"
    exit_status=$?
    # After the program runs, check if it exited with a non-zero status (failed test)
    if [ $exit_status -ne 0 ]; then
        echo -e "${RED}EXITED with non-zero status.${RESET}"
    else
        echo -e "${GREEN}Test passed: No exit encountered.${RESET}"
    fi
    # Only run valgrind on Linux
     if [[ "$(uname)" == "Linux" ]]; then
    #     # Run valgrind and capture output
         valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 ./cub3D "$map" 2>&1)
    #     # Check for memory leaks or errors
         if echo "$valgrind_output" | grep -q "All heap blocks were freed"; then
            echo -e "${GREEN}Memory PASSED: No memory leaks detected.${RESET}"
         else
             echo -e "${RED}Memory issues detected${RESET}"
             echo "$valgrind_output" # Show full valgrind output if there are issues
         fi
     else
        echo -e "${YELLOW}Test does not handle nor support memory check on mac OS${RESET}"
     fi
    # Add a new line after each test
    echo
}
# Loop through invalid map files
for map in "$MAP"/*
do
    run_test "$map" "invalid" "$RED"
done