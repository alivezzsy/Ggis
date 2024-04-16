#ifndef ENV_H
#define ENV_H

#include "opengl/shader.h"
#include "opengl/renderer.h"
#include "operation/operationlist.h"

#include<QString>

//在头文件中声明变量，是为了让其他源文件知道这些变量的存在，
//并可以在需要时使用它们。然后，在源文件中提供变量的定义和初始化
//，以分配内存并为变量赋予初始值。

class GeoMap;

namespace Env {

	/* Shaders */
	extern Shader pointShader;
	extern Shader lineShader;
	extern Shader polygonShader;
	extern Shader borderShader;
	extern Shader highlightShader;
	extern Shader textureShader;
	extern Renderer renderer;
	void createShaders();

	/* Mouse Cursor */
	enum class CursorType {
		Normal = 0,
		Palm = 1,
		Editing = 2,
		WhatIsThis = 3,
	};

	// Whether is editing map
	extern bool isEditing;

	// Mouse cursor type
	// Normal, palm, etc.
	extern CursorType cursorType;

	// map
	// There is only one map in one project
	extern GeoMap* map;

	// Project home path
	extern QString HOME;

	// Record the operations: move features, delete features, etc.
	extern OperationList opList;

	extern float zoom;
} // namespace Env

#endif // ENV_H
