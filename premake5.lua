-- premake5.lua
workspace "Launcher"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Launcher"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "WalnutExternal.lua"
include "Launcher"