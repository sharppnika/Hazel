#pragma once
//供Hazel App使用，将所有需要的头文件聚集起来。注意，此时的入口点文件只能在application下方，否则无法识别到命名空间
//由于事先定义了宏，根据是否为应用端决定是导出还是导入dll，因此所有的声明到了app端都会自动变成导入。（因为项目宏定义中进行了相关设置）


#include "Hazel/Application.h"
 
#include "Hazel/Log.h"

//———————————入口点———————————————
#include "Hazel/EntryPoint.h"
//———————————————————————————————— 