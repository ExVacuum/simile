workspace("glad")
    configurations({
        "Debug",
        "Release"
    })

project("glad")
    kind("StaticLib")
    language("C")
    targetdir("bin/%{cfg.buildcfg}")
 
    files({
        "inc/**.h",
        "src/**c"
    })

    filter("configurations:Debug")
        defines({
            "DEBUG"
        })
        symbols("On")

    filter("configurations:Release")
        defines({
            "NDEBUG"
        })
        optimize("On")


