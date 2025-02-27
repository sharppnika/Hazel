
-- workspace ��������������solution�ĸ���
workspace "Hazel"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	-- ���Ŀ¼ ���ڿ����õ�������Ǵ洢�ڱ����У�����ʹ���˺����Զ�ȷ��ϵͳ�ܹ�����Ϣ��
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Hazel/vendor/GLFW/include"
	IncludeDir["Glad"] = "Hazel/vendor/Glad/include"
	IncludeDir["ImGui"] = "Hazel/vendor/imgui"
	
	include "Hazel/vendor/GLFW/"
	include "Hazel/vendor/Glad/"
	include "Hazel/vendor/ImGui/"
	

project "Hazel"
	--ָ������������е���Ŀλ�ã��Ա��ڽ����ɵ������ļ�������ȷ��Ŀ¼��
	location "Hazel"
	kind "SharedLib" 
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.."/%{prj.name}")
	objdir ("bin-int/" ..outputdir.."/%{prj.name}")

	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"Hazel/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}


	--filter 用于定义指定的内容，当filter被激活。范围为直至下一个filter或project
	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0"

		-- Ԥ�����
		defines
		{
			 "HZ_PLATFORM_WINDOWS",
			 "HZ_BUILD_DLL",
			 "GLFW_INCLUDE_NONE"
		}
		postbuildcommands
		{
			
			--("{MKDIR} %[bin/".. outputdir .."/Sandbox]"),
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"") 
		}

	filter "configurations:Debug"
		defines
		{
			"HZ_DEBUG"
		}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"HZ_RELEASE"
		}	
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines
		{
			"HZ_Dist"
		}
		runtime "Release"
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp" 
	language "C++"
	staticruntime "off"

	targetdir ("bin/" ..outputdir.."/%{prj.name}")
	objdir ("bin-int/" ..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vendor/spdlog/include",
		"Hazel/src"
	}

	--Hazel由于被build为了一个dll，因此需要指定将Sandbox链接到Hazel
	links
	{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "10.0"

		-- Ԥ�����
		defines
		{
			 "HZ_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines
		{
			"HZ_DEBUG"
		}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"HZ_RELEASE"
		}	
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines
		{
			"HZ_Dist"
		}
		runtime "Release"
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }
