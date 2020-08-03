add_library(
        StringUtils
        KmpSearch.h
        StringSplit.h
)

set_target_properties(StringUtils PROPERTIES LINKER_LANGUAGE CXX)