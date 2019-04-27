add_executable(SOURCE_FILES Chain.h, Chain.cc, Bitmap.h, Bitmap.cc, Converter.h, Converter.cc,  InstructionInterpreter.h, InstructionInterpreter.cc, CompressEPS.cc)
add_library(src ${SOURCE_FILES})
