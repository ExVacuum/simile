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

    files({
        "inc/**.h",
        "src/**.c"
    })

    filter("configurations:Debug")
        defines({
            "DEBUG"
        })
        symbols("On")
        postbuildcommands({
            "doxygen"
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
        "unity",
        "simile"
    })

    files({
        "test/inc/**.h",
        "test/src/**.c"
    })

    postbuildcommands({
        "%{cfg.buildtarget.relpath}"
    })

