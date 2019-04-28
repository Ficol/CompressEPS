find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(CompressEPSTests a.cc ChainTests.cc BitmapTests.cc InstructionInterpreterTests.cc ConverterTests.cc)
target_link_libraries(CompressEPSTests ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(boostUnitTestsRun compressEPSTests)
