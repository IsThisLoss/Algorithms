add_library(
        StringUtils
        KmpSearch.h
        KmpSearch.cpp
        StringSplit.h
        StringSplit.cpp
        LevenshtainDistance.h
        LevenshtainDistance.cpp
        BKTree.h
        BKTree.cpp
)

set_target_properties(StringUtils PROPERTIES LINKER_LANGUAGE CXX)
