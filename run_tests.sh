#!/bin/bash

# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Error: You need to specify the operating system as a parameter."
  echo "Usage: ./run_tests.sh <OS>"
  exit 1
fi

# Get the operating system from the argument
OS=$1

# Emulate Docker image testing
echo "Running tests for the Docker image based on OS: $OS..."

# Stub for successful test
sleep 2  # Simulate testing time
echo "Docker image testing for $OS completed successfully!"
exit 0
