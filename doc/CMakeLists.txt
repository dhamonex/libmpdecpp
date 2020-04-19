if (DOXYGEN_FOUND)
  set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md")
  set(DOXYGEN_EXCLUDE_SYMBOLS detail)
  set(DOXYGEN_EXCLUDE_PATTERNS 
      test
      CMakeLists.txt
      */.git/*
      gtest
    )
  set(DOXYGEN_EXTRACT_ALL YES)
  doxygen_add_docs(doc
    ${CMAKE_SOURCE_DIR}
  )
endif()
