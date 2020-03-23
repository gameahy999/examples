workspace(name = "examples")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "9f9fb8b2f0213989247c9d5c0e814a8451d18d7f",
    remote = "https://github.com/nelhage/rules_boost",
    shallow_since = "1570056263 -0700",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()

git_repository(
    name = "com_github_double_conversion",
    commit = "109381b12529aba71f2204570dab4ce4841ddae3",
    remote = "git@coding.jd.com:rec_fork/double-conversion.git",
    shallow_since = "1575890362 +0800",
)

git_repository(
    name = "com_github_libevent",
    commit = "9bf1a96bc7e05c00418939340a2e883750166471",
    remote = "git@coding.jd.com:rec_fork/libevent.git",
)

git_repository(
    name = "com_github_folly",
    commit = "03b2b60272ba1746d4c41e5a5adb10c8d1015256",
    remote = "git@coding.jd.com:rec_fork/folly.git",
)

git_repository(
    name = "com_github_gflags_gflags",
    commit = "a187792cd3302c7dd12bb136faf4dd119eaa9095",
    remote = "git@coding.jd.com:rec_fork/gflag.git",
    shallow_since = "1575819989 +0800",
)

git_repository(
    name = "com_github_google_glog",
    commit = "234cd8619068db71538f5df8d0c0a17a65841fcd",
    remote = "git@coding.jd.com:rec_fork/glog.git",
)
