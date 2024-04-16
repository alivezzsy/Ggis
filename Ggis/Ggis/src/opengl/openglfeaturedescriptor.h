//VAO¡¢VBO¡¢IBOµÄ¼¯ºÏ
#pragma once

#include "opengl/vertexarray.h"
#include "opengl/vertexbuffer.h"
#include "opengl/indexbuffer.h"
#include "geo/geofeature/geometry.h"

class OpenglFeatureDescriptor
{
public:
	OpenglFeatureDescriptor(int stride) : stride(stride) {}
	~OpenglFeatureDescriptor();

	void offset(double xOffset, double yOffset);

	 // Just resend data to GPU

public:
	int stride;
	VertexBuffer* vbo = nullptr;
	VertexArray* vao = nullptr;
	std::vector<IndexBuffer*> ibos;
};