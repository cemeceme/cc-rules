
subinclude("//build_defs:cc")

export_file(
    name="GenSrc",
    src="genSource.cpp"
)

export_file(
    name="GenHdr",
    src="genHeader.h"
)

cc_library(
    name = "TestLib",
    srcs=["libSource.cpp", "testFolder/folderSource.cpp", ":GenSrc"],
    hdrs=["libHeader.h", "testFolder/folderHeader.h", ":GenHdr"],
    includes=["testFolder"],
    deps=["//test/lib2:TestLib2"],
    defines=["TEST_DEFINE"]
)

cc_shared_object(
    name = "TestShared",
    srcs=["sharedLibSource.cpp"],
    hdrs=["sharedLibHeader.h"],
    deps=[":TestLib"]
)

cc_binary(
    name = "TestBinary",
    srcs=["main.cpp"],
    hdrs=["main.h"],
    deps=[":TestShared"],
    linker_flags=["-rpath '$ORIGIN'"]
)