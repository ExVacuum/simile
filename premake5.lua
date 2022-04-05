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

    filter("configurations:Release")
        defines({
            "NDEBUG"
        })
        optimize("On")

newaction
{
    trigger     = "docs",
    description = "Build documentation",
    execute = function ()
        os.execute "doxygen doxygen.config"
    end
}
