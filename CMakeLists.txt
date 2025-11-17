cmake_minimum_required(VERSION 3.28.3)

project(termgci)

add_executable(a.out)

target_sources(a.out
  PRIVATE
    main.c
    termgi.c
)
