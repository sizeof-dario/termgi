cmake_minimum_required(VERSION 3.28.3)

project(termgci)

add_executable(termgci_test)

target_sources(termgci_test
  PRIVATE
    ./code/main.c

)
