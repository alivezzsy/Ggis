#pragma once

#include "opengl/vertexarray.h"
#include "opengl/indexbuffer.h"
#include "opengl/shader.h"

#include<vector>

class Renderer {
public:
	void Clear() const;
	void DrawPoint(const VertexArray* vao, const IndexBuffer* ibo, Shader& pointShader);
	void DrawLine(const VertexArray* vao, const IndexBuffer* ibo, Shader& lineShader);
	void DrawPolygon(const VertexArray* vao, const IndexBuffer* ibo, Shader& polygonShader);
	void DrawPolygonBorder(const VertexArray* vao, Shader& borderShader);
	void DrawHighlight(const VertexArray* vao, Shader& highlightShder);
};