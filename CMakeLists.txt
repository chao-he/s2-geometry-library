project(s2 CXX)
set(PROJECT_NAME s2)
set(PROJECT_VERSION 0.1.1)
cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
add_definitions(-DS2_USE_EXACTFLOAT -DHASH_NAMESPACE=std -DNDEBUG)
set_property(GLOBAL PROPERTY CXX_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

include_directories(
	.
	${OPENSSL_INCLUDE_DIR}
)

set(s2sources
	geometry/base/int128.cc
	geometry/base/logging.cc
	geometry/base/stringprintf.cc
	geometry/base/strtoint.cc
	geometry/strings/ascii_ctype.cc
	geometry/strings/split.cc
	geometry/strings/stringprintf.cc
	geometry/strings/strutil.cc
	geometry/util/coding/coder.cc
	geometry/util/coding/varint.cc
	geometry/util/hash/hash.cc
	geometry/util/math/exactfloat/exactfloat.cc
	geometry/util/math/mathlimits.cc
	geometry/util/math/mathutil.cc
	geometry/s1angle.cc
	geometry/s2.cc
	geometry/s2cellid.cc
	geometry/s2latlng.cc
	geometry/s1interval.cc
	geometry/s2cap.cc
	geometry/s2cell.cc
	geometry/s2cellunion.cc
	geometry/s2edgeindex.cc
	geometry/s2edgeutil.cc
	geometry/s2latlngrect.cc
	geometry/s2loop.cc
	geometry/s2pointregion.cc
	geometry/s2polygon.cc
	geometry/s2polygonbuilder.cc
	geometry/s2polyline.cc
	geometry/s2r2rect.cc
	geometry/s2region.cc
	geometry/s2regioncoverer.cc
	geometry/s2regionintersection.cc
	geometry/s2regionunion.cc
)

set(s2
  geometry/s2/hash_map_backward.h
	geometry/s2/r1interval.h
	geometry/s2/s1angle.h
	geometry/s2/s1interval.h
	geometry/s2/s2cap.h
	geometry/s2/s2cell.h
	geometry/s2/s2cellid.h
	geometry/s2/s2cellunion.h
	geometry/s2/s2edgeindex.h
	geometry/s2/s2edgeutil.h
	geometry/s2/s2.h
	geometry/s2/s2latlng.h
	geometry/s2/s2latlngrect.h
	geometry/s2/s2loop.h
	geometry/s2/s2pointregion.h
	geometry/s2/s2polygonbuilder.h
	geometry/s2/s2polygon.h
	geometry/s2/s2polyline.h
	geometry/s2/s2r2rect.h
	geometry/s2/s2regioncoverer.h
	geometry/s2/s2region.h
	geometry/s2/s2regionintersection.h
	geometry/s2/s2regionunion.h
  )

set(s2base
	geometry/base/basictypes.h
	geometry/base/casts.h
	geometry/base/commandlineflags.h
	geometry/base/int128.h
	geometry/base/integral_types.h
	geometry/base/logging.h
	geometry/base/macros.h
	geometry/base/port.h
	geometry/base/scoped_ptr.h
	geometry/base/stl_decl.h
	geometry/base/stl_decl_msvc.h
	geometry/base/stl_decl_osx.h
	geometry/base/stringprintf.h
	geometry/base/strtoint.h
	geometry/base/template_util.h
	geometry/base/type_traits.h
  )

set(s2string
	geometry/strings/ascii_ctype.h
	geometry/strings/split.h
	geometry/strings/stringprintf.h
	geometry/strings/strutil.h
  )

set(s2coding
	geometry/util/coding/coder.h
	geometry/util/coding/varint.h
  )

set(s2endian
	geometry/util/endian/endian.h
  )

set(s2hash
	geometry/util/hash/hash.h
	geometry/util/hash/hash_jenkins_lookup2.h
  )

set(s2math
	geometry/util/math/mathlimits.h
	geometry/util/math/mathutil.h
	geometry/util/math/matrix3x3.h
	geometry/util/math/matrix3x3-inl.h
	geometry/util/math/vector2.h
	geometry/util/math/vector2-inl.h
	geometry/util/math/vector3.h
	geometry/util/math/vector3-inl.h
	geometry/util/math/vector4.h
	geometry/util/math/vector4-inl.h
)

add_library(s2 SHARED ${s2sources})
target_link_libraries(s2 ${OPENSSL_LIBRARIES} pthread)

add_library(s2static STATIC ${s2sources})
set_target_properties(s2static PROPERTIES OUTPUT_NAME s2)

install(TARGETS s2 s2static
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

CONFIGURE_FILE(
	${CMAKE_CURRENT_SOURCE_DIR}/s2.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/s2.pc
	@ONLY
)

CONFIGURE_FILE(
	${CMAKE_CURRENT_BINARY_DIR}/s2.pc
	@ONLY
)

# Install header files
install(FILES ${s2} DESTINATION include/geometry/s2)
install(FILES ${s2base} DESTINATION include/geometry/base)
install(FILES ${s2string} DESTINATION include/geometry/strings)
install(FILES ${s2coding} DESTINATION include/geometry/util/coding)
install(FILES ${s2endian} DESTINATION include/geometry/util/endian)
install(FILES ${s2hash} DESTINATION include/geometry/util/hash)
install(FILES ${s2math} DESTINATION include/geometry/util/math)

install(FILES ${CMAKE_BINARY_DIR}/s2.pc DESTINATION lib/pkgconfig)
