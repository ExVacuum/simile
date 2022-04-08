workspace("simile")
    configurations({
        "Debug",
        "Release"
    })

project("simile")
    kind("StaticLib")
    language("C")
    targetdir("bin/%{cfg.buildcfg}")
    libdirs({
        "libs"
    })

    links({
        "gl",
        "glad",
        "glfw"
    })

    files({
        "inc/**.h",
        "src/**.c"
    })

    filter("system:not windows")
        defines({
            "NOT_WINDOWS"
        })

    filter("configurations:Debug")
        defines({
            "DEBUG"
        })
        symbols("On")
        postbuildcommands({
            "doxygen"
        })

    filter({ "system:linux", "configurations:Debug", "action:gmake or action:gmake2" })
        buildoptions({
            "-fprofile-arcs",
            "-ftest-coverage"
        })
        linkoptions({
            "-lgcov",
            "--coverage"
        })

    filter("configurations:Release")
        defines({
            "NDEBUG"
        })
        optimize("On")

project("SimileTests")
    kind("ConsoleApp")
    language("C")
    targetdir("test/bin/%{cfg.buildcfg}")
    libdirs({
        "libs/**"
    })

    links({
        "criterion",
        "simile",
        "glad",
        "glfw"
    })

    files({
        "test/inc/**.h",
        "test/src/**.c"
    })

    objdir("test/obj")

    postbuildcommands({
        "%{cfg.buildtarget.relpath}"
    })

    filter({ "system:linux", "action:gmake or action:gmake2" })
        buildoptions({
            "-fprofile-arcs",
            "-ftest-coverage"
        })
        linkoptions({
            "-lgcov",
            "--coverage"
        })



