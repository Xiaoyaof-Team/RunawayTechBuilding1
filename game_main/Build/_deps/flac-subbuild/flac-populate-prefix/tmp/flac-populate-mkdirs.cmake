# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-src")
  file(MAKE_DIRECTORY "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-src")
endif()
file(MAKE_DIRECTORY
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-build"
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix"
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/tmp"
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/src/flac-populate-stamp"
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/src"
  "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/src/flac-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/src/flac-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/elab/game_study_team/RunawayDUT353/RunawayDUT353/game_main/Build/_deps/flac-subbuild/flac-populate-prefix/src/flac-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
