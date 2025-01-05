
-- workspace ��������������solution�ĸ���
workspace "Hazel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- ���Ŀ¼ ���ڿ����õ�������Ǵ洢�ڱ����У�����ʹ���˺����Զ�ȷ��ϵͳ�ܹ�����Ϣ��
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	--ָ������������е���Ŀλ�ã��Ա��ڽ����ɵ������ļ�������ȷ��Ŀ¼��
	location "Hazel"
	kind "SharedLib" 
	language "C++"

	targetdir ("bin/" ..outputdir.."/%{prj.name}")
	objdir ("bin-int/" ..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vender/spdlog/include"
	}

	--filter 用于定义指定的内容，当filter被激活。范围为直至下一个filter或project
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0"

		-- Ԥ�����
		defines
		{
			 "HZ_PLATFORM_WINDOWS",
			 "HZ_BUILD_DLL"
		}
		postbuildcommands
		{
			("{MKDIR} %[bin/".. outputdir .."/Sandbox]"),
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

	filter "configurations:Debug"
		defines
		{
			"HZ_DEBUG"
		}
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"HZ_RELEASE"
		}	
		optimize "On"

	filter "configurations:Dist"
		defines
		{
			"HZ_Dist"
		}
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp" 
	language "C++"

	targetdir ("bin/" ..outputdir.."/%{prj.name}")
	objdir ("bin-int/" ..outputdir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vender/spdlog/include",
		"Hazel/src"
	}

	--Hazel由于被build为了一个dll，因此需要指定将Sandbox链接到Hazel
	links
	{
		"Hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
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
		symbols "On"

	filter "configurations:Release"
		defines
		{
			"HZ_RELEASE"
		}	
		optimize "On"

	filter "configurations:Dist"
		defines
		{
			"HZ_Dist"
		}
		optimize "On"

	filter "action:vs*"
        buildoptions { "/utf-8" }