

filegroup(
    name = "cc",
    srcs = ["cc.build_defs"],
    visibility = ["PUBLIC"]
)

filegroup(
    name = "c",
    srcs = ["c.build_defs"],
    visibility = ["PUBLIC"]
)

filegroup(
    name = "compilerPlugin",
    srcs = ["compilerPlugin.build_defs"],
    visibility = ["PUBLIC"]
)

subinclude("///cc//build_defs:compilerPlugin")

compilerPlugin(
    name="gcc",
    include="///cc//build_defs/compilers:gcc",
    compiler="translationUnit",
    archiver="archive",
    linker="link"
)