cc_binary(
  name = "test",
  srcs = [
    "main.cpp",
    "boost_stuff.cpp",
    "boost_stuff.h",
    "closure.cpp",
    "closure.h",
    "copy_control.cpp",
    "copy_control.h",
    "default_constructor.cpp",
    "default_constructor.h",
    "folly_stuff.cpp",
    "folly_stuff.h",
    "grammer.cpp",
    "grammer.h",
    "long_integer.cpp",
    "long_integer.h",
    "math_experiment.cpp",
    "math_experiment.h",
    "memory_leak.cpp",
    "memory_leak.h",
    "misc.cpp",
    "misc.h",
    "parallel_programming.cpp",
    "parallel_programming.h",
    "policy_template.h",
    "sine_graph.cpp",
    "sine_graph.h",
    "standard_library.cpp",
    "standard_library.h",
    "template_specialization.cpp",
    "template_specialization.h",
    "test_const.cpp",
    "test_const.h",
    "test_gdb.cpp",
    "test_gdb.h",
    "test_pb.cpp",
    "test_pb.h",
    "test_rvo.cpp",
    "test_rvo.h",
    "trait_template.cpp",
    "trait_template.h",
    "trivial_template.h",
    "utils.cpp",
    "utils.h",
    "warmup.cpp",
    "warmup.h",
    "warmup_utils.cpp",
    "warmup_utils.h",
  ],
  deps = [
    "@com_github_folly//:folly",
    "@com_github_google_glog//:glog",
    # "@com_github_libevent//:libevent",
  ],
  linkopts = ["-lpthread", "-levent"],
  visibility = ["//visibility:public"],
)
